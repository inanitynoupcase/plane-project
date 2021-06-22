#include"CTDL.h"
#include<cmath>
#include<string.h>
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cstdio>
#include <iomanip>  
#pragma once
NodeMayBay dsmb;
ptrDSCB pheadDSCB=NULL;
nodehk root=NULL;
ofstream MBO; 
ifstream MBI;
ofstream HKT;
ifstream HKTIN;
ofstream CBO;
ifstream CBI;
void FileOutMB(ofstream &MBOut,NodeMayBay nodemb,int n)
{
	MBOut.open("DSMB.txt",ios::app);
	MBOut<<nodemb.data[n]->ID<<" "<<nodemb.data[n]->Type<<" "<<nodemb.data[n]->Room<<" "<<nodemb.data[n]->SoLuotBay<<" "<<nodemb.data[n]->Active<<endl;
 	MBOut.close();
}

void FileInMB(ifstream &MBIn,NodeMayBay &nodemb){
  	MBI.open("DSMB.txt");
  	string TempRead;
  	vector<string>temp;
  	int TempTotal=0;
	char tempID[16];
	char tempType[41];
  
 	while(getline(MBI,TempRead)){
	stringstream iss(TempRead);
	for( string a; iss >>a;){
		temp.push_back(a);
	}
  /*  for (int  i = 0; i < temp.size(); i++)
    {
      cout<< temp[i]<<" ";
    } */
  //  cout<<endl;
  	int x[3]; 
	vector<int>number;
    for(int i=(temp.size()-3); i<temp.size(); i++){
        int count =0;
        stringstream go(temp[i]);
        go >> x[count];
        number.push_back(x[count]);
       //  cout<< x[count]<<" ";
        count++;
    }
     
      	MayBay* mb= new MayBay;
    	mb->Room = number[0];  
    	mb->SoLuotBay = number[1];
    	mb->Active = number[2];
    // cout<<mb->Room<<" "<<mb->SoLuotBay<<" "<<mb->ACTIVE<<endl;
    
     	strcpy(tempID, temp[0].c_str());
     	strcpy(tempType, temp[1].c_str());
      	strcpy(mb->ID,tempID);
     	strcpy(mb->Type,tempType);
      	nodemb.data[TempTotal] = mb;
      // cout<<nodemb.data[TempTotal]->Room<<" "<<nodemb.data[TempTotal]->SoLuotBay<<" "<<nodemb.data[TempTotal]->ACTIVE<<endl;
      //  cout<< nodemb.data[TempTotal]->ID <<" "<<nodemb.data[TempTotal]->Type;
    TempTotal++;
    dsmb.total = TempTotal;
    number.clear();
    temp.clear();  
	}
	MBI.close();
}

void FileOutCB(ofstream &out,ptrDSCB phead)
{
	out.open("ChuyenBay.txt",ios::app);
	NodeChuyenBay* ptr= new NodeChuyenBay;
	ptr=phead;
	while(ptr!= NULL)
	{
		int count=0;
		string temp =ptr->data.SanBayDen;
		stringstream iss(temp);
		for(string a; iss>> a;)
		{
			count++;
		}
		out<<ptr->data.MaCB<<" ";
		out<<ptr->data.DepartTime.day<<" ";
		out<<ptr->data.DepartTime.mon<<" ";
		out<<ptr->data.DepartTime.year<<" ";
		out<<ptr->data.DepartTime.hour<<" ";
		out<<ptr->data.DepartTime.min<<" ";
		out<<ptr->data.ID<<" ";
		out<<ptr->data.Status<<" ";
		out<<ptr->data.SanBayDen<<" "<<count<<endl;
		ptr=ptr->next;
	}
	out.close();
}


void NLR_FileOutHK(ofstream &out,nodehk root)
{
  out.open("HanhKhach.txt",ios::app | ios::binary );
  if(root != NULL)
  {
  	   int count=0;
  	   string name;
  	   name = root->data.TEN;
  	   stringstream is(name);
  	   for(string a; is >>a;)
  	   {
  	      count++;	
	   }
       out<<root->data.CCCD<<" "<<root->data.HO <<" "<< root->data.TEN<<" "<<count<<" "<< root->data.GioiTinh<<endl;
       out.close();
       NLR_FileOutHK(out,root->left);
       out.close();
       NLR_FileOutHK(out,root->right);
  }
  out.close();
}

