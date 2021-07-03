#include "XuLy.h"
#include "DoHoa.h"

//CHAY CHUONG TRINH 
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
	int DEMSOHK = 0;
	NodeChuyenBay* ptr = new NodeChuyenBay;
	ptr = pheadDSCB;
	ktHK = FileGoodHK(CheckHK);
	if(FileGoodMB(CheckMB) == 1)                                                                                     
	{                                                                           
	FileInMB(MBI,dsmb);
	 if(FileGoodCB(CheckCB) == 1)
	  {
	   FileInCB(CBI,pheadDSCB);
         if(FileGoodVe(CheckVe) == 1 && ktHK == 1)
          FileInVe(VEI);
	  }
    }
    cout<<" this is kthk "<<ktHK<<" ";
    if(ktHK ==1)
    {
    	FileINHK(HKTIN);
	}
     
	while (1){         
		if(kbhit()){
			char c = getch();
		}
		delay(1);
		if (ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			cout << x <<"," << y <<"," <<MID[x][y] << endl;
		}
        menu:
    	if(x!=-1 && y!=-1)
		switch(MID[x][y]){
			case 1:{ // man hinh Quan Ly May Bay
				Menu();
				QuanLyMayBay();
				trang1 = 1;
				tongtrang1 = dsmb.total/9;
				if (dsmb.total%9 != 0){
			   		tongtrang1 +=1;
				}
				IntToChar(tongtrang1,charTongTrang1);
				IntToChar(trang1,charTrang1);
				OUTTEXT(730,585,3,1,3,3,charTrang1);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang1);
				int m[3] = {300,310,300};
				int xx = 335; int yy = 65;
				int j = 9; 
				for(int i=0;i<j && i < dsmb.total;i++){
					if(dsmb.data[i]->Active == false){
						j++;
					}
					else{
						OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
						OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
						char CharRoom[50];
						IntToChar(dsmb.data[i]->Room,CharRoom);
						OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
						yy+=55;
					}
				}
				if(trang1==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
			  	else taoID(405,575,455,625,10001);
				if(tongtrang1>1) taoID(1130,575,1180,625,10002); // TAO ID NUT NEXT
				if(trang1==tongtrang1) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
				x=-1,y=-1;
				break;
				}
			case 11:{ //ID MAY BAY
				 	taoO(450,650,925,680,15,0,11);
				 	taoO(450,717,925,747,15,0,0);
					taoO(450,787,925,817,15,0,0);
				 	
				 	taoButton(335+200,600,335+200+40,640,1001,4,0,3,"X");
				 	ScanMa(450+5,650+5,ID1,10,15);
				 	if(strlen(ID1)==0){
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"ID: ");
				 		BaoLoi1(970 + 25,645);
				 		okID1=false; 
					 }
					 else if(SearchIdMb(dsmb,ID1)!=-1){
						sotam1 = SearchIdMb(dsmb,ID1);
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"ID: ");
				 		TonTai1(970 + 25,645);
						okID1=false;
						okLOAI1=true;
						okSOCHO1=true;
						strcpy(LOAI1,dsmb.data[sotam1]->Type);
						tempSoCho = dsmb.data[sotam1]->Room;
						char CharRoom[50];
						IntToChar(dsmb.data[sotam1]->Room,CharRoom);
						strcpy(SOCHO1,CharRoom);
						taoID(450,650,925,680,0); //ID OFF
						OUTTEXT(450+5,650+5,15,4,6,1,ID1);
					 	OUTTEXT(450+5,717+5,15,0,6,1,LOAI1);
					 	OUTTEXT(450+5,787+5,15,0,6,1,SOCHO1);
					 	taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
						taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
				 		taoID(450,717,925,747,12); // LOAI ON  
				 		taoID(450,787,925,817,13); // SO CHO ON 
					}
				 	else {
				 		cout << "run" << endl;
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"ID: ");
				 		HopLe1(970 + 25,645);
				 		okID1=true;
				 		taoID(450,717,925,747,12); // LOAI ON 
					 	}
				 	x=-1;y=-1;
				 	break;
			}
			case 12:{ // Loai
					taoID(450,650,925,680,0); //ID OFF
					taoID(450,787,925,817,13);
					ScanMa(450+5,717+5,LOAI1,10,15) ;
				 	if(strlen(LOAI1)==0){
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,680,"LOAI: ");
				 		BaoLoi1(970 + 50,675);
				 		okLOAI1=false;
						taoButton(965,780,1040,830,0,7,8,3,"NEW");
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE"); 
					 }
				 	else {
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,680,"LOAI: ");
				 		HopLe1(970 + 50,675);
				 		okLOAI1=true; 
				 		taoID(450,787,925,817,13); // SO CHO ON 
				 		
				 		if(okID1 == false && okLOAI1 == true && okSOCHO1 == true){
							taoButton(965,780,1040,830,0,7,8,3,"NEW");

							taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
		
							taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
						}
						else if(SearchIdMb(dsmb,ID1)!=-1){
							if(strcmp(dsmb.data[sotam1]->Type,LOAI1) != 0 || dsmb.data[sotam1]->Room != tempSoCho ){
								if(okID1 == false && okLOAI1 == true && okSOCHO1 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
	
								taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
			
								taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
								}
							}
						}
						
					}
					x=-1;y=-1;
					break;
			}
			case 13:{ // So cho ngoi 
					if(sotam1 == 0)
				 	taoID(450,717,925,747,0); // LOAI OFF	

				 	ScanSo(450+5,787+5,SOCHO1,2,15);
				 	if(strlen(SOCHO1)==0){
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,710,"SOCHO: ");
				 		BaoLoi1(970 + 75,705);
				 		okSOCHO1=false; 
				 		taoButton(965,780,1040,830,0,7,8,3,"NEW");

						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				 	else {
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		tempSoCho = CharToInt(SOCHO1);
				 		if(tempSoCho >= 20){
					 		outtextxy(970,710,"SOCHO: ");
					 		HopLe1(970 + 75,705);
					 		okSOCHO1=true; 
					 		if(okID1 == true && okLOAI1 == true && okSOCHO1 == true){
						 		taoButton(965,780,1040,830,1002,7,0,3,"NEW");
		
								taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
			
								taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
							}
						 	if(okID1 == false && okLOAI1 == true && okSOCHO1 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
	
								taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
			
								taoButton(1145,780,1265,830,1004,7,0,3,"REMOVE");
							}
							tempSoCho = CharToInt(SOCHO1);
							if(SearchIdMb(dsmb,ID1)!=-1){
								if(strcmp(dsmb.data[sotam1]->Type,LOAI1) != 0 || dsmb.data[sotam1]->Room != tempSoCho ){
									if(okID1 == false && okLOAI1 == true && okSOCHO1 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
									taoButton(1050,780,1135,830,1003,7,0,3,"SAVE");
				
									taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
									}
								}
							}	
						}
						else{
							setbkcolor(3);
					 		setcolor(0);
					 		settextstyle(3,0,1);
					 		outtextxy(970,710,"SOCHO: ");
					 	    KhongHopLe1(970 + 75,705);
					 	    okSOCHO1= false;
					 	    taoButton(965,780,1040,830,0,7,8,3,"NEW");

							taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
		
							taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
						}	
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
					sotam1 = 0;
					taoO(450,650,925,680,7,0,11);
				 	taoO(450,717,925,747,7,0,0);
					taoO(450,787,925,817,7,0,0);
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
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
					AddMb(dsmb,ID1,LOAI1,tempSoCho);
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
					//VE BANG
					int m[3] = {300,310,300};
					char text[][50]={"ID","Loai","So Cho"};
				  	taoBang(335,10,55,m,3,10,text,15,0);
					trang1 = 1;
					tongtrang1 = dsmb.total/9;
					if (dsmb.total%9 != 0){
					  	tongtrang1 +=1;
					}
					IntToChar(tongtrang1,charTongTrang1);
					IntToChar(trang1,charTrang1);
					OUTTEXT(730,585,3,1,3,3,charTrang1);
					OUTTEXT1(760,585,3,0,3,3);
					OUTTEXT(790,585,3,0,3,3,charTongTrang1);
					int xx = 335; int yy = 65;
					int j = 9; 
					for(int i=0;i<j && i < dsmb.total;i++){
						if(dsmb.data[i]->Active == false){
							j++;
						}
						else{
							OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
							char CharRoom[50];
							IntToChar(dsmb.data[i]->Room,CharRoom);
							OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
							yy+=55;
						}
					}
					if(trang1==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
				  	else taoID(405,575,455,625,10001);
					if(tongtrang1>1) taoID(1130,575,1180,625,10002); // TAO ID NUT NEXT	
					if(trang1==tongtrang1) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
					MessageBox("Da Them Thanh Cong",14);
					delay(400);
					MessageBox("",0);
					x=-1;y=-1;
				break;
			}
			case 1003:{ // Chinh Sua
					taoButton(1050,780,1135,830,1003,15,1,3,"SAVE");
					delay(50);
					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					EditMb(dsmb,ID1,LOAI1,tempSoCho);
					strcpy(ID1,"");
					strcpy(LOAI1,"");
					strcpy(SOCHO1,"");
					FileOutMBV2(MBO,dsmb);
					taoO(450,650,925,680,7,0,11);
					taoO(450,717,925,747,7,0,0);
					taoO(450,787,925,817,7,0,0);
					//VE BANG
					int m[3] = {300,310,300};
					char text[][50]={"ID","Loai","So Cho"};
			  		taoBang(335,10,55,m,3,10,text,15,0);
					trang1 = 1;
					tongtrang1 = dsmb.total/9;
					if (dsmb.total%9 != 0){
				   		tongtrang1 +=1;
					}
					IntToChar(tongtrang1,charTongTrang1);
					IntToChar(trang1,charTrang1);
					OUTTEXT(730,585,3,1,3,3,charTrang1);
					OUTTEXT1(760,585,3,0,3,3);
					OUTTEXT(790,585,3,0,3,3,charTongTrang1);
					int xx = 335; int yy = 65;
					int j = 9; 
					for(int i=0;i<j && i < dsmb.total;i++){
						if(dsmb.data[i]->Active == false){
							j++;
						}
						else{
							OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
							char CharRoom[50];
							IntToChar(dsmb.data[i]->Room,CharRoom);
							OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
							yy+=55;
						}
					}
				  	if(trang1==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
				  	else taoID(405,575,455,625,10001);
					if(tongtrang1>1) taoID(1130,575,1180,625,10002); // TAO ID NUT NEXT	
					if(trang1==tongtrang1) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
					MessageBox("Da Luu Thanh Cong",14);
					delay(400);
					MessageBox("",0);	
					x=-1;y=-1;
				break;
			}
			case 1004:{ // Xoa
					taoButton(1145,780,1265,830,1004,15,1,3,"REMOVE");
					delay(50);
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
					if(IsHaveFlight(pheadDSCB,ID1)==false){
					//	CMDREMOVE();
						DelMb(dsmb,ID1);
						FREEMayBay(pheadDSCB,ID1);
						strcpy(ID1,"");
						strcpy(LOAI1,"");
						strcpy(SOCHO1,"");
//						for(int i=0;i<dsmb.total;i++){
//							if(dsmb.data[i]->Active == true)
//							FileOutMB(MBO,dsmb,i);	
//						}
                        FileOutMBV2(MBO,dsmb);
						taoO(450,650,925,680,7,0,11);
						taoO(450,717,925,747,7,0,0);
						taoO(450,787,925,817,7,0,0);
						trang1 = 1;
						int m[3] = {300,310,300};
						char text[][50]={"ID","Loai","So Cho"};
						taoBang(335,10,55,m,3,10,text,15,0);
						tongtrang1 = dsmb.total/9;
						if (dsmb.total%9 != 0){
						   	tongtrang1 +=1;
						}
						IntToChar(tongtrang1,charTongTrang1);
						IntToChar(trang1,charTrang1);
						OUTTEXT(730,585,3,1,3,3,charTrang1);
						OUTTEXT1(760,585,3,0,3,3);
						OUTTEXT(790,585,3,0,3,3,charTongTrang1);
						int xx = 335; int yy = 65;
						int j = 9; 
						for(int i=0;i<j && i < dsmb.total;i++){
							if(dsmb.data[i]->Active == false){
								j++;
							}
							else{
								OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[i]->Type);
								char CharRoom[50];
								IntToChar(dsmb.data[i]->Room,CharRoom);
								OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
								yy+=55;
							}
						}
						if(trang1==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
					  	else taoID(405,575,455,625,10001);
						if(tongtrang1>1) taoID(1130,575,1180,625,10002); // TAO ID NUT NEXT
						if(trang1==tongtrang1) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
						MessageBox("Da Xoa Thanh Cong",14);
						delay(400);
						MessageBox("",0);
					}
					else{
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		MessageBox("KHONG THE XOA ",4);
				 		outtextxy(1010,650,"MB CO CHUYEN BAY ");
						taoID(450,717,925,747,0);
						taoID(450,787,925,817,0);
					}
					x=-1;y=-1;
				break;
			}
			case 10001:{ // nut back
				taoButton(405,575,455,625,10001,15,1,2,"<");
			  	delay(50);
			  	taoButton(405,575,455,625,10001,7,0,2,"<");
				trang1 -=1;
			  	int m[3] = {300,310,300};
			  	char text[][50]={"ID","Loai","So Cho"};
			  	taoBang(335,10,55,m,3,10,text,15,0);
			  	tongtrang1 = dsmb.total/9;
   				if (dsmb.total%9 != 0) tongtrang1 +=1;
   				IntToChar(tongtrang1,charTongTrang1);
				IntToChar(trang1,charTrang1);
				OUTTEXT(730,585,3,1,3,3,charTrang1);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang1);
			  	int xx = 335; int yy = 65;
				int j = 9; 
				for(int i=0;i<j && 9*(trang1-1)+i < dsmb.total;i++){
					if(dsmb.data[9*(trang1-1)+i]->Active == false){
						j++;
					}
					else{
						OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[9*(trang1-1)+i ]->ID);
						OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[ 9*(trang1-1)+i ]->Type);
						char CharRoom[50];
						IntToChar(dsmb.data[9*(trang1-1)+i ]->Room,CharRoom);
						OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
						yy+=55;
					}
				}
				if(trang1==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
			  	else taoID(405,575,455,625,10001);
				if(tongtrang1>1) taoID(1130,575,1180,625,10002); // TAO ID NUT NEXT		  	
				if(trang1==tongtrang1) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
				x=-1;y=-1;
				break;
			}
			case 10002:{ // nut next
				taoButton(1130,575,1180,625,10002,15,1,2," >");
			  	delay(50);
				taoButton(1130,575,1180,625,10002,7,0,2," >");
				if (trang1 + 1 > tongtrang1) break;
			  	trang1 +=1;
			  	int m[3] = {300,310,300};
			  	char text[][50]={"ID","Loai","So Cho"};
			  	taoBang(335,10,55,m,3,10,text,15,0);
				tongtrang1 = dsmb.total/9;
   				if (dsmb.total%9 != 0) tongtrang1 +=1;
   				IntToChar(tongtrang1,charTongTrang1);
				IntToChar(trang1,charTrang1);
				OUTTEXT(730,585,3,1,3,3,charTrang1);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang1);
			   	int xx = 335; int yy = 65;
				int j = 9; 
				for(int i=0;i<j && 9*(trang1-1)+i < dsmb.total;i++){
					if(dsmb.data[9*(trang1-1)+i]->Active == false){
						j++;
					}
					else{
						OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[9*(trang1-1)+i ]->ID);
						OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,dsmb.data[ 9*(trang1-1)+i ]->Type);
						char CharRoom[50];
						IntToChar(dsmb.data[9*(trang1-1)+i ]->Room,CharRoom);
						OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,CharRoom);
						yy+=55;
					}
				}
				if(trang1==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
			  	else taoID(405,575,455,625,10001);
				if(tongtrang1>1) taoID(1130,575,1180,625,10002); // TAO ID NUT NEXT
				if(trang1==tongtrang1) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
				x=-1;y=-1;
				break;
			}
			
			case 2:{ // MAN HINH CHUYEN BAY 
				Menu();
				QuanLyChuyenBay();
			   	NodeChuyenBay* ptr = pheadDSCB;
//				ptr = pheadDSCB;
				SortCB_Time(pheadDSCB);
				UpdateCB(pheadDSCB);
				FileOutVe(VEO,pheadDSCB);
				tempTOTALCB = CountTotalChuyenBay(pheadDSCB);
				trang2 = 1;
				tongtrang2 = tempTOTALCB/9;
				if (tempTOTALCB%9 != 0)	tongtrang2 +=1;
				IntToChar(tongtrang2,charTongTrang2);
				IntToChar(trang2,charTrang2);
				OUTTEXT(730,585,3,1,3,3,charTrang2);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang2);
				char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
				int m[5] = {180,250,150,200,120};
				taoBang(335,10,55,m,5,10,text,15,0);
				int xx = 335; int yy = 65;
				int i = 0; 	
				while(ptr != NULL)
				{
					if(i<9 && i < tempTOTALCB){
				    	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
				 
				    	char day[50]= "";
				    	char mon[50]= "";
				    	char year[50]= "";
				    	char hour[50]= "";
				    	char min[50]= "";
				    	IntToChar(ptr->data.DepartTime.day,day);
				    	IntToChar(ptr->data.DepartTime.mon,mon);
				    	IntToChar(ptr->data.DepartTime.year,year);
				    	IntToChar(ptr->data.DepartTime.hour,hour);
				    	IntToChar(ptr->data.DepartTime.min,min);
						OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
				    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
				    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
				    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
				    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
				    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
				    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
				    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
									
				    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
				    	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
				    	char TT[50] = "";
				    	IntToChar(ptr->data.Status,TT);
				    	OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,TT);
				    	yy +=55;
				    	i++;
				    }
				   	ptr = ptr->next;  
				}
				if(trang2==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
				else taoID(405,575,455,625,20001);
				if(tongtrang2>1) taoID(1130,575,1180,625,20002); // TAO ID NUT NEXT
				if(trang2==tongtrang2) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
	
				x=-1,y=-1;
				break;
			}
			case 21:{ // ID CHUYEN BAY

				taoO(458,650,925,680,15,0,21);

				taoO(395,697,475,727,15,0,0);
				taoO(550,697,600,727,15,0,0);
				taoO(660,697,710,727,15,0,0);
				taoO(750,697,800,727,15,0,0);
				taoO(860,697,925,727,15,0,0);
				
				taoO(458,742,925,772,15,0,0);
				taoO(458,787,820,817,15,0,0);
				taoO(860,787,925,817,15,0,0);
				
				taoButton(335+200,600,335+200+40,640,2001,4,0,3,"X");
				
				ScanMa(458+5,650+5,ID2,7,15);
				if(strlen(ID2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
			 		outtextxy(970,650,"IDCB: ");
					BaoLoi1(970 + 50,645);
					okID2=false; 
				}
				else if(SearchNode(pheadDSCB,ID2)!=NULL ){ // SEARCH ID CHUYENBAY FUNCTION
					NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
					setbkcolor(3);
			 		setcolor(0);
			 		settextstyle(3,0,1);
			 		outtextxy(970,650,"IDCB: ");
				 	TonTai1(970 + 50,645);
					okID2=false;
					
					//LAY DU LIEU
					char day[50]= "";
    				char mon[50]= "";
    				char year[50]= "";
    				char hour[50]= "";
    				char min[50]= "";
    				IntToChar(ptr->data.DepartTime.day,day);
    				IntToChar(ptr->data.DepartTime.mon,mon);
    				IntToChar(ptr->data.DepartTime.year,year);
    				IntToChar(ptr->data.DepartTime.hour,hour);
    				IntToChar(ptr->data.DepartTime.min,min);
    				
					TempNgay2 = ptr->data.DepartTime.day;
					TempThang2 = ptr->data.DepartTime.mon;
					TempNam2= ptr->data.DepartTime.year;
					TempGio2 = ptr->data.DepartTime.hour;
					TempPhut2 = ptr->data.DepartTime.min; 
    
    				
    				strcpy(NGAY2,day); strcpy(THANG2,mon); strcpy(NAM2,year); strcpy(GIO2,hour); strcpy(PHUT2,min);
					strcpy(TOI2,ptr->data.SanBayDen);
					strcpy(IDMAYBAY2,ptr->data.ID);
					
					if(SearchIdMb(dsmb,IDMAYBAY2) == -1){
						ptr->data.Status = 0;
					}
					char TT[50] = "";
					IntToChar(ptr->data.Status,TT);
					strcpy(TRANGTHAI2,TT);
					okNGAY2 = true;
					okTHANG2 = true;
					okNAM2= true;
					okGIO2 = true;
					okPHUT2 = true;
					okTOI2 = true;
					okIDMAYBAY2 = true;

					taoO(458,650,925,680,15,0,0); // ID CHUYEN BAY OFF
					
					taoO(395,697,475,727,15,0,201); // NAM ON 
					OUTTEXT(458+5,650+5,15,4,6,1,ID2);
					OUTTEXT(395+5,697+5,15,0,6,1,NAM2);
					OUTTEXT(550+5,697+5,15,0,6,1,THANG2);
					OUTTEXT(660+5,697+5,15,0,6,1,NGAY2);
					OUTTEXT(750+5,697+5,15,0,6,1,GIO2);
					OUTTEXT(860+5,697+5,15,0,6,1,PHUT2);
					
					OUTTEXT(458+5,742+5,15,0,6,1,TOI2);
					OUTTEXT(458+5,787+5,15,0,6,1,IDMAYBAY2);
					OUTTEXT(860+5,787+5,15,0,6,1,TRANGTHAI2);
					taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
					//XET TRANG THAI 
					if(ptr->data.Status== 0 || ptr->data.Status == 3){
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
						taoID(458,650,925,680,0);

						taoID(395,697,475,727,0);
						taoID(550,697,600,727,0);
						taoID(660,697,710,727,0);
						taoID(750,697,800,727,0);
						taoID(860,697,925,727,0);
				
						taoID(458,742,925,772,0);
						taoID(458,787,820,817,0);
						taoID(860,787,925,817,0);
						}
					}
					else {
						strcpy(TRANGTHAI2,"1");
						TempTT = CharToInt(TRANGTHAI2);
				 		setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"IDCB: ");
				 		HopLe1(970 + 50,645);
				 		okID2=true;
				 		taoID(395,697,475,727,201);
				 		OUTTEXT(860+5,787+5,15,0,6,1,TRANGTHAI2);
					 	}
				x=-1;y=-1;
				break;
				}
