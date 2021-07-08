#include <iostream>
#include <winbgim.h>
#define maxX 1280
#define maxY 880
#pragma once
using namespace std;
const int ENTER = 13; 
const int BACKSPACE = 8; 
const int SPACE = 32;
int MID[maxX][maxY];
//========================================================================//===================================================================//
void ScanHo(int x, int y, char s[], int lenMax,int mauNen);
void ScanTen(int x, int y, char s[], int lenMax,int mauNen);
void ScanSo(int x, int y, char *s, int lenMax,int mauNen);
void ScanSoCCCD(int x, int y, char *s, int lenMax,int mauNen);
void ScanMa(int x, int y, char s[], int lenMax,int mauNen);

void khoitaoID();
void taoID(int x1,int y1, int x2,int y2, int ID);
void taoO(int x1,int y1,int x2,int y2,int mau,int mauvien,int ID);
void taoOkoID(int x1,int y1,int x2,int y2,int mau,int mauvien);
void taoDong(int x1,int y1,int chieucao,int mangdodai[], int slcot,int mau,int mauvien);
void taoBang(int x1,int y1,int chieucao,int mangdodai[],int slcot,int sldong,char td[][50],int mau,int mauvien);
void taoButton(int x1, int y1,int x2, int y2,int ID,int maunen, int mauchu,int cochu, char text[]);

void MessageBox(char temp[],int mauchu);
void BaoLoi1(int x,int y);
void HopLe1(int x,int y);
void KhongHopLe1(int x,int y);
void TonTai1(int x,int y);
void KhongTonTai1(int x,int y);
void BiHuy1(int x,int y);
void HoanTat1(int x,int y);
void GioiTinh1(int x,int y,int ss);
void Late30Min(int x,int y);
void CleanMessageBox(int x,int y);

void OUTTEXT(int x, int y, int maunen, int mauchu,int fontchu, int sizechu, char text[]);
void OUTTEXT1(int x, int y, int maunen, int mauchu,int fontchu, int sizechu);
void OUTTEXT2(int x, int y, int maunen, int mauchu,int fontchu, int sizechu);

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

void DatVe_Nhap();
void DatVe_HienThi();
void DatVe();

void DanhSachHanhKhach();
 
void ThongKeChuyenBay();


//========================================================================//==================================================================//

//=====================================================================BO-SCAN================================================================//
//KO SPACE, CHU DAU HOA, CHU SAU THUONG
void ScanHo(int x, int y, char s[], int lenMax,int mauNen){  
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
	     	if((int)c == 0){
	     		c = getch();
	     		continue;
			 }
	     	if (l<lenMax){
	     		if(('a'<=c&&c<='z')||('A'<=c&&c<='Z')|| c=='_' ){	
	     			if (l==0  && ('a'<=c&&c<='z'))		c=c+'A'-'a'; // thuong thanh hoa
	     			else if (l!=0 && s[l-1] == ' ' && ('a'<=c&&c<='z')) c=c+'A'-'a';
	     			else if (l!=0 && s[l-1] != ' ' && ('A'<=c&&c<='Z')) 	c=c-'A' + 'a'; // hoa thanh thuong
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
//CO SPACE, CHU DAU HOA, CHU SAU THUONG
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
	     	if((int)c == 0){
	     		c = getch();
	     		continue;
				}
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
				}
				else if (c==13){
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
		}
		else if (c==13){
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
	if (s[l-1] == ' ')
	{s[l-1] = '\0'; cout << "Da Xoa Space " << endl;}
	else s[l] = '\0';	
}
//KO SPACE, KO NHAN SO 0 DAU
void ScanSo(int x, int y, char *s, int lenMax,int mauNen){
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
	}
}
//KO SPACE, CO NHAN SO 0 DAU 
void ScanSoCCCD(int x, int y, char *s, int lenMax,int mauNen){
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
					s[l]=c;
					l++;
					s[l+1]='\0';
					outtextxy(x,y,s);	
				}
				else if(c==8){
					if (l==0) continue;
					s[l-1]='|';
					s[l]=' ';
					l--;
					outtextxy(x,y,s);	
				}else if (c==13){
					s[l]='\0';
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
	}
}
//KO SPACE,CO NHAN SO 0 DAU, CHI CHU HOA VA SO 
void ScanMa(int x, int y, char s[], int lenMax,int mauNen ){
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
	     	if((int)c == 0){
	     		c = getch();
	     		continue;
			 }
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
	}
}
//============================================================================================================================================//

