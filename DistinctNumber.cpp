//

#include<iostream>

using namespace std;

int main()
{
	int number1, number2 = -2;
	
	do {
		cin >> number1;
		if (number1 != number2 && number2 != -2)
			cout << number2 << " ";
		number2 = number1;
	} while (number2 != -1);
	cout << number2;
	return 0;
}
