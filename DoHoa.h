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
	for(int i=0;i < slcot;i++){
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
	int index = 0;
	int trang1 = 1;
	int tongtrang1 = 0;
	char charTongTrang1[50] = "";
	char charTrang1[50] = "";
	int trang2 = 1;
	int tongtrang2 = 0;
	char charTongTrang2[50] = "";
	int tempTOTALCB = 0;
	char charTrang2[50] = "";
	int trang3 = 1; 
	int tongtrang3 = 0;
	char charTongTrang3[50] = "";
	char charTrang3[50] = "";
	int trang4 = 1; 
	int tongtrang4 = 0;
	char charTongTrang4[50] = "";
	char charTrang4[50] = "";
	int tempTOTALSEARCHCB = 0;
	int trang5 = 1; 
	int tongtrang5 = 0;
	char charTongTrang5[50] = "";
	char charTrang5[50] = "";
	int trang6 = 1; 
	int tongtrang6 = 0;
	char charTongTrang6[50] = "";
	char charTrang6[50] = "";
	int trang7 = 1; 
	int tongtrang7 = 0;
	char charTongTrang7[50] = "";
	char charTrang7[50] = "";
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
	char TRANGTHAI2[10]= ""; 
	char CCCD3[50] = "";
	char HO3[50] = ""; 
	char TEN3[50] = ""; 
	char GIOITINH3[50] = "";
	char ID4[50] = ""; 
	char NGAY4[50] = "";
	char THANG4[50] = ""; 
	char NAM4[50] = "";
	char TOI4[50] = ""; 
	char ID5[50] = "";
	char NGAY5[50] = ""; 
	char THANG5[50] = ""; 
	char NAM5[50] = ""; 
	char GIO5[50] = ""; 
	char PHUT5[50] = ""; 
	char TOI5[50] = "";
	char VITRI5[50] = "";
	char CCCD5[50] = ""; 
	char HO5[50] = "";
	char TEN5[50] = "";
	char GIOITINH5[50] = ""; 
	char ID6[50] = "";
	char NGAY6[50] = ""; 
	char THANG6[50] = ""; 
	char NAM6[50] = ""; 
	char GIO6[50] = ""; 
	char PHUT6[50] = ""; 
	char TOI6[50] = "";
	bool okID1 = false;
	bool okLOAI1 = false;
	bool okSOCHO1 = false; 
	bool okID2 = false;
	bool okNGAY2= false; 
	bool okTHANG2 = false; 
	bool okNAM2 = false;
	bool NamNhuan2 = false; 
	bool okGIO2 = false; 
	bool okPHUT2 = false;
	bool okTOI2 = false;
	bool okIDMAYBAY2 = false; 
	bool okCCCD3 = false;
	bool okHO3 = false; 
	bool okTEN3 = false;
	bool okGIOITINH3= false;
// Man 4 KHONG CAN CHECK 
	bool HUYVECCCD = false;
	bool okID5 = false;
	bool okVITRI5= false;
	bool okCCCD5 = false; 
	bool okViTriCCCD5 = false;
	bool okHO5 = false;
    bool okTEN5 = false;
	bool okGIOITINH5 = false; 
	bool okVE5 = false;
// MAN 6 K CHECK
// MAN 7 K CHECK
	int sotam1 = 0;
	int tempSoCho = 0;
	int TempNgay2 = 0;
	int TempThang2 = 0;
	int TempNam2 = 0;
	int TempGio2 = 0;
	int TempPhut2 = 0;
	int sotam3 = 0;
	int TempNgay4 = 0;
	int TempThang4 = 0;
	int TempNam4 = 0;
	int SoChoNgoi5 = 0;
	int ViTriVe5 = 0;
	int tempvitri = 0;
	int sotam5 = 0;
	int TempTT = 0; 

void ClearData(){
	index = 0;
	trang1 = 1;
	tongtrang1 = 0;
	strcpy(charTongTrang1,"");
	strcpy(charTrang1,"");
	trang2 = 1;
	tongtrang2 = 0;
	tempTOTALCB = 0;
	strcpy(charTongTrang2,"");
	strcpy(charTrang2,"");
	trang3 = 1; 
	tongtrang3 = 0;
	strcpy(charTongTrang3,"");
	strcpy(charTrang3,"");
	trang4 = 1; 
	tongtrang4 = 0;
	strcpy(charTongTrang4,"");
	strcpy(charTrang4,"");	
	tempTOTALSEARCHCB = 0;
	trang5 = 1; 
	tongtrang5 = 0;
	strcpy(charTongTrang5,"");
	strcpy(charTrang5,"");
	trang6 = 1; 
	tongtrang6 = 0;
	strcpy(charTongTrang6,"");
	strcpy(charTrang6,"");
	trang7 = 1; 
	tongtrang7 = 0;
	strcpy(charTongTrang7,"");
	strcpy(charTrang7,"");
	strcpy(ID1,""); 
	strcpy(LOAI1,"");
	strcpy(SOCHO1,""); 
	strcpy(ID2,"");
	strcpy(NGAY2,"");
	strcpy(THANG2,"");
	strcpy(NAM2,"");
	strcpy(GIO2,"");
	strcpy(PHUT2,""); 
	strcpy(TOI2,"");
	strcpy(IDMAYBAY2,"");
	strcpy(TRANGTHAI2,"");
	strcpy(CCCD3,"");
	strcpy(HO3,"");
	strcpy(TEN3,"");
	strcpy(GIOITINH3,"");
	strcpy(ID4,"");
	strcpy(NGAY4,"");
	strcpy(THANG4,"");
	strcpy(NAM4,"");
	strcpy(TOI4,"");
	strcpy(ID5,"");
	strcpy(NGAY5,"");
	strcpy(THANG5,""); 
	strcpy(NAM5,"");
	strcpy(GIO5,"");
	strcpy(PHUT5,"");
	strcpy(TOI5,"");
	strcpy(VITRI5,"");
	strcpy(CCCD5,"");
	strcpy(HO5,"");
	strcpy(TEN5,"");
	strcpy(GIOITINH5,""); 
	strcpy(ID6,"");
	strcpy(NGAY6,""); 
	strcpy(THANG6,""); 
	strcpy(NAM6,"");
	strcpy(GIO6,"");
 	strcpy(PHUT6,""); 
	strcpy(TOI6,"");
	okID1 = false;
	okLOAI1 = false;
	okSOCHO1 = false; 
	okID2 = false;
	okNGAY2= false; 
	okTHANG2 = false; 
	okNAM2 = false;
 	NamNhuan2 = false; 
	okGIO2 = false; 
	okPHUT2 = false;
	okTOI2 = false;
	okIDMAYBAY2 = false; 
	okCCCD3 = false;
	okHO3 = false; 
	okTEN3 = false;
	okGIOITINH3= false;
// Man 4 KHONG CAN CHECK 
	HUYVECCCD = false;
	okID5 = false;
	okVITRI5= false;
	okCCCD5 = false; 
	okViTriCCCD5 = false;
	okHO5 = false;
    okTEN5 = false;
	okGIOITINH5 = false; 
	okVE5 = false;
// MAN 6 K CHECK
// MAN 7 K CHECK
	sotam1 = 0;
	tempSoCho = 0;
	TempNgay2 = 0;
	TempThang2 = 0;
	TempNam2 = 0;
	TempGio2 = 0;
	TempPhut2 = 0;
	sotam3 = 0;
	TempNgay4 = 0;
	TempThang4 = 0;
	TempNam4 = 0;
	SoChoNgoi5 = 0;
	ViTriVe5 = 0;
	tempvitri = 0;
 	sotam5 = 0;
	TempTT = 0; 
}

