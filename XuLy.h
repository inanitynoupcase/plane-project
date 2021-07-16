#include"CTDL.h"
#include<cmath>
#include<string.h>
#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#pragma once
NodeMayBay dsmb;
ptrDSCB pheadDSCB=NULL;
nodehk root=NULL;

// ham xu ly may bay        
int SearchIdMb(NodeMayBay NodeMb,char TempId[]);
void AddMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom);
void EditMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom);
void DelMb(NodeMayBay &nodemb,char TempID[]);
bool IsHaveFlight(ptrDSCB &pheadCB, char MaMB[]);
void SortMayBay(NodeMayBay &dsmb);

// ham xu ly chuyen bay
ptrDSCB SearchNode(ptrDSCB &pheadCB,char TempMCB[]);
void InsertNodeCB(ptrDSCB &pheadCB, NodeChuyenBay *p);
void AddNewChuyenBay(ptrDSCB &pheadDSCB,char TempMCB[],int TempDay,int TempMonth,int TempYear,int TempHour, int TempMin,char TempNoiToi[],char tempIDMB[],int TempTT);
bool checkYear(int year);
bool check_decent_chuyen_bay(ptrDSCB &pheadDSCB,char temp_so_hieu[],Date temp);
void SortCB_Time(ptrDSCB &pheadDSCB);
void EditChuyenBay(ptrDSCB &pheadDSCB,ptrDSCB &editnode,char TempMCB[],int TempDay,int TempMon,int TempYear,int TempHour, int TempMin);
bool check_decent_chuyen_bay_version_2(ptrDSCB &pheadDSCB,ptrDSCB &EditNode,char TempIDMB[],Date Temp);
void DelChuyenBay(ptrDSCB &pheadDSCB,ptrDSCB ptr, NodeMayBay &DSMB);
void UpdateCB(ptrDSCB &pheadDSCB);
int CountTotalChuyenBay(ptrDSCB &pheadDSCB);
int CountTotalChuyenBayTheoSearch(ptrDSCB &pheadDSCB,int TempNgay,int TempThang,int TempNam,char TempToi[]);

//HAM XU LY HANH KHACH
void InsertNodehk(nodehk &root,HanhKhach datahk);
NodeHanhKhach* deleteNodeHK(nodehk  &root, char CCCDtemp[]);
void LNR(nodehk &root, HanhKhach *data,int &number);
void NLR(nodehk &root, HanhKhach *data,int &number);
nodehk SearchHk(nodehk &root,char tempcmnd[]);

//HAM XU LY VE
void CreateVe(DsVe &dsv, int quantity); // khoi tao ve cho chuyen bay
bool IsOnPlane(ptrDSCB phead, char CCCDtemp[]);
bool Late30Min(Date dt1,Date dt2);
void FREEVE(DsVe &dsv);
void SortVe(DsVe &dsv);
bool IsEmpty(DsVe &dsv,int pos);
void RemoveVe(DsVe &dsv,int i);
void OrderVe(DsVe &dsv ,int pos,nodehk Check,HanhKhach data);

//HAM INPUT & OUTPUT
void FileInMB(NodeMayBay &nodemb);
void FileOutMB(NodeMayBay nodemb,int n);
void FileOutMBV2(NodeMayBay dsmb);
bool FileGoodMB();

void FileInCB(ptrDSCB &pheadDSCB);
void FileOutCB(ptrDSCB phead);
bool FileGoodCB();

void FileINHK();
void NLR_FileOutHK(HanhKhach *data, int countHK);
bool FileGoodHK();
void OrderVe_V2(DsVe &dsv ,int pos,char TempCCCD[]);

void FileInVe();
void FileOutVe(ptrDSCB phead);
bool FileGoodVe();
//HAM DELETE
void DeleteTree(nodehk &root);
void DeleteDSMB(NodeMayBay &dsmb);
void DeleteDSCB(ptrDSCB &pheadCB);

//HAM CHUYEN DOI INT <-> CHAR
int CharToInt(char ch[]);
void IntToChar(int num,char ch[]);


