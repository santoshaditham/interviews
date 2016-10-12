#include <iostream>
using namespace std;

int DaysInMonth(int m, int y){
	if(m==2) {
		if(y%4 == 0)
			return 29;
		else
			return 28;
	}
	else if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
		return 31;
	else
		return 30;
}

int findDays(int year1, int month1, int day1, int year2, int month2, int day2){
	int days=0;
	
	int y1 = (year1-year2 > 0) ? year2 : year1;
	int y2 = (year1-year2 > 0) ? year1 : year2;
	
	int m1 = (y1 == year1) ? month1 : month2;
	int m2 = (y1 == year1) ? month2 : month1;
	
	while(y1 < y2 && m1 <= 12){
		days += DaysInMonth(m1, y1);
		m1++;
		if(m1==12) {
			days += 31; //add days in december and go to next year
			m1=1;
			y1++;
		}
	}
	
	if(y1==y2){
		while(m1 < m2){
			days += DaysInMonth(m1, y1);
			m1++;
		}
		days -= (m1 == month1) ? day1 : day2; //subtract days from first month
		days += (m1 == month1) ? day2 : day1; //add days from last month
	}
	
	return days;
}

int main() {
	cout << findDays(2015, 10, 10, 2016, 10, 10) << endl;
	return 0;
}
