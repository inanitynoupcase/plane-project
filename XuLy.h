#include"CTDL.h"
#include<cmath>
#include<string.h>
#include<vector>
#include<iostream>
#include<sstream>

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



//search co ma may bay
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
void AddNewChuyenBay(ptrDSCB &pheadDSCB,char TempMCB[],char TempNoiToi[],char tempIDMB[],int TempDay,int TempMonth,int TempYear,int TempHour, int TempMin)
{
	ChuyenBay data;
   	strcpy(data.MaCB,TempMCB);
   	strcpy(data.SanBayDen,TempNoiToi);
   	strcpy(data.ID,tempIDMB);
  	NodeChuyenBay*p = new NodeChuyenBay;
	p->data = data;
   	p->next = NULL;
	data.DepartTime.hour = TempHour;
  	data.DepartTime.min = TempMin;
    data.DepartTime.day = TempDay;
    data.DepartTime.mon = TempMonth;
	data.DepartTime.year = TempYear;

	cout << data.DepartTime.day << " " << data.DepartTime.mon << " " << data.DepartTime.year << " " << data.DepartTime.hour << " " << data.DepartTime.min;
	InsertNodeCB(pheadDSCB,p);
}