//====================================================================================
			case 201:{ //NAM
				taoID(458,650,925,680,0); //ID CHUYEN BAY OFF
				ScanSo(395+5,697+5,NAM2,4,15);
				if(strlen(NAM2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,680);
				 	outtextxy(970,680,"NAM:");
				 	BaoLoi1(970 + 50,675);
				 	okNAM2=false; 
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				else{
					TempNam2 = CharToInt(NAM2);
					if(TempNam2 > 2000 && TempNam2 < 2100){
						setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"NAM:");
				 		HopLe1(970 + 50,675);
				 		NamNhuan2 = checkYear(TempNam2);
				 		okNAM2=true;
						taoID(550,697,600,727,202); //THANG ON 
						if(SearchNode(pheadDSCB,ID2)!=NULL){
							NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
							if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
	
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
			
								taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
							}
							if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
								if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
									taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
								}
							}
						}
					}
					else {
						setbkcolor(3);
					 	setcolor(0);
					 	settextstyle(3,0,1);
					 	CleanMessageBox(970,680);
					 	outtextxy(970,680,"NAM:");
					 	KhongHopLe1(970 + 50,675);
				 		okNAM2=false; 
				 		taoButton(965,780,1040,830,0,7,8,3,"NEW");

						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				 		
					}
				}
				
				x=-1;y=-1;
				break;
			}
		
			case 202:{ //THANG
				taoID(395,697,475,727,0); // NAM OFF
				ScanSo(550+5,697+5,THANG2,2,15);
				if(strlen(THANG2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,680);
				 	outtextxy(970,680,"THANG:");
				 	BaoLoi1(970 + 70,675);
				 	okTHANG2=false; 
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				else{
					TempThang2 = CharToInt(THANG2);
					if(TempThang2 >= 1 && TempThang2 <= 12){
						setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"THANG:");
				 		HopLe1(970 + 70,675);
				 		okTHANG2=true;
						taoID(660,697,710,727,203); // NGAY ON 
						if(SearchNode(pheadDSCB,ID2)!=NULL){
							NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
							if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
	
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
			
								taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
							} 
							if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
								if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
									taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
								}
							}
						}
					}
					else{
					 	setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"THANG:");
				 		KhongHopLe1(970 + 70,675);
				 		okTHANG2=false;
					}
				}
				x=-1;y=-1;
				break;
			}
			case 203:{ //NGAY
			    taoID(550,697,600,727,0); // THANG OFF
				ScanSo(660+5,697+5,NGAY2,2,15);
				if(strlen(NGAY2)==0){
					CleanMessageBox(970,680);
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,680);
				 	outtextxy(970,680,"NGAY:");
				 	BaoLoi1(970 + 60,675);
				 	okNGAY2=false; 
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				else {
					TempNgay2 = CharToInt(NGAY2);
					if(TempThang2 == 1 || TempThang2 == 3 || TempThang2 == 5 || TempThang2 == 7 || TempThang2 == 8 || TempThang2 == 10 || TempThang2 == 12){
						if(TempNgay2 >=1 && TempNgay2 <= 31){
							setbkcolor(3);
						 	setcolor(0);
							settextstyle(3,0,1);
							CleanMessageBox(970,680);
					 		outtextxy(970,680,"NGAY:");
					 		HopLe1(970 + 60,675);
					 		okNGAY2=true; 
							taoID(750,697,800,727,204); //GIO ON 
							if(SearchNode(pheadDSCB,ID2)!=NULL){
							NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
								if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
									taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
								} 
								if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
									if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
										taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
										taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
										taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
									}
								}
							}
						}
						else{
						 	setbkcolor(3);
						 	setcolor(0);
							settextstyle(3,0,1);
							CleanMessageBox(970,680);
					 		outtextxy(970,680,"NGAY:");
					 		KhongHopLe1(970 + 60,675);
					 		okNGAY2=false; 
					 		taoButton(965,780,1040,830,0,7,8,3,"NEW");

							taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
		
							taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
			 			}
					}	
					else if(TempThang2 == 4 || TempThang2 == 6 || TempThang2 == 9 || TempThang2 == 11){
						if(TempNgay2 >=1 && TempNgay2 <= 30){
							setbkcolor(3);
						 	setcolor(0);
							settextstyle(3,0,1);
							CleanMessageBox(970,680);
					 		outtextxy(970,680,"NGAY:");
					 		HopLe1(970 + 60,675);
					 		okNGAY2=true; 
							taoID(750,697,800,727,204); //GIO ON 
							if(SearchNode(pheadDSCB,ID2)!=NULL){
							NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
								if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
									taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
								} 
								if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
									if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
										taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
										taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
										taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
									}
								}
							}
						}
						else{
						 	setbkcolor(3);
						 	setcolor(0);
							settextstyle(3,0,1);
							CleanMessageBox(970,680);
					 		outtextxy(970,680,"NGAY:");
					 		KhongHopLe1(970 + 60,675);
					 		okNGAY2=false; 
					 		taoButton(965,780,1040,830,0,7,8,3,"NEW");
	
							taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
		
							taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
			 			}
			 		}
					else if(TempThang2 == 2){
						if(NamNhuan2 == true){
							if(TempNgay2 >=1 && TempNgay2 <= 29){
								setbkcolor(3);
							 	setcolor(0);
								settextstyle(3,0,1);
								CleanMessageBox(970,680);
						 		outtextxy(970,680,"NGAY:");
						 		HopLe1(970 + 60,675);
						 		okNGAY2=true;
								taoID(750,697,800,727,204); //GIO ON 
								if(SearchNode(pheadDSCB,ID2)!=NULL){
								NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
									if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
										taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
										taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
										taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
									} 
									if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
										if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
											taoButton(965,780,1040,830,0,7,8,3,"NEW");
				
											taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
						
											taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
										}
									}
								}
							}	
							else{
							 	setbkcolor(3);
							 	setcolor(0);
								settextstyle(3,0,1);
								CleanMessageBox(970,680);
						 		outtextxy(970,680,"NGAY:");
						 		KhongHopLe1(970 + 60,675);
						 		okNGAY2=false; 
						 		taoButton(965,780,1040,830,0,7,8,3,"NEW");

					         	taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
						        taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
			 				}
						}
						else{
							if(TempNgay2 >=1 && TempNgay2 <= 28){
								setbkcolor(3);
							 	setcolor(0);
								settextstyle(3,0,1);
								CleanMessageBox(970,680);
						 		outtextxy(970,680,"NGAY:");
						 		HopLe1(970 + 60,675);
						 		okNGAY2=true;
								taoID(750,697,800,727,204); //GIO ON 
								if(SearchNode(pheadDSCB,ID2)!=NULL){
								NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
									if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
										taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
										taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
										taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
									} 
									if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
										if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
											taoButton(965,780,1040,830,0,7,8,3,"NEW");
				
											taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
						
											taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
										}
									}
								}
							}
							else{
							 	setbkcolor(3);
							 	setcolor(0);
								settextstyle(3,0,1);
								CleanMessageBox(970,680);
						 		outtextxy(970,680,"NGAY:");
						 		KhongHopLe1(970 + 60,675);
						 		okNGAY2=false; 				 		
								taoButton(965,780,1040,830,0,7,8,3,"NEW");

								taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
			
								taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
			 				}	
						}
					}
				}
				x=-1;y=-1;
				break;
			}
			case 204:{ //GIO
				taoID(660,697,710,727,0); // NGAY OFF
				ScanSo(750+5,697+5,GIO2,2,15);
				if(strlen(GIO2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,680);
				 	outtextxy(970,680,"GIO:");
				 	BaoLoi1(970 + 40,675);
				 	okGIO2=false; 
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				else{
					TempGio2 = CharToInt(GIO2);
					if(TempGio2 <= 23 && TempGio2 >= 0){
						setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"GIO:");
				 		HopLe1(970 + 40,675);
				 		okGIO2=true;					 	
						taoID(860,697,925,727,205);	//PHUT ON
						if(SearchNode(pheadDSCB,ID2)!=NULL){
						NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
							if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
								taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
							} 
							if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
								if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
									taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
								}
							}
						}
					}
					else if(TempGio2 == 24){
						setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"GIO:");
				 		HopLe1(970 + 40,675);
				 		okGIO2=true;					 	
						taoID(860,697,925,727,205);	//PHUT ON
						strcpy(GIO2,"0");
						TempGio2 = CharToInt(GIO2);
						taoO(750,697,800,727,15,0,204);
						OUTTEXT(750+5,697+5,15,0,6,1,GIO2);
						if(SearchNode(pheadDSCB,ID2)!=NULL){
						NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
							if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
								taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
							} 
							if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
								if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
									taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
								}
							}
						}
					}
					else{
					 	setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"GIO:");
				 		KhongHopLe1(970 + 40,675);
				 		okGIO2=false;
						taoButton(965,780,1040,830,0,7,8,3,"NEW");

						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");					 	
						}
					}
				x=-1;y=-1;
				break;
			}
			case 205:{ //PHUT
				taoID(750,697,800,727,0);// GIO OFF
				ScanSo(860+5,697+5,PHUT2,2,15);					
				if(strlen(PHUT2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,680);
				 	outtextxy(970,680,"PHUT:");
				 	BaoLoi1(970 + 60,675);
				 	okPHUT2=false; 
				 	taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}	
				else {
					TempPhut2 = CharToInt(PHUT2);
					if(TempPhut2 >= 0 && TempPhut2 < 60){
						setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"PHUT:");
				 		HopLe1(970 + 60,675);
				 		okPHUT2=true;	
				 		taoID(458,742,925,772,23); // NOI TOI ON
				 		if(SearchNode(pheadDSCB,ID2)!=NULL){
							NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
							if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
								taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
								taoID(458,742,925,772,0); // KO EDIT NHUNG THONG TIN CON LAI 
							} 
							if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
								if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
									taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
									taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
									taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
									taoID(458,742,925,772,0); // KO EDIT NHUNG THONG TIN CON LAI 
								}
							}
						}
					}
					else{
					 	setbkcolor(3);
					 	setcolor(0);
						settextstyle(3,0,1);
						CleanMessageBox(970,680);
				 		outtextxy(970,680,"PHUT:");
				 		KhongHopLe1(970 + 60,675);
				 		okPHUT2=false;
				 		taoButton(965,780,1040,830,0,7,8,3,"NEW");

						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
				}
				x=-1;y=-1;
				break;
			}