//=====================================================================HAM-VE-VA-SET-ID=======================================================//
//SET LAI ID

void taoID(int x1,int y1, int x2,int y2, int ID){
	for(int i = x1; i < x2;i++){
		for(int j = y1; j < y2;j++){
			MID[i][j] = ID;
		}
	}
}

void taoO(int x1,int y1,int x2,int y2,int mau,int mauvien,int ID){
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);
	taoID(x1,y1,x2,y2,ID);
}

void taoOkoID(int x1,int y1,int x2,int y2,int mau,int mauvien){
	setfillstyle(1,mau);
	bar(x1,y1,x2,y2);
	setcolor(mauvien);
	rectangle(x1,y1,x2,y2);

}

void taoDong(int x1,int y1,int chieucao,int mangdodai[], int slcot,int mau,int mauvien){
	int x2, y2;	
	y2 = y1 + chieucao; 
	for(int i=0;i < slcot;i++)
	{
		x2 = x1 + mangdodai[i];
		taoOkoID(x1,y1,x2,y2,mau,mauvien);
		x1 = x2;	
		
	}
}

void taoBang(int x1,int y1,int chieucao,int mangdodai[],int slcot,int sldong,char td[][50],int mau,int mauvien){
	setcolor(0);
	setbkcolor(mau);
	settextstyle(3,0,2);
	int y = y1;
	for(int i=1;i<=sldong;i++){
	 	taoDong(x1,y1,chieucao,mangdodai,slcot,mau,mauvien);
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
//============================================================================================================================================//

//=====================================================================MESSAGE-BOX============================================================//
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

void KhongHopLe1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(4);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"Khong Hop Le!");
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
//THONG BAO DAT VE
void BiHuy1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(4);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"CB Da Bi Huy!");
}

void HoanTat1(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(4);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"CB Da Khoi Hanh!");
}

void GioiTinh1(int x,int y,int ss){
	settextstyle(3,0,1);
	setbkcolor(3);
	if(ss == 0){
		setcolor(1);
		outtextxy(x+5,y+5,"                                          ");
		outtextxy(x+5,y+5,"Nam");
	}
	else{
		setcolor(4);
		outtextxy(x+5,y+5,"                                          ");
		outtextxy(x+5,y+5,"Nu");
	}
}
void Late30Min(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(4);
	outtextxy(x+5,y+5,"                                          ");
	outtextxy(x+5,y+5,"Vui Long Doi 30p De Tiep");
	outtextxy(x+5-60,y+30+5,"Tuc Dat Ve");
}
void CleanMessageBox(int x,int y){
	settextstyle(3,0,1);
	setbkcolor(3);	
	setcolor(0);
	outtextxy(x+5,y+5,"                                                        ");
}
//=============================================================================================================================================//

//=====================================================================IN-RA-MAN-HINH==========================================================//
void OUTTEXT(int x, int y, int maunen, int mauchu,int fontchu, int sizechu, char text[]){
	settextstyle(fontchu,0,sizechu);
	setbkcolor(maunen);	
	setcolor(mauchu);
	outtextxy(x,y,text);
}

void OUTTEXT1(int x, int y, int maunen, int mauchu,int fontchu, int sizechu){
	settextstyle(fontchu,0,sizechu);
	setbkcolor(maunen);	
	setcolor(mauchu);
	outtextxy(x,y,"/");
}

void OUTTEXT2(int x, int y, int maunen, int mauchu,int fontchu, int sizechu){
	settextstyle(fontchu,0,sizechu);
	setbkcolor(maunen);	
	setcolor(mauchu);
	outtextxy(x,y,":");
}
//=============================================================================================================================================//


void Menu(){
	taoID(0,0,maxX,maxY,0);
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

//MAN 1
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
   	taoBang(335,10,55,m,3,10,text,15,0);
   	
	taoButton(405,575,455,625,0,7,0,2,"<");
   	taoButton(1130,575,1180,625,0,7,0,2," >");
}

void QuanLyMayBay(){
	taoID(310,0,maxX,maxY,0);
	QuanLyMayBay_HienThiMayBay();
	QuanLyMayBay_NhapMayBay();
}

