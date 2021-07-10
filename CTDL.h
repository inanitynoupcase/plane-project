#include<iostream>
#include<conio.h>
#include"Date.h"
#pragma once
using namespace std;

struct MayBay
{
  char ID[15];
  char Type[40];
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
    char CCCD[12];
    int stt; // so thu tu 
}; 
struct DsVe
{
  Ve** ve;
  int n=0; // so ve da dat
  int max; // so ghe max
};

//khoi tao mang 2 chieu con tro nhung no la 1 chieu

void CreateVe(DsVe &dsv, int quantity)
{
	dsv.ve=new Ve*[quantity];
	for(int i=0;i<quantity;i++)
	{
		dsv.ve[i] = new Ve[1];
	}
	dsv.max = quantity;
}

struct ChuyenBay
{
	char MaCB[15]; // ma chuyen bay
    Date DepartTime; // thoi gian
    char SanBayDen[20]; // noitoi
    char ID[15];	// id may bay
    int Status = 1 ; // trang thai 0: huy chuyen, 1: con ve,  2: het ve, 3: hoan tat
    DsVe dsv; 
};
struct NodeChuyenBay
{
  ChuyenBay data;
  NodeChuyenBay* next=NULL;
};

typedef NodeChuyenBay*ptrDSCB;



// CAY NHI PHAN TIM KIEM
struct HanhKhach
{
  char CCCD[12];
  char HO[10];
  char TEN[15];
  char GioiTinh[4]; 
};
struct NodeHanhKhach
{
  HanhKhach data;
  NodeHanhKhach* right=NULL;
  NodeHanhKhach* left=NULL;
};
typedef NodeHanhKhach* nodehk;



