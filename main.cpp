
#include "XuLy.h"
#include <iostream>
#include <winbgim.h>
#define maxX 1280
#define maxY 880
#include <sstream>

using namespace std;
const int ENTER = 13; 
const int BACKSPACE = 8; 
int MID[maxX][maxY];
//========================================================================//===================================================================//


void khoitaoID();
void taoID(int x1,int y1, int x2,int y2, int ID);
void ScanChu(char s[],int max, int px, int py, int ID, int &IDnext);
void ScanTen(char s[],int max, int px, int py, int ID, int &IDnext);
void ScanSo(char s[],int max, int px, int py, int ID, int &IDnext);
void taoO(int x1,int y1,int x2,int y2,int mau,int mauvien,int ID);
void taoDong(int x1,int y1,int chieucao,int mangdodai[], int slcot,int mau,int mauvien,int ID);
void taoBang(int x1,int y1,int chieucao,int mangdodai[],int slcot,int sldong,char td[][50],int mau,int mauvien, int ID);
void taoButton(int x1, int y1,int x2, int y2,int ID,int maunen, int mauchu,int cochu, char text[]);
void Menu();
void QuanLyMayBay_NhapMayBay();
void QuanLyMayBay_HienThiMayBay();
void QuanLyMayBay();
void QuanLyChuyenBay_NhapChuyenBay();
void QuanLyChuyenBay_HienThiChuyenBay();
void QuanLyChuyenBay();
void QuanLyHanhKhach_NhapHanhKhach();
void QuanLyHanhKhach_HienThiHanhKhach();
void QuanLyHanhKhach();
void TimChuyenBay_Nhap();
void TimChuyenBay_HienThi();
void TimChuyenBay();
void ThongKeChuyenBay_HienThiThongKe();
void ThongKeChuyenBay();
void run();

//========================================================================//===================================================================//

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

void khoitaoID(){
	for(int i = 0; i < maxX;i++){
		for(int j = 0; j < maxY;j++){
			MID[i][j]=0;
		}
	}
}

void taoID(int x1,int y1, int x2,int y2, int ID){
	for(int i = x1; i < x2;i++){
		for(int j = y1; j < y2;j++){
			MID[i][j] = ID;
		}
	}
}

void BaoLoi1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(4);
	outtextxy(x+5,y+5,"Khong Duoc De Trong!");
}

void HopLe1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(14);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"Hop Le!");
}

void TonTai1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(14);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"Da Ton Tai!");
}

void KhongTonTai1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(4);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"Khong Ton Tai");
}

void OUTTEXT(int x, int y, int maunen, int mauchu,int fontchu, int sizechu, char text[]){
	settextstyle(fontchu,0,sizechu);
	setbkcolor(maunen);	
	setcolor(mauchu);
	outtextxy(x,y,text);
}
void ScanTen(int x, int y, char s[], int lenMax,int mauNen){   
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';
    s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if (l<lenMax){
	     		if('a'<=c&&c<='z'||'A'<=c&&c<='Z'|| c==' ')	{
	     			if (l==0  && ('a'<=c&&c<='z'))		c=c+'A'-'a'; // thuong thanh hoa
	     			else if (l!=0 && s[l-1] == ' ' && ('a'<=c&&c<='z')) c=c+'A'-'a';
	     			else if (l!=0 && s[l-1] != ' ' && ('A'<=c&&c<='Z')) 	c=c-'A' + 'a'; // hoa thanh thuong
	     			else if (c==' ' && (l==0 || s[l-1] == ' ')) continue;				
			     	s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';
					s[l]=' ';
					s[l+1] = ' ';
					s[l+2] = ' ';
					outtextxy(x,y,s);	
					l--;
				}else if (c==13){
					s[l]='\0';
					break;
				}
				else continue;
			} 	
			 else if(c==8){
					s[l-1]=' ';
					s[l]=' ';
					s[l+1]= ' ';
					s[l+2] = ' ';
					outtextxy(x,y,s);
					l--;
 
			}else if (c==13){
				s[l]='\0';
				break;
			}else continue;	
		}
		else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
 
	}	 
}
//, int &Key
void ScanSo(int x, int y, char *s, int lenMax,int mauNen, int id){
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';
    s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if (l<lenMax){
	     		if(c >= '0' && c <= '9'){
				 	if (l==0 && c=='0') continue;
					else{
						s[l]=c;
						l++;
						s[l+1]='\0';
						outtextxy(x,y,s);
					}	
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]='|';
					s[l]=' ';
					l--;
					outtextxy(x,y,s);	
				}else if (c==13){
					s[l]='\0';
//					Key=-2;
					break;
				}	
			 } 	
			 else if(c==8){
					s[l-1]='|';
					s[l]=' ';
					l--;
					outtextxy(x,y,s);
 
				}else if (c==13){
					s[l]='\0';
//					Key=-2;
					break;
				}
		}
		else{
 
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
//		if (ismouseclick(WM_LBUTTONDOWN)){
//			 getmouseclick(WM_LBUTTONDOWN, x1, y1);
//			 if (Mapid[x1][y1] != id) {
//			 	s[l]='\0';
//			 	Key=Mapid[x1][y1];
//			 	break;
//			 }
//		}
	 }
}
void ScanMa(int x, int y, char s[], int lenMax,int mauNen ,int id){
	settextstyle(6,0,1);
	setcolor(0);
	setbkcolor(mauNen);
    int l=strlen(s);
    s[l+1]='\0';
    s[l]='|';
    int x1,y1;
     while(1){
		outtextxy(x,y,s);
     	if(kbhit()){
	     	char c= getch();
	     	if (l<lenMax){
	     		if(('0' <=c  && c <= '9') || ('a'<=c&&c<='z')||('A'<=c&&c<='Z')|| c=='_' ){	
	     			if ('a'<=c&&c<='z')	c=c+'A'-'a';
			     	s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';
					s[l]=' ';
					s[l+1] = ' ';
					s[l+2] = ' ';
					outtextxy(x,y,s);	
					l--;	
				}else if (c==13){
					s[l]='\0';
//					Key=-2;
					break;
				}	
			 } 	
			 else if(c==8){
					if (l==0) continue;
					s[l-1]=' ';
					s[l]=' ';
					s[l+1] = ' ';
					s[l+2] = ' ';
					outtextxy(x,y,s);	
					l--;
			}else if (c==13){
				s[l]='\0';
//				Key=-2;
				break;
			}
	}
		else{
			s[l]='|';
			delay(100);
			outtextxy(x,y,s);
			s[l]=' ';
			delay(100);
			outtextxy(x,y,s);
		}
//		if (ismouseclick(WM_LBUTTONDOWN)){
//			 getmouseclick(WM_LBUTTONDOWN, x1, y1);
//			 if (Mapid[x1][y1] != id) {
//			 	s[l]='\0';
//			 	Key=Mapid[x1][y1];
//			 	break;
//			 }
//		}
	 }
}

void taoO(int x1,int y1,int x2,int y2,int mau,int mauvien,int ID){
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);
	taoID(x1,y1,x2,y2,ID);
}

void taoOKID(int x1,int y1,int x2,int y2,int mau,int mauvien){
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);

}

void taoDong(int x1,int y1,int chieucao,int mangdodai[], int slcot,int mau,int mauvien,int ID){
	int x2, y2;	
	y2 = y1 + chieucao; 
	for(int i=0;i < slcot;i++){
		x2 = x1 + mangdodai[i];
		taoO(x1,y1,x2,y2,mau,mauvien,ID);
		x1 = x2;	
		
	}
}

void taoDongKID(int x1,int y1,int chieucao,int mangdodai[], int slcot,int mau,int mauvien){
	int x2, y2;	
	y2 = y1 + chieucao; 
	for(int i=0;i < slcot;i++){
		x2 = x1 + mangdodai[i];
		taoOKID(x1,y1,x2,y2,mau,mauvien);
		x1 = x2;	
		
	}
}

