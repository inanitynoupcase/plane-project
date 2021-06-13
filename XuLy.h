#include"CTDL.h"
#include<cmath>
#include<string.h>
#include<vector>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cstdio>

#pragma once
NodeMayBay dsmb;
ptrDSCB pheadDSCB=NULL;
NodeHk* hk=NULL;
ofstream MBO; 
ifstream MBI;
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
void FreeMemory(DsVe &DSV);
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
//DUYET CHUYEN BAY 
void TraverseDSCB(ptrDSCB pheadCB)
{	
	NodeChuyenBay*ptr = pheadCB;
	if(ptr == NULL)
	{
		cout<<"dsmb rong";
	}
	else
	{ 
		while(ptr != NULL)
    	{
		cout<<"cai gi do"; 
	    }
       ptr = ptr->next;
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
  	InitializeVe(TempDsVe, dsmb.data[result]->Room, 0);
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

	cout << data.DepartTime.day << " " << data.DepartTime.mon << " " << data.DepartTime.year << " " << data.DepartTime.hour << " " << data.DepartTime.min << endl;
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
	cout<<ptr->data.DepartTime.day<<" "<<ptr->data.DepartTime.mon<<" "<<ptr->data.DepartTime.year<<" "<<ptr->data.DepartTime.hour << " "<<ptr->data.DepartTime.min<<endl;
	cout<<ptr->data.ID;
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
void FreeMemory(DsVe &DVS)
{
	for(int i=DVS.n;i<DVS.max;i++)
  {
		delete DVS.SoGhe[i];
		DVS.SoGhe[i]=NULL;
	}
}
//XOA CHUYEN BAY 
void DelChuyenBay(ptrDSCB &pheadDSCB,ptrDSCB ptr, NodeMayBay &DSMB)
{
    ptr->data.Status=0;
	int result = SearchIdMb(DSMB,ptr->data.ID);
  	dsmb.data[result]->SoLuotBay--;
    FreeMemory(ptr->data.dsv);
}