//====================================================================================
			case 23:{ // NOI TOI 
				taoID(860,697,925,727,0);// PHUT OFF	
				ScanTen(458+5,742+5,TOI2,10,15);
				if(strlen(TOI2)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
			 		outtextxy(970,710,"NOI TOI: ");
			 		BaoLoi1(970 + 80,705);
			 		okTOI2=false; 
			 		taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");		
					}
				else{
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
					outtextxy(970,710,"NOI TOI: ");
					HopLe1(970 + 80,705);
					okTOI2=true; 
					taoID(458,787,820,817,24); // ID MAY BAY ON
					if(SearchNode(pheadDSCB,ID2)!=NULL){
						NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
						if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
							taoButton(965,780,1040,830,0,7,8,3,"NEW");
		
							taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
				
							taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
						} 
						if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
							
							if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
								taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
							}
						}
					}
				} 
				x=-1;y=-1;
				break;
			}
			case 24:{ // ID MAY BAY 
				taoID(458,742,925,817,0);// NOI TOI OFF
				ScanMa(458+5,787+5,IDMAYBAY2,10,15);
				if(strlen(IDMAYBAY2)==0){
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,740,"ID: ");
					BaoLoi1(970 + 25,735);
					okIDMAYBAY2=false;	
					taoID(458,787,820,817,24);
					taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				}
				else if(SearchIdMb(dsmb,IDMAYBAY2)!=-1){
					sotam1 = SearchIdMb(dsmb,IDMAYBAY2);
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,740,"ID: ");
					TonTai1(970 + 25,735);
					okIDMAYBAY2=true;
					if(SearchNode(pheadDSCB,ID2)!=NULL){
						NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID2);
						if(okID2 == false && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
							taoButton(965,780,1040,830,0,7,8,3,"NEW");
			
							taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
					
							taoButton(1145,780,1265,830,2004,7,0,3,"REMOVE");
						} 
						if(ptr->data.DepartTime.day != TempNgay2 || ptr->data.DepartTime.mon != TempThang2 || ptr->data.DepartTime.year != TempNam2 || ptr->data.DepartTime.hour != TempGio2 || ptr->data.DepartTime.min != TempPhut2){
							
							if(okID2 == false && okTOI2 == true && okIDMAYBAY2 == true){
								taoButton(965,780,1040,830,0,7,8,3,"NEW");
				
								taoButton(1050,780,1135,830,2003,7,0,3,"SAVE");
						
								taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
							}
						}
					}
					if(okID2 == true && okNAM2 == true && okTHANG2 == true && okNGAY2 == true && okGIO2 == true && okPHUT2 == true && okTOI2 == true && okIDMAYBAY2 == true){
						taoButton(965,780,1040,830,2002,7,0,3,"NEW");
	
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
		
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					}
					taoID(458,787,820,817,24); 
				}
				else{
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,740,"ID: ");
					KhongTonTai1(970 + 25,735);
					okIDMAYBAY2=false;
					taoID(458,787,820,817,24); 
					taoButton(965,780,1040,830,0,7,8,3,"NEW");

					taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
					taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				}
				x=-1;y=-1;
				break;
			}
			case 2001:{ // HUY THONG TIN 
		
				strcpy(ID2,"");
				strcpy(NGAY2,"");
				strcpy(THANG2,"");
				strcpy(NAM2,"");
				strcpy(GIO2,"");
				strcpy(PHUT2,"");
				
				strcpy(TOI2,"");
				strcpy(IDMAYBAY2,"");	
				strcpy(TRANGTHAI2,"");
				TempNgay2 = 0;
				TempThang2 = 0;
				TempNam2= 0;
				TempGio2 = 0;
				TempPhut2 = 0;
				TempTT = 0;
				okID2 = false;
				okNGAY2 = false;
				okTHANG2 = false;
				okNAM2 = false;
				okGIO2 = false;
				okPHUT2 = false;
				NamNhuan2 = false;
				okTOI2 = false;
				okIDMAYBAY2 = false;
				
				taoO(458,650,925,680,7,0,21);

				taoO(395,697,475,727,7,0,0);
				taoO(550,697,600,727,7,0,0);
				taoO(660,697,710,727,7,0,0);
				taoO(750,697,800,727,7,0,0);
				taoO(860,697,925,727,7,0,0);
				
				taoO(458,742,925,772,7,0,0);
				taoO(458,787,820,817,7,0,0);
				taoO(860,787,925,817,7,0,0);
				
				taoButton(335+200,600,335+200+40,640,2001,4,0,3,"X");
				
				taoButton(965,780,1040,830,0,7,8,3,"NEW");

				taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
	
				taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				//CLEAN
				taoO(965,640,1265,770,3,0,0);
				setbkcolor(3);
   				settextstyle(3,0,1);
   				outtextxy(1060,625,"MessageBox");
   			
				x=-1;y=-1;
				break;
			}
			case 2002:{ // ADD_CHUYENBAY
			    	Date temp;
			    	temp.year = TempNam2;
			   		temp.mon = TempThang2;
			   		temp.day = TempNgay2;
			   		temp.hour = TempGio2;
			   		temp.min = TempPhut2;
			    	if(CheckDepartTime(temp)==true){
						if(check_decent_chuyen_bay(pheadDSCB,IDMAYBAY2,temp)==true){   			
						//	remove("ChuyenBay.txt");
							AddNewChuyenBay(pheadDSCB,ID2,TempNgay2,TempThang2,TempNam2,TempGio2,TempPhut2,TOI2,IDMAYBAY2,TempTT);
							SortCB_Time(pheadDSCB);
							UpdateCB(pheadDSCB);
							FileOutCB(CBO,pheadDSCB);
							FileOutMBV2(MBO,dsmb);
							//CLEAR DU LIEU CU
							strcpy(ID2,"");
							strcpy(NGAY2,"");
							strcpy(THANG2,"");
							strcpy(NAM2,"");
							strcpy(GIO2,"");
							strcpy(PHUT2,"");
							strcpy(TOI2,"");
							strcpy(IDMAYBAY2,"");	
							strcpy(TRANGTHAI2,"");
							
							TempNgay2 = 0;
							TempThang2 = 0;
							TempNam2= 0;
							TempGio2 = 0;
							TempPhut2 = 0;
							TempTT = 0;
							
							okID2 = false;
							okNGAY2 = false;
							okTHANG2 = false;
							okNAM2 = false;
							okGIO2 = false;
							okPHUT2 = false;
							NamNhuan2 = false;
							okTOI2 = false;
							okIDMAYBAY2 = false;
							//VE LAI MAN 
							taoO(458,650,925,680,7,0,21);

							taoO(395,697,475,727,7,0,0);
							taoO(550,697,600,727,7,0,0);
							taoO(660,697,710,727,7,0,0);
							taoO(750,697,800,727,7,0,0);
							taoO(860,697,925,727,7,0,0);
							
							taoO(458,742,925,772,7,0,0);
							taoO(458,787,820,817,7,0,0);
							taoO(860,787,925,817,7,0,0);
							
							//OUTPUT LEN MAN HINH
							NodeChuyenBay* ptr = pheadDSCB;
					//		ptr = pheadDSCB;

							FileOutVe(VEO,pheadDSCB);
							tempTOTALCB = CountTotalChuyenBay(pheadDSCB);
							trang2 = 1;
							tongtrang2 = tempTOTALCB/9;
							if (tempTOTALCB%9 != 0)	tongtrang2 +=1;
							IntToChar(tongtrang2,charTongTrang2);
							IntToChar(trang2,charTrang2);
							OUTTEXT(730,585,3,1,3,3,charTrang2);
							OUTTEXT1(760,585,3,0,3,3);
							OUTTEXT(790,585,3,0,3,3,charTongTrang2);
					     	char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
							int m[5] = {180,250,150,200,120};
					     	taoBang(335,10,55,m,5,10,text,15,0);
							int xx = 335; int yy = 65;
							int i = 0; 	
							while(ptr != NULL)
							{
								if(i<9 && i < tempTOTALCB){
								   	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
								 
								   	char day[50]= "";
								   	char mon[50]= "";
								   	char year[50]= "";
								   	char hour[50]= "";
								   	char min[50]= "";
								   	IntToChar(ptr->data.DepartTime.day,day);
								   	IntToChar(ptr->data.DepartTime.mon,mon);
								    IntToChar(ptr->data.DepartTime.year,year);
								   	IntToChar(ptr->data.DepartTime.hour,hour);
								   	IntToChar(ptr->data.DepartTime.min,min);
									OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
							    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
							    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
							    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
							    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
							    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
							    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
								    OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
													
								    OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
								    OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
								   	char TT[50] = "";
								   	IntToChar(ptr->data.Status,TT);
								   	OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,TT);
								   	yy +=55;
								   	i++;
								}
								ptr = ptr->next;  
							}
							if(trang2==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
							else taoID(405,575,455,625,20001);
							if(tongtrang2>1) taoID(1130,575,1180,625,20002); // TAO ID NUT NEXT
							if(trang2==tongtrang2) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 	
						}
						taoButton(965,780,1040,830,2002,15,1,3,"NEW");
						delay(50);
				    	taoButton(965,780,1040,830,0,7,8,3,"NEW");
						MessageBox("Da Them Thanh Cong",14);
						delay(400);
						MessageBox("",0);
				
					}		
					else{
						taoO(458,787,820,817,7,0,0);
						MessageBox("Khong The Them",4);
						outtextxy(980,650,"NHO HON GIO HE THONG");
						taoID(458,650,925,680,0);

						taoID(395,697,475,727,0);
						taoID(550,697,600,727,0);
						taoID(660,697,710,727,0);
						taoID(750,697,800,727,0);
						taoID(860,697,925,727,0);
							
						taoID(458,742,925,772,0);
						taoID(458,787,820,817,0);
						taoID(860,787,925,817,0);
						taoButton(965,780,1040,830,2002,15,1,3,"NEW");
						delay(50);
				    	taoButton(965,780,1040,830,0,7,8,3,"NEW");	
					}
				x=-1;y=-1;
				break;
			}
			case 2003:{ //EDIT_CHUYENBAY
					Date temp;
			    	temp.year = TempNam2;
			    	temp.mon = TempThang2;
			    	temp.day = TempNgay2;
			    	temp.hour = TempGio2;
			    	temp.min = TempPhut2;
			    	NodeChuyenBay *Edit = pheadDSCB;
		// new	    	Edit = pheadDSCB;
			    	while(Edit != NULL)
			    	{
			    		if(strcmp(Edit->data.MaCB,ID2)==0)break;
			    		else Edit = Edit->next;
					}
			    	if(CheckDepartTime(temp)==true){
						if(check_decent_chuyen_bay_version_2(pheadDSCB,Edit,IDMAYBAY2,temp)==true){ 
							EditChuyenBay(pheadDSCB,Edit,ID2,TempNgay2,TempThang2,TempNam2,TempGio2,TempPhut2);
							FileOutCB(CBO,pheadDSCB);
							//CLEAR DU LIEU CU
							strcpy(ID2,"");
							strcpy(NGAY2,"");
							strcpy(THANG2,"");
							strcpy(NAM2,"");
							strcpy(GIO2,"");
							strcpy(PHUT2,"");
							strcpy(TOI2,"");
							strcpy(IDMAYBAY2,"");	
							strcpy(TRANGTHAI2,"");
							
							TempNgay2 = 0;
							TempThang2 = 0;
							TempNam2= 0;
							TempGio2 = 0;
							TempPhut2 = 0;
							TempTT = 0;
							
							okID2 = false;
							okNGAY2 = false;
							okTHANG2 = false;
							okNAM2 = false;
							okGIO2 = false;
							okPHUT2 = false;
							NamNhuan2 = false;
							okTOI2 = false;
							okIDMAYBAY2 = false;
							//VE LAI MAN 
							taoO(458,650,925,680,7,0,21);

							taoO(395,697,475,727,7,0,0);
							taoO(550,697,600,727,7,0,0);
							taoO(660,697,710,727,7,0,0);
							taoO(750,697,800,727,7,0,0);
							taoO(860,697,925,727,7,0,0);
							
							taoO(458,742,925,772,7,0,0);
							taoO(458,787,820,817,7,0,0);
							taoO(860,787,925,817,7,0,0);
							//===============
							NodeChuyenBay* ptr = pheadDSCB;
					// new		ptr = pheadDSCB;
							SortCB_Time(pheadDSCB);
							UpdateCB(pheadDSCB);
							FileOutVe(VEO,pheadDSCB);
							tempTOTALCB = CountTotalChuyenBay(pheadDSCB);
							trang2 = 1;
							tongtrang2 = tempTOTALCB/9;
							if (tempTOTALCB%9 != 0)	tongtrang2 +=1;
							IntToChar(tongtrang2,charTongTrang2);
							IntToChar(trang2,charTrang2);
							OUTTEXT(730,585,3,1,3,3,charTrang2);
							OUTTEXT1(760,585,3,0,3,3);
							OUTTEXT(790,585,3,0,3,3,charTongTrang2);
							char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
							int m[5] = {180,250,150,200,120};
							taoBang(335,10,55,m,5,10,text,15,0);
							int xx = 335; int yy = 65;
							int i = 0; 	
							while(ptr != NULL)
							{
								if(i<9 && i < tempTOTALCB){
								    OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
								 
								   	char day[50]= "";
								    char mon[50]= "";
								    char year[50]= "";
								   	char hour[50]= "";
								    char min[50]= "";
								    IntToChar(ptr->data.DepartTime.day,day);
								    IntToChar(ptr->data.DepartTime.mon,mon);
								    IntToChar(ptr->data.DepartTime.year,year);
								    IntToChar(ptr->data.DepartTime.hour,hour);
								    IntToChar(ptr->data.DepartTime.min,min);
									OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
								    OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
								    OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
								    OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
								    OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
								    OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
								    OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
								    OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
											
								    OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
								    OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
								    char TT[50] = "";
								    IntToChar(ptr->data.Status,TT);
								    OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,TT);
								    yy +=55;
									i++;
								}
						 		ptr = ptr->next;  
							}
						if(trang2==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
						else taoID(405,575,455,625,20001);
						if(tongtrang2>1) taoID(1130,575,1180,625,20002); // TAO ID NUT NEXT
						if(trang2==tongtrang2) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 	
						}
						taoButton(1050,780,1135,830,2003,15,1,3,"SAVE");
						delay(50);
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
						MessageBox("Da Sua Thanh Cong",14);
						delay(400);
						MessageBox("",0);
					}
					else{
						taoButton(1050,780,1135,830,2003,15,1,3,"SAVE");
						delay(50);
						taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
						MessageBox("Khong The Sua",4);
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
					break;
			}
			case 2004:{ // XOA_CHUYENBAY
					NodeChuyenBay *ptr = SearchNode(pheadDSCB,ID2);
					if(ptr->data.Status == 1 || ptr->data.Status == 2)
					{
					//	remove("ChuyenBay.txt");
						DelChuyenBay(ptr,dsmb);
						strcpy(ID2,"");
						strcpy(NGAY2,"");
						strcpy(THANG2,"");
						strcpy(NAM2,"");
						strcpy(GIO2,"");
						strcpy(PHUT2,"");
						strcpy(TOI2,"");
						strcpy(IDMAYBAY2,"");
						strcpy(TRANGTHAI2,"");	
												
						NodeChuyenBay* ptr = pheadDSCB;
						ptr = pheadDSCB;
				
						SortCB_Time(pheadDSCB);
						UpdateCB(pheadDSCB);
						FileOutCB(CBO,pheadDSCB);
						FileOutVe(VEO,pheadDSCB);
						
						tempTOTALCB = CountTotalChuyenBay(pheadDSCB);
						trang2 = 1;
						tongtrang2 = tempTOTALCB/9;
						if (tempTOTALCB%9 != 0)	tongtrang2 +=1;
						IntToChar(tongtrang2,charTongTrang2);
						IntToChar(trang2,charTrang2);
						OUTTEXT(730,585,3,1,3,3,charTrang2);
						OUTTEXT1(760,585,3,0,3,3);
						OUTTEXT(790,585,3,0,3,3,charTongTrang2);
						char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
						int m[5] = {180,250,150,200,120};
						taoBang(335,10,55,m,5,10,text,15,0);
						int xx = 335; int yy = 65;
						int i = 0; 	
						while(ptr != NULL)
						{
							if(i<9 && i < tempTOTALCB){
						    	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
						 
						    	char day[50]= "";
						    	char mon[50]= "";
						    	char year[50]= "";
						    	char hour[50]= "";
						    	char min[50]= "";
						    	IntToChar(ptr->data.DepartTime.day,day);
						    	IntToChar(ptr->data.DepartTime.mon,mon);
						    	IntToChar(ptr->data.DepartTime.year,year);
						    	IntToChar(ptr->data.DepartTime.hour,hour);
						    	IntToChar(ptr->data.DepartTime.min,min);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
						    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
						    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
						    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
						    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
						    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
						    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
						    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
											
						    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
						    	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
						    	char TT[50] = "";
						    	IntToChar(ptr->data.Status,TT);
						    	OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,TT);
						    	yy +=55;
						    	i++;
						    }
						   	ptr = ptr->next;  
						}
						if(trang2==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
						else taoID(405,575,455,625,20001);
						if(tongtrang2>1) taoID(1130,575,1180,625,20002); // TAO ID NUT NEXT
						if(trang2==tongtrang2) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
						taoButton(1145,780,1265,830,2004,15,1,3,"REMOVE");
				     	delay(50);
					    taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					    taoButton(1050,780,1135,830,0,7,8,3,"SAVE");	
						MessageBox("Da Xoa Thanh Cong",14);
						delay(50);
						MessageBox("",0);
						
						
					}
					else{
						taoButton(1145,780,1265,830,2004,15,1,3,"REMOVE");
				     	delay(50);
					    taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
					    taoButton(1050,780,1135,830,0,7,8,3,"SAVE");
						MessageBox("Khong The Xoa",4);
						
						delay(400);
						MessageBox("",0);
					}
					x=-1;y=-1;
				break;
			}
			case 20001:{ //NUT BACK
				  	NodeChuyenBay* ptr = pheadDSCB;
				// new	ptr = pheadDSCB;
					SortCB_Time(pheadDSCB);
					UpdateCB(pheadDSCB);
					FileOutVe(VEO,pheadDSCB);
					tempTOTALCB = CountTotalChuyenBay(pheadDSCB);
				  	trang2 -=1;
					tongtrang2 = tempTOTALCB/9;
					if (tempTOTALCB%9 != 0)	tongtrang2 +=1;
					IntToChar(tongtrang2,charTongTrang2);
					IntToChar(trang2,charTrang2);
					OUTTEXT(730,585,3,1,3,3,charTrang2);
					OUTTEXT1(760,585,3,0,3,3);
					OUTTEXT(790,585,3,0,3,3,charTongTrang2);
					int m[5] = {180,250,150,200,120};
					char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
				   	taoBang(335,10,55,m,5,10,text,15,0);
					int xx = 335; int yy = 65;
					int i = 0;
					int j = 9*(trang2-1); 	
					while(ptr != NULL)
					{
						if((i-j)<9 && i>=j &&  +i < tempTOTALCB){
					    	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
					 
					    	char day[50]= "";
					    	char mon[50]= "";
					    	char year[50]= "";
					    	char hour[50]= "";
					    	char min[50]= "";
					    	IntToChar(ptr->data.DepartTime.day,day);
					    	IntToChar(ptr->data.DepartTime.mon,mon);
					    	IntToChar(ptr->data.DepartTime.year,year);
					    	IntToChar(ptr->data.DepartTime.hour,hour);
					    	IntToChar(ptr->data.DepartTime.min,min);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
					    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
					    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
					    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
					    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
					    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
					    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
					    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
										
					    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
					    	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
					    	char TT[50] = "";
					    	IntToChar(ptr->data.Status,TT);
					    	OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,TT);
					    	yy +=55;
					    }
					    i++;
					   	ptr = ptr->next;  
					}
					taoButton(405,575,455,625,20001,15,1,2,"<");
				  	delay(50);
				  	taoButton(405,575,455,625,20001,7,0,2,"<");
					if(trang2==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
					else taoID(405,575,455,625,20001);
					if(tongtrang2>1) taoID(1130,575,1180,625,20002); // TAO ID NUT NEXT
					if(trang2==tongtrang2) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 	

				  	x=-1;y=-1;
				break;
			}
			case 20002:{ // NUT NEXT
				  	NodeChuyenBay* ptr = pheadDSCB;
					//ptr = pheadDSCB;
					SortCB_Time(pheadDSCB);
					UpdateCB(pheadDSCB);
					FileOutVe(VEO,pheadDSCB);
					tempTOTALCB = CountTotalChuyenBay(pheadDSCB);
					if (trang2 + 1 > tongtrang2) break;
				  	trang2 +=1;
					tongtrang2 = tempTOTALCB/9;
					if (tempTOTALCB%9 != 0)	tongtrang2 +=1;
					IntToChar(tongtrang2,charTongTrang2);
					IntToChar(trang2,charTrang2);
					OUTTEXT(730,585,3,1,3,3,charTrang2);
					OUTTEXT1(760,585,3,0,3,3);
					OUTTEXT(790,585,3,0,3,3,charTongTrang2);
					int m[5] = {180,250,150,200,120};
					char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","ID May Bay","Trang Thai"};
				   	taoBang(335,10,55,m,5,10,text,15,0);
					int xx = 335; int yy = 65;
					int i = 0;
					int j = 9*(trang2-1); 	
					while(ptr != NULL)
					{
						if((i-j)<9 && i>=j &&  i < tempTOTALCB){
					    	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
					 
					    	char day[50]= "";
					    	char mon[50]= "";
					    	char year[50]= "";
					    	char hour[50]= "";
					    	char min[50]= "";
					    	IntToChar(ptr->data.DepartTime.day,day);
					    	IntToChar(ptr->data.DepartTime.mon,mon);
					    	IntToChar(ptr->data.DepartTime.year,year);
					    	IntToChar(ptr->data.DepartTime.hour,hour);
					    	IntToChar(ptr->data.DepartTime.min,min);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
					    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
					    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
					    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
					    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
					    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
					    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
					    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
										
					    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
					    	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,ptr->data.ID);
					    	char TT[50] = "";
					    	IntToChar(ptr->data.Status,TT);
					    	OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,TT);
					    	yy +=55;
					    }
					    i++;
					   	ptr = ptr->next;  
					}
					taoButton(1130,575,1180,625,20002,15,1,2," >");
				  	delay(50);
				  	taoButton(1130,575,1180,625,20002,7,0,2," >");
					if(trang2==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
					else taoID(405,575,455,625,20001);
					if(tongtrang2>1) taoID(1130,575,1180,625,20002); // TAO ID NUT NEXT
					if(trang2==tongtrang2) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 	
					
				  	x=-1;y=-1;
				break;
			}		
			case 3:{ // MAN HINH 3 - QUAN LY HANH KHACH
				Menu();
				QuanLyHanhKhach();
				trang3 = 1;
				tongtrang3 = CountTotalHK/9;
				if (CountTotalHK%9 != 0){
			   		tongtrang3 +=1;
				}
				IntToChar(tongtrang3,charTongTrang3);
				IntToChar(trang3,charTrang3);
				OUTTEXT(730,585,3,1,3,3,charTrang3);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang3);
				int m[4] = {200,260,250,200};
				int xx = 335;int yy = 65;
			   	//cout<<"   "<<CountTotalHK<<"    ";
			   	HanhKhach *array = new HanhKhach[CountTotalHK];
			   	LNR(root,array);
			   	
			   	for(int i=0; i< 9 && i< CountTotalHK; i++)
			   	{
			  	   	OUTTEXT(xx+12,yy+15,15,0,3,3,array[i].CCCD);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,array[i].HO);
					OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,array[i].TEN);
					OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,array[i].GioiTinh);
			  		yy += 55;
				}
				indexHK =0;
			    delete [] array;
			    if(trang3==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
			  	else taoID(405,575,455,625,30001);
				if(tongtrang3>1) taoID(1130,575,1180,625,30002); // TAO ID NUT NEXT		  	
				if(trang3==tongtrang3) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
				x=-1,y=-1;
				break;
			}
			case 31:{ // CCCD
			   	taoO(450,650,925,680,15,0,31);
			   	
				taoO(450,717,640,747,7,0,0);	
				taoO(735,717,925,747,7,0,0);
				
				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				
				taoButton(335+200,600,335+200+40,640,3001,4,0,3,"X");
				nodehk check;
				ScanSoCCCD(450+5,650+5,CCCD3,9,15);
				check = SearchHk(root,CCCD3);
				if(strlen(CCCD3)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,650,"CCCD: ");
				 	BaoLoi1(970 + 60,645);
				 	okCCCD3=false; 
					 }
				//IF SEARCH CCCD FUNCTION.
				else if(check != NULL){
					
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"CCCD: ");
				 		TonTai1(970 + 60,645);
						okCCCD3=false;
						okHO3=true;
						okTEN3=true;
						okGIOITINH3=true;
						strcpy(CCCD3,check->data.CCCD);
						strcpy(HO3,check->data.HO);
						strcpy(TEN3,check->data.TEN);
						strcpy(GIOITINH3,check->data.GioiTinh);
						taoO(450,650,925,680,15,0,31);
						
						taoO(450,717,640,747,15,0,0);	
			   	        taoO(735,717,925,747,15,0,0);
				
						taoO(500,787,600,817,7,0,0);
						OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				
						taoO(775,787,875,817,7,0,0);
						OUTTEXT(775+35,787+5,7,8,3,1,"NU");
						
						taoButton(1145,780,1265,830,3003,7,0,3,"REMOVE");
						OUTTEXT(450+5,650+5,15,4,6,1,CCCD3);
					 	OUTTEXT(450+5,717+5,15,0,6,1,HO3);
						OUTTEXT(735+5,717+5,15,0,6,1,TEN3);			
					 	if(strcmp(GIOITINH3,"Nam")==0){
							taoO(500,787,600,817,1,0,0);        //NAM ON
							OUTTEXT(500+25,787+5,1,15,3,1,"NAM");
							taoO(775,787,875,817,7,0,0);
							OUTTEXT(775+35,787+5,7,8,3,1,"NU");
						}
						else{
							taoO(500,787,600,817,7,0,0);        //NU ON
							OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
							taoO(775,787,875,817,4,0,0);
							OUTTEXT(775+35,787+5,4,15,3,1,"NU");
						 }
						taoID(450,650,925,680,0);
				 		taoID(450,717,925,747,0);  
					}
				else if(strcmp(CCCD3,"000000000")==0){
					setbkcolor(3);
					setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,650,"CCCD:");
					KhongHopLe1(970 + 60,645);
				 	okCCCD3=false; 
				}
				else if(strlen(CCCD3)==9){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,650,"CCCD: ");
				 	HopLe1(970 + 60,645);
				 	okCCCD3=true;
				 	taoO(450,717,640,747,15,0,32); //HO TEN ON 
					}
				else{
					setbkcolor(3);
					setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,650,"CCCD:");
					KhongHopLe1(970 + 60,645);
				 	okCCCD3=false; 
				}
				x=-1;y=-1;
				break;
			}
			case 32:{ //HO VA TEN
				taoID(450,650,925,680,0);//CCCD OFF
				ScanHo(450+5,717+5,HO3,10,15);
				if(strlen(HO3)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,675);
				 	outtextxy(970,680,"HO: ");
				 	BaoLoi1(970 + 40,675);
				 	okHO3=false; 
				 		
				}
				else {
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,675);
				 	outtextxy(970,680,"HO: ");
				 	HopLe1(970 + 40,675);
					okHO3=true; 
					taoO(735,717,925,747,15,0,32);
				 	ScanTen(735+5,717+5,TEN3,13,15);
				 	if(strlen(TEN3)==0){
					 	setbkcolor(3);
					 	setcolor(0);
					 	settextstyle(3,0,1);
					 	CleanMessageBox(970,675);
					 	outtextxy(970,680,"TEN: ");
					 	BaoLoi1(970 + 60,675);
					 	okTEN3=false; 
				 	}
				 	else{
				 		setbkcolor(3);
					 	setcolor(0);
					 	settextstyle(3,0,1);
					 	CleanMessageBox(970,675);
					 	outtextxy(970,680,"TEN: ");
					 	HopLe1(970 + 60,675);
						okTEN3=true; 
						taoO(500,787,600,817,9,0,33);        //GIOI TINH ON
				     	OUTTEXT(500+25,787+5,9,0,3,1,"NAM");
				
				 	    taoO(775,787,875,817,12,0,34);
					    OUTTEXT(775+35,787+5,12,0,3,1,"NU");
					}
				}
				x=-1;y=-1;
				break;
			}
			case 33:{ // GIOI TINH NAM 
				taoID(450,717,640,747,0);	
			   	taoID(735,717,925,747,0);
				taoO(500,787,600,817,1,0,33);        //NAM ON
				OUTTEXT(500+25,787+5,1,15,3,1,"NAM");
				taoO(775,787,875,817,7,0,34);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				strcpy(GIOITINH3,"Nam");
				okGIOITINH3 = true;
				setbkcolor(3);
			 	setcolor(0);
			 	settextstyle(3,0,1);
			 	outtextxy(970,710,"Phai:");
			 	GioiTinh1(970 + 50,705,strcmp(GIOITINH3,"Nam"));
				taoButton(965,780,1040,830,3002,7,0,3,"NEW");
				x=-1;y=-1;
				break;
			}
			case 34:{ // GIOI TINH NU 
				taoID(450,717,640,747,0);	// HO TEN OFF
			   	taoID(735,717,925,747,0); 
				taoO(500,787,600,817,7,0,33);        //NU ON
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				taoO(775,787,875,817,4,0,34);
				OUTTEXT(775+35,787+5,4,15,3,1,"NU");
				strcpy(GIOITINH3,"Nu");
				okGIOITINH3 = true;
				setbkcolor(3);
			 	setcolor(0);
			 	settextstyle(3,0,1);
			 	outtextxy(970,710,"Phai:");
			 	GioiTinh1(970 + 50,705,strcmp(GIOITINH3,"Nam"));
			 	taoButton(965,780,1040,830,3002,7,0,3,"NEW");
				x=-1;y=-1;
				break;
			}
			case 3001:{ // Huy thong tin
					strcpy(CCCD3,"");
					strcpy(HO3,"");
					strcpy(TEN3,"");
					strcpy(GIOITINH3,"");	
					okCCCD3 = false;
					okHO3 = false;
					okTEN3 = false;
					okGIOITINH3 = false;
					
				 	taoO(965,640,1265,770,3,0,0);
				 	setbkcolor(3);
   					settextstyle(3,0,1);
   					outtextxy(1060,625,"MessageBox");
   					
   					taoO(450,650,925,680,7,0,31);
			
					taoO(450,717,640,747,7,0,0);
					taoO(735,717,925,747,7,0,0);
					
					taoO(500,787,600,817,7,0,0);
					OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					
					taoO(775,787,875,817,7,0,0);
					OUTTEXT(775+35,787+5,7,8,3,1,"NU");
					x=-1;y=-1;
					break;
				}
			
			case 3002:{ // THEM VAO
					taoButton(965,780,1040,830,3002,15,1,3,"NEW");
					delay(50);
					taoButton(965,780,1040,830,0,7,8,3,"NEW");	
					if(okCCCD3 == true && okHO3 == true && okTEN3 == true && okGIOITINH3 == true){
                        HanhKhach data;
                        strcpy(data.CCCD,CCCD3);
					    strcpy(data.HO,HO3);
					    strcpy(data.TEN,TEN3);
					    strcpy(data.GioiTinh,GIOITINH3);
					 //   remove("HanhKhach.txt");
                        InsertNodehk(root,data);
                   //	 	NLR_FileOutHK(HKT,root);
						strcpy(CCCD3,"");
						strcpy(HO3,"");
						strcpy(TEN3,"");
						strcpy(GIOITINH3,"");	
						okCCCD3 = false;
						okHO3 = false;
						okTEN3 = false;
						okGIOITINH3 = false;
						
						taoO(965,640,1265,770,3,0,0);
					 	setbkcolor(3);
	   					settextstyle(3,0,1);
	   					outtextxy(1060,625,"MessageBox");
	   					
	   					taoO(450,650,925,680,7,0,31);
						taoO(450,717,640,747,7,0,0);
						taoO(735,717,925,747,7,0,0);
						
						taoO(500,787,600,817,7,0,0);
						OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
						
						taoO(775,787,875,817,7,0,0);
						OUTTEXT(775+35,787+5,7,8,3,1,"NU");
						
						trang3 = 1;
						tongtrang3 = CountTotalHK/9;
						if (CountTotalHK%9 != 0){
					   		tongtrang3 +=1;
						}
						IntToChar(tongtrang3,charTongTrang3);
						IntToChar(trang3,charTrang3);
						OUTTEXT(730,585,3,1,3,3,charTrang3);
						OUTTEXT1(760,585,3,0,3,3);
						OUTTEXT(790,585,3,0,3,3,charTongTrang3);
						int m[4] = {200,260,250,200};
						char text[][50]={"CCCD","HO","TEN","PHAI"};
					   	taoBang(335,10,55,m,4,10,text,15,0);
						int xx = 335;int yy = 65;
					   	//cout<<"   "<<CountTotalHK<<"    ";
					   	HanhKhach *array = new HanhKhach[CountTotalHK];
					   	LNR(root,array);
					   	indexHK =0;
					   	
			      	   	HanhKhach *array2 = new HanhKhach[CountTotalHK];
					   	NLR(root,array2);
					   	indexHK2 =0;
					   	
					    NLR_FileOutHK(HKT,array2,CountTotalHK);
					  for(int i=0 ; i< CountTotalHK ; i++)
					  {
					    cout<<"ten "<<array2[i].CCCD<<endl;
					   
			       	}
					   	for(int i=0; i< 9 && i< CountTotalHK; i++)
					   	{
					  	   	OUTTEXT(xx+12,yy+15,15,0,3,3,array[i].CCCD);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,array[i].HO);
							OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,array[i].TEN);
							OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,array[i].GioiTinh);
					  		yy += 55;
						}
					    delete [] array;
					    if(trang3==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
					  	else taoID(405,575,455,625,30001);
						if(tongtrang3>1) taoID(1130,575,1180,625,30002); // TAO ID NUT NEXT		  	
						if(trang3==tongtrang3) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
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
			case 3003:{	// XOA HANH KHACH
				taoButton(1145,780,1265,830,3002,15,1,3,"REMOVE");
				delay(50);	
				taoButton(1145,780,1265,830,0,7,8,3,"REMOVE");
				if(IsOnPlane(pheadDSCB,CCCD3)==0){
					if(okCCCD3 == false && okHO3 == true && okTEN3 == true && okGIOITINH3 == true){
//						    remove("HanhKhach.txt");
	            			root = deleteNodeHK(root,CCCD3);
	            			cout<<"old count "<<CountTotalHK<<endl;
	            			CountTotalHK--;
//            			if(CountTotalHK == 0)
//            			{
//            				DeleteTree(root);
//						}
	            			HanhKhach *array2 = new HanhKhach[CountTotalHK];
					   	    NLR(root,array2);
					   		indexHK2 =0;
	                   	 	NLR_FileOutHK(HKT,array2,CountTotalHK);
                            cout<<"this is si"<<root->data.CCCD;
							strcpy(CCCD3,"");
							strcpy(HO3,"");
							strcpy(TEN3,"");
							strcpy(GIOITINH3,"");	
							okCCCD3 = false;
							okHO3 = false;
							okTEN3 = false;
							okGIOITINH3 = false;
							
	                                       
							
							
							taoO(965,640,1265,770,3,0,0);
						 	setbkcolor(3);
		   					settextstyle(3,0,1);
		   					outtextxy(1060,625,"MessageBox");
		   					
		   					taoO(450,650,925,680,7,0,31);
							taoO(450,717,640,747,7,0,0);
							taoO(735,717,925,747,7,0,0);
							
							taoO(500,787,600,817,7,0,0);
							OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
							
							taoO(775,787,875,817,7,0,0);
							OUTTEXT(775+35,787+5,7,8,3,1,"NU");
							
							trang3 = 1;
							tongtrang3 = CountTotalHK/9;
							if (CountTotalHK%9 != 0){
						   		tongtrang3 +=1;
							}
							IntToChar(tongtrang3,charTongTrang3);
							IntToChar(trang3,charTrang3);
							OUTTEXT(730,585,3,1,3,3,charTrang3);
							OUTTEXT1(760,585,3,0,3,3);
							OUTTEXT(790,585,3,0,3,3,charTongTrang3);
							int m[4] = {200,260,250,200};
							char text[][50]={"CCCD","HO","TEN","PHAI"};
						   	taoBang(335,10,55,m,4,10,text,15,0);
							int xx = 335;int yy = 65;
						   	//cout<<"   "<<CountTotalHK<<"    ";
						   	HanhKhach *array = new HanhKhach[CountTotalHK];
						   	LNR(root,array);
						   	cout<<"new count "<<CountTotalHK<<endl;
						   	for(int i=0;i< CountTotalHK ;i++)
						   	{
						   	   cout<<"this is ccd"<< array[i].CCCD<<endl;	
							}
						   	for(int i=0; i< 9 && i< CountTotalHK; i++)
						   	{
						  	   	OUTTEXT(xx+12,yy+15,15,0,3,3,array[i].CCCD);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,array[i].HO);
								OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,array[i].TEN);
								OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,array[i].GioiTinh);
						  		yy += 55;
							}
							indexHK =0;
						    delete [] array;
						    delete [] array2;
						    if(trang3==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
						  	else taoID(405,575,455,625,30001);
							if(tongtrang3>1) taoID(1130,575,1180,625,30002); // TAO ID NUT NEXT		  	
							if(trang3==tongtrang3) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
							MessageBox("Da Xoa Thanh Cong",14);
							delay(400);
							MessageBox("",0);
						}
					}
							
					else{
						taoID(450,650,925,680,0);
						taoID(450,717,640,747,0);
						taoID(735,717,925,747,0);
						
						taoID(500,787,600,817,0);
						
						taoID(775,787,875,817,0);

						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		MessageBox("KHONG THE XOA ",4);
				 		outtextxy(980,650,"VUI LONG HUY VE TRUOC KHI XOA");
					
					}

				x=-1;y=-1;
				break;
			}
			case 30001:{ // NUT BACK
				taoButton(405,575,455,625,30001,15,1,2,"<");
				delay(50);
				taoButton(405,575,455,625,30001,7,0,2,"<");
				if (trang3 - 1 > tongtrang3) break;
				trang3 -= 1;
				tongtrang3 = CountTotalHK/9;
				if (CountTotalHK%9 != 0)	tongtrang3 +=1;
				IntToChar(tongtrang3,charTongTrang3);
				IntToChar(trang3,charTrang3);
				OUTTEXT(730,585,3,1,3,3,charTrang3);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang3);
				int m[4] = {200,260,250,200};
				char text[][50]={"CCCD","HO","TEN","PHAI"};
			   	taoBang(335,10,55,m,4,10,text,15,0);
				int xx = 335;int yy = 65;
			   	//cout<<"   "<<CountTotalHK<<"    ";
			   	HanhKhach *array = new HanhKhach[CountTotalHK];
			   	LNR(root,array);
			   	for(int i=0; i< 9 && 9*(trang3-1)+i < CountTotalHK; i++)
			   	{
			  	   	OUTTEXT(xx+12,yy+15,15,0,3,3,array[ 9*(trang3-1)+i].CCCD);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,array[9*(trang3-1)+i].HO);
					OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,array[9*(trang3-1)+i].TEN);
					OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,array[9*(trang3-1)+i].GioiTinh);
			  		yy += 55;
				}
				indexHK =0;
			    delete [] array;
			    if(trang3==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
			  	else taoID(405,575,455,625,30001);
				if(tongtrang3>1) taoID(1130,575,1180,625,30002); // TAO ID NUT NEXT		  	
				if(trang3==tongtrang3) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
				
				x=-1;y=-1;
				break;
			}

			case 30002:{ // NUT NEXT
			  	taoButton(1130,575,1180,625,30002,15,1,2," >");
			  	delay(50);
			  	taoButton(1130,575,1180,625,30002,7,0,2," >");
			  	if (trang3 + 1 > tongtrang3) break;
			  	trang3 += 1;
				tongtrang3 = CountTotalHK/9;
				if (CountTotalHK%9 != 0)	tongtrang3 +=1;
				IntToChar(tongtrang3,charTongTrang3);
				IntToChar(trang3,charTrang3);
				OUTTEXT(730,585,3,1,3,3,charTrang3);
				OUTTEXT1(760,585,3,0,3,3);
				OUTTEXT(790,585,3,0,3,3,charTongTrang3);
				int m[4] = {200,260,250,200};
				char text[][50]={"CCCD","HO","TEN","PHAI"};
			   	taoBang(335,10,55,m,4,10,text,15,0);
				int xx = 335;int yy = 65;
			   	//cout<<"   "<<CountTotalHK<<"    ";
			   	HanhKhach *array = new HanhKhach[CountTotalHK];
			   	LNR(root,array);
			   	for(int i=0; i< 9 && 9*(trang3-1)+i < CountTotalHK; i++)
			   	{
			  	   	OUTTEXT(xx+12,yy+15,15,0,3,3,array[ 9*(trang3-1)+i].CCCD);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,array[9*(trang3-1)+i].HO);
					OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,array[9*(trang3-1)+i].TEN);
					OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,array[9*(trang3-1)+i].GioiTinh);
			  		yy += 55;
				}
				indexHK =0;
			    delete [] array;
			    if(trang3==1) taoID(405,575,455,625,0); // KO TAO ID NUT BACK
			  	else taoID(405,575,455,625,30001);
				if(tongtrang3>1) taoID(1130,575,1180,625,30002); // TAO ID NUT NEXT		  	
				if(trang3==tongtrang3) taoID(1130,575,1180,625,0); // KO TAO ID NUT NEXT 
			  	x=-1;y=-1;
				break;	
			}
			
			case 4:{ // MAN HINH 4 - TIM KIEM CHUYEN BAY
				Menu();
				TimChuyenBay();
				x=-1,y=-1;
				break;
			}
			case 41:{ // NAM
				
				taoO(430,50,560,80,15,0,41);
				taoO(695,50,780,80,15,0,42);
				taoO(885,50,970,80,15,0,43);
				taoO(1065,50,1230,80,15,0,44);
				OUTTEXT(430+5,50+5,15,0,6,1,NAM4);
				OUTTEXT(695+5,50+5,15,0,6,1,THANG4);
				OUTTEXT(885+5,50+5,15,0,6,1,NGAY4);
				OUTTEXT(1065+5,50+5,15,0,6,1,TOI4);
				ScanSo(430+5,50+5,NAM4,4,15); 
				TempNam4 = CharToInt(NAM4);
				if(strlen(NAM4) != 0 && strlen(THANG4)!=0 && strlen(NGAY4)!=0 && strlen(TOI4)!=0){
					taoO(1065,105,1230,135,4,0,45);
					OUTTEXT(1110,110,4,15,3,1,"Tim Kiem");
				}
				x=-1;y=-1;
				break;
			}
			case 42:{ // THANG
				OUTTEXT(430+5,50+5,15,0,6,1,NAM4);
				OUTTEXT(695+5,50+5,15,0,6,1,THANG4);
				OUTTEXT(885+5,50+5,15,0,6,1,NGAY4);
				OUTTEXT(1065+5,50+5,15,0,6,1,TOI4);
				ScanSo(695+5,50+5,THANG4,2,15);
				TempThang4 = CharToInt(THANG4);
				if(strlen(NAM4) != 0 && strlen(THANG4)!=0 && strlen(NGAY4)!=0 && strlen(TOI4)!=0){
					taoO(1065,105,1230,135,4,0,45);
					OUTTEXT(1110,110,4,15,3,1,"Tim Kiem");
				}
				x=-1;y=-1;
				break;
			}
			case 43:{ //  NGAY
				OUTTEXT(430+5,50+5,15,0,6,1,NAM4);
				OUTTEXT(695+5,50+5,15,0,6,1,THANG4);
				OUTTEXT(885+5,50+5,15,0,6,1,NGAY4);
				OUTTEXT(1065+5,50+5,15,0,6,1,TOI4);
				ScanSo(885+5,50+5,NGAY4,2,15);
				TempNgay4 = CharToInt(NGAY4);
				if(strlen(NAM4) != 0 && strlen(THANG4)!=0 && strlen(NGAY4)!=0 && strlen(TOI4)!=0){
					taoO(1065,105,1230,135,4,0,45);
					OUTTEXT(1110,110,4,15,3,1,"Tim Kiem");
				}
				x=-1;y=-1;
				break;
			}
			case 44:{ // NOI TOI
				OUTTEXT(430+5,50+5,15,0,6,1,NAM4);
				OUTTEXT(695+5,50+5,15,0,6,1,THANG4);
				OUTTEXT(885+5,50+5,15,0,6,1,NGAY4);
				OUTTEXT(1065+5,50+5,15,0,6,1,TOI4);
				ScanTen(1065+5,50+5,TOI4,10,15);
				if(strlen(NAM4) != 0 && strlen(THANG4)!=0 && strlen(NGAY4)!=0 && strlen(TOI4)!=0){
					taoO(1065,105,1230,135,4,0,45);
					OUTTEXT(1110,110,4,15,3,1,"Tim Kiem");
				}
				x=-1;y=-1;
				break;
			}
			case 45:{ //search 
				taoO(1065,105,1230,135,15,0,45);
				OUTTEXT(1110,110,15,1,3,1,"Tim Kiem");
				delay(50);
				taoO(1065,105,1230,135,7,0,0);
				OUTTEXT(1110,110,7,8,3,1,"Tim Kiem");	
				char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","Trang Thai"};
				int m[4] = {210,300,210,210};
   				taoBang(335,150,55,m,4,10,text,15,0);
				NodeChuyenBay* ptr = pheadDSCB;
			//	ptr = pheadDSCB;
				cout << "Nhap Tay: " << TempNgay4 << " " << TempThang4 <<" " << TempNam4 << " " << TOI4 << endl;
				tempTOTALSEARCHCB = CountTotalChuyenBayTheoSearch(pheadDSCB,TempNgay4,TempThang4,TempNam4,TOI4);
				trang4 = 1;
				tongtrang4 = tempTOTALSEARCHCB/9;
				if (tempTOTALSEARCHCB%9 != 0)	tongtrang4 +=1;
				IntToChar(tongtrang4,charTongTrang4);
				IntToChar(trang4,charTrang4);
				OUTTEXT(730,770,3,1,3,3,charTrang4);
				OUTTEXT1(760,770,3,0,3,3);
				OUTTEXT(790,770,3,0,3,3,charTongTrang4);
				int xx = 335; int yy = 150 + 55;	
				int i = 0;		
				int j = 0;
				while(ptr != NULL)
				{	
					if(ptr->data.DepartTime.day == TempNgay4 && ptr->data.DepartTime.mon == TempThang4 && ptr->data.DepartTime.year == TempNam4 && strcmp(ptr->data.SanBayDen,TOI4)==0 )
					{			
						if(i<9  && i < tempTOTALSEARCHCB){
							   	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
							   	char day[50]= "";
							   	char mon[50]= "";
							   	char year[50]= "";
							   	char hour[50]= "";
							   	char min[50]= "";
							   	IntToChar(ptr->data.DepartTime.day,day);
							   	IntToChar(ptr->data.DepartTime.mon,mon);
							   	IntToChar(ptr->data.DepartTime.year,year);
						 	  	IntToChar(ptr->data.DepartTime.hour,hour);
							   	IntToChar(ptr->data.DepartTime.min,min);
								OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
						    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
						    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
						    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
						    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
						    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
						    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
						    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
												
						    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
								int TongVe = ptr->data.dsv.max;
								int DaDatVe =  ptr->data.dsv.n;
		
								char charTongVe[10] = "";
								char charDaDatVe[10] = "";
								IntToChar(DaDatVe,charDaDatVe);
								IntToChar(TongVe,charTongVe);
						     	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,charDaDatVe);
						     	OUTTEXT1(xx+12+m[0]+m[1]+m[2]+30,yy+15,15,0,3,3);
						     	OUTTEXT(xx+12+m[0]+m[1]+m[2]+30+25,yy+15,15,0,3,3,charTongVe);
						     	
						     	char temptrangthai[3] = ""; 
						     	IntToChar(ptr->data.Status,temptrangthai) ;
						   		OUTTEXT(xx+12+m[0]+m[1]+m[2]+30+25+90+20,yy+15,15,0,3,3,temptrangthai);
						   		yy +=55;	
						   		i++;
						   }
					}
					ptr = ptr->next; 
				}
					