void taoBang(int x1,int y1,int chieucao,int mangdodai[],int slcot,int sldong,char td[][50],int mau,int mauvien, int ID){
	setcolor(0);
	setbkcolor(mau);
	settextstyle(3,0,2);
	int y = y1;
	for(int i=1;i<=sldong;i++){
	 	taoDong(x1,y1,chieucao,mangdodai,slcot,mau,mauvien,ID + i);
		 y1 = y1 + chieucao;
	}
	for(int i=0;i<slcot;i++){
		outtextxy(x1+12,y+15,td[i]);
		x1 = x1 + mangdodai[i];
	}
}

void taoBangKID(int x1,int y1,int chieucao,int mangdodai[],int slcot,int sldong,char td[][50],int mau,int mauvien){
	setcolor(0);
	setbkcolor(mau);
	settextstyle(3,0,2);
	int y = y1;
	for(int i=1;i<=sldong;i++){
	 	taoDongKID(x1,y1,chieucao,mangdodai,slcot,mau,mauvien);
		 y1 = y1 + chieucao;
	}
	for(int i=0;i<slcot;i++){
		outtextxy(x1+12,y+15,td[i]);
		x1 = x1 + mangdodai[i];
	}
}


void taoButton(int x1, int y1,int x2, int y2,int ID,int maunen, int mauchu,int cochu, char text[]){
	setfillstyle(1,maunen);
	bar(x1,y1,x2,y2);
	setbkcolor(maunen);
	setcolor(mauchu);
	settextstyle(3,0,cochu);
	outtextxy(x1 + 10,y1 + 10, text);
	taoID(x1,y1,x2,y2,ID);
}

void MessageBox(char temp[],int mauchu){
	settextstyle(3,0,1);
   	setbkcolor(3);	
	setcolor(0);
	taoO(965,640,1265,770,3,0,0);
   	outtextxy(1060,625,"MessageBox");
   	outtextxy(970,650,"                                          ");
   	outtextxy(970,680,"                                          ");
	outtextxy(970,710,"                                          ");
	outtextxy(970,740,"                                          ");
	setcolor(mauchu);
	outtextxy(1030,680,temp);
} 
void Menu(){
	setfillstyle(1,3);						
	bar(0,0,maxX,maxY);
	setbkcolor(3);
	setcolor(0);

	for (int i = 1; i < 4;i++){
		line(310 + i,0,310 + i,1280);
	}

	taoButton(10,40,280,110,1,7,0,3,"Quan Ly May Bay");
	taoButton(10,160,280,230,2,7,0,3,"Quan Ly Chuyen Bay");
	taoButton(10,280,280,350,3,7,0,3,"Quan Ly Hanh Khach");
	taoButton(10,400,280,470,4,7,0,3,"Tim Chuyen Bay");
	taoButton(10,520,280,590,5,7,0,3,"Dat Ve");
	taoButton(10,640,280,710,6,7,0,3,"Danh Sach Hanh Khach");
	taoButton(10,760,280,830,7,7,0,3,"Thong Ke Chuyen Bay");

}

void QuanLyMayBay_NhapMayBay(){
	setbkcolor(3);	
	setcolor(0);
	settextstyle(3,0,2);
	taoO(335,640,945,830,3,0,0);

	outtextxy(345,655,"ID");
	taoO(450,650,925,680,7,0,11);

	outtextxy(345,722,"LOAI");
	taoO(450,717,925,747,7,0,0);

	outtextxy(345,792,"SO CHO");
	taoO(450,787,925,817,7,0,0);
	
	taoO(965,640,1265,770,3,0,0);
   	settextstyle(3,0,1);
   	outtextxy(1060,625,"MessageBox");
	

	
	taoButton(965,780,1040,830,0,7,8,3,"NEW");

	taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
	taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
}

void QuanLyMayBay_HienThiMayBay(){
	settextstyle(3,0,3);
	taoButton(10,40,280,110,1,8,15,3,"Quan Ly May Bay");
	char text[][50]={"ID","Loai","So Cho"};
	int m[3] = {300,310,300};
   	taoBang(335,10,55,m,3,10,text,15,0,101);
   	
	taoButton(405,575,455,625,10001,7,0,2,"<");
   	taoButton(1130,575,1180,625,10002,7,0,2," >");
//	int xx = 335; int yy = 65;
//	for(int i=0;i<9 &&;i++){
//		if(dsmb.data[i]->Active == true){
//		OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
//		OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
//		char CharRoom[50];
//		IntToChar(dsmb.data[i]->Room,CharRoom);
//		OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
//		yy+=55;
//		}
//	}
}

void QuanLyMayBay(){
	QuanLyMayBay_HienThiMayBay();
	QuanLyMayBay_NhapMayBay();
}

void QuanLyChuyenBay_NhapChuyenBay(){
	setbkcolor(3);	
	setcolor(0);
	settextstyle(3,0,1);
	taoO(335,640,945,830,3,0,0);
	
	outtextxy(345,655,"IDCB");
	taoO(458,650,925,680,7,0,21);
	
	outtextxy(345,702,"NGAY");
	taoO(405,697,455,727,7,0,0);
	outtextxy(460,702,"THANG");
	taoO(530,697,580,727,7,0,0);
	outtextxy(585,702,"NAM");
	taoO(630,697,710,727,7,0,0);
	outtextxy(715,702,"GIO");
	taoO(750,697,800,727,7,0,0);
	outtextxy(805,702,"PHUT");
	taoO(860,697,910,727,7,0,0);
	
	
	outtextxy(345,747,"TOI");
	taoO(458,742 ,925,772,7,0,0);
	
	outtextxy(345,792,"IDMAYBAY");
	taoO(458,787,925,817,7,0,0);
	
	taoO(965,640,1265,770,3,0,0);

   	outtextxy(1060,625,"MessageBox");

	taoButton(965,780,1040,830,0,7,8,3,"NEW");

	taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
	taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
	
}

void QuanLyChuyenBay_HienThiChuyenBay(){
	taoButton(10,160,280,230,2,8,15,3,"Quan Ly Chuyen Bay");
	char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
	int m[5] = {100,250,150,200,200};
   	taoBang(335,10,55,m,5,10,text,15,0,201);
  	taoButton(405,575,455,625,20001,7,0,2,"<");
   	taoButton(1130,575,1180,625,20002,7,0,2," >");
   	int xx = 335; int yy = 65;
   	NodeChuyenBay* ptr = new NodeChuyenBay;
	ptr = pheadDSCB;

	while(ptr != NULL){
    	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
    	
//    	char day[50]= "";
//    	char mon[50]= "";
//    	char year[50]= "";
//    	char hour[50]= "";
//    	char min[50]= "";
//    	IntToChar(ptr->data.DepartTime.day,day);
//    	IntToChar(ptr->data.DepartTime.mon,mon);
//    	IntToChar(ptr->data.DepartTime.year,year);
//    	IntToChar(ptr->data.DepartTime.hour,hour);
//    	IntToChar(ptr->data.DepartTime.min,min);
//    	cout << ptr->data.DepartTime.day << " "<< ptr->data.DepartTime.mon << " "<< ptr->data.DepartTime.year << " "<< ptr->data.DepartTime.hour << " "<< ptr->data.DepartTime.min << endl;
//    	OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
//    	OUTTEXT(xx+12+m[0]+30,yy+15,15,0,3,3,mon);
//    	OUTTEXT(xx+12+m[0]+30,yy+15,15,0,3,3,year);
//    	OUTTEXT(xx+12+m[0]+30,yy+15,15,0,3,3,hour);
//    	OUTTEXT(xx+12+m[0]+30,yy+15,15,0,3,3,min);	
					
    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
    	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
//    	OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,ptr->data.Status);
    	ptr = ptr->next;  
   		yy +=55;
	}
}