//MAN 2
void QuanLyChuyenBay_NhapChuyenBay(){
	setbkcolor(3);	
	setcolor(0);
	settextstyle(3,0,1);
	taoO(335,640,945,830,3,0,0);
	
	outtextxy(345,655,"IDCB");
	taoO(458,650,925,680,7,0,21);
	
	outtextxy(345,702,"NAM");
	taoO(395,697,475,727,7,0,0);
	outtextxy(480,702,"THANG");
	taoO(550,697,600,727,7,0,0);
	outtextxy(605,702,"NGAY");
	taoO(660,697,710,727,7,0,0);
	outtextxy(715,702,"GIO");
	taoO(750,697,800,727,7,0,0);
	outtextxy(805,702,"PHUT");
	taoO(860,697,925,727,7,0,0);
	
	
	outtextxy(345,747,"TOI");
	taoO(458,742 ,925,772,7,0,0);
	
	outtextxy(345,792,"IDMAYBAY");
	taoO(458,787,820,817,7,0,0);
	
	outtextxy(830,792,"TT");
	taoO(860,787,925,817,7,0,0);
	
	taoO(965,640,1265,770,3,0,0);
   	outtextxy(1060,625,"MessageBox");

	taoButton(965,780,1040,830,0,7,8,3,"NEW");

	taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
	taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
	
}

void QuanLyChuyenBay_HienThiChuyenBay(){
	taoButton(10,160,280,230,2,8,15,3,"Quan Ly Chuyen Bay");
	char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
	int m[5] = {180,250,150,200,120};
   	taoBang(335,10,55,m,5,10,text,15,0);
  	taoButton(405,575,455,625,20001,7,0,2,"<");
   	taoButton(1130,575,1180,625,20002,7,0,2," >");
}

void QuanLyChuyenBay(){
	taoID(310,0,maxX,maxY,0);
	QuanLyChuyenBay_HienThiChuyenBay();
   	QuanLyChuyenBay_NhapChuyenBay();
}

//MAN 3
void QuanLyHanhKhach_NhapHanhKhach(){
	setbkcolor(3);	
	setcolor(0);
	settextstyle(3,0,1);
	taoO(335,640,945,830,3,0,0);
	
   	outtextxy(345,655,"CCCD: ");
   	taoO(450,650,925,680,7,0,31);
	
	outtextxy(345,722,"HO: ");
	taoO(450,717,640,747,7,0,0);
	
	outtextxy(670,722,"TEN: ");
	taoO(735,717,925,747,7,0,0);
	
	outtextxy(345,792,"GIOI TINH: ");
	taoO(500,787,600,817,7,0,0);
	OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
	
	taoO(775,787,875,817,7,0,0);
	OUTTEXT(775+35,787+5,7,8,3,1,"NU");
		
	taoO(965,640,1265,770,3,0,0);
	OUTTEXT(1060,625,3,0,3,1,"MessageBox");
	
	taoButton(965,780,1040,830,0,7,8,3,"NEW");
	taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");	
}




void QuanLyHanhKhach_HienThiHanhKhach(){
	taoButton(10,280,280,350,3,8,15,3,"Quan Ly Hanh Khach");
	char text[][50]={"CCCD","HO","TEN","PHAI"};
	int m[4] = {200,260,250,200};
   	taoBang(335,10,55,m,4,10,text,15,0);
    taoButton(405,575,455,625,0,7,0,2,"<");
   	taoButton(1130,575,1180,625,0,7,0,2," >");
}

	

void QuanLyHanhKhach(){
	taoID(310,0,maxX,maxY,0);
	QuanLyHanhKhach_HienThiHanhKhach();
	QuanLyHanhKhach_NhapHanhKhach();
}

//MAN 4
void TimChuyenBay_Nhap(){
	setbkcolor(3);	
	setcolor(0);
	
   	taoO(335,40,1260,90,3,0,0);
	outtextxy(355,55,"NAM");
	taoO(430,50,560,80,7,0,41);

	outtextxy(595,55,"THANG");
	taoO(695,50,780,80,7,0,0);
	outtextxy(805,55,"NGAY");
	taoO(885,50,970,80,7,0,0);
	outtextxy(1015,55,"TOI");
	taoO(1065,50,1230,80,7,0,0);
	
	
	taoO(335,95,1260,145,3,0,0);
	taoO(1065,105,1230,135,7,0,0);
	OUTTEXT(1110,110,7,8,3,1,"Tim Kiem");
}