void CMDREMOVE() // De phong ham remove bi loi 
{
  system("echo %cd% > location.txt");
    ifstream in("location.txt");
    string temp;
    vector<char> RLocation;
    getline(in,temp);
    for(int i=0; i< temp.size(); i++)
    {
        RLocation.push_back(temp[i]);
        if (temp[i] == '\\')
        {
            RLocation.push_back('\\');
        }
    }
    string location(RLocation.begin(),RLocation.end());
  //  cout<<location;
    string cmd;
    cmd= "cd /d "+ location + " & del DSMB.txt";
    system(cmd.c_str());
}

#define IDCANCEL 2
// ham xu ly may bay        
int SearchIdMb(NodeMayBay NodeMb, char TempId[]);
void AddMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom);
int VerifyMb(char TempId[]);
bool VerifyMbBool(char TempID[]);
void DelMb(NodeMayBay &nodemb,char TempID[]);
void EditMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom);

// ham xu ly chuyen bay
void InsertNodeCB(ptrDSCB &pheadCB, NodeChuyenBay *p);
void UpdateCB(ptrDSCB &pheadDSCB);
void EditChuyenBay(ptrDSCB &pheadDSCB);
HanhKhach CreateData(char TempCmnd[]);
void UpCase(char t[]);
void AddNewChuyenBay(ptrDSCB &pheadDSCB);
void DelChuyenBay(ptrDSCB &pheadDSCB, NodeMayBay &DSMB);
void SortCB_Time(ptrDSCB &pheadDSCB);
void PrintRemainTicket(DsVe &DSVE , char TempMaCB[]);
void PrintTotalFlight(NodeMayBay DSMB);



//search ma may bay
int SearchIdMb(NodeMayBay NodeMb,char TempId[])
{
    for(int i=0; i< NodeMb.total ; i++)
     {
        if(strcmp(NodeMb.data[i]->ID , TempId)==0 && NodeMb.data[i]->Active == true){
        	return i;
		}
	 }   
	return -1;
}

// them may bay
void AddMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom){
   MayBay* mb= new MayBay;
   strcpy(mb->ID, TempID);
   strcpy(mb->Type, TempType);
   mb->Room = TempRoom;
   nodemb.data[nodemb.total] = mb;
   nodemb.total++;
}
// chinh sua may bay
void EditMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom)
 {
   	int result = SearchIdMb(nodemb,TempID); // return i;
    dsmb.data[result]->Room = TempRoom;
    strcpy(dsmb.data[result]->Type,TempType);
}
     
//xoa may bay 
void DelMb(NodeMayBay &nodemb,char TempID[])
{
//nhap vao id may bay truoc
  	int result = SearchIdMb(nodemb,TempID);

    if(dsmb.data[result]->Active == true)
    {
       dsmb.data[result]->Active = false;
       return;
    }
    else if(dsmb.data[result]->Active == false)
    {
       // may bay da bi xoa tu truoc
       while (kbhit()) getch();
       return;
    }
}

