// How to read

#include <iostream>


using namespace std;

void print(int n){
	int hundred = n / 100;
	int	tenth = (n - hundred*100)/10;
	int unit = n%10;
	if (n!=0){
	
		switch (hundred){
			case 1: cout << "one ";break;
			case 2: cout << "two ";break;
			case 3: cout << "three ";break;
			case 4: cout << "four ";break;
			case 5:	cout << "five ";break;
			case 6:	cout << "six ";break;
			case 7:	cout << "seven ";break;
			case 8:	cout << "eight ";break;
			case 9:	cout << "nine ";break;
			}
		if (hundred != 0) cout << "hundred ";
		if ( n % 100 < 20)
			switch (n%100) {
			case 1:	cout << "one ";break;
			case 2:	cout << "two ";break;
			case 3:	cout << "three ";break;
			case 4:	cout << "four ";break;
			case 5:	cout << "five ";break;
			case 6:	cout << "six ";break;
			case 7:	cout << "seven ";break;
			case 8:	cout << "eight ";break;
			case 9:	cout << "nine ";break;
			case 10: cout << "ten ";break;
			case 11: cout << "eleven ";break;
			case 12: cout << "twelve ";break;
			case 13: cout << "thirteen ";break;
			case 14: cout << "fourteen ";break;
			case 15: cout << "fifteen ";break;
			case 16: cout << "sixteem ";break;
			case 17: cout << "seventeen ";break;
			case 18: cout << "eighteen ";break;
			case 19: cout << "nineteen ";break;
			} 
			else {
			switch (tenth){
				case 2: cout << "twenty ";break;
				case 3: cout << "thirty ";break;
				case 4: cout << "fourty ";break;
				case 5: cout << "fifty ";break;
				case 6: cout << "sixty ";break;
				case 7: cout << "seventy ";break;
				case 8: cout << "eighty ";break;
				case 9: cout << "ninety ";break;
			}
			if (unit != 0)
				switch (unit ){
				case 1:	cout << "one ";break;
				case 2:	cout << "two ";break;
				case 3: cout << "three ";break;
				case 4: cout << "four ";break;
				case 5: cout << "five ";break;
				case 6: cout << "six ";break;
				case 7: cout << "seven ";break;
				case 8: cout << "eight ";break;
				case 9: cout << "nine ";break;
				}
		}
	}
}
void readNumber(int n){
	int million = n / 1000000;
	int thousand = (n-million*1000000) / 1000;
	int leftOver = n % 1000;
	if (million != 0){
		print(million);cout << "million ";
		print(thousand);if (thousand != 0) cout << "thousand ";
		print(leftOver);
	} else{
		if (thousand != 0){
			print(thousand); cout << "thousand ";
			print(leftOver);
		} else print(leftOver);
	}
}
int main()
{
	long n;
	int isNegative;
	cin >> n;
	if (n < 0) {
		n = -n;
		isNegative = 1;
	}
	if (n == 0){
		cout << "Zero"; return 0;
	}
	if (isNegative == 1)
		cout << "Negative ";
	readNumber(n);
}
