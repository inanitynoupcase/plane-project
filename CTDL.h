#include<iostream>
#include<conio.h>
#pragma once
using namespace std;

struct MayBay
{
  char ID[16];
  char Type[41];
  int Room; // so cho cua may bay
  bool Active = true;
  int SoLuotBay;
  // cho so phu

};
struct NodeMayBay
{
   MayBay *data[300];
   int total=0; // so may bay
};


struct Ve
{
    char CMND[10];
    int stt; // so thu tu 
}; 
struct DsVe
{
  Ve** SoGhe;
  int n; // so ve da dat
  int max; // so ghe max
};

//khoi tao mang 2 chieu con tro va 
void InitializeVe(DsVe &dsve, int quantity,int booked)
{
	dsve.SoGhe=new Ve*[quantity];
	for(int i=0; i<quantity ;i++)
  {
		dsve.SoGhe[i] = new Ve[1];
	}
	dsve.max = quantity;
	dsve.n = booked;
}


struct ChuyenBay
{
	   char MaCB[16]; // ma chuyen bay
     char ID[16]; // so hieu may bay
     char SanBayDen[21]; 
//     Date DepartTime;
     int Status; // trang thai 0: huy chuyen, 1: con ve,  2: het ve, 3: hoan tat
     DsVe dsv; 
};
struct NodeChuyenBay
{
  ChuyenBay data;
  NodeChuyenBay* next;
};
typedef NodeChuyenBay*ptrDSCB;



// CAY NHI PHAN TIM KIEM CAN BANG
struct HanhKhach
{
  char CMND[10];
  char Ho[31];
  char Ten[11];
  bool Phai; // 0 la nu  1 la nam
};
struct NodeHk
{
  HanhKhach data;
  int bf=0; //chi so can bang cua nut
  NodeHk* right=NULL;
  NodeHk* left=NULL;
};