//Search CHUYEN BAY 
ptrDSCB SearchNode(ptrDSCB &pheadCB,char TempMCB[])
{	
	NodeChuyenBay*ptr = pheadCB;
	while(ptr!=NULL)
  {
		if(strcmp(ptr->data.MaCB,TempMCB) == 0)
    	{
			return ptr;
		}
		ptr=ptr->next;
	}
	return NULL;
}
//INSERT NODE CHUYEN BAY
void InsertNodeCB(ptrDSCB &pheadCB, NodeChuyenBay *p)
{
  	if(pheadCB == NULL)
 	{
    pheadCB = p;
    return;
 	}
 	else
  	{
    ptrDSCB ptr = pheadCB;
    while(ptr->next != NULL) ptr = ptr->next;
    ptr->next =p;
    return;
  }
}
//ADD CHUYEN BAY
void AddNewChuyenBay(ptrDSCB &pheadDSCB,char TempMCB[],int TempDay,int TempMonth,int TempYear,int TempHour, int TempMin,char TempNoiToi[],char tempIDMB[],int TempTT)
{
	ChuyenBay data;
   	strcpy(data.MaCB,TempMCB);
   	strcpy(data.SanBayDen,TempNoiToi);
   	strcpy(data.ID,tempIDMB);
   	
   	
   	
   	Date d;
   	d.day = TempDay;
   	d.mon = TempMonth;
   	d.year = TempYear;
   	d.hour = TempHour;
   	d.min = TempMin;
   	data.DepartTime = d;
   	data.Status = TempTT;
   	
  	NodeChuyenBay*p = new NodeChuyenBay;
  	int result = SearchIdMb(dsmb,tempIDMB);
    DsVe TempDsVe;
  	CreateVe(TempDsVe, dsmb.data[result]->Room);
    data.dsv = TempDsVe;
    dsmb.data[result]->SoLuotBay++;
   
	p->data = data;
   	p->next = NULL;
   	
	/*
	data.DepartTime.hour = TempHour;
  	data.DepartTime.min = TempMin;
    data.DepartTime.day = TempDay;
    data.DepartTime.mon = TempMonth;
	data.DepartTime.year = TempYear;
	*/

//	cout << data.DepartTime.day << " " << data.DepartTime.mon << " " << data.DepartTime.year << " " << data.DepartTime.hour << " " << data.DepartTime.min << endl;
	InsertNodeCB(pheadDSCB,p);
}
bool checkYear(int year){
	//So nam chia het cho 400 thi la nam nhuan
    if (year % 400 == 0) 
        return true; 
  
    //So nam chia het cho 4 nhung k chia het cho 100 thi do k phai la nam nhuan 
    if (year % 4 == 0 && year % 100 != 0) 
        return true;
 
    //Cac truong hop con lai 
    return false; 
} 
// check khoang cach 2 tieng
bool check_decent_chuyen_bay(ptrDSCB &pheadDSCB,char temp_so_hieu[],Date temp)
{
	NodeChuyenBay *ptr = new NodeChuyenBay;
	ptr=pheadDSCB;
	while(ptr!=NULL)
{
//	cout<<ptr->data.DepartTime.day<<" "<<ptr->data.DepartTime.mon<<" "<<ptr->data.DepartTime.year<<" "<<ptr->data.DepartTime.hour << " "<<ptr->data.DepartTime.min<<endl;
//	cout<<ptr->data.ID;
	if(strcmp(ptr->data.ID,temp_so_hieu)==0 && ptr->data.Status!=0)
	{
		if(ptr->data.DepartTime.day==temp.day && ptr->data.DepartTime.mon==temp.mon && ptr->data.DepartTime.year==temp.year )
    {
			
			if(ptr->data.DepartTime.hour!=temp.hour)
      {
				int time=abs((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)-(temp.hour*60+temp.min));
				if(time<120)
        {
					return false;
				}
			}	
			else if(ptr->data.DepartTime.hour==temp.hour) return false;				
		}
			
		else if(abs(ptr->data.DepartTime.day-temp.day)==1 && ptr->data.DepartTime.mon==temp.mon && ptr->data.DepartTime.year==temp.year)
    {
			
			//cach nhau 1 ngay, cb truoc ptr->data
			if(ptr->data.DepartTime.day>temp.day)
      {
				int time=(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)
				+(1440-(temp.hour*60+temp.min));
			   if(time<120) return false;
			}
			
			//cach nhau 1 ngay, cb sau ptr->data
			else if(temp.day>ptr->data.DepartTime.day)
      {
				int time=(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))
				+(temp.hour*60+temp.min);
				if(time<120) return false;
			}
    }
    else if(ptr->data.DepartTime.year==temp.year && abs(ptr->data.DepartTime.mon-temp.mon)==1 )
    {
    	
		if((ptr->data.DepartTime.day==day[ptr->data.DepartTime.mon] && temp.day==1) || (temp.day==day[temp.mon] && ptr->data.DepartTime.day==1))
    {
			if(ptr->data.DepartTime.mon>temp.mon)
      {
				if((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)+(1440-(temp.hour*60+temp.min))<120)
        {
				return false;
				}
			}
			else
        {
				if((temp.hour*60+temp.min)+(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))<120)
        {
				return false;
			}
		}
	}
	}
	else if(abs(ptr->data.DepartTime.year-temp.year)==1 )
  {
		if(ptr->data.DepartTime.day==31 && ptr->data.DepartTime.mon==12 && temp.day==1 && temp.mon==1)
    {
			if((temp.hour*60+temp.min)+(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))<120)
      {
				return false;
		}
	}
		else if(ptr->data.DepartTime.day==1 && ptr->data.DepartTime.mon==1 && temp.day==31 && temp.mon==12)
    {
			if((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)+(1440-(temp.hour*60+temp.min))<120)
      {
				return false;
				}
		}

	 }

  }
		ptr=ptr->next;

 }
		return true;
}
// Sort Chuyen Bay 
void SortCB_Time(ptrDSCB &pheadDSCB)
{
  	ptrDSCB ptr1= pheadDSCB;
  	while(ptr1 != NULL)
   {
     	ptrDSCB ptr2 = ptr1->next;
    	  while(ptr2 != NULL)
     	{
        if(CheckDepartTime(ptr1->data.DepartTime)==true && CheckDepartTime(ptr2->data.DepartTime)==true)
        {
          	if(IsNearer(ptr2->data.DepartTime, ptr1->data.DepartTime))
          	{
             ChuyenBay TempChuyenBay = ptr1->data;
             ptr1->data = ptr2->data;
             ptr2->data = TempChuyenBay;
          	}
    	}
        else if(ptr1->data.Status == 3 || CheckDepartTime(ptr1->data.DepartTime) == false && CheckDepartTime(ptr2->data.DepartTime) == true )
        {
            ChuyenBay TempChuyenBay = ptr1->data;
            ptr1->data = ptr2->data;
            ptr2->data = TempChuyenBay;
        }
        else if(CheckDepartTime(ptr1->data.DepartTime)== false && CheckDepartTime(ptr2->data.DepartTime)== false)
        {
            if(IsNearer2(ptr2->data.DepartTime, ptr1->data.DepartTime))
            {
              ChuyenBay TempChuyenBay = ptr1->data;
              ptr1->data = ptr2->data;
              ptr2->data = TempChuyenBay;
            }
        }
         ptr2 = ptr2->next; 
    	}
      	ptr1 = ptr1->next;
   }
}
//EDIT CHUYEN BAY 
void EditChuyenBay(ptrDSCB &pheadDSCB,ptrDSCB &editnode,char TempMCB[],int TempDay,int TempMon,int TempYear,int TempHour, int TempMin)
{
 /*	NodeChuyenBay* EditNode = pheadDSCB;
  	while(EditNode != NULL)
  	{
    if(strcmp(EditNode->data.MaCB,TempMCB) == 0)
     {
       break;
     }
    else EditNode = EditNode->next;
 	}
 	*/
    Date TempDepart;
    TempDepart.day = TempDay;
    TempDepart.mon = TempMon;
    TempDepart.year = TempYear;
    TempDepart.hour = TempHour;
    TempDepart.min = TempMin;

    editnode->data.DepartTime = TempDepart;
}
//check HOP LE edit CHUYEN BAY
bool check_decent_chuyen_bay_version_2(ptrDSCB &pheadDSCB,ptrDSCB &EditNode,char TempIDMB[],Date Temp)
{
	
		NodeChuyenBay*ptr=pheadDSCB;
	while(ptr!=NULL)
	{
	if(strcmp(ptr->data.ID,TempIDMB)==0 && ptr->data.Status!=0 && ptr!=EditNode)
	{
		if(ptr->data.DepartTime.day==Temp.day && ptr->data.DepartTime.mon==Temp.mon
		&& ptr->data.DepartTime.year==Temp.year )
		{
			
			if(ptr->data.DepartTime.hour!=Temp.hour)
			{
				int time=abs((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)-(Temp.hour*60+Temp.min));
				if(time<120)
				{
					return false;
				}
			}
			
			else if(ptr->data.DepartTime.hour==Temp.hour) return false;				
		}
			
		else if(abs(ptr->data.DepartTime.day-Temp.day)==1 && ptr->data.DepartTime.mon==Temp.mon
		&& ptr->data.DepartTime.year==Temp.year){
			
			//cach nhau 1 ngay, cb truoc ptr->data
			if(ptr->data.DepartTime.day>Temp.day){
				int time=(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)
				+(1440-(Temp.hour*60+Temp.min));
			   if(time<120) return false;
			}
			
			//cach nhau 1 ngay, cb sau ptr->data
			else if(Temp.day>ptr->data.DepartTime.day){
				int time=(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))+(Temp.hour*60+Temp.min);
				if(time<120) return false;
			}
        }
    else if(ptr->data.DepartTime.year==Temp.year && abs(ptr->data.DepartTime.mon-Temp.mon)==1 )
	{
    	
		if((ptr->data.DepartTime.day==day[ptr->data.DepartTime.mon] && Temp.day==1) || (Temp.day==day[Temp.mon] && ptr->data.DepartTime.day==1))
		{
			if(ptr->data.DepartTime.mon>Temp.mon){
				if((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)+(1440-(Temp.hour*60+Temp.min))<120)
				{
				return false;
				}
			}
			else{
				if((Temp.hour*60+Temp.min)+(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))<120){
				return false;
			}
		}
	}
	}
	else if(abs(ptr->data.DepartTime.year-Temp.year)==1 ){
		if(ptr->data.DepartTime.day==31 && ptr->data.DepartTime.mon==12 && Temp.day==1 && Temp.mon==1){
			if((Temp.hour*60+Temp.min)+(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))<120){
				return false;
		}
	}
		else if(ptr->data.DepartTime.day==1 && ptr->data.DepartTime.mon==1 && Temp.day==31 && Temp.mon==12){
			if((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)+(1440-(Temp.hour*60+Temp.min))<120){
				return false;
				}
		}

	}

	}
		ptr=ptr->next;

	}
		return true;
}

