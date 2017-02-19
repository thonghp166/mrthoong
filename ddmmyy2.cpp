// dmyy

#include <iostream>
#include <cstdlib>

using namespace std;

int d1[]= {31,28,31,30,31,30,31,31,30,31,30,31};
int d2[]= {31,29,31,30,31,30,31,31,30,31,30,31};

void Leap(int d, int m,int y, int k);
void notLeap (int d, int m, int y, int k);
int isLeapYear(int a)
{
	if (a % 400 == 0|| (a % 100 != 0 && a % 4 == 0))
		return 1;
	else return 0;
}

void Leap(int day, int month, int year, int k)
{
	int d = day, m = month, y = year;
	
		while (d + k > d2[m-1]) {
			k = d + k -d2[m-1]; d = 0;
			if (m != 12){
				m++;
			} else {
				m = 1;y++;
				if (isLeapYear(y) == 0) {
					notLeap(d,m,y,k);exit(1);
				} else { Leap(d,m,y,k);exit(1);}
			}
		}
		if (d+k > 0 )
			cout << d+k << "-" << m << "-" << y << endl;
		else {
			while (d+k <= 0) {
				k = d + k; d=d2[m-1];
				if (m!=1){
					m--;
				} else{
					m = 12;y--;
					if (isLeapYear(y) == 0) {
						notLeap(d,m,y,k);exit(1);
					} else { Leap(d,m,y,k);exit(1);}
				}
			}
			cout << d << "-" << m <<"-"<< y << endl;
		}
}

void notLeap(int day, int month, int year, int k)
{
	int d = day, m = month, y = year;
		while (d + k > d1[m-1]) {
			k = d + k -d1[m-1]; d = 0;
			if (m != 12){
				m++;
			} else {
				m = 1;y++;
				if (isLeapYear(y) == 0) {
					notLeap(d,m,y,k);exit(1);
				} else { Leap(d,m,y,k);exit(1);}
			}
		}
		if (d+k > 0 )
			cout << d+k << "-" << m << "-" << y << endl;
		else {
			while (d+k <= 0) {
				k = d + k; d=d1[m-1];
				if (m!=1){
					m--;
				} else{
					m = 12;y--;
					if (isLeapYear(y) == 0) {
						notLeap(d,m,y,k);exit(1);
					} else { Leap(d,m,y,k);exit(1);}
				}
			}
			cout << d+k << "-" << m << "-" << y << endl;
		}
}

void printDate(int day, int month, int year, int k)
{
	int d = day, m = month, y = year;
	if (isLeapYear(y) == 0) notLeap(d,m,y,k);
	else Leap(d,m,y,k);
}
int main()
{
	int d,m,y;
	cout << "Enter your date: ";
	cin >> d >> m >> y;

	int integers[1000],count = 0;
	
	do {
		cout << endl << "Enter your number: ";
		cin >> integers[count];
		count ++;
	} while (integers[count-1] != 0);
	
	for (int i = 0; i < count-1;i++) {
		printDate(d,m,y,integers[i]);
	}
	return 0;
}
