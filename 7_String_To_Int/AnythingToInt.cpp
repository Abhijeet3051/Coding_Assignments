
#include <iostream>
#include <string>

using namespace std;

int atoi(char* str) {
	int num = 0;
	int i = 0;
	while (*(i + str) != '\0')
	{
		num = num * 10 + (*(i + str) - '0');
		i++;
	}
	return num;
}

int main()

{
	string x, y;
	cout << "Enter First Integer string	:	" << x;
	cin >> x;
	cout << endl;
	cout << "Enter Second Integer string	:	" << y;
	cin >> y;
	cout << endl;
	string str = x + y;
	cout << "Entered string is :		" << str;
	cout << endl << endl;
	cout << "The length of the Total string is: " << " " << str.length();
	cout << endl;

	char* a = const_cast<char*>(str.c_str());

	int number = atoi(a);

	cout << endl << "String to Integer: " << number << endl << endl;
	return 0;
}