//Xoa het ds ve
void FREEVE(DsVe &dsv)
{
	for(int i=dsv.n; i< dsv.max;i++)
	{
		delete dsv.ve[i];
		dsv.ve[i]=NULL;
	}
}
// sort danh sach ve
void SortVe(DsVe &dsv)
{
	for(int i=0;i<dsv.n-1;i++)
	{
		Ve*Temp = dsv.ve[i];
		int TempIndex=i;
		for(int j=i+1;j<dsv.n;j++)
		{
			if(Temp->stt > dsv.ve[j]->stt)
			{
				Temp=dsv.ve[j];
				TempIndex=j;
			}
		}
		
		Temp=dsv.ve[i];
		dsv.ve[i]=dsv.ve[TempIndex];
		dsv.ve[TempIndex]=Temp;		
	}
}

//KIEM TRA VE TRONG 
//ve[1]->stt 323
//ve[2]->stt 1
bool IsEmpty(DsVe &dsv,int pos)
{
	for(int i=0;i<dsv.n;i++)
	{
		if(dsv.ve[i]->stt == pos)
		{
			return false;
		}
	}
	return true;
}

//XOA CHUYEN BAY 
void DelChuyenBay(ptrDSCB &pheadDSCB,ptrDSCB ptr, NodeMayBay &DSMB)
{
    ptr->data.Status=0;
	int result = SearchIdMb(DSMB,ptr->data.ID);
  	dsmb.data[result]->SoLuotBay--;
    FREEVE(ptr->data.dsv);
}
//UPDATE CHUYEN BAY 
void UpdateCB(ptrDSCB &pheadDSCB)
{
   NodeChuyenBay* ptr= new NodeChuyenBay;
   ptr = pheadDSCB;
   while(ptr != NULL)
   {
      if(ptr->data.dsv.n == ptr->data.dsv.max && ptr->data.Status != 0 )
      {
        ptr->data.Status = 2;
      }
      if(CheckDepartTime(ptr->data.DepartTime) == false && ptr->data.Status != 0 && ptr->data.Status != 3)
      {
        ptr->data.Status = 3;
        FREEVE(pheadDSCB->data.dsv);
      }
        ptr=ptr->next;
   }
}
int CountTotalHK =0;
void InsertNodehk(nodehk &root, HanhKhach &datahk)
{
   if(root == NULL )
   {
    nodehk temp = new NodeHanhKhach;
    strcpy(temp->data.CCCD,datahk.CCCD);
    strcpy(temp->data.HO,datahk.HO);
    strcpy(temp->data.TEN,datahk.TEN);
    strcpy(temp->data.GioiTinh,datahk.GioiTinh);
    temp->left = NULL;
    temp->right = NULL;
    root = temp;
    CountTotalHK++;
 	}
   else
   {
     if(strcmp(datahk.CCCD,root->data.CCCD) >0 )
	 {
       InsertNodehk(root->right,datahk);
     }
     else if(strcmp(datahk.CCCD, root->data.CCCD) <0 )
	 {
       InsertNodehk(root->left,datahk);
     }
   }
}