void TimChuyenBay_HienThi(){
	taoButton(10,400,280,470,4,8,15,3,"Tim Chuyen Bay");
	char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","Trang Thai"};
	int m[4] = {210,300,210,210};
   	taoBang(335,150,55,m,4,10,text,15,0);
	taoButton(395,760,445,810,0,7,0,2,"<");
	taoButton(1130,760,1180,810,0,7,0,2," >");
}

void TimChuyenBay(){
	taoID(310,0,maxX,maxY,0);
   	TimChuyenBay_HienThi();
   	TimChuyenBay_Nhap();
}
//MAN 5
void DatVe_Nhap(){
	taoButton(10,520,280,590,5,8,15,3,"Dat Ve");

	setbkcolor(3);	
	setcolor(0);
	settextstyle(3,0,3);
   	taoO(335,40,1260,90,3,0,0);

	outtextxy(345,50,"ID");
	taoO(375,50,535,80,7,0,501);

	outtextxy(550,50,"Khoi Hanh");


	taoO(670,50,1000,80,7,0,0);

	outtextxy(1015,50,"Toi");
	taoO(1065,50,1230,80,7,0,0);
	
	

	settextstyle(3,0,1);
	taoO(335,640,945,830,3,0,0);
	
	outtextxy(345,655,"VI TRI: ");
	taoO(458,650,925,680,7,0,0);

	outtextxy(345,702,"CCCD:");
	taoO(458,697,925,727,7,0,0);


    outtextxy(345,747,"HO: ");
	taoO(458,742,640,772,7,0,0);
	
	outtextxy(670,747,"TEN: ");
	taoO(735,742,925,772,7,0,0);
	

	outtextxy(345,792,"GIOI TINH: ");
	taoO(500,787,600,817,7,0,0);
	OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
	
	taoO(775,787,875,817,7,0,0);
	OUTTEXT(775+35,787+5,7,8,3,1,"NU");
	
			
	taoO(965,640,1265,770,3,0,0);
	OUTTEXT(1060,625,3,0,3,1,"MessageBox");
	
	taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
	taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");

  	taoButton(635,575,900,625,0,7,8,3,"HUY VE THEO CCCD");

}

void DatVe_HienThi(){
	taoO(335,110,1260,550,15,0,0);
	line(355,330,1240,330);
}

void DatVe(){
	taoID(310,0,maxX,maxY,0);
	DatVe_Nhap();
	DatVe_HienThi();
}
//MAN 6
void DanhSachHanhKhach(){
	taoID(310,0,maxX,maxY,0);
	taoButton(10,640,280,710,6,8,15,3,"Danh Sach Hanh Khach");
	setbkcolor(3);	
	setcolor(0);

	outtextxy(435,50,"Danh Sach Hanh Khach Thuoc Chuyen Bay");
	taoO(915,50,1135,80,7,0,61);
	outtextxy(335,110,"Ngay Khoi Hanh");
	taoO(515,110,800,140,7,0,0);
	outtextxy(815,110,"Noi Den");
	taoO(915,110,1135,140,7,0,0);
	char text[][50]={"STT","So Ve","CCCD","Ho","Ten","Gioi Tinh"};
	int m[6] = {90,90,200,170,220,150}; //sum = 900;
   	taoBang(335,190,55,m,6,10,text,15,0);
   	taoButton(395,760,445,810,0,7,0,2,"<");
   	taoButton(1130,760,1180,810,0,7,0,2," >");
}
//MAN 7
void ThongKeChuyenBay(){
	taoID(310,0,maxX,maxY,0);
	taoButton(10,760,280,830,5,8,15,3,"Thong Ke Chuyen Bay");
	char text[][50]={"ID May Bay","So Chuyen Bay Da Bay"};
	int m[2] = {450,450};
   	taoBang(335,10,55,m,2,13,text,15,0);
   	taoButton(395,760,445,810,70001,7,0,2,"<");
   	taoButton(1130,760,1180,810,70002,7,0,2," >");
}
//===================================================================================================================//

