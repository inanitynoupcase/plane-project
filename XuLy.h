#include"CTDL.h"
#include<cmath>
#include<string.h>
#pragma once
NodeMayBay dsmb;
ptrDSCB pheadDSCB=NULL;
NodeHk* hk=NULL;

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

//bool SearchIdMb(NodeMayBay NodeMb, char TempId[])
//{
//	NodeMb* current = head; // Initialize current
//    while (current != NULL)
//    {
//        if (strcmp(NodeMb.data[i]->ID , TempId)==1)
//            return true;
//        current = current->next;
//    }
//    return false;	
//}



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
    cout << " " << TempType << endl;
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