//================================================================================================================================================//
//=====================================================================HAM-XU-LY-HANH-KHACH=======================================================//
//THEM HANH KHACH
//int CountTotalHK =0;
int count(nodehk &root)
{
	int c=1;
	if (root ==NULL)
        return 0;
    else
    {
        c += count(root->left);
        c += count(root->right);
        return c;
    }
}

void InsertNodehk(nodehk &root, HanhKhach datahk)
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
 //   CountTotalHK++;
    
   // find->TotalHK++;
   // cout<<"this is root   "<<find->data.CCCD<<" "<<find->TotalHK<<endl;
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

//XOA HANH KHACH
NodeHanhKhach* deleteNodeHK(nodehk  &root, char CCCDtemp[])
{
    if (root == NULL)
        return root;
      
    if (strcmp(CCCDtemp,root->data.CCCD) <0 )
     {
        root->left = deleteNodeHK(root->left, CCCDtemp);
       return root;
    }
    else if (strcmp(CCCDtemp,root->data.CCCD) >0)
     {
        root->right = deleteNodeHK(root->right, CCCDtemp);
       return root;
    }
 
    if (root->left == NULL)
     {
        NodeHanhKhach* temp = root->right;
        delete root;
       return temp;
    }
    else if (root->right == NULL)
     {
        NodeHanhKhach* temp = root->left;
        delete root;
        return temp;
    }
    else 
	{

        NodeHanhKhach* succParent = root;
        NodeHanhKhach* succ = root->right;
        while (succ->left != NULL) 
        {
            succParent = succ;
            succ = succ->left;
        }

        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;

        strcpy(root->data.CCCD,succ->data.CCCD);
        delete succ;
        return root;
    }
}


void LNR(nodehk &root, HanhKhach *data,int &number)
{
  	if(root != NULL)
  	{
    LNR(root->left,data,number);
  	strcpy(data[number].CCCD,root->data.CCCD);
    strcpy(data[number].HO,root->data.HO);
    strcpy(data[number].TEN,root->data.TEN);
    strcpy(data[number].GioiTinh,root->data.GioiTinh);
    number++;
    LNR(root->right,data,number);
   }
} 

void NLR(nodehk &root, HanhKhach *data,int &number)
{
  	if(root != NULL)
  	{
  	strcpy(data[number].CCCD,root->data.CCCD);
    strcpy(data[number].HO,root->data.HO);
    strcpy(data[number].TEN,root->data.TEN);
    strcpy(data[number].GioiTinh,root->data.GioiTinh);
    number++;
    NLR(root->left,data,number);
    NLR(root->right,data,number); 
	}
} 

// TIM KIEM HANH KHACH = CCCD
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
//================================================================================================================================================//