void QuanLyChuyenBay(){
	QuanLyChuyenBay_HienThiChuyenBay();
   	QuanLyChuyenBay_NhapChuyenBay();
}

void QuanLyHanhKhach_NhapHanhKhach(){
	setbkcolor(3);	
	setcolor(0);
	taoO(335,640,945,830,3,0,0);
	
   	outtextxy(345,655,"CCCD");
   	taoO(450,650,925,680,7,0,31);
	
	outtextxy(345,722,"HO TEN");
	taoO(450,717,925,747,7,0,0);
	
	outtextxy(345,792,"GIOI TINH");
	taoO(450,787,925,817,7,0,0);
	


//	taoButton(945,570,985,620,3001,4,0,3,"X");
	
	taoButton(965,780,1040,830,3002,7,0,3,"NEW");

	taoButton(1050,780,1135,830,3003,7,0,3,"SAVE");
	
	taoButton(1145,780,1265,830,3004,7,0,3,"REMOVE");
	
}

void QuanLyHanhKhach_HienThiHanhKhach(){
	taoButton(10,280,280,350,3,8,15,3,"Quan Ly Hanh Khach");
	char text[][50]={"CCCD","TEN","HO"};
	int m[3] = {300,310,300};
   	taoBangKID(335,10,55,m,3,10,text,15,0);
    taoButton(405,575,455,625,30001,7,0,2,"<");
   	taoButton(1130,575,1180,625,30002,7,0,2," >");
}

	

void QuanLyHanhKhach(){
	QuanLyHanhKhach_HienThiHanhKhach();
	QuanLyHanhKhach_NhapHanhKhach();
}

void TimChuyenBay_Nhap(){
	setbkcolor(3);	
	setcolor(0);
	
   	taoO(335,40,1260,90,3,0,0);
	outtextxy(345,55,"ID");
	taoO(375,50,535,80,7,0,41);
	outtextxy(550,55,"NGAY");
	taoO(620,50,670,80,7,0,42);
	outtextxy(690,55,"THANG");
	taoO(780,50,840,80,7,0,43);
	outtextxy(855,55,"NAM");
	taoO(910,50,1000,80,7,0,44);
	outtextxy(1015,55,"TOI");
	taoO(1065,50,1230,80,7,0,45);

}

void TimChuyenBay_HienThi(){
	taoButton(10,400,280,470,4,8,15,3,"Tim Chuyen Bay");
	char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","Trang Thai"};
	int m[4] = {210,300,210,210};
   	taoBangKID(335,150,55,m,4,10,text,15,0);
    taoButton(395,760,445,810,40001,7,0,2,"<");
   	taoButton(1130,760,1180,810,40002,7,0,2," >");
}

void TimChuyenBay(){
   	TimChuyenBay_HienThi();
   	TimChuyenBay_Nhap();
}

void DatVe_Nhap(){
	taoButton(10,520,280,590,5,8,15,3,"Dat Ve");

	setbkcolor(3);	
	setcolor(0);
	
   	taoO(335,40,1260,90,3,0,0);

	outtextxy(345,50,"ID");
	taoO(375,50,535,80,7,0,0);

	outtextxy(550,50,"Khoi Hanh");


	taoO(670,50,1000,80,7,0,0);

	outtextxy(1015,50,"Toi");
	taoO(1065,50,1230,80,7,0,0);
	
	
	taoO(335,110,1260,550,15,0,0);

	
//		int x1 = 345;
//		int y1 = 120;
//		int x2 = 395;
//		int y2 = 170;
//		for(int i = 0;i < 10; i++){
//		taoO(x1,y1,x2,y2,4,3,20000+i);
//		x1 = x1 + 80;
//		x2 = x2 + 80;
//	}

	taoO(335,640,945,830,3,0,0);

	outtextxy(345,655,"ID");
	taoO(458,650,925,680,7,0,51);

	outtextxy(345,702,"Ngay");
	taoO(458,697,925,727,7,0,0);

	outtextxy(345,747,"Toi");
	taoO(458,742 ,925,772,7,0,0);

	outtextxy(345,792,"IDMB");
	taoO(458,787,925,817,7,0,0);
	
//	taoButton(965,620,1245,670,200001,7,0,3,"Thong Tin Hanh Khach");
	

	
	taoButton(965,780,1065,830,5001,7,0,3,"Ban Ve");
	taoButton(1145,780,1245,830,5002,7,0,3,"Huy Ve");

	
}

void DatVe_HienThi(){
	taoO(335,110,1260,550,15,0,0);
	int x,y;
	x = 345; y = 125;
	for (int i = 1; i <= 8;i++){
		for(int j = 1; j <= 10; j++){
			taoO(x,y,x+86,y+49,4,0,0);
			x = x + 91;
		}
		x = 345;
		y = y + 51; 
	}
	taoButton(405,575,455,625,50001,7,0,2,"<");
   	taoButton(1130,575,1180,625,50002,7,0,2," >");
}

void DatVe(){
	DatVe_Nhap();
	DatVe_HienThi();
}
void DanhSachHanhKhach(){
	taoButton(10,640,280,710,6,8,15,3,"Danh Sach Hanh Khach");
	setbkcolor(3);	
	setcolor(0);
//	taoButton(315,0,365,50,25,4,0,3,"<");
	outtextxy(435,50,"Danh Sach Hanh Khach Thuoc Chuyen Bay");
	taoO(915,50,1135,80,7,0,601);
	outtextxy(435,110,"Ngay Khoi Hanh");
	taoO(615,110,800,140,7,0,602);
	outtextxy(815,110,"Noi Den");
	taoO(915,110,1135,140,7,0,603);
	char text[][50]={"STT","So Ve","CCCD","Ho Va Ten","Gioi Tinh"};
	int m[5] = {100,250,150,200,200};
   	taoBang(335,190,55,m,5,10,text,15,0,99999);
   	taoButton(395,760,445,810,60001,7,0,2,"<");
   	taoButton(1130,760,1180,810,60002,7,0,2," >");
}

void ThongKeChuyenBay_HienThiThongKe(){
	taoButton(10,760,280,830,5,8,15,3,"Thong Ke Chuyen Bay");
	char text[][50]={"ID May Bay","So Chuyen Bay Da Bay"};
	int m[2] = {450,450};
   	taoBangKID(335,10,55,m,2,13,text,15,0);
   	taoButton(395,760,445,810,70001,7,0,2,"<");
   	taoButton(1130,760,1180,810,70002,7,0,2," >");
}

void ThongKeChuyenBay(){
	ThongKeChuyenBay_HienThiThongKe();
}

//void hieuung(){
//	int x= -1; int ymouse = -1;
//	if(ismouseclick(WM_MOUSEMOVE)){
//		getmouseclick(WM_MOUSEMOVE,xmouse,ymouse);
//		if (MID[xmouse][ymouse]==1){
//    		taoButton(10,40,270,140,1,8,15,3,"Quan Ly May Bay");
//		}
//		else{
//		taoButton(10,40,270,140,1,7,0,3,"Quan Ly May Bay");}
//		}
//	else if(ismouseclick(WM_LBUTTONDOWN)){
//    	getmouseclick(WM_LBUTTONDOWN,xmouse,ymouse);}
//    	if (MID[xmouse][ymouse]==1){
//    		taoButton(10,40,270,140,1,8,15,3,"Quan Ly May Bay");
//    		break;
//		}
//	delay(1);
//}