//				strcpy(NAM4,"");
//				strcpy(NGAY4,"");
//				strcpy(THANG4,"");
//				strcpy(TOI4,"");
//				taoO(430,50,560,80,7,0,41);
//				taoO(695,50,780,80,7,0,42);
//				taoO(885,50,970,80,7,0,43);
//				taoO(1065,50,1230,80,7,0,44);
//				TempNgay4 = 0;
//				TempThang4 = 0;
//				TempNam4 = 0;
				if(trang4==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
				else taoID(395,760,445,810,40001);
				if(tongtrang4>1) taoID(1130,760,1180,810,40002); // TAO ID NUT NEXT
				if(trang4==tongtrang4) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 
			
				x=-1;y=-1;
				break;
			}
			case 40001:{ //BACK 
 			  	NodeChuyenBay* ptr = pheadDSCB;
			//	ptr = pheadDSCB;
 			  	char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","Trang Thai"};
				int m[4] = {210,300,210,210};
   				taoBang(335,150,55,m,4,10,text,15,0);
				tempTOTALSEARCHCB = CountTotalChuyenBayTheoSearch(pheadDSCB,TempNgay4,TempThang4,TempNam4,TOI4);
				trang4 -= 1;
				tongtrang4 = tempTOTALSEARCHCB/9;
				if (tempTOTALSEARCHCB%9 != 0)	tongtrang4 +=1;
				IntToChar(tongtrang4,charTongTrang4);
				IntToChar(trang4,charTrang4);
				OUTTEXT(730,770,3,1,3,3,charTrang4);
				OUTTEXT1(760,770,3,0,3,3);
				OUTTEXT(790,770,3,0,3,3,charTongTrang4);
				int xx = 335; int yy = 150 + 55;	
				int i = 0;	
				int j = 9*(trang4-1); 		
				while(ptr != NULL)
				{
					if(ptr->data.DepartTime.day == TempNgay4 && ptr->data.DepartTime.mon == TempThang4 && ptr->data.DepartTime.year == TempNam4 && strcmp(ptr->data.SanBayDen,TOI4) == 0 )
					{		
						if((i-j)<9 && i>=j && i <tempTOTALSEARCHCB){
						   	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
						   	char day[50]= "";
						   	char mon[50]= "";
						   	char year[50]= "";
						   	char hour[50]= "";
						   	char min[50]= "";
						   	IntToChar(ptr->data.DepartTime.day,day);
						   	IntToChar(ptr->data.DepartTime.mon,mon);
						   	IntToChar(ptr->data.DepartTime.year,year);
					 	  	IntToChar(ptr->data.DepartTime.hour,hour);
						   	IntToChar(ptr->data.DepartTime.min,min);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
					    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
					    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
					    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
					    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
					    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
					    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
					    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
											
					    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
							int TongVe = ptr->data.dsv.max;
							int DaDatVe =  ptr->data.dsv.n;
	
							char charTongVe[10] = "";
							char charDaDatVe[10] = "";
							IntToChar(DaDatVe,charDaDatVe);
							IntToChar(TongVe,charTongVe);
					     	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,charDaDatVe);
					     	OUTTEXT1(xx+12+m[0]+m[1]+m[2]+30,yy+15,15,0,3,3);
					     	OUTTEXT(xx+12+m[0]+m[1]+m[2]+30+25,yy+15,15,0,3,3,charTongVe);
					     	
					     	char temptrangthai[3] = ""; 
						    IntToChar(ptr->data.Status,temptrangthai) ;
						   	OUTTEXT(xx+12+m[0]+m[1]+m[2]+30+25+90+20,yy+15,15,0,3,3,temptrangthai);
					   		yy +=55;
							}
							i++;
						}
					ptr = ptr->next; 
				}
				taoButton(395,760,445,810,40001,15,1,2,"<");
 			  	delay(30);
 			  	taoButton(395,760,445,810,40001,7,0,2,"<");
					
				if(trang4==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
				else taoID(395,760,445,810,40001);
				if(tongtrang4>1) taoID(1130,760,1180,810,40002); // TAO ID NUT NEXT
				if(trang4==tongtrang4) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 


 			  	x=-1;y=-1;
				break;
			}
			case 40002:{ //NEXT

				NodeChuyenBay* ptr =pheadDSCB;
			//	ptr = pheadDSCB;
				char text[][50]={"ID","Ngay Gio Khoi Hanh","Toi","Trang Thai"};
				int m[4] = {210,300,210,210};
   				taoBang(335,150,55,m,4,10,text,15,0);
				trang4 += 1;
				tongtrang4 = tempTOTALSEARCHCB/9;
				if (tempTOTALSEARCHCB%9 != 0)	tongtrang4 +=1;
				IntToChar(tongtrang4,charTongTrang4);
				IntToChar(trang4,charTrang4);
				OUTTEXT(730,770,3,1,3,3,charTrang4);
				OUTTEXT1(760,770,3,0,3,3);
				OUTTEXT(790,770,3,0,3,3,charTongTrang4);
				int xx = 335; int yy = 150 + 55;	
				int i = 0;	
				int j = 9*(trang4-1); 		
				while(ptr != NULL)
				{	
					if(ptr->data.DepartTime.day == TempNgay4 && ptr->data.DepartTime.mon == TempThang4 && ptr->data.DepartTime.year == TempNam4 && strcmp(ptr->data.SanBayDen,TOI4) == 0 )
					{	
						if((i-j)<9 && i>=j && i < tempTOTALSEARCHCB){	
						   	OUTTEXT(xx+12,yy+15,15,0,3,3,ptr->data.MaCB);
						   	char day[50]= "";
						   	char mon[50]= "";
						   	char year[50]= "";
						   	char hour[50]= "";
						   	char min[50]= "";
						   	IntToChar(ptr->data.DepartTime.day,day);
						   	IntToChar(ptr->data.DepartTime.mon,mon);
						   	IntToChar(ptr->data.DepartTime.year,year);
					 	  	IntToChar(ptr->data.DepartTime.hour,hour);
						   	IntToChar(ptr->data.DepartTime.min,min);
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,day);
					    	OUTTEXT1(xx+12+m[0]+30,yy+15,15,0,3,3); // dau /
					    	OUTTEXT(xx+12+m[0]+40,yy+15,15,0,3,3,mon);
					    	OUTTEXT1(xx+12+m[0]+70,yy+15,15,0,3,3); // Dau / 
					    	OUTTEXT(xx+12+m[0]+80,yy+15,15,0,3,3,year);
					    	OUTTEXT(xx+12+m[0]+140,yy+15,15,0,3,3,hour);
					    	OUTTEXT2(xx+12+m[0]+165,yy+15,15,0,3,3);// Dau : 
					    	OUTTEXT(xx+12+m[0]+170,yy+15,15,0,3,3,min);	
											
					    	OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,ptr->data.SanBayDen);
							int TongVe = ptr->data.dsv.max;
							int DaDatVe =  ptr->data.dsv.n;
	
							char charTongVe[10] = "";
							char charDaDatVe[10] = "";
							IntToChar(DaDatVe,charDaDatVe);
							IntToChar(TongVe,charTongVe);
					     	OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,charDaDatVe);
					     	OUTTEXT1(xx+12+m[0]+m[1]+m[2]+30,yy+15,15,0,3,3);
					     	OUTTEXT(xx+12+m[0]+m[1]+m[2]+30+25,yy+15,15,0,3,3,charTongVe);
					     	
					     	char temptrangthai[3] = ""; 
						    IntToChar(ptr->data.Status,temptrangthai) ;
						   	OUTTEXT(xx+12+m[0]+m[1]+m[2]+30+25+90+20,yy+15,15,0,3,3,temptrangthai);
					   		yy +=55;
							}
							i++;
						}
						ptr = ptr->next; 
					}
				taoButton(1130,760,1180,810,40002,15,1,2," >");
				delay(30);
				taoButton(1130,760,1180,810,40002,7,0,2," >");
				if(trang4==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
				else taoID(395,760,445,810,40001);
				if(tongtrang4>1) taoID(1130,760,1180,810,40002); // TAO ID NUT NEXT
				if(trang4==tongtrang4) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 

				x=-1;y=-1;
				break;
			}
			case 5:{ // MAN HINH 5 - DAT VE
				Menu();
				DatVe();
				x=-1,y=-1;
				break;

						}
			case 51:{ // VI TRI CHO NGOI 
				taoID(375,50,535,80,0); // ID MAY BAY OFF
				taoButton(335+200,600,335+200+40,640,503,4,0,3,"X");
				taoO(458,650,925,680,15,0,51);
				taoButton(635,575,900,625,0,7,8,3,"HUY VE THEO CCCD");

//				taoO(458,742,640,772,7,0,0);
//				taoO(735,742,925,772,7,0,0);
//				

				
				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
	
				
				NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID5);
				ScanSo(458+5,650+5,VITRI5,2,15);
				tempvitri = CharToInt(VITRI5);
				for(int i=0; i<ptr->data.dsv.n ; i++)
				{
					if(ptr->data.dsv.ve[i]->stt == tempvitri)
					{
						strcpy(CCCD5,ptr->data.dsv.ve[i]->CCCD);
					}
				}
				nodehk check;
				check = SearchHk(root,CCCD5);
				if(strlen(VITRI5)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,650);
				 	outtextxy(970,650,"VI TRI: ");
				 	BaoLoi1(970 + 65,645);
				 	okVITRI5=false; 
					}
				else if(tempvitri > SoChoNgoi5){
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,645);
				 	outtextxy(970,650,"VI TRI: ");
				 	KhongHopLe1(970 + 65,645);
				 	okVITRI5=false;
					}
				else if(IsEmpty(ptr->data.dsv,tempvitri)==true){
					cout << tempvitri << " Trong " << endl;
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,650);
				 	outtextxy(970,650,"VI TRI: ");
				 	HopLe1(970 + 65,645);
				 	okVITRI5=true;
				 	taoO(458,697,925,727,15,0,52); // CCCD ON 
				}
				else if(IsEmpty(ptr->data.dsv,tempvitri)==false){
					cout << tempvitri << " khong trong " << endl;
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,650);
				 	outtextxy(970,650,"VI TRI: ");
				 	TonTai1(970 + 65,645);
				 	okVITRI5=false;
					okCCCD5=false;
					okHO5=true;
					okTEN5=true;
					okGIOITINH5=true;
					strcpy(CCCD5,check->data.CCCD);
					strcpy(HO5,check->data.HO);
					strcpy(TEN5,check->data.TEN);
					strcpy(GIOITINH5,check->data.GioiTinh);
					
					taoO(458,697,925,727,15,0,0); // CCCD
					taoO(458,742,640,772,15,0,0); // HO
					taoO(735,742,925,772,15,0,0); 	// TEN
				
					taoO(500,787,600,817,15,0,0);
					OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					taoO(775,787,875,817,7,0,0);
					OUTTEXT(775+35,787+5,7,8,3,1,"NU");
			
					OUTTEXT(458+5,697+5,15,4,6,1,CCCD5);
				 	OUTTEXT(458+5,742+5,15,0,6,1,HO5);
					OUTTEXT(735+5,742+5,15,0,6,1,TEN5);			
					if(strcmp(GIOITINH5,"Nam")==0){
						taoO(500,787,600,817,1,0,0);        //NAM ON
						OUTTEXT(500+25,787+5,1,15,3,1,"NAM");
						taoO(775,787,875,817,7,0,0);
						OUTTEXT(775+35,787+5,7,8,3,1,"NU");
					}
					else{
						taoO(500,787,600,817,7,0,0);        //NU ON
						OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
						taoO(775,787,875,817,4,0,0);
						OUTTEXT(775+35,787+5,4,15,3,1,"NU");
					}
					taoID(458,650,925,680,0);
					taoID(458,697,925,727,0);
				 	taoID(458,742,640,772,0);
				    taoID(735,742,925,772,0);
					taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
					taoButton(1145,780,1245,830,5002,7,0,3,"Huy Ve");
					}
				x=-1;y=-1;
				break;
				
			} 
			case 52:{ // CCCD 
				taoID(458,650,925,680,0); // VI TRI OFF
				ScanSoCCCD(458+5,697+5,CCCD5,9,15);
				nodehk check;
				check = SearchHk(root,CCCD5);
				NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID5);
			    NodeChuyenBay* ptr2 = pheadDSCB;
			    while(ptr2 != NULL)
			    {
			    	if(Late30Min(ptr2->data.DepartTime,ptr->data.DepartTime) == true && ptr2 != ptr)
			    	 {
			    	 	cout<<"may bay dat"<<ptr->data.DepartTime.day <<" "<< ptr->data.DepartTime.mon <<" "<<ptr->data.DepartTime.year <<" "<<ptr->data.DepartTime.hour << " "<< ptr->data.DepartTime.min<<endl<<endl;
			    	 	cout<<"may bay tim"<< ptr2->data.DepartTime.day <<" "<< ptr2->data.DepartTime.mon <<" "<<ptr2->data.DepartTime.year <<" "<<ptr2->data.DepartTime.hour << " "<< ptr2->data.DepartTime.min<<endl;
			    	 	for(int i=0; i< ptr2->data.dsv.n ; i++)
			    	 	{
			    	 		if(strcmp(CCCD5,ptr2->data.dsv.ve[i]->CCCD) ==0 )
			    	 		 {
			    	 		 	cout << "CHECK " << endl;
			    	 		 	// Hanh khach khong the dat 2 chuyen bay khoi hanh cach nhau duoi 30 phut!
							 }
						}
			    	 	
					 }
			       ptr2= ptr2->next;	
				}
				for (int i =0; i< ptr->data.dsv.n ; i++)
				{
					if(strcmp(CCCD5,ptr->data.dsv.ve[i]->CCCD)==0)
					{
						okViTriCCCD5 = true;
					}
				}
				if(strlen(CCCD5)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,680,"CCCD: ");
				 	BaoLoi1(970 + 60,675);
				 	okCCCD5=false; 
					}
				else if(strlen(CCCD5)==9 && okViTriCCCD5 == false && check == NULL){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,680,"CCCD: ");
				 	HopLe1(970 + 60,675);
				 	okCCCD5=true;
				  //HO TEN ON 
				 	taoO(458,742,640,772,15,0,53);
				    taoO(735,742,925,772,15,0,0);
					}
				else if(check != NULL){
					
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,680,"CCCD: ");
				 	TonTai1(970 + 60,675);
					okCCCD5=false;
					okHO5=true;
					okTEN5=true;
					okGIOITINH5=true;
					strcpy(CCCD5,check->data.CCCD);
					strcpy(HO5,check->data.HO);
					strcpy(TEN5,check->data.TEN);
					strcpy(GIOITINH5,check->data.GioiTinh);
					
					taoO(500,787,600,817,15,0,0);
					OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					taoO(775,787,875,817,7,0,0);
					OUTTEXT(775+35,787+5,7,8,3,1,"NU");
	
					taoO(458,742,640,772,15,0,0);
					taoO(735,742,925,772,15,0,0);
					OUTTEXT(458+5,697+5,15,4,6,1,CCCD5);
				 	OUTTEXT(458+5,742+5,15,0,6,1,HO5);
					OUTTEXT(735+5,742+5,15,0,6,1,TEN5);
							
					if(strcmp(GIOITINH5,"Nam")==0){
						taoO(500,787,600,817,1,0,0);        //NAM ON
						OUTTEXT(500+25,787+5,1,15,3,1,"NAM");
						taoO(775,787,875,817,7,0,0);
						OUTTEXT(775+35,787+5,7,8,3,1,"NU");
					}
					else{
						taoO(500,787,600,817,7,0,0);        //NU ON
						OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
						taoO(775,787,875,817,4,0,0);
						OUTTEXT(775+35,787+5,4,15,3,1,"NU");
					 }
					taoID(458,697,925,727,0);
				 	taoID(458,742,640,772,0);
				    taoID(735,742,925,772,0);
				    if(okViTriCCCD5 == true){
				    	taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
						taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
					}
