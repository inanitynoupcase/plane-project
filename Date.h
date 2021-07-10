#include<time.h>
#include<iostream>
using namespace std;
int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct Date
{
    int hour;
	int min;
	int day;
	int mon;
	int year;
};

bool CheckDepartTime(Date dt)
{
	
	time_t now=time(0);
	tm *ltm=localtime(&now);
	Date DtNow; 
	DtNow.day=ltm->tm_mday;
	DtNow.mon=1+ltm->tm_mon; //0 -> 11
	DtNow.year=1900+ltm->tm_year; //TINH TU 1900
	DtNow.hour=ltm->tm_hour;
	DtNow.min=ltm->tm_min;
	
	
	
	if(dt.year<DtNow.year) return false;
	if(dt.year==DtNow.year){
		if(dt.mon<DtNow.mon) return false;
			if(dt.mon==DtNow.mon){
				if(dt.day<DtNow.day) return false;
					if(dt.day==DtNow.day){
						if(dt.hour<DtNow.hour) return false;
						if(dt.hour==DtNow.hour){
							if(dt.min<=DtNow.min) return false;
						}
					}
			}
	}
	return true;
}


// thoi gian tuong lai
bool IsNearer(Date time1,Date time2)
{
	if(time1.year<time2.year) return true;
	else if(time1.year>time2.year) return false;
	else if(time1.year==time2.year)
	{
		if(time1.mon<time2.mon) return true;
		else if(time1.mon>time2.mon) return false;
		else if(time1.mon==time2.mon)
		{
			if(time1.day<time2.day) return true;
			else if(time1.day>time2.day) return false;
			else if(time1.day==time2.day)
			{
				if(time1.hour<time2.hour) return true;
				else if(time1.hour>time2.hour) return false;
				else if(time1.hour==time2.hour)
				{
					if(time1.min<time2.min) return true;
					else if(time1.min>time2.min) return false;
					else if(time1.min==time2.min) return false;
				}
			}
		}
	}

}

//thoi gian qua khu
bool IsNearer2(Date time1, Date time2)
{
		if(time1.year>time2.year) return true;
	else if(time1.year<time2.year) return false;
	else if(time1.year==time2.year)
	{
		if(time1.mon>time2.mon) return true;
		else if(time1.mon<time2.mon) return false;
		else if(time1.mon==time2.mon)
		{
			if(time1.day>time2.day) return true;
			else if(time1.day<time2.day) return false;
			else if(time1.day==time2.day)
			{
				if(time1.hour>time2.hour) return true;
				else if(time1.hour<time2.hour) return false;
				else if(time1.hour==time2.hour)
				{
					if(time1.min>time2.min) return true;
					else if(time1.min<time2.min) return false;
					else if(time1.min==time2.min) return false;
				}
			}
		}
	}
}