void run(){
	int x = -1, y = -1;
	khoitaoID();
	Menu();
	taoO(428,80,1028,360,3,15,0);
	settextstyle(3,0,5);
	setbkcolor(3);
	outtextxy(550,100,"PLANE PROJECT");
	outtextxy(450,150,"N19DCCN017");
	outtextxy(500,200,"TRAN NGUYEN GIA BAO");
	outtextxy(450,250,"N19DCCN037");
	outtextxy(500,300,"PHAN CONG DANG");
	int tempSoCho = 0; 
	int trang = 1;
	int tongtrang = 0;
	char charTongTrang[50] = "";
	char charTrang[50] = "";
	char ID1[50] = ""; 
	char LOAI1[50] = "";
	char SOCHO1[50] = ""; 
	char ID2[50] = "";
	char NGAY2[50] = ""; 
	char THANG2[50] = ""; 
	char NAM2[50] = ""; 
	char GIO2[50] = ""; 
	char PHUT2[50] = ""; 
	char TOI2[50] = "";
	char IDMAYBAY2[50] = ""; 
	char CCCD3[50] = "";
	char HOTEN3[50] = ""; 
	char GIOITINH3[50] = "";
	char ID4[50] = ""; 
	char NGAY4[50] = "";
	char THANG4[50] = ""; 
	char NAM4[50] = "";
	char TOI4[50] = ""; 
	char ID5[50] = "";
	char NGAY5[50] = ""; 
	char TOI5[50] = "";
	char IDMB5[50] = ""; 
	char DANHSACH6[50] = "";
	char NGAYKHOIHANH6[50] = ""; 
	char NOIDEN6[50] = "";
	bool okID1 = false;
	bool okLOAI1 = false;
	bool okSOCHO1 = false; 
	bool okID2 = false;
	bool okNGAY2= false; 
	bool okTHANG2 = false; 
	bool okNAM2 = false; 
	bool okGIO2 = false; 
	bool okPHUT2 = false;
	bool okTOI2 = false;
	bool okIDMAYBAY2 = false; 
	bool okCCCD3 = false;
	bool okHOTEN3 = false; 
	bool okGIOITINH3= false;
	bool okID4= false; 
	bool okNGAY4 = false;
	bool okTHANG4 = false; 
	bool okNAM4= false;
	bool okTOI4= false; 
	bool okID5= false;
	bool okNGAY5 = false; 
	bool okTOI5= false;
	bool okIDMB5 = false; 
	bool okDANHSACH6 = false;
	bool okNGAYKHOIHANH6= false; 
	bool okNOIDEN6 = false;
	int sotam = 0;
	int TempNgay = 0;
	int TempThang = 0;
	int TempNam = 0;
	int TempGio = 0;
	int TempPhut = 0;
	FileInMB(MBI,dsmb);
	while (1){
		if(kbhit()){
			char c = getch();
		}
//        if(ismouseclick(WM_MOUSEMOVE)){
//        	int xmouse = -1; 
//        	int ymouse = -1;
//			getmouseclick(WM_MOUSEMOVE,xmouse,ymouse);
//			if (MID[xmouse][ymouse]==1){
//    			taoButton(10,40,270,140,1,8,15,3,"Quan Ly May Bay");
//    		}
//			else{
//				taoButton(10,40,270,140,1,7,0,3,"Quan Ly May Bay");}
//			if (MID[xmouse][ymouse]==2){
//				taoButton(10,190,270,290,2,8,15,3,"Quan Ly Chuyen Bay");
//			}
//			else{
//				taoButton(10,190,270,290,2,7,0,3,"Quan Ly Chuyen Bay");
//			}
//			if (MID[xmouse][ymouse]==3){
//				taoButton(10,340,270,440,3,8,15,3,"Quan Ly Hanh Khach");
//			}
//			else{
//				taoButton(10,340,270,440,3,7,0,3,"Quan Ly Hanh Khach");
//			}
//			if (MID[xmouse][ymouse]==4){
//				taoButton(10,490,270,590,4,8,15,3,"Tim Chuyen Bay");
//			}
//			else{
//				taoButton(10,490,270,590,4,7,0,3,"Tim Chuyen Bay");
//			}
//			if (MID[xmouse][ymouse]==5){
//				taoButton(10,640,270,740,5,8,15,3,"Thong Ke Chuyen Bay");
//			}
//			else{
//				taoButton(10,640,270,740,5,7,0,3,"Thong Ke Chuyen Bay");
//			}
//		}
				
//		if(ismouseclick(WM_MOUSEMOVE))
//		getmouseclick(WM_MOUSEMOVE,xmouse,ymouse);
//		if (MID[xmouse][ymouse]==2){
//    		taoButton(10,190,270,290,2,8,15,3,"Quan Ly Chuyen Bay");
//		}
//		else{
//			taoButton(10,190,270,290,2,7,0,3,"Quan Ly Chuyen Bay");
//		}
//		xmouse = -1; ymouse =-1; 
//	}
//	else if(ismouseclick(WM_LBUTTONDOWN)){
//    	getmouseclick(WM_LBUTTONDOWN,xmouse,ymouse);}
//    	if (MID[xmouse][ymouse]==1){
//    		taoButton(10,40,270,140,1,8,15,3,"Quan Ly May Bay");
//		}
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			cout << x <<"," << y <<"," <<MID[x][y];
//			if (MID[x][y]==1){
//    			taoButton(10,40,270,140,1,8,15,3,"Quan Ly May Bay");
//    		}
//			else{
//				taoButton(10,40,270,140,1,7,0,3,"Quan Ly May Bay");}
//			if (MID[x][y]==2){
//				taoButton(10,190,270,290,2,8,15,3,"Quan Ly Chuyen Bay");
//			}
//			else{
//				taoButton(10,190,270,290,2,7,0,3,"Quan Ly Chuyen Bay");
//			}
//			if (MID[x][y]==3){
//				taoButton(10,340,270,440,3,8,15,3,"Quan Ly Hanh Khach");
//			}
//			else{
//				taoButton(10,340,270,440,3,7,0,3,"Quan Ly Hanh Khach");
//			}
//			if (MID[x][y]==4){
//				taoButton(10,490,270,590,4,8,15,3,"Tim Chuyen Bay");
//			}
//			else{
//				taoButton(10,490,270,590,4,7,0,3,"Tim Chuyen Bay");
//			}
//			if (MID[x][y]==5){
//				taoButton(10,640,270,740,5,8,15,3,"Thong Ke Chuyen Bay");
//			}
//			else{
//				taoButton(10,640,270,740,5,7,0,3,"Thong Ke Chuyen Bay");
//			}
		}
        menu:
    	if(x!=-1 && y!=-1)
		switch(MID[x][y]){
			case 1:{ // man hinh Quan Ly May Bay
				Menu();
				QuanLyMayBay();
//				int m[3] = {300,310,300};
//				tongtrang = dsmb.total/9;
//			   	if (dsmb.total%9 != 0){
//			   		tongtrang +=1;
//					}
//			   	trang = 1;
//			   	int xx = 335; int yy = 65;
//			   	for(int i=0;i<9 && 9*(trang-1)+i < tongtrang;i++){
//			   	OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
//				OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
//				char CharRoom[50];
//				IntToChar(dsmb.data[i]->Room,CharRoom);
//				OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
//			  	yy+=55;
//			  	}
				trang = 1;
				tongtrang = dsmb.total/9;
				if (dsmb.total%9 != 0){
			   		tongtrang +=1;
				}
				IntToChar(tongtrang,charTongTrang);
				IntToChar(trang,charTrang);
//				OUTTEXT()
				int m[3] = {300,310,300};
				int xx = 335; int yy = 65;
				for(int i=0;i<9 && i < dsmb.total;i++){
				if(dsmb.data[i]->Active == true){
					OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
					char CharRoom[50];
					IntToChar(dsmb.data[i]->Room,CharRoom);
					OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
					yy+=55;
		}
	}
				x=-1,y=-1;
				break;
				}
			case 11:{ //ID MAY BAY
				 	taoO(450,650,925,680,15,0,11);
				 	taoO(450,717,925,747,15,0,12);
					taoO(450,787,925,817,15,0,0);
				 	
				 	taoButton(335+200,600,335+200+40,640,1001,4,0,3,"X");
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				 	ScanMa(450+5,650+5,ID1,10,15,11);
				 	if(strlen(ID1)==0){
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"ID: ");
				 		BaoLoi1(970 + 25,645);
				 		okID1=false; 
					 }
					 else if(SearchIdMb(dsmb,ID1)!=-1){
						sotam = SearchIdMb(dsmb,ID1);
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"ID: ");
				 		TonTai1(970 + 25,645);
						okID1=false;
						okLOAI1=true;
						okSOCHO1=true;
						strcpy(LOAI1,dsmb.data[sotam]->Type);
						char CharRoom[50];
						IntToChar(dsmb.data[sotam]->Room,CharRoom);
						strcpy(SOCHO1,CharRoom);
						taoO(450,650,925,680,15,0,0);
						OUTTEXT(450+5,650+5,15,4,6,1,ID1);
					 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
					 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
					 	taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
						taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
					}
				 	else {
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"ID: ");
				 		HopLe1(970 + 25,645);
				 		okID1=true;
					 	}
				 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
				 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
				 	x=-1;y=-1;
				 	break;
			}
			case 12:{ // Loai
					if(SearchIdMb(dsmb,ID1)!=-1){
						OUTTEXT(450+5,650+5,15,4,6,1,ID1);}
					else{
						OUTTEXT(450+5,650+5,15,0,6,1,ID1);
					}	
				 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
				 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
				 	taoButton(335+200,600,335+200+40,640,1001,4,0,3,"X");

				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					taoID(450,787,925,817,13);
					ScanMa(450+5,717+5,LOAI1,10,15,12) ;
				 	if(strlen(LOAI1)==0){
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,680,"LOAI: ");
				 		BaoLoi1(970 + 50,675);
				 		okLOAI1=false; 
				 		
					 }
				 	else {
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,680,"LOAI: ");
				 		HopLe1(970 + 50,675);
				 		okLOAI1=true; 
					 }
					x=-1;y=-1;
					break;
			}
			case 13:{ // So cho ngoi 
					if(SearchIdMb(dsmb,ID1)!=-1){
						OUTTEXT(450+5,650+5,15,4,6,1,ID1);}
					else{
						OUTTEXT(450+5,650+5,15,0,6,1,ID1);
					}
				
				 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
				 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
				 	ScanSo(450+5,787+5,SOCHO1,2,15,12);
				 	if(strlen(SOCHO1)==0){
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,710,"SOCHO: ");
				 		BaoLoi1(970 + 75,705);
				 		okSOCHO1=false; 
					}
				 	else {
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		tempSoCho = CharToInt(SOCHO1);
				 		outtextxy(970,710,"SOCHO: ");
				 		HopLe1(970 + 75,705);
				 		okSOCHO1=true; 
				 		
					 }
					taoButton(335+200,600,335+200+40,640,1001,4,0,3,"X");
					if(SearchIdMb(dsmb,ID1)!=-1){
						taoButton(965,780,1040,830,0,7,8,3,"NEW");
						
						taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
		
						taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
					}
					else{
						taoButton(965,780,1040,830,1002,7,0,3,"NEW");
					
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
					x=-1; y=-1;
					break;
					}
			case 1001:{ // Huy thong tin
					strcpy(ID1,"");
					strcpy(LOAI1,"");
					strcpy(SOCHO1,"");	
					okID1 = false;
					okLOAI1 = false;
					okSOCHO1 = false;
					taoO(450,650,925,680,15,0,11);
				 	taoO(450,717,925,747,15,0,12);
					taoO(450,787,925,817,15,0,0);
				 	OUTTEXT(450+5,650+5,15,0,6,1,ID1);
				 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
				 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
				 	taoO(965,640,1265,770,3,0,0);
				 	setbkcolor(3);
   					settextstyle(3,0,1);
   					outtextxy(1060,625,"MessageBox");
					x=-1;y=-1;
					break;
				}
			case 1002:{ // Them Vao

					taoButton(965,780,1040,830,1002,15,1,3,"NEW");
					delay(50);
					taoButton(965,780,1040,830,0,7,8,3,"NEW");
					if(okID1 == true && okLOAI1 == true && okSOCHO1 == true){
					
						AddMb(dsmb,ID1,LOAI1,tempSoCho);
//						Menu();
//						QuanLyMayBay();
						FileOutMB(MBO,dsmb,dsmb.total-1);	

						strcpy(ID1,"");
						strcpy(LOAI1,"");
						strcpy(SOCHO1,"");
						okID1 = false;
						okLOAI1 = false;
						okSOCHO1 = false; 
						
						taoO(450,650,925,680,7,0,11);
					 	taoO(450,717,925,747,7,0,0);
						taoO(450,787,925,817,7,0,0);
					 	OUTTEXT(450+5,650+5,15,0,6,1,ID1);
					 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
					 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
						
						int m[3] = {300,310,300};
						char text[][50]={"ID","Loai","So Cho"};
				  		taoBang(335,10,55,m,3,10,text,15,0,101);
						trang = 1;
						tongtrang = dsmb.total/9;
						if (dsmb.total%9 != 0){
					   		tongtrang +=1;
						}
						int xx = 335; int yy = 65;
						for(int i=0;i<9 && i < dsmb.total;i++){
							if(dsmb.data[i]->Active == true){
								OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
								char CharRoom[50];
								IntToChar(dsmb.data[i]->Room,CharRoom);
								OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
								yy+=55;
								}
							}
							MessageBox("Da Them Thanh Cong",14);
						delay(400);
						MessageBox("",0);
					
						}
							
					else{
						MessageBox("Khong The Them",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
			case 1003:{ // Chinh Sua
					
					taoButton(1050,780,1135,830,1003,15,1,3,"SAVE");
					delay(50);
					taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
					if(okID1 == false && okLOAI1 == true && okSOCHO1 == true){
						CMDREMOVE();
						EditMb(dsmb,ID1,LOAI1,tempSoCho);
						strcpy(ID1,"");
						strcpy(LOAI1,"");
						strcpy(SOCHO1,"");
						for(int i=0;i<dsmb.total;i++){
							FileOutMB(MBO,dsmb,i);	
						}
						taoO(450,650,925,680,7,0,11);
					 	taoO(450,717,925,747,7,0,0);
						taoO(450,787,925,817,7,0,0);
					 	OUTTEXT(450+5,650+5,15,0,6,1,ID1);
					 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
					 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
						
						int m[3] = {300,310,300};
						char text[][50]={"ID","Loai","So Cho"};
				  		taoBang(335,10,55,m,3,10,text,15,0,101);
						trang = 1;
						tongtrang = dsmb.total/9;
						if (dsmb.total%9 != 0){
					   		tongtrang +=1;
						}
						int xx = 335; int yy = 65;
						for(int i=0;i<9 && i < dsmb.total;i++){
							if(dsmb.data[i]->Active == true){
								OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
								char CharRoom[50];
								IntToChar(dsmb.data[i]->Room,CharRoom);
								OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
								yy+=55;
								}
				  			}
						MessageBox("Da Luu Thanh Cong",14);
						delay(400);
						MessageBox("",0);	
						}
					else{
						MessageBox("Khong The Luu",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
			case 1004:{ // Xoa
					taoButton(1145,780,1265,830,1004,15,1,3,"REMOVE");
					delay(50);
					taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
					if(okID1 == false && okLOAI1 == true && okSOCHO1 == true){
					 	DelMb(dsmb,ID1);
						strcpy(ID1,"");
						strcpy(LOAI1,"");
						strcpy(SOCHO1,"");
						Menu();
						QuanLyMayBay();
						for(int i=0;i<dsmb.total;i++){
							if(dsmb.data[i]->Active == true)
							FileOutMB(MBO,dsmb,i);	
						}
						taoO(450,650,925,680,7,0,11);
					 	taoO(450,717,925,747,7,0,0);
						taoO(450,787,925,817,7,0,0);
					 	OUTTEXT(450+5,650+5,15,0,6,1,ID1);
					 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
					 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
						trang = 1;
						int m[3] = {300,310,300};
						char text[][50]={"ID","Loai","So Cho"};
					  	taoBang(335,10,55,m,3,10,text,15,0,101);
						tongtrang = dsmb.total/9;
						if (dsmb.total%9 != 0){
					   		tongtrang +=1;
						}
						int xx = 335; int yy = 65;
							for(int i=0;i<9 && i < dsmb.total;i++){
								if(dsmb.data[i]->Active == true){
								OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
								char CharRoom[50];
								IntToChar(dsmb.data[i]->Room,CharRoom);
								OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
								yy+=55;
							}
						}
						MessageBox("Da Xoa Thanh Cong",14);
						delay(400);
						MessageBox("",0);
					}
					else{
						MessageBox("Khong The Xoa",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
			case 10001:{ // nut back
					taoButton(405,575,455,625,10001,15,1,2,"<");
				  	delay(50);
				  	taoButton(405,575,455,625,10001,7,0,2,"<");
				  	if (trang - 1 < 1) break;
				  	trang -=1;
				  	int m[3] = {300,310,300};
				  	char text[][50]={"ID","Loai","So Cho"};
				  	taoBang(335,10,55,m,3,10,text,15,0,101);
				  	tongtrang = dsmb.total/9;
   					if (dsmb.total%9 != 0) tongtrang +=1;
				   	int xx = 335; int yy = 65;
				   	for(int i=0;i<9 && 9*(trang-1)+i < dsmb.total;i++){
				   		if(dsmb.data[i]->Active == 1){
				   			
						   	OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[9*(trang-1)+i]->ID);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[9*(trang-1)+i]->Type);
							char CharRoom[50];
							IntToChar(dsmb.data[9*(trang-1)+i]->Room,CharRoom);
							OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
						  	yy+=55;
						}
				  	}		  	
				x=-1;y=-1;
				break;
			}
			case 10002:{ // nut next
				  	taoButton(1130,575,1180,625,10002,15,1,2," >");
				  	delay(50);
				  	taoButton(1130,575,1180,625,10002,7,0,2," >");
				  	if (trang + 1 > tongtrang) break;
				  	trang +=1;
				  	int m[3] = {300,310,300};
				  	char text[][50]={"ID","Loai","So Cho"};
				  	taoBang(335,10,55,m,3,10,text,15,0,101);
				  	tongtrang = dsmb.total/9;
   					if (dsmb.total%9 != 0) tongtrang +=1;
				   	int xx = 335; int yy = 65;
				   	for(int i=0;i<9 && 9*(trang-1)+i < dsmb.total;i++){
				   		if(dsmb.data[i]->Active == 1){
				   			
						   	OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[9*(trang-1)+i]->ID);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[9*(trang-1)+i]->Type);
							char CharRoom[50];
							IntToChar(dsmb.data[9*(trang-1)+i]->Room,CharRoom);
							OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
						  	yy+=55;
						}
				  	}
				x=-1;y=-1;
				break;
			}
			
			case 2:{ // MAN HINH CHUYEN BAY 
				
				Menu();
				QuanLyChuyenBay();
				x=-1,y=-1;
				break;
			}
			case 21:{ // ID CHUYEN BAY

				taoO(458,650,925,680,15,0,21);

				taoO(405,697,455,727,15,0,22);
	
				taoO(530,697,580,727,15,0,22);
	

				taoO(585 + 45,697,585 + 45 + 80,727,15,0,22);

				taoO(585 + 45 + 85 + 35,697,585 + 45 + 85 + 35 + 50,727,15,0,22);

				taoO(585 + 45 + 85 + 35 + 50 + 10 +50,697,585 + 45 + 85 + 35 + 50 + 10 +50 + 50,727,15,0,22);
				
				taoO(458,742,925,772,15,0,0);
				taoO(458,787,925,817,15,0,0);
				OUTTEXT(458+5,697+5,15,0,6,1,NGAY2);
				OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
				OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);
				
				taoButton(335+200,600,335+200+40,640,2001,4,0,3,"X");
				
				taoButton(965,780,1040,830,0,7,8,3,"NEW");

				taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
				taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				ScanMa(458+5,650+5,ID2,10,15,21);
				if(strlen(ID2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
			 		outtextxy(970,650,"IDCB: ");
					BaoLoi1(970 + 50,645);
					okID2=false; 
				}
				else if(SearchNode(pheadDSCB,ID2)!=NULL){ // SEARCH ID CHUYENBAY FUNCTION
					NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
					setbkcolor(3);
			 		setcolor(0);
			 		settextstyle(3,0,1);
			 		outtextxy(970,650,"IDCB: ");
				 	TonTai1(970 + 50,645);
					okID2=false;
//					strcpy(NGAY2,ptr->data.DepartTime);
//					char CharRoom[50];
//					IntToChar(dsmb.data[sotam]->Room,CharRoom);
//					strcpy(SOCHO1,CharRoom);
					strcpy(TOI2,ptr->data.SanBayDen);
					strcpy(IDMAYBAY2,ptr->data.ID);
					taoO(458,650,925,680,15,0,0);
					OUTTEXT(458+5,650+5,15,4,6,1,ID2);
					OUTTEXT(458+5,697+5,15,0,6,1,NGAY2);
					OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
					OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);
				 	taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
					taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
					}
					else {
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"IDCB: ");
				 		HopLe1(970 + 50,645);
				 		okID2=true;
					 	}
				x=-1;y=-1;
				break;
				}
			case 22:{ // NGAY
				if(SearchNode(pheadDSCB,ID2)!=NULL){ // SEARCH CHUYEN BAY 
						OUTTEXT(458+5,650+5,15,4,6,1,ID2);}
					else{
						OUTTEXT(458+5,650+5,15,0,6,1,ID2);
					}
				OUTTEXT(458+5,697+5,15,0,6,1,NGAY2);
				OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
				OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);
			
				taoButton(335+200,600,335+200+40,640,2001,4,0,3,"X");
				
				taoButton(965,780,1040,830,0,7,8,3,"NEW");

				taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
				taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				taoID(458,742,925,772,23);
				

							
				ScanSo(405+5,697+5,NGAY2,2,15,22);
				ScanSo(530+5,697+5,THANG2,2,15,22);
				ScanSo(585 + 45+5,697+5,NAM2,4,15,22);
				ScanSo(585 + 45 + 85 + 35+5,697+5,GIO2,2,15,22);
				ScanSo(585 + 45 + 85 + 35 + 50 + 10 +50+5,697+5,PHUT2,2,15,22);
				if(strlen(NGAY2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,680,"NGAY:");
				 	BaoLoi1(970 + 60,675);
				 	okNGAY2=false; 
					}
				else {
					TempNgay = CharToInt(NGAY2);
					TempThang = CharToInt(THANG2);
					TempNam = CharToInt(NAM2);
					TempGio = CharToInt(GIO2);
					TempPhut = CharToInt(PHUT2);
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
			 		outtextxy(970,680,"NGAY:");
			 		HopLe1(970 + 60,675);
			 		okNGAY2=true; 
					}
				x=-1;y=-1;
				break;
			}
			case 23:{ // NOI TOI 
				if(SearchNode(pheadDSCB,ID2)!=NULL){ // SEARCH CHUYEN BAY 
						OUTTEXT(458+5,650+5,15,4,6,1,ID2);}
					else{
						OUTTEXT(458+5,650+5,15,0,6,1,ID2);
					}
				OUTTEXT(458+5,650+5,15,0,6,1,ID2); // TEST OUTTEXT ID CHUYEN BAY
				OUTTEXT(458+5,697+5,15,0,6,1,NGAY2);
				OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
				OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);
				taoButton(335+200,600,335+200+40,640,2001,4,0,3,"X");
				ScanTen(458+5,742+5,TOI2,10,15);
				if(strlen(TOI2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
			 		outtextxy(970,710,"NOI TOI: ");
			 		BaoLoi1(970 + 80,705);
			 		okTOI2=false; 
					}
				 	else {
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
					outtextxy(970,710,"NOI TOI: ");
					HopLe1(970 + 80,705);
					okTOI2=true; 
					}
					taoID(458,787,925,817,24);
				x=-1;y=-1;
				break;
			}
			case 24:{ // ID MAY BAY 
				if(SearchNode(pheadDSCB,ID2)!=NULL){ // SEARCH CHUYEN BAY 
						OUTTEXT(458+5,650+5,15,4,6,1,ID2);}
					else{
						OUTTEXT(458+5,650+5,15,0,6,1,ID2);
					}
				OUTTEXT(458+5,650+5,15,0,6,1,ID2); // TEST OUTTEXT ID CHUYEN BAY
				OUTTEXT(458+5,697+5,15,0,6,1,NGAY2);
				OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
				OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);				
				
				
				
				taoButton(335+200,600,335+200+40,640,2001,4,0,3,"X");
				ScanMa(458+5,787+5,IDMAYBAY2,10,15,24);
				if(strlen(IDMAYBAY2)==0){
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,740,"ID: ");
					BaoLoi1(970 + 25,735);
					okIDMAYBAY2=false;	
				}
				else if(SearchIdMb(dsmb,IDMAYBAY2)!=-1){
					sotam = SearchIdMb(dsmb,IDMAYBAY2);
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,740,"ID: ");
					TonTai1(970 + 25,735);
					okIDMAYBAY2=true;
					}
				else{
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,740,"ID: ");
					KhongTonTai1(970 + 25,735);
					okIDMAYBAY2=false;
				}
					if(SearchNode(pheadDSCB,ID2)!=NULL){ //SEARCH ID CHUYEN BAY 
						taoButton(965,780,1040,830,0,7,8,3,"NEW");
						
						taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
		
						taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
					}
					else{
						taoButton(965,780,1040,830,2002,7,0,3,"NEW");
					
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				x=-1;y=-1;
				break;
			}
			case 2001:{ // HUY THONG TIN 
				strcpy(ID2,"");
				strcpy(NGAY2,"");
				strcpy(TOI2,"");
				strcpy(IDMAYBAY2,"");	
				okID2 = false;
				okNGAY2 = false;
				okTOI2 = false;
				okIDMAYBAY2 = false;
			taoO(458,650,925,680,15,0,21);
				taoO(458,697,925,727,15,0,22);
				taoO(458,742,925,772,15,0,0);
				taoO(458,787,925,817,15,0,0);
			 	OUTTEXT(458+5,650+5,15,0,6,1,ID2); 
				OUTTEXT(458+5,697+5,15,0,6,1,NGAY2);
				OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
				OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);	
				taoO(965,640,1265,770,3,0,0);
				setbkcolor(3);
   				settextstyle(3,0,1);
   				outtextxy(1060,625,"MessageBox");
				x=-1;y=-1;
				break;
			}
			case 2002:{ // ADD_CHUYENBAY
					taoButton(965,780,1040,830,2002,15,1,3,"NEW");
					delay(250);
			    	taoButton(965,780,1040,830,2002,7,0,3,"NEW");
			    	if(okID2 == true && okNGAY2 == true && okTOI2 == true && okIDMAYBAY2 == true){
			    		AddNewChuyenBay(pheadDSCB,ID2,TOI2,IDMAYBAY2,TempNgay,TempThang,TempNam,TempGio,TempPhut);
						Menu();
						QuanLyChuyenBay();
						
						MessageBox("Da Them Thanh Cong",14);
						delay(400);
						MessageBox("",0);
						strcpy(ID2,"");
						strcpy(NGAY2,"");
						strcpy(TOI2,"");
						strcpy(IDMAYBAY2,"");
						okID2 = false;
						okNGAY2 = false;
						okTOI2 = false;
						okIDMAYBAY2 = false;
					}
					else{
						MessageBox("Khong The Them",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
			case 2003:{ //EDIT_CHUYENBAY
					taoButton(1050,780,1135,830,2003,15,1,3,"SAVE");
					delay(250);
					taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					if(okID2 == false && okNGAY2 == true && okTOI2 == true && okIDMAYBAY2 == true){
//						EDIT_CHUYENBAY_FUNCTION
						Menu();
						QuanLyChuyenBay();
						
						MessageBox("Da Them Thanh Cong",14);
						delay(400);
						MessageBox("",0);
						strcpy(ID2,"");
						strcpy(NGAY2,"");
						strcpy(TOI2,"");
						strcpy(IDMAYBAY2,"");
						okID2 = false;
						okNGAY2 = false;
						okTOI2 = false;
						okIDMAYBAY2 = false;
					}
					else{
						MessageBox("Khong The Them",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
			case 2004:{ // XOA_CHUYENBAY
					taoButton(1145,780,1265,830,2004,15,1,3,"REMOVE");
					delay(250);
					taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
					if(okID2 == false && okNGAY2 == true && okTOI2 == true && okIDMAYBAY2 == true){
						//XOA_CHUYENBAY_FUNCTION
						Menu();
						QuanLyChuyenBay();
						MessageBox("Da Xoa Thanh Cong",14);
						delay(400);
						MessageBox("",0);
						strcpy(ID2,"");
						strcpy(NGAY2,"");
						strcpy(TOI2,"");
						strcpy(IDMAYBAY2,"");
						okID2 = false;
						okNGAY2 = false;
						okTOI2 = false;
						okIDMAYBAY2 = false;
					}
					else{
						MessageBox("Khong The Xoa",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
//			case 20001:{
//				  	taoButton(405,575,455,625,20001,15,1,2,"<");
//				  	delay(400);
//				  	taoButton(405,575,455,625,20001,7,0,2,"<");
//				  	x=-1;y=-1;
//				break;
//			}
//			case 20002:{
//				  	taoButton(1130,575,1180,625,20002,15,1,2," >");
//				  	delay(400);
//				  	taoButton(1130,575,1180,625,20002,7,0,2," >");
//				  	x=-1;y=-1;
//				break;
//			}		
			case 3:{
				Menu();
				QuanLyHanhKhach();
				x=-1,y=-1;
				break;
			}
			case 31:{
   				taoO(450,650,925,680,15,0,31);
				taoO(450,717,925,747,7,0,32);
//				taoO(450,787,925,817,7,0,33);
				ScanSo(450+5,650+5,CCCD3,10,15,31);
				
				x=-1;y=-1;
				break;
			}
			case 32:{
//   			taoO(450,650,925,680,7,0,31);
				taoO(450,717,925,747,15,0,32);
				taoO(450,787,925,817,7,0,33);
				ScanTen(450+5,717+5,HOTEN3,10,15);
				x=-1;y=-1;
				break;
			}
			case 33:{
//   			taoO(450,650,925,680,7,0,31);
//				taoO(450,717,925,747,7,0,32);
				taoO(450,787,925,817,15,0,33);
				
				x=-1;y=-1;
				break;
			}
			case 3002:{
					taoButton(965,780,1040,830,3002,15,1,3,"NEW");
					delay(250);
					taoButton(965,780,1040,830,3002,7,0,3,"NEW");
					Menu();
					QuanLyHanhKhach();
					x=-1;y=-1;
				break;
			}
			case 3003:{
					taoButton(1050,780,1135,830,3003,15,1,3,"SAVE");
					delay(250);
					taoButton(1050,780,1135,830,3003,7,0,3,"SAVE");
					Menu();
					QuanLyHanhKhach();
					x=-1;y=-1;
				break;
			}
			case 3004:{
					taoButton(1145,780,1265,830,3004,15,1,3,"REMOVE");
					delay(250);
					taoButton(1145,780,1265,830,3004,7,0,3,"REMOVE");
					Menu();
					QuanLyHanhKhach();
					x=-1;y=-1;
				break;
			}
			case 30001:{
				  	taoButton(405,575,455,625,30001,15,1,2,"<");
				  	delay(400);
				  	taoButton(405,575,455,625,30001,7,0,2,"<");
				  	x=-1;y=-1;
				break;
			}
			case 30002:{
				  	taoButton(1130,575,1180,625,30002,15,1,2," >");
				  	delay(400);
				  	taoButton(1130,575,1180,625,30002,7,0,2," >");
				  	x=-1;y=-1;
				break;
			}
			case 4:{
				Menu();
				TimChuyenBay();
				x=-1,y=-1;
				break;
			}
			case 41:{
				taoO(375,50,535,80,15,0,41);
//				taoO(620,50,670,80,7,0,42);
//				taoO(780,50,840,80,7,0,43);
//				taoO(910,50,1000,80,7,0,44);
//				taoO(1065,50,1230,80,7,0,45);
				ScanMa(375+5,50+5,ID4,10,15,41);
				x=-1;y=-1;
				break;
			}
			case 42:{
//				taoO(375,50,535,80,7,0,41);
				taoO(620,50,670,80,15,0,42);
//				taoO(780,50,840,80,7,0,43);
//				taoO(910,50,1000,80,7,0,44);
//				taoO(1065,50,1230,80,7,0,45);
				ScanSo(620+5,50+5,NGAY4,10,15,42);
				x=-1;y=-1;
				break;
			}
			case 43:{
//				taoO(375,50,535,80,7,0,41);
//				taoO(620,50,670,80,7,0,42);
				taoO(780,50,840,80,15,0,43);
//				taoO(910,50,1000,80,7,0,44);
//				taoO(1065,50,1230,80,7,0,45);
				ScanSo(780+5,50+5,THANG4,10,15,43);
				x=-1;y=-1;
				break;
			}
			case 44:{
//				taoO(375,50,535,80,7,0,41);
//				taoO(620,50,670,80,7,0,42);
//				taoO(780,50,840,80,7,0,43);
				taoO(910,50,1000,80,15,0,44);
//				taoO(1065,50,1230,80,7,0,45);
				ScanSo(910+5,50+5,NAM4,10,15,44);
				x=-1;y=-1;
				break;
			}
			case 45:{
//				taoO(375,50,535,80,7,0,41);
//				taoO(620,50,670,80,7,0,42);
//				taoO(780,50,840,80,7,0,43);
//				taoO(910,50,1000,80,7,0,44);
				taoO(1065,50,1230,80,15,0,45);
				ScanTen(1065+5,50+5,TOI4,10,15);
				x=-1;y=-1;
				break;
			}
			case 40001:{
				taoButton(395,760,445,810,40001,15,1,2,"<");
 			  	delay(400);
 			  	taoButton(395,760,445,810,40001,7,0,2,"<");
 			  	x=-1;y=-1;
				break;
			}
			case 40002:{
				taoButton(1130,760,1180,810,40002,15,1,2," >");
				delay(400);
				taoButton(1130,760,1180,810,40002,7,0,2," >");
				x=-1;y=-1;
				break;
			}
			case 5:{
				Menu();
				DatVe();
				x=-1,y=-1;
				break;
			}
			case 51:{
				taoO(458,650,925,680,15,0,51);
				taoO(458,697,925,727,7,0,52);
//				taoO(458,742 ,925,772,7,0,53);
//				taoO(458,787,925,817,7,0,54);
				ScanMa(458+5,650+5,ID5,10,15,51);
				taoO(375,50,535,80,15,0,0);
				outtextxy(375+5,50+5,ID5);
				x=-1;y=-1;
				break;
			}
			case 52:{
//				taoO(458,650,925,680,7,0,51);
				taoO(458,697,925,727,15,0,52);
				taoO(458,742 ,925,772,7,0,53);
//				taoO(458,787,925,817,7,0,54);
				ScanSo(458+5,697+5,NGAY5,10,15,52);
				taoO(670,50,1000,80,15,0,0);
				outtextxy(670+5,50+5,NGAY5);
				x=-1;y=-1;
				break;
			}
			case 53:{
//				taoO(458,650,925,680,7,0,51);
//				taoO(458,697,925,727,7,0,52);
				taoO(458,742 ,925,772,15,0,53);
				taoO(458,787,925,817,7,0,54);
				ScanTen(458+5,742+5,TOI5,10,15);
				taoO(1065,50,1230,80,15,0,0);
				outtextxy(1065+5,50+5,TOI5);
				x=-1;y=-1;
				break;
			}
			case 54:{
//				taoO(458,650,925,680,7,0,51);
//				taoO(458,697,925,727,7,0,52);
//				taoO(458,742 ,925,772,7,0,53);
				taoO(458,787,925,817,15,0,54);
				ScanMa(458+5,787+5,IDMB5,10,15,54);
				x=-1;y=-1;
				break;
			}
			case 5001:{
				taoButton(965,780,1065,830,5001,15,1,3,"Ban Ve");
				delay(250);
				taoButton(965,780,1065,830,5001,7,0,3,"Ban Ve");
				Menu();
				DatVe();
				x=-1,y=-1;
				break;
			}
			case 5002:{
				taoButton(1145,780,1245,830,5002,15,1,3,"Huy Ve");
				delay(250);
				taoButton(1145,780,1245,830,5002,7,0,3,"Huy Ve");
				Menu();
				DatVe();
				x=-1,y=-1;
				break;
			}
			case 50001:{
				  	taoButton(405,575,455,625,50001,15,1,2,"<");
				  	delay(400);
				  	taoButton(405,575,455,625,50001,7,0,2,"<");
				  	x=-1;y=-1;
				break;
			}
			case 50002:{
				  	taoButton(1130,575,1180,625,50002,15,1,2," >");
				  	delay(400);
				  	taoButton(1130,575,1180,625,50002,7,0,2," >");
				  	x=-1;y=-1;
				break;
			}
			case 6:{
				Menu();
				DanhSachHanhKhach();
				x=-1,y=-1;
				break;
			}
			case 601:{
				taoO(915,50,1135,80,15,0,601);
				ScanMa(915+5,50+5,DANHSACH6,10,15,601);
				taoO(615,110,800,140,15,0,602);
				taoO(915,110,1135,140,15,0,603);
				x=-1;y=-1;
				break;
			}
			case 60001:{
				taoButton(395,760,445,810,60001,15,1,2,"<");
 			  	delay(400);
 			  	taoButton(395,760,445,810,60001,7,0,2,"<");
 			  	x=-1;y=-1;
				break;
			}
			case 60002:{
				taoButton(1130,760,1180,810,60002,15,1,2," >");
				delay(400);
				taoButton(1130,760,1180,810,60002,7,0,2," >");
				x=-1;y=-1;
				break;
			}
			case 7:{
				Menu();
				ThongKeChuyenBay();
				x=-1,y=-1;
				break;
			}
			case 70001:{
				taoButton(395,760,445,810,70001,15,1,2,"<");
 			  	delay(400);
 			  	taoButton(395,760,445,810,70001,7,0,2,"<");
 			  	x=-1;y=-1;
				break;
			}
			case 70002:{
				taoButton(1130,760,1180,810,70002,15,1,2," >");
				delay(400);
				taoButton(1130,760,1180,810,70002,7,0,2," >");
				x=-1;y=-1;
				break;
			}
			default: break;
			
		}
	}
}


//========================================================================//===================================================================//


int main(int argc, char *argv[])
{
	initwindow(maxX, maxY);					
   	cleardevice();	
	run();
	while(!kbhit()) delay(1);
	system("pause");
    closegraph();
}