//					else if(okViTriCCCD5 == false){
					else{
						taoButton(965,780,1065,830,5001,7,0,3,"Ban Ve");
						taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
						}
					}
				else{
					setbkcolor(3);
					setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,680,"CCCD:");
					KhongHopLe1(970 + 60,675);
				 	okCCCD5=false; 
				}
				x=-1;y=-1;
				break;
			}
			case 53:{ //HO VA TEN
				taoID(458,697,925,680,0);
				ScanTen(458+5,742+5,HO5,10,15);
				if(strlen(HO5)==0){
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,705);
				 	outtextxy(970,710,"HO: ");
				 	BaoLoi1(970 + 40,705);
				 	okHO5=false; 
				 		
				}
				else {
				 	setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	CleanMessageBox(970,705);
				 	outtextxy(970,710,"HO: ");
				 	HopLe1(970 + 40,705);
					okHO5=true; 
					taoO(735,742,925,772,15,0,53);
					ScanTen(735+5,742+5,TEN5,10,15);
				 	if(strlen(TEN5)==0){
					 	setbkcolor(3);
					 	setcolor(0);
					 	settextstyle(3,0,1);
					 	CleanMessageBox(970,705);
					 	outtextxy(970,710,"TEN: ");
					 	BaoLoi1(970 + 60,705);
					 	okTEN5=false; 
					}
					else{
						setbkcolor(3);
					 	setcolor(0);
					 	settextstyle(3,0,1);
					 	CleanMessageBox(970,705);
					 	outtextxy(970,710,"TEN: ");
					 	HopLe1(970 + 60,705);
						okTEN5=true; 
						taoO(500,787,600,817,9,0,54);        //GIOI TINH ON
						OUTTEXT(500+25,787+5,9,0,3,1,"NAM");
						taoO(775,787,875,817,12,0,55);
						OUTTEXT(775+35,787+5,12,0,3,1,"NU");
					}
				}
				x=-1;y=-1;
				break;
			}
			case 54:{
				taoID(458,742,925,772,0);
				taoO(500,787,600,817,1,0,54);        //NAM ON
				OUTTEXT(500+25,787+5,1,15,3,1,"NAM");
				taoO(775,787,875,817,7,0,55);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				strcpy(GIOITINH5,"Nam");
				okGIOITINH5 = true;
				setbkcolor(3);
			 	setcolor(0);
			 	settextstyle(3,0,1);
			 	outtextxy(970,740,"Phai:");
			 	GioiTinh1(970 + 50,735,strcmp(GIOITINH5,"Nam"));
			 	taoButton(965,780,1065,830,5001,7,0,3,"Ban Ve");
				x=-1;y=-1;
				break;
			}
			case 55:{
				taoID(458,742,925,772,0);
				taoO(500,787,600,817,7,0,54);        //NU ON
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				taoO(775,787,875,817,4,0,55);
				OUTTEXT(775+35,787+5,4,15,3,1,"NU");
				strcpy(GIOITINH5,"Nu");
				okGIOITINH5 = true;
				setbkcolor(3);
			 	setcolor(0);
			 	settextstyle(3,0,1);
			 	outtextxy(970,740,"Phai:");
			 	GioiTinh1(970 + 50,735,strcmp(GIOITINH5,"Nam"));
			 	taoButton(965,780,1065,830,5001,7,0,3,"Ban Ve");
				x=-1;y=-1;
				break;
			}
			case 501:{ //ID CHUYEN BAY 
				taoO(375,50,535,80,15,0,501);
				taoO(670,50,1000,80,15,0,0);
				taoO(1065,50,1230,80,15,0,0);
				
				taoButton(335,5,375,45,502,4,0,3,"X");
				ScanMa(375+5,50+5,ID5,7,15);
				if(strlen(ID5)==0){
					taoO(335,110,1260,550,15,0,0);
					line(355,330,1240,330);
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
			 		outtextxy(970,650,"IDCB: ");
					BaoLoi1(970 + 50,645);
					okID5=false; 
				}
				else if(SearchNode(pheadDSCB,ID5)!=NULL ){ // SEARCH ID CHUYENBAY FUNCTION
					UpdateCB(pheadDSCB);
					FileOutVe(VEO,pheadDSCB);
					NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID5);
					if(ptr->data.Status == 0 )
					{
						taoO(335,110,1260,550,15,0,0);
						line(355,330,1240,330);
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"IDCB: ");
					 	BiHuy1(970 + 50,645);
						okID5=false;
					}
					else if(ptr->data.Status == 3)
					{
						taoO(335,110,1260,550,15,0,0);
						line(355,330,1240,330);
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"IDCB: ");
						HoanTat1(970 + 50,645);
						okID5=false;
					}
					else if(ptr->data.Status == 2 || ptr->data.Status == 1)
					{
						setbkcolor(3);
				 		setcolor(0);
				 		settextstyle(3,0,1);
				 		outtextxy(970,650,"IDCB: ");
					 	TonTai1(970 + 50,645);
						okID5=true;
						
						char day[50]= "";
	    				char mon[50]= "";
	    				char year[50]= "";
	    				char hour[50]= "";
	    				char min[50]= "";
	    				IntToChar(ptr->data.DepartTime.day,day);
	    				IntToChar(ptr->data.DepartTime.mon,mon);
	    				IntToChar(ptr->data.DepartTime.year,year);
	    				IntToChar(ptr->data.DepartTime.hour,hour);
	    				IntToChar(ptr->data.DepartTime.min,min);
	    				
	    				strcpy(NGAY5,day); strcpy(THANG5,mon); strcpy(NAM5,year); strcpy(GIO5,hour); strcpy(PHUT5,min);
						strcpy(TOI5,ptr->data.SanBayDen);
						char IDMAYBAY5[50] = "";
						int trunggian = 0;
						strcpy(IDMAYBAY5,ptr->data.ID);
						trunggian = SearchIdMb(dsmb,IDMAYBAY5);
						SoChoNgoi5 = dsmb.data[trunggian]->Room;

						OUTTEXT(670+12,50+1,15,0,3,3,day);
				    	OUTTEXT1(670+12+30,50+1,15,0,3,3); // dau /
				    	OUTTEXT(670+12+40,50+1,15,0,3,3,mon);
				    	OUTTEXT1(670+12+70,50+1,15,0,3,3); // Dau / 
				    	OUTTEXT(670+12+80,50+1,15,0,3,3,year);
				    	OUTTEXT(670+12+140,50+1,15,0,3,3,hour);
				    	OUTTEXT2(670+12+165,50+1,15,0,3,3);// Dau : 
				    	OUTTEXT(670+12+170,50+1,15,0,3,3,min);
							
						OUTTEXT(1065+5,50+5,15,0,6,1,TOI5);
						//VE BANG DAT VE
						taoO(335,110,1260,550,15,0,0);
						line(355,330,1240,330);
						int x1 = 355, y1 = 120;
						int k1 = 0;
						for(int j = 0; j < 10; j++){
							for(int i = 1; i <= 5 ; i++){
								if(i + k1 <= SoChoNgoi5){
									taoO(x1,y1,x1+30,y1+30,15,0,0);
									char tempi[50] = "";
									IntToChar(i + k1,tempi);
									OUTTEXT(x1 + 5,y1+5,15,1,3,1,tempi);
									y1 = y1 + 40;	
									}
								}
							k1 = k1 + 10;
							x1 = x1 + 95;
							y1 = 120;
						}
						int x2 = 355, y2 = 350;
						int k2 = 0;
						for(int j = 0; j < 10; j++){
							for(int i = 6; i <= 10 ; i++){
								if(i + k2 <= SoChoNgoi5){
									taoO(x2,y2,x2+30,y2+30,15,0,0);
									char tempi[50] = "";
									IntToChar(i + k2,tempi);
									OUTTEXT(x2+5,y2+5,15,1,3,1,tempi);
									y2 = y2 + 40;
									}
								}
							k2 = k2 + 10;
							x2 = x2 + 95;
							y2 = 350;
						}
						//PHU LOP' VE DA DUOC DAT
					
						
						
						int arrayVITRI[ptr->data.dsv.n];
							int count=0;
						    for(int i=0; i< ptr->data.dsv.n; i++)
						    {
						    	arrayVITRI[count]= ptr->data.dsv.ve[i]->stt;
						    	count++;
							}
						x1 = 355, y1 = 120;
						k1 = 0;
						for(int j = 0; j < 10; j++){
							for(int i = 1; i <= 5 ; i++){
								if(i + k1 <= SoChoNgoi5){
									for(int l = 0;l<count;l++){
										if((i + k1) == arrayVITRI[l]){
											cout << "1: " << arrayVITRI[l] << endl;
											taoO(x1,y1,x1+30,y1+30,4,0,0);
											char tempi[50] = "";
											IntToChar(i + k1,tempi);
											OUTTEXT(x1 + 5,y1+5,4,15,3,1,tempi);
										}
									}
									y1 = y1 + 40;	
								}
							}
							k1 = k1 + 10;
							x1 = x1 + 95;
							y1 = 120;
						}
		
						x2 = 355, y2 = 350;
						k2 = 0;
						for(int j = 0; j < 10; j++){
							for(int i = 6; i <= 10 ; i++){
								if(i + k2 <= SoChoNgoi5){
									for(int l = 0;l<count;l++){
										if((i + k2) == arrayVITRI[l]){
											cout << "2: " << arrayVITRI[l] << endl;
											taoO(x2,y2,x2+30,y2+30,4,0,0);
											char tempi[50] = "";
											IntToChar(i + k2,tempi);
											OUTTEXT(x2+5,y2+5,4,15,3,1,tempi);
										}
									}
									y2 = y2 + 40;
								}
							}
							k2 = k2 + 10;
							x2 = x2 + 95;
							y2 = 350;		
						}
						taoID(458,650,925,680,51);
						taoButton(635,575,900,625,50001,4,11,3,"HUY VE THEO CCCD");
					}
				}
					
				else {
					taoO(335,110,1260,550,15,0,0);
					line(355,330,1240,330);
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,650,"IDCB: ");
					KhongTonTai1(970 + 50,645);
					okID5=false;
				}
				x=-1;y=-1;
				break;
		
			}
			case 502:{ // HUY ID CHUYEN BAY BAY VA THONG TIN NHAP
				Menu();
				DatVe();
				taoO(335,110,1260,550,15,0,0);
				strcpy(ID5,"");
				strcpy(NGAY5,"");
				strcpy(THANG5,"");
				strcpy(NAM5,"");
				strcpy(GIO5,"");
				strcpy(PHUT5,"");
				strcpy(TOI5,"");
				strcpy(CCCD5,"");	
				strcpy(HO5,"");
				strcpy(TEN5,"");
				strcpy(GIOITINH5,"");	
				tempvitri = 0;
				okCCCD5 = false;
				okHO5 = false;
				okTEN5 = false;
				okGIOITINH5 = false;
				okID5 = false;
				okViTriCCCD5 = false;
				taoO(375,50,535,80,7,0,501);
				taoO(670,50,1000,80,7,0,0);
				taoO(1065,50,1230,80,7,0,0);

				
				taoO(458,650,925,680,7,0,0);

   				taoO(458,697,925,727,7,0,0);
   				
				taoO(458,742,640,772,7,0,0);
				taoO(735,742,925,772,7,0,0);
					
				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");	
				taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
				taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
				taoO(965,640,1265,770,3,0,0);
				setbkcolor(3);
   				settextstyle(3,0,1);
   				outtextxy(1060,625,"MessageBox");
				x=-1;y=-1;
				break;
			}
			case 503:{ // Huy thong tin KHUNG NHAP VI TRI
			    strcpy(VITRI5,"");
				strcpy(CCCD5,"");
				strcpy(HO5,"");
				strcpy(TEN5,"");
				strcpy(GIOITINH5,"");	
				tempvitri = 0;
				okViTriCCCD5 = false;
				okCCCD5 = false;
				okHO5 = false;
				okTEN5 = false;
				okGIOITINH5 = false;
					
				taoO(965,640,1265,770,3,0,0);
				setbkcolor(3);
   				settextstyle(3,0,1);
   				outtextxy(1060,625,"MessageBox");
   				taoO(458,650,925,680,7,0,51);

   				taoO(458,697,925,727,7,0,0);
   				
				taoO(458,742,640,772,7,0,0);
				taoO(735,742,925,772,7,0,0);
					
				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
				taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
				taoButton(635,575,900,625,50001,4,11,3,"HUY VE THEO CCCD");
				x=-1;y=-1;
				break;
				}
			case 5001:{ // BAN VE
				taoButton(965,780,1065,830,5001,15,1,3,"Ban Ve");
				delay(50);
				taoButton(965,780,1065,830,5001,7,0,3,"Ban Ve");
				nodehk check;
				check = SearchHk(root,CCCD5);
				NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID5);
				tempvitri = CharToInt(VITRI5);
				HanhKhach data;
				strcpy(data.CCCD,CCCD5);
				strcpy(data.HO,HO5);
				strcpy(data.TEN,TEN5);
				strcpy(data.GioiTinh,GIOITINH5);
				OrderVe(ptr->data.dsv,tempvitri,check,data);
				remove("HanhKhach.txt");
                NLR_FileOutHK(HKT,root);
                remove("Ve.txt");
                FileOutVe(VEO,pheadDSCB);
				
				int arrayVITRI[ptr->data.dsv.n];
				int count=0;
			    for(int i=0; i< ptr->data.dsv.n; i++)
			    {
			    	arrayVITRI[count]= ptr->data.dsv.ve[i]->stt;
			    	cout<<"Day la vi tri "<< count << " : " << arrayVITRI[count]<< endl; 
			    	count++;
				}
				int x1 = 355, y1 = 120;
				int k1 = 0;
				for(int j = 0; j < 10; j++){
					for(int i = 1; i <= 5 ; i++){
						if(i + k1 <= SoChoNgoi5){
							for(int l = 0;l<count;l++){
								if((i + k1) == arrayVITRI[l]){
									cout << "1: " << arrayVITRI[l] << endl;
									taoO(x1,y1,x1+30,y1+30,4,0,0);
									char tempi[50] = "";
									IntToChar(i + k1,tempi);
									OUTTEXT(x1 + 5,y1+5,4,15,3,1,tempi);
								}
							}
							y1 = y1 + 40;	
						}
					}
					k1 = k1 + 10;
					x1 = x1 + 95;
					y1 = 120;
				}

				int x2 = 355, y2 = 350;
				int k2 = 0;
				for(int j = 0; j < 10; j++){
					for(int i = 6; i <= 10 ; i++){
						if(i + k2 <= SoChoNgoi5){
							for(int l = 0;l<count;l++){
								if((i + k2) == arrayVITRI[l]){
									cout << "2: " << arrayVITRI[l] << endl;
									taoO(x2,y2,x2+30,y2+30,4,0,0);
									char tempi[50] = "";
									IntToChar(i + k2,tempi);
									OUTTEXT(x2+5,y2+5,4,15,3,1,tempi);
								}
							}
							y2 = y2 + 40;
						}
					}
					k2 = k2 + 10;
					x2 = x2 + 95;
					y2 = 350;		
				}
				settextstyle(3,0,1);
				
				taoO(458,650,925,680,7,0,51);
				taoO(458,697,925,727,7,0,0);
				taoO(458,742,640,772,7,0,0);

				taoO(735,742,925,772,7,0,0);

				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				
						
				taoO(965,640,1265,770,3,0,0);
				OUTTEXT(1060,625,3,0,3,1,"MessageBox");
				
				taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
				taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
				taoButton(635,575,900,625,50001,4,11,3,"HUY VE THEO CCCD");
				
				strcpy(VITRI5,"");
				strcpy(CCCD5,"");
				strcpy(HO5,"");
				strcpy(TEN5,"");
				strcpy(GIOITINH5,"");	
				okCCCD5 = false;
				okHO5 = false;
				okTEN5 = false;
				okGIOITINH5 = false;
				okViTriCCCD5 = false;
				tempvitri = 0;
				
				x=-1,y=-1;
				break;
			}
			case 5002:{ //XOA VE
				taoButton(1145,780,1245,830,5002,15,1,3,"Huy Ve");
				delay(50);
				taoButton(1145,780,1245,830,5002,7,0,3,"Huy Ve");
				NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID5);
				RemoveVe(ptr->data.dsv,CCCD5,index);
				FileOutVe(VEO,pheadDSCB);
				int x1 = 355, y1 = 120;
				int k1 = 0;
				cout << tempvitri << endl;
				for(int j = 0; j < 10; j++){
					for(int i = 1; i <= 5 ; i++){
						if(i + k1 <= SoChoNgoi5){
								if((i + k1) == tempvitri){
									taoO(x1,y1,x1+30,y1+30,15,0,0);
									char tempi[50] = "";
									IntToChar(i + k1,tempi);
									OUTTEXT(x1 + 5,y1+5,15,1,3,1,tempi);
								}
							y1 = y1 + 40;									
							}
						}
					k1 = k1 + 10;
					x1 = x1 + 95;
					y1 = 120;
				}

				int x2 = 355, y2 = 350;
				int k2 = 0;
				for(int j = 0; j < 10; j++){
					for(int i = 6; i <= 10 ; i++){
						if(i + k2 <= SoChoNgoi5){
								if((i + k2) == tempvitri){
									taoO(x2,y2,x2+30,y2+30,15,0,0);
									char tempi[50] = "";
									IntToChar(i + k2,tempi);
									OUTTEXT(x2+5,y2+5,15,1,3,1,tempi);
								}
							y2 = y2 + 40;
							}
						}
					k2 = k2 + 10;
					x2 = x2 + 95;
					y2 = 350;		
				}
				
				settextstyle(3,0,1);
				
				taoO(458,650,925,680,7,0,51);
				taoO(458,697,925,727,7,0,0);
				taoO(458,742,640,772,7,0,0);

				taoO(735,742,925,772,7,0,0);

				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
				
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				
						
				taoO(965,640,1265,770,3,0,0);
				OUTTEXT(1060,625,3,0,3,1,"MessageBox");
				
				taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
				taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
				
				strcpy(VITRI5,"");
				strcpy(CCCD5,"");
				strcpy(HO5,"");
				strcpy(TEN5,"");
				strcpy(GIOITINH5,"");	
				okCCCD5 = false;
				okHO5 = false;
				okTEN5 = false;
				okGIOITINH5 = false;
				okViTriCCCD5 = false;
				tempvitri = 0;
				
				x=-1,y=-1;
				break;
			}
			case 50001:{// HUY VE THEO CCCD
				taoButton(635,575,900,625,0,7,15,3,"HUY VE THEO CCCD");
				taoButton(910,575,1030,625,50003,4,11,3,"THOAT");
				taoO(458,650,925,680,7,0,0);
				taoO(458,697,925,727,15,0,50002);
				taoButton(335+200,600,335+200+40,640,0,7,8,3,"X");
				x=-1;y=-1;
				break;
			}
			case 50002:{ //  CCCD 2
				taoID(458,650,925,680,0); // VI TRI OFF
				ScanSoCCCD(458+5,697+5,CCCD5,9,15);
				nodehk check;
				check = SearchHk(root,CCCD5);
				NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID5);
			    NodeChuyenBay* ptr2 = pheadDSCB;
			    for (int i =0; i< ptr->data.dsv.n ; i++)
				{
					if(strcmp(CCCD5,ptr->data.dsv.ve[i]->CCCD)==0)
					{
						tempvitri = ptr->data.dsv.ve[i]->stt;
						index = i;
					}
				}
			    IntToChar(tempvitri,VITRI5);

				if(strlen(CCCD5)==0){
				 	setbkcolor(3);
				 	setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,680,"CCCD: ");
				 	BaoLoi1(970 + 60,675);
				 	okCCCD5=false; 
					}
				else if(check != NULL){
					
					setbkcolor(3);
				 	setcolor(0);
				 	settextstyle(3,0,1);
				 	outtextxy(970,680,"CCCD: ");
				 	TonTai1(970 + 60,675);
					okCCCD5=false;
					okHO5=true;
					okTEN5=true;
					okGIOITINH5=true;
					strcpy(CCCD5,check->data.CCCD);
					strcpy(HO5,check->data.HO);
					strcpy(TEN5,check->data.TEN);
					strcpy(GIOITINH5,check->data.GioiTinh);
					
					taoO(500,787,600,817,15,0,0);
					OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					taoO(775,787,875,817,7,0,0);
					OUTTEXT(775+35,787+5,7,8,3,1,"NU");
	
					taoO(458,742,640,772,15,0,0);
					taoO(735,742,925,772,15,0,0);
					OUTTEXT(458+5,697+5,15,4,6,1,CCCD5);
				 	OUTTEXT(458+5,742+5,15,0,6,1,HO5);
					OUTTEXT(735+5,742+5,15,0,6,1,TEN5);
							
					if(strcmp(GIOITINH5,"Nam")==0){
						taoO(500,787,600,817,1,0,0);        //NAM ON
						OUTTEXT(500+25,787+5,1,15,3,1,"NAM");
						taoO(775,787,875,817,7,0,0);
						OUTTEXT(775+35,787+5,7,8,3,1,"NU");
					}
					else{
						taoO(500,787,600,817,7,0,0);        //NU ON
						OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
						taoO(775,787,875,817,4,0,0);
						OUTTEXT(775+35,787+5,4,15,3,1,"NU");
					 }
					taoO(458,650,925,680,15,0,0);
					OUTTEXT(458+5,650+5,15,0,6,1,VITRI5);
					taoID(458,697,925,727,0);
				 	taoID(458,742,640,772,0);
				    taoID(735,742,925,772,0);
					taoButton(965,780,1065,830,0,7,8,3,"Ban Ve");
					if(tempvitri == 0){
						taoButton(1145,780,1245,830,0,7,8,3,"Huy Ve");
					}
					else{
						taoButton(1145,780,1245,830,5002,7,0,3,"Huy Ve");
					}
				}
				else{
					setbkcolor(3);
					setcolor(0);
					settextstyle(3,0,1);
					outtextxy(970,680,"CCCD:");
					KhongTonTai1(970 + 60,675);
				 	okCCCD5=false; 
				}
				x=-1;y=-1;
				break;
			}
			case 50003:{ // NUT THOAT CUA HUY VE THEO CCCD
				taoButton(635,575,900,625,50001,4,11,3,"HUY VE THEO CCCD");
				taoButton(910,575,1030,625,0,3,3,3,"THOAT");
				taoButton(335+200,600,335+200+40,640,503,4,0,3,"X");
   				strcpy(VITRI5,"");
				strcpy(CCCD5,"");
				strcpy(HO5,"");
				strcpy(TEN5,"");
				strcpy(GIOITINH5,"");	
				tempvitri = 0;
				okViTriCCCD5 = false;
				okCCCD5 = false;
				okHO5 = false;
				okTEN5 = false;
				okGIOITINH5 = false;
				//RESET FORM NHAP VI TRI
				taoO(965,640,1265,770,3,0,0);
				setbkcolor(3);
   				settextstyle(3,0,1);
   				outtextxy(1060,625,"MessageBox");
   				taoO(458,650,925,680,7,0,51);

   				taoO(458,697,925,727,7,0,0);
   				
				taoO(458,742,640,772,7,0,0);
				taoO(735,742,925,772,7,0,0);
					
				taoO(500,787,600,817,7,0,0);
				OUTTEXT(500+25,787+5,7,8,3,1,"NAM");
					
				taoO(775,787,875,817,7,0,0);
				OUTTEXT(775+35,787+5,7,8,3,1,"NU");
				x=-1;y=-1;
				break;
			}
			case 6:{
				Menu();
				DanhSachHanhKhach();
				x=-1,y=-1;
				break;
			}
			case 61:{ //ID CHUYEN BAY 
				taoO(915,50,1135,80,15,0,61);
				ScanMa(915+5,50+5,ID6,10,15);
				if(SearchNode(pheadDSCB,ID6)!=NULL ){ // SEARCH ID CHUYENBAY FUNCTION
					UpdateCB(pheadDSCB);
					FileOutVe(VEO,pheadDSCB);
					NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID6);
					// LAY DU LIEU
					char day[50]= "";
	    			char mon[50]= "";
	    			char year[50]= "";
	   				char hour[50]= "";
	   				char min[50]= "";
	    			IntToChar(ptr->data.DepartTime.day,day);
	    			IntToChar(ptr->data.DepartTime.mon,mon);
	    			IntToChar(ptr->data.DepartTime.year,year);
	   				IntToChar(ptr->data.DepartTime.hour,hour);
	   				IntToChar(ptr->data.DepartTime.min,min);
	    			
	    			strcpy(NGAY6,day); strcpy(THANG6,mon); strcpy(NAM6,year); strcpy(GIO6,hour); strcpy(PHUT6,min);
					strcpy(TOI6,ptr->data.SanBayDen);
					taoO(515,110,800,140,15,0,0);
					taoO(915,110,1135,140,15,0,0);
					OUTTEXT(535+5,110+1,15,0,3,3,day);
				   	OUTTEXT1(535+5+30,110+1,15,0,3,3); // dau /
				   	OUTTEXT(535+5+40,110+1,15,0,3,3,mon);
				   	OUTTEXT1(535+5+70,110+1,15,0,3,3); // Dau / 
				   	OUTTEXT(535+5+80,110+1,15,0,3,3,year);
				   	OUTTEXT(535+5+140,110+1,15,0,3,3,hour);
				   	OUTTEXT2(535+5+165,110+1,15,0,3,3);// Dau : 
				   	OUTTEXT(535+5+170,110+1,15,0,3,3,min);
							
					OUTTEXT(915+5,110+5,15,0,6,1,TOI6);
					//VE BANG
					trang6 = 1;
					tongtrang6 = ptr->data.dsv.n/9;
					if (ptr->data.dsv.n%9 != 0)
			  	 		tongtrang6 +=1;
					IntToChar(tongtrang6,charTongTrang6);
					IntToChar(trang6,charTrang6);
					OUTTEXT(730,770,3,1,3,3,charTrang6);
					OUTTEXT1(760,770,3,0,3,3);
					OUTTEXT(790,770,3,0,3,3,charTongTrang6);
					nodehk find;
					int xx = 335; int yy = 190+55;
					char text[][50]={"STT","So Ve","CCCD","Ho","Ten","Gioi Tinh"};
					int m[6] = {90,90,200,170,220,150}; //sum = 900;
					taoBang(335,190,55,m,6,10,text,15,0);
				    for(int i=0; i<9 && i < ptr->data.dsv.n ;i++)
				    {
				    	
				    	find = SearchHk(root,ptr->data.dsv.ve[i]->CCCD);
				    	cout<<i+1<<"  "<<ptr->data.dsv.ve[i]->stt<<"  "<<find->data.CCCD<<"  "<<find->data.HO<<" "<<find->data.TEN<<" "<<find->data.GioiTinh<<endl;
				    	char tempi[10] = "";
				    	IntToChar(i+1,tempi);
				    	OUTTEXT(xx+12,yy+15,15,0,3,3,tempi);
				    	char tempve[10] = "";
				    	IntToChar(ptr->data.dsv.ve[i]->stt,tempve);
				    	
						OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,tempve);
						OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,find->data.CCCD);
						OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,find->data.HO);
						OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,find->data.TEN);
						OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3]+m[4],yy+15,15,0,3,3,find->data.GioiTinh);
				    	yy+=55;
						}
						if(trang6==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
					  	else taoID(395,760,445,810,60001);
						if(tongtrang6>1) taoID(1130,760,1180,810,60002); // TAO ID NUT NEXT
						if(trang6==tongtrang6) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 
					}	
				x=-1;y=-1;
				break;
			}
			case 60001:{ //BACK
				taoButton(395,760,445,810,60001,15,1,2,"<");
 			  	delay(50);
 			  	taoButton(395,760,445,810,0,7,0,2,"<");	
				if(SearchNode(pheadDSCB,ID6)!=NULL ){ // SEARCH ID CHUYENBAY FUNCTION
					UpdateCB(pheadDSCB);
					FileOutVe(VEO,pheadDSCB);
					NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID6);
				 	trang6 -= 1;
					tongtrang6 = ptr->data.dsv.n/9;
					if (ptr->data.dsv.n%9 != 0) tongtrang6 +=1;
					IntToChar(tongtrang6,charTongTrang6);
					IntToChar(trang6,charTrang6);
					OUTTEXT(730,770,3,1,3,3,charTrang6);
					OUTTEXT1(760,770,3,0,3,3);
					OUTTEXT(790,770,3,0,3,3,charTongTrang6);
					nodehk find;
					int xx = 335; int yy = 190+55;
					char text[][50]={"STT","So Ve","CCCD","Ho","Ten","Gioi Tinh"};
					int m[6] = {90,90,200,170,220,150}; //sum = 900;
					taoBang(335,190,55,m,6,10,text,15,0);
					for(int i=0; i<9 && 9*(trang6-1)+i < ptr->data.dsv.n  ;i++)
					{
					    	find = SearchHk(root,ptr->data.dsv.ve[9*(trang6-1)+i]->CCCD);
					    	cout<<9*(trang6-1)+i+1<<"  "<<ptr->data.dsv.ve[9*(trang6-1)+i]->stt<<"  "<<find->data.CCCD<<"  "<<find->data.HO<<" "<<find->data.TEN<<" "<<find->data.GioiTinh<<endl;
					    	char tempi[10] = "";
					    	IntToChar(9*(trang6-1)+i+1,tempi);
					    	OUTTEXT(xx+12,yy+15,15,0,3,3,tempi);
					    	char tempve[10] = "";
					    	IntToChar(ptr->data.dsv.ve[9*(trang6-1)+i]->stt,tempve);
					    	
							OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,tempve);
							OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,find->data.CCCD);
							OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,find->data.HO);
							OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,find->data.TEN);
							OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3]+m[4],yy+15,15,0,3,3,find->data.GioiTinh);
					    	yy+=55;
						}
					if(trang6==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
				  	else taoID(395,760,445,810,60001);
					if(tongtrang6>1) taoID(1130,760,1180,810,60002); // TAO ID NUT NEXT
					if(trang6==tongtrang6) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT
				}

 			  	x=-1;y=-1;
				break;
			}
			case 60002:{ // NEXT
				taoButton(1130,760,1180,810,0,15,1,2," >");
				delay(50);
				taoButton(1130,760,1180,810,0,7,0,2," >");
				if(SearchNode(pheadDSCB,ID6)!=NULL ){ // SEARCH ID CHUYENBAY FUNCTION
					UpdateCB(pheadDSCB);
					FileOutVe(VEO,pheadDSCB);
					NodeChuyenBay* ptr = SearchNode(pheadDSCB,ID6);
					trang6 += 1;
					tongtrang6 = ptr->data.dsv.n/9;
					if (ptr->data.dsv.n % 9 != 0) tongtrang6 +=1;
					IntToChar(tongtrang6,charTongTrang6);
					IntToChar(trang6,charTrang6);
					OUTTEXT(730,770,3,1,3,3,charTrang6);
					OUTTEXT1(760,770,3,0,3,3);
					OUTTEXT(790,770,3,0,3,3,charTongTrang6);
					nodehk find;
					int xx = 335; int yy = 190+55;
					char text[][50]={"STT","So Ve","CCCD","Ho","Ten","Gioi Tinh"};
					int m[6] = {90,90,200,170,220,150}; //sum = 900;
					taoBang(335,190,55,m,6,10,text,15,0);
					for(int i=0; i<9 &&  9*(trang6-1)+i < ptr->data.dsv.n ;i++)
					{
					    find = SearchHk(root,ptr->data.dsv.ve[9*(trang6-1)+i]->CCCD);
					    cout<<9*(trang6-1)+i+1<<"  "<<ptr->data.dsv.ve[9*(trang6-1)+i]->stt<<"  "<<find->data.CCCD<<"  "<<find->data.HO<<" "<<find->data.TEN<<" "<<find->data.GioiTinh<<endl;
					    char tempi[10] = "";
					    IntToChar(9*(trang6-1)+i+1,tempi);
					   	OUTTEXT(xx+12,yy+15,15,0,3,3,tempi);
					   	char tempve[10] = "";
					   	IntToChar(ptr->data.dsv.ve[9*(trang6-1)+i]->stt,tempve);
					    	
						OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,tempve);
						OUTTEXT(xx+12+m[0]+m[1],yy+15,15,0,3,3,find->data.CCCD);
						OUTTEXT(xx+12+m[0]+m[1]+m[2],yy+15,15,0,3,3,find->data.HO);
						OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3],yy+15,15,0,3,3,find->data.TEN);
						OUTTEXT(xx+12+m[0]+m[1]+m[2]+m[3]+m[4],yy+15,15,0,3,3,find->data.GioiTinh);
					   	yy+=55;
					}
					if(trang6==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
				  	else taoID(395,760,445,810,60001);
					if(tongtrang6>1) taoID(1130,760,1180,810,60002); // TAO ID NUT NEXT
					if(trang6==tongtrang6) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 
				}
				x=-1;y=-1;
				break;
			}
			case 7:{
				Menu();
				ThongKeChuyenBay();
				SortMayBay(dsmb);
				trang7 = 1;
				tongtrang7 = dsmb.total/12;
				if (dsmb.total%12 != 0){
			   		tongtrang7 +=1;
				}
				IntToChar(tongtrang7,charTongTrang7);
				IntToChar(trang7,charTrang7);
				OUTTEXT(730,770,3,1,3,3,charTrang7);
				OUTTEXT1(760,770,3,0,3,3);
				OUTTEXT(790,770,3,0,3,3,charTongTrang7);
				int m[2] = {450,450};
				int xx = 335; int yy = 65;
				for(int i=0;i<12 && i < dsmb.total;i++){
					OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[i]->ID);
					char tempSoLuotBay[10] = "";
					IntToChar(dsmb.data[i]->SoLuotBay,tempSoLuotBay);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,tempSoLuotBay);
					yy+=55;
				}
				if(trang7==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
			  	else taoID(395,760,445,810,70001);
				if(tongtrang7>1) taoID(1130,760,1180,810,70002); // TAO ID NUT NEXT
				if(trang7==tongtrang7) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 
				x=-1,y=-1;
				break;
			}
			case 70001:{ //NUT BACK
				taoButton(395,760,445,810,70001,15,1,2,"<");
 			  	delay(50);
 			  	taoButton(395,760,445,810,70001,7,0,2,"<");
 			  	trang7 -= 1;
				tongtrang7 = dsmb.total/12;
				if (dsmb.total%12 != 0){
			   		tongtrang7 +=1;
				}
				IntToChar(tongtrang7,charTongTrang7);
				IntToChar(trang7,charTrang7);
				OUTTEXT(730,770,3,1,3,3,charTrang7);
				OUTTEXT1(760,770,3,0,3,3);
				OUTTEXT(790,770,3,0,3,3,charTongTrang7);
				char text[][50]={"ID May Bay","So Chuyen Bay Da Bay"};
				int m[2] = {450,450};
			   	taoBang(335,10,55,m,2,13,text,15,0);
				int xx = 335; int yy = 65;
				for(int i=0;i<12 &&  12*(trang7-1)+i < dsmb.total;i++){
					OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[12*(trang7-1)+i]->ID);
					char tempSoLuotBay[10] = "";
					IntToChar(dsmb.data[12*(trang7-1)+i]->SoLuotBay,tempSoLuotBay);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,tempSoLuotBay);
					yy+=55;
				}
				if(trang7==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
			  	else taoID(395,760,445,810,70001);
				if(tongtrang7>1) taoID(1130,760,1180,810,70002); // TAO ID NUT NEXT
				if(trang7==tongtrang7) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 
 			  	x=-1;y=-1;
				break;
			}
			case 70002:{ //NUT NEXT 
				taoButton(1130,760,1180,810,70002,15,1,2," >");
				delay(50);
				taoButton(1130,760,1180,810,70002,7,0,2," >");
				 trang7 += 1;
				tongtrang7 = dsmb.total/12;
				if (dsmb.total%12 != 0){
			   		tongtrang7 +=1;
				}
				IntToChar(tongtrang7,charTongTrang7);
				IntToChar(trang7,charTrang7);
				OUTTEXT(730,770,3,1,3,3,charTrang7);
				OUTTEXT1(760,770,3,0,3,3);
				OUTTEXT(790,770,3,0,3,3,charTongTrang7);
				char text[][50]={"ID May Bay","So Chuyen Bay Da Bay"};
				int m[2] = {450,450};
			   	taoBang(335,10,55,m,2,13,text,15,0);
				int xx = 335; int yy = 65;
				for(int i=0;i<12 && 12*(trang7-1)+i < dsmb.total;i++){
					OUTTEXT(xx+12,yy+15,15,0,3,3,dsmb.data[12*(trang7-1)+i]->ID);
					char tempSoLuotBay[10] = "";
					IntToChar(dsmb.data[12*(trang7-1)+i]->SoLuotBay,tempSoLuotBay);
					OUTTEXT(xx+12+m[0],yy+15,15,0,3,3,tempSoLuotBay);
					yy+=55;
				}
				if(trang7==1) taoID(395,760,445,810,0); // KO TAO ID NUT BACK
			  	else taoID(395,760,445,810,70001);
				if(tongtrang7>1) taoID(1130,760,1180,810,70002); // TAO ID NUT NEXT
				if(trang7==tongtrang7) taoID(1130,760,1180,810,0); // KO TAO ID NUT NEXT 
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
	DeleteTree(root);
	DeleteDSMB(dsmb);
	DeleteDSCB(pheadDSCB);
	while(!kbhit()) delay(1);
	system("pause");
    closegraph();
}