//=====================================================================HAM-XU-LY-VE===============================================================//
//CHECK HANH KHACH CO TREN MAYBAY
bool IsOnPlane(ptrDSCB phead, char CCCDtemp[])
{
  ptrDSCB ptr = phead;
  while(ptr != NULL)
  {
    for(int i=0; i< ptr->data.dsv.n ; i++)
     {
      if(strcmp(ptr->data.dsv.ve[i]->CCCD, CCCDtemp) == 0)
       return 1;
     }
   ptr= ptr->next;
  }
 return 0;
}
//CHECK VE DAT CACH NHAU 30P
bool Late30Min(Date dt1,Date dt2)
{
	if(dt1.day==dt2.day)
  	{//PHUT < 30, CUNG GIO, CUNG NGAY, THANG, NAM
		if(dt1.year==dt2.year && dt1.mon==dt2.mon &&dt1.hour==dt2.hour && abs(dt1.min-dt2.min)<=30)
    	{
			return true;
		}
	}
	else if(dt1.year==dt2.year && dt1.mon==dt2.mon && abs(dt1.day-dt2.day)==1)
  	{//~1 NGAY, DAU NGAY A, CUOI NGAY B, CUNG THANG, NAM
		if(dt1.day>dt2.day)
  		{
			if((dt1.hour*60+dt1.min)+(1440-(dt2.hour*60+dt2.min))<=30)
     		{
				return true;
			}
		}
		else if(dt1.day<dt2.day)
   		{
			if((dt2.hour*60+dt2.min)+(1440-(dt1.hour*60+dt1.min))<=30)
      		{
				return true;
		  	}
		}
	}
	else if(dt1.year==dt2.year && abs(dt1.mon-dt2.mon)==1 )
 	{//CUOI THANG A, DAU THANG B 
		if(dt1.day== day[dt1.mon] && dt2.day==1 || dt2.day==day[dt2.mon] && dt1.day==1)
   		{
			if(dt1.mon>dt2.mon)
            {
				if((dt1.hour*60+dt1.min)+(1440-(dt2.hour*60+dt2.min))<=30)
       			{
				return true;
				}
			}
			else
     		{
				if((dt2.hour*60+dt2.min)+(1440-(dt1.hour*60+dt1.min))<=30)
       			{
					return true;
		   		}
		 	}
  		}
	}
	else if(abs(dt1.year-dt2.year)==1 )
  	{//CUOI NAM A, DAU NAM B
		if(dt1.day==31 && dt1.mon==12 && dt2.day==1 && dt2.mon==1)
 	   	{
			if((dt2.hour*60+dt2.min)+(1440-(dt1.hour*60+dt1.min))<=30)
     		{
				return true;
	 	  	}
  		}
		else if(dt1.day==1 && dt1.mon==1 && dt2.day==31 && dt2.mon==12)
   		{
			if((dt1.hour*60+dt1.min)+(1440-(dt2.hour*60+dt2.min))<=30)
     	 	{
				return false;
			}
		}
	}
	return false;
}

//Xoa het ds ve
void FREEVE(DsVe &dsv)
{
	for(int i=0; i< dsv.n;i++)
	{
		delete dsv.ve[i];
		dsv.ve[i]=NULL;
	}
	dsv.n =0;
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
				//kt temp Temp=dsv.ve[j];
				TempIndex=j;
			}
		}
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


// xoa ve
void RemoveVe(DsVe &dsv,int i)
{
	delete dsv.ve[i];
   	for(int j=i;j<dsv.n-1;j++)
	{
		
	  *dsv.ve[j]=*dsv.ve[j+1];
	}
   dsv.n--;
}

// DAT VE 
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
//================================================================================================================================================//

//=====================================================================HAM-XU-LY-MAY-BAY==========================================================//
int SearchIdMb(NodeMayBay NodeMb,char TempId[])
{
    for(int i=0; i< NodeMb.total ; i++)
     {
        if(strcmp(NodeMb.data[i]->ID , TempId)==0){
        	return i;
		}
	 }   
	return -1;
}
void AddMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom){
   MayBay* mb= new MayBay;
   strcpy(mb->ID, TempID);
   strcpy(mb->Type, TempType);
   mb->Room = TempRoom;
   nodemb.data[nodemb.total] = mb;
   nodemb.total++;
}
void EditMb(NodeMayBay &nodemb,char TempID[],char TempType[],int TempRoom){
   	int result = SearchIdMb(nodemb,TempID); // Tim Kiem may bay can sua ;
    dsmb.data[result]->Room = TempRoom;
    strcpy(dsmb.data[result]->Type,TempType);
}
void DelMb(NodeMayBay &nodemb,char TempID[])
{
  	int result = SearchIdMb(nodemb,TempID); // Tim Kiem may bay con xoa
	delete nodemb.data[result];
    for(int j=result ;j <nodemb.total-1 ;j++)
	{
	  	*nodemb.data[j]=*nodemb.data[j+1];
	}
	nodemb.total--;
}
// CHECK MAYBAY CO CHUYEN BAY CHUA
bool IsHaveFlight(ptrDSCB &pheadCB, char MaMB[])
{
  	NodeChuyenBay *ptr = pheadDSCB;

	while(ptr != NULL) 
	{
//		cout << ptr->data.ID << " " << MaMB << " " << strcmp(ptr->data.ID,MaMB) << endl;
	 	if(strcmp(ptr->data.ID,MaMB)==0)  return true;
	 	ptr=ptr->next;
    }
    return false;
}