void FileInCB(ifstream &in, ptrDSCB &pheadDSCB)
{
	in.open("ChuyenBay.txt");
	string temp;
	while(getline(in,temp))
	{
		string *read = new string[15];
		int count=0;
		stringstream iss(temp);
		for(string a; iss >>a;)
		{
			read[count] = a;
			count++;
		}
		stringstream n(read[7]);
		int STAT;
		n >> STAT;
		stringstream is(read[count-1]);
		int CountNOIDEN;
	    is>> CountNOIDEN;
		string NoiDen;
		for(int i= count- CountNOIDEN -1 ; i< count-1; i++)
		{
			NoiDen = NoiDen+" "+read[i];
		}
		// CC 3 2 2022 2 1 MAYBAY1 1 Quang Nam 2  count = 11;
		//  0 1 2 3    4 5  6      7  8     9  10
 	ChuyenBay data;
	strcpy(data.MaCB,read[0].c_str());
	strcpy(data.ID,read[6].c_str());
	strcpy(data.SanBayDen,NoiDen.c_str());
	data.Status = STAT;
	
	int count2=0;
	int array[5];
	for(int i=1; i< 6; i++)
	{
		stringstream is(read[i]);
		is >> array[count2];
		count2++;
	}
		
		Date d;
		d.day = array[0];
		d.mon = array[1];
		d.year = array[2];
		d.hour = array[3];
		d.min = array[4];
		data.DepartTime = d;
		NodeChuyenBay*p = new NodeChuyenBay;
    	int result = SearchIdMb(dsmb,data.ID);
        DsVe TempDsVe;
    	CreateVe(TempDsVe, dsmb.data[result]->Room);
        data.dsv = TempDsVe;
	    p->data = data;
     	p->next = NULL;
     	InsertNodeCB(pheadDSCB,p);
	}
	
	in.close();
}

