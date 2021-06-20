#include<iostream>
#include<conio.h>
#include"Date.h"
#pragma once
using namespace std;

struct MayBay
{
  char ID[16];
  char Type[41];
  int Room; // so cho cua may bay
  bool Active = true;
  int SoLuotBay = 0;
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
    Date DepartTime; // thoi gian
    char SanBayDen[21]; // noitoi
    char ID[16];	// id may bay
    int Status = 1 ; // trang thai 0: huy chuyen, 1: con ve,  2: het ve, 3: hoan tat
    DsVe dsv; 
};
struct NodeChuyenBay
{
  ChuyenBay data;
  NodeChuyenBay* next=NULL;
};

typedef NodeChuyenBay*ptrDSCB;



// CAY NHI PHAN TIM KIEM CAN BANG
struct HanhKhach
{
  char CCCD[12];
  char HOTEN[25];
  char GioiTinh[3]; 
  bool IsOnPlane =1;
};
struct NodeHanhKhach
{
  HanhKhach data;
  NodeHanhKhach* right=NULL;
  NodeHanhKhach* left=NULL;
};
typedef NodeHanhKhach* nodehk;