//SORT THEO SO LUOT BAY
void SortMayBay(NodeMayBay &dsmb)
{
 for(int i=0; i< dsmb.total-1 ; i++)
  {
    int Index =i;
    for(int j=i+1; j< dsmb.total ; j++)
     {
       	if(dsmb.data[Index]->SoLuotBay < dsmb.data[j]->SoLuotBay)
		  	{
			   Index=j;
			  }	
     }
   MayBay *Temp = dsmb.data[i];
   dsmb.data[i] = dsmb.data[Index];
   dsmb.data[Index] = Temp; 
  }
}

//================================================================================================================================================//
//=====================================================================HAM-XU-LY-CHUYEN-BAY=======================================================//
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

//khoi tao mang 2 chieu con tro thanh 1 chieu

void CreateVe(DsVe &dsv, int quantity)
{
	dsv.ve=new Ve*[quantity];
	for(int i=0;i<quantity;i++)
	{
		dsv.ve[i] = new Ve[1];
	}
	dsv.max = quantity;
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
   	
	
	InsertNodeCB(pheadDSCB,p);
}

//CHECK NAM NHUAN
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
//check khoang cach 2 tieng GIUA 2 CHUYEN BAY
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
	    	{//XET CUNG NGAY, CUNG THANG, CUNG NAM
				
				if(ptr->data.DepartTime.hour!=temp.hour)
	     		{
					int time=abs((ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)-(temp.hour*60+temp.min));
					if(time<120) //PHUT 
	        		{			
						return false;
					}
				}	
				else if(ptr->data.DepartTime.hour==temp.hour) return false;				
			}	
			else if(abs(ptr->data.DepartTime.day-temp.day)==1 && ptr->data.DepartTime.mon==temp.mon && ptr->data.DepartTime.year==temp.year)
	   		{//XET ~1 NGAY, CUNG THANG, CUNG NAM
				
				//THOI GIAN CAN XET TRUOC CHUYEN BAY CUNG MAY BAY
				if(ptr->data.DepartTime.day>temp.day)
	     		{
					int time=(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)+(1440-(temp.hour*60+temp.min));
				   	if(time<120) return false;
				}
				//THOI GIAN CAN XET SAU CHUYEN BAY CUNG MAY BAY
				else if(temp.day>ptr->data.DepartTime.day)
	    		{
					int time=(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))+(temp.hour*60+temp.min);
					if(time<120) return false;
				}
	    	}
		    else if(ptr->data.DepartTime.year==temp.year && abs(ptr->data.DepartTime.mon-temp.mon)==1 )
		    {//XET ~1 THANG, CUOI THANG A & DAU THANG B, CUNG NAM
		    	
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
		 	{//XET ~1 NAM, CUOI NAM A & DAU NAM B
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
// Sort Chuyen Bay THEO THOI GIAN
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
        else if((ptr1->data.Status == 3 || CheckDepartTime(ptr1->data.DepartTime))== false && CheckDepartTime(ptr2->data.DepartTime) == true )
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
 
    Date TempDepart;
    TempDepart.day = TempDay;
    TempDepart.mon = TempMon;
    TempDepart.year = TempYear;
    TempDepart.hour = TempHour;
    TempDepart.min = TempMin;

    editnode->data.DepartTime = TempDepart;
}
//check KHOANG CACH HOP LE KHI edit CHUYEN BAY
bool check_decent_chuyen_bay_version_2(ptrDSCB &pheadDSCB,ptrDSCB &EditNode,char TempIDMB[],Date Temp)
{
	
	NodeChuyenBay*ptr=pheadDSCB;
	while(ptr!=NULL)
	{
	if(strcmp(ptr->data.ID,TempIDMB)==0 && ptr->data.Status!=0 && ptr!=EditNode)
	{
		if(ptr->data.DepartTime.day==Temp.day && ptr->data.DepartTime.mon==Temp.mon && ptr->data.DepartTime.year==Temp.year )
		{//XET CUNG NGAY, CUNG THANG, CUNG NAM
			
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
			
		else if(abs(ptr->data.DepartTime.day-Temp.day)==1 && ptr->data.DepartTime.mon==Temp.mon && ptr->data.DepartTime.year==Temp.year){
		//XET ~1 NGAY, CUNG THANG, CUNG NAM
			//CHUYEN BAY CAN XET TRUOC CHUYEN BAY CUNG MAY BAY
			if(ptr->data.DepartTime.day>Temp.day){
				int time=(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min)+(1440-(Temp.hour*60+Temp.min));
			   if(time<120) return false;
			}
			
			//CHUYEN BAY CAN XET SAU CHUYEN BAY CUNG MAY BAY
			else if(Temp.day>ptr->data.DepartTime.day){
				int time=(1440-(ptr->data.DepartTime.hour*60+ptr->data.DepartTime.min))+(Temp.hour*60+Temp.min);
				if(time<120) return false;
			}
        }
    else if(ptr->data.DepartTime.year==Temp.year && abs(ptr->data.DepartTime.mon-Temp.mon)==1 )
	{//XET ~1 THANG, CUNG NAM, DAU THANG A & CUOI THANG B
    	
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
	//XET ~1 NAM, DAU NAM A & CUOI NAM B
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

//XOA CHUYEN BAY 
void DelChuyenBay(ptrDSCB &ptr, NodeMayBay &DSMB)
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
        FREEVE(ptr->data.dsv);
      }
        ptr=ptr->next;
   }
}
//DUYET CHUYEN BAY
int CountTotalChuyenBay(ptrDSCB &pheadDSCB){
	NodeChuyenBay* ptr= pheadDSCB;
//   	ptr = pheadDSCB;
 	int TOTALchuyenbay = 0;
 	while(ptr != NULL){
 		TOTALchuyenbay++;
        ptr=ptr->next;
	}
	cout << "Tong: " << TOTALchuyenbay << endl; 
	return TOTALchuyenbay;
}
//DUYET CHUYEN BAY THEO SEARCH
int CountTotalChuyenBayTheoSearch(ptrDSCB &pheadDSCB,int TempNgay,int TempThang,int TempNam,char TempToi[]){
	NodeChuyenBay* ptr= pheadDSCB;
 	int TOTALchuyenbaySEARCH = 0;
 	while(ptr != NULL){
 		if(ptr->data.DepartTime.day == TempNgay && ptr->data.DepartTime.mon == TempThang && ptr->data.DepartTime.year == TempNam && strcmp(ptr->data.SanBayDen,TempToi) == 0 )
		{
	 		TOTALchuyenbaySEARCH++;
		}
		ptr=ptr->next;
	}
	cout << "Tong Search: " << TOTALchuyenbaySEARCH << endl;
	return TOTALchuyenbaySEARCH;
}
//================================================================================================================================================//

//=====================================================================INPUT-OUTPUT-FILE==========================================================//
//MAY BAY
void FileInMB(NodeMayBay &nodemb)
{
	ifstream MBI;
  	MBI.open("DSMB.txt");
  	string TempRead;
  	int TempTotal=0;
	char tempID[16];
	char tempType[41];
 	while(getline(MBI,TempRead))
 {
 	string *array = new string[6];
 	int count =0;
	stringstream iss(TempRead);
	for( string a; iss >>a;)
	{
		array[count] = a;
		count++;
	}

  	int x[3]; 
  	int countN =0;
    for(int i=2 ; i< 4; i++)
	{
        
        stringstream go(array[i]);
        int number;
        go >> number;
        x[countN] = number;
       //  cout<< x[count]<<" ";
        countN++;
    }

     
      	MayBay* mb= new MayBay;
    	mb->Room = x[0];  
    	mb->SoLuotBay = x[1];
 
      	strcpy(mb->ID,array[0].c_str());
     	strcpy(mb->Type,array[1].c_str());
      	nodemb.data[TempTotal] = mb;

    TempTotal++;
    dsmb.total = TempTotal;
   delete [] array;
   
 }
	MBI.close();
}

void FileOutMB(NodeMayBay nodemb,int n)
{
	ofstream MBOut;
	MBOut.open("DSMB.txt",ios::app);
	MBOut<<nodemb.data[n]->ID<<" "<<nodemb.data[n]->Type<<" "<<nodemb.data[n]->Room<<" "<<nodemb.data[n]->SoLuotBay<<endl;
 	MBOut.close();
}

void FileOutMBV2(NodeMayBay dsmb)
{
	ofstream MBOut;
	MBOut.open("DSMB.txt",ios::trunc);
	if(dsmb.total >0 )
  {	
	for(int i=0; i<dsmb.total; i++)
	{		
    	MBOut<<dsmb.data[i]->ID<<" "<<dsmb.data[i]->Type<<" "<<dsmb.data[i]->Room<<" "<<dsmb.data[i]->SoLuotBay<<endl;
    }
 	MBOut.close();
  }
}

// kiem tra file may bayDSMB.t
bool FileGoodMB()
{
 ifstream in;
 in.open("DSMB.txt");
 if( in.fail() == 1 )
 {
    return 0;  
 }
 else 
 {
   string temp;
   int count=0;
   ifstream empty;
   empty.open("DSMB.txt");
   while(getline(empty,temp))
   {
    count++;
   }
//   cout<<"this is "<<count<<endl;
   empty.close();
   in.close();
   if(count == 0)
      return 0;
   else return 1;   
 }
}

//CHUYEN BAY
// FILE INPUT CHUYEN BAY 
void FileInCB(ptrDSCB &pheadDSCB)
{
	ifstream in;
	in.open("DSCB.txt");
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
		NoiDen.erase(NoiDen.begin());
		
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
     	delete [] read;
	}
	
	in.close();
}

void FileOutCB(ptrDSCB phead)
{
	ofstream out;
	out.open("DSCB.txt",ios::trunc);
	NodeChuyenBay* ptr= phead;
// new	ptr=phead;
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


bool FileGoodCB()
{
	ifstream in;
 in.open("DSCB.txt");
 if( in.fail() == 1 )
 {
    return 0;  
 }
 else 
 {
   string temp;
   int count=0;
   ifstream empty;
   empty.open("DSCB.txt");
   while(getline(empty,temp))
   {
    count++;
   }
   empty.close();
   in.close();
   if(count == 0)
      return 0;
   else return 1;   
 }
}
//HANH KHACH
void FileINHK()
{
  ifstream in;
  in.open("DSHK.dat",ios::binary);
  string temp;
   while(getline(in,temp))
   {
       stringstream iss(temp); 
       string *read = new string[10];
       string Name;
       int count=0;				   
       for(string a; iss >>a;)
       {
         read[count] = a;
         count++;
       }
       stringstream is(read[count-2]);
       int CountName;
       is>> CountName;

       for(int i=count-2-CountName; i<count-2 ; i++)
       {
       	Name = Name+" "+read[i];
	   }
	   Name.erase(Name.begin());
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

//void NLR_FileOutHK(ofstream &out,nodehk root)
//{
//	
//  out.open("DSHK.dat", ios::app |ios::binary );
//  if(root != NULL)
//  {
//  	   int count=0;
//  	   string name;
//  	   name = root->data.TEN;
//  	   stringstream is(name);
//  	   for(string a; is >>a;)
//  	   {
//  	      count++;	
//	   }
//       out<<root->data.CCCD<<" "<<root->data.HO <<" "<< root->data.TEN<<" "<<count<<" "<< root->data.GioiTinh<<endl;
//       out.close();
//       NLR_FileOutHK(out,root->left);
//       out.close();
//       NLR_FileOutHK(out,root->right);
//  }
//  out.close();
//}

// file out hk
void NLR_FileOutHK(HanhKhach *data, int countHK)
{
	ofstream out;
	out.open("DSHK.dat", ios::trunc |ios::binary );
	if(countHK > 0)
  {
	 	for(int i=0; i< countHK ;i++)
	{
	   int count=0;
  	   string name;
  	   name = data[i].TEN;
  	   stringstream is(name);
  	   for(string a; is >>a;)
  	   {
  	      count++;	
	   }
		out<<data[i].CCCD<<" "<<data[i].HO <<" "<< data[i].TEN<<" "<<count<<" "<< data[i].GioiTinh<<endl;
	}
  }
	out.close();
}

bool FileGoodHK()
{
	ifstream in;
 in.open("DSHK.dat");
 if( in.fail() == 1 )
 {
    return 0;  
 }
 else 
 {
   string temp;
   int count=0;
   ifstream empty;
   empty.open("DSHK.dat");
   while(getline(empty,temp))
   {
    count++;
   }
   empty.close();
   in.close();
   if(count == 0)
      return 0;
   else return 1;  
 }
}

//DANH SACH VE
// dung trong doc file --- order co vi tri 
void OrderVe_V2(DsVe &dsv ,int pos,char TempCCCD[])
{     
				dsv.ve[dsv.n]->stt=pos;
				strcpy(dsv.ve[dsv.n]->CCCD,TempCCCD);
				dsv.n ++;
} 
// doc file ve
void FileInVe()
{
	ifstream read;
    read.open("DSV.txt");
    string temp;
    string d;
    NodeChuyenBay *ptr;
    while(getline(read,temp))
    {
     string *a = new string[2];
     int count =0;
     stringstream iss(temp);
      for(string b; iss>> b;)
       {
         a[count]=b;
         count++;
       }
        if (count == 1 )
         {
           char MACB[16];
		   strcpy(MACB,a[0].c_str());
           ptr = SearchNode(pheadDSCB,MACB);
//           cout<< "this is data"<< ptr->data.MaCB<<"     "<<endl;
         }      
        else if(count == 2 )
        {
//        	cout<<"this is so ve"<< ptr->data.dsv.n<<endl;;
           int pos;
           stringstream is(a[0]);
           is>> pos;
//           cout<< "this is pos "<<pos<<endl;
           char CCCD[12];
           strcpy(CCCD,a[1].c_str());
//           cout<<"this is cccd "<<CCCD<<endl;
           OrderVe_V2(ptr->data.dsv,pos,CCCD);
        } 
		delete [] a; 
     }
     read.close();
}
void FileOutVe(ptrDSCB phead)
{
	ofstream out;
  out.open("DSV.txt",ios::trunc);
  NodeChuyenBay *ptr = phead;
 while (ptr != NULL)
 {
     if(ptr->data.Status != 0 || ptr->data.Status != 3)
     {
      if(ptr->data.dsv.n >0)	
      {
       out << ptr->data.MaCB <<endl;
       for(int i=0; i< ptr->data.dsv.n ; i++)
        {
          out<< ptr->data.dsv.ve[i]->stt <<" "<<ptr->data.dsv.ve[i]->CCCD<<endl;
        }
      }
     }
     ptr=ptr->next;
 }
 out.close();
}

bool FileGoodVe()
{
 ifstream in;
 in.open("DSV.txt");
 if( in.fail() == 1 )
 {
    return 0;  
 }
 else 
 {
   string temp;
   int count=0;
   ifstream empty;
   empty.open("DSV.txt");
   while(getline(empty,temp))
   {
    count++;
   }
   empty.close();
   in.close();
   if(count == 0)
      return 0;
   else return 1;
 }
}

//=============================================================================================================================================//

int CharToInt(char ch[]){ 
	int l=strlen(ch);
	int i=0;
	int res=0;
	while (i<l){
		res =res*10 + (int)(ch[i] - '0');
		i++;
	}
	return res;
}

void IntToChar(int num,char ch[]){
	itoa(num,ch,10);
}


//=============================================================================================================================================//



//=====================================================================HAM-DELETE==============================================================//
void DeleteTree(nodehk &root)
 {
    if (root == NULL) 
        return;
        DeleteTree(root->left);
        DeleteTree(root->right);
	delete root;
}
void DeleteDSMB(NodeMayBay &dsmb)
{
	for(int i=0; i<dsmb.total ;i++)
	{
		delete dsmb.data[i];
	}
}
void DeleteDSCB(ptrDSCB &pheadCB)
{
	ptrDSCB ptr=pheadCB;
	while(ptr!=NULL)
	{
		delete ptr;
		ptr=ptr->next;
	}
}
//=============================================================================================================================================//

