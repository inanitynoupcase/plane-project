#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<cstdio>
#include"CTDL.h"
#pragma once
ofstream MBO; 
ifstream MBI;
void FileOutMB(ofstream &MBOut,NodeMayBay nodemb)
{
  MBOut.open("test.txt",ios::app);
  MBOut<<nodemb.data->ID<<" "<<nodemb.data->Type<<" "<<nodemb.data->Room<<" "<<nodemb.data->SoLuotBay<<" "<<nodemb.data->Active<<endl;
  MBOut.close();
}