void FileINHK(ifstream &in)
{
 
  in.open("HanhKhach.txt");
  if(in.fail())
  {
  	return;
  }
  else
  {
  string temp;
   while(getline(in,temp))
   {
       stringstream iss(temp); 
       string *read = new string[10];
       string Name;
       int count=0;
       // 234234234  Phan     Dang1    ngu      2       Nam  count 6
       //     0        1       2        3      4        5
                            //  6-2-2      					   
       for(string a; iss >>a;)
       {
         read[count] = a;
         count++;
       }
       stringstream is(read[count-2]);
       int CountName;
       is>> CountName;
//       cout<<count<<" "<<CountName<<endl;
       for(int i=count-2-CountName; i<count-2 ; i++)
       {
       	Name = Name+" "+read[i];
	   }
        HanhKhach data;
        strcpy(data.CCCD, read[0].c_str());
	    strcpy(data.HO, read[1].c_str());
	    strcpy(data.TEN, Name.c_str());
	    strcpy(data.GioiTinh, read[count-1].c_str());
	    InsertNodehk(root,data);
	    delete [] read;
	   } 
	in.close();
  }
}

nodehk SearchHk(nodehk &root,char tempcmnd[])
{
  if(root == NULL )
  {
    return root;
  }
  else if(strcmp(tempcmnd,root->data.CCCD) >0 )
  {
    return SearchHk(root->right,tempcmnd);
  }
  else if(strcmp(tempcmnd,root->data.CCCD) <0 )
  {
    return SearchHk(root->left, tempcmnd);
  }
  else 
  return root;
}

void OrderVe(DsVe &dsv ,int pos,nodehk Check,HanhKhach data)
{
  	  if (Check == NULL)
			{
				InsertNodehk(root,data);
				dsv.ve[dsv.n]->stt = pos;
				strcpy(dsv.ve[dsv.n]->CCCD,data.CCCD);
			}
			else if (Check != NULL)
           {
				dsv.ve[dsv.n]->stt=pos;
				strcpy(dsv.ve[dsv.n]->CCCD,Check->data.CCCD);
			} 
			dsv.n++;
			SortVe(dsv);
}
