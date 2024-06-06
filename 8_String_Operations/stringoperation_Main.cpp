#include "stringoperation.h"

int main() {
	bool exit = false;
	char input_Str[100];

	MyString str1, str2, str3;

	while (exit == false)
	{
		system("cls");
		int programme_no;
		cout << "\n ##Please enter one option from below program list :\n------------------------------------------------------------------------------------\n\n";
		cout << " 1) Conversion of lower case string to upper case string \n 2) Conversion of upper case string to lower case string \n 3) string reverse \n 4) Concatenate Two Strings \n 5) Copy One String into Another String \n 6) Find & Replace One String from Another String \n 7) Exit";
		cout << "\n \n------------------------------------------------------------------------------------\n" << endl;
		cin >> programme_no;
		cin.clear();

		switch (programme_no)
		{
		case 1:
			cout << "\nEnter First String in lower case     :	";
			cin.ignore();
			cin.getline(input_Str, 100);
			str1.SetString(input_Str);

			cout << "\nEnter Second String in lower case    :	";
			cin.getline(input_Str, 100);
			str2.SetString(input_Str);

			str1.Concat(str2);

			cout << "\nEntered overall lower case string is :	";
			str1.Display();
			cout << "\nUpper case converted string is       :	";
			str1.ToUpper();
			cout << str1.ToUpper();
			_getch();
			break;

		case 2:
			cout << "\nEnter First String in upper case     :	";
			cin.ignore();
			cin.getline(input_Str, 100);
			str1.SetString(input_Str);

			cout << "\nEnter Second String in upper case    :	";
			cin.getline(input_Str, 100);
			str2.SetString(input_Str);

			str1.Concat(str2);

			cout << "\nEntered overall upper case string is :	";
			str1.Display();
			cout << "\nUpper case converted string is       :	";
			str1.ToLower();
			cout << str1.ToLower();
			_getch();
			break;

		case 3:
			cout << "\nEnter First String	  :	";
			cin.ignore();
			cin.getline(input_Str, 100);
			str1.SetString(input_Str);

			cout << "\nEnter Second String	  :	";
			cin.getline(input_Str, 100);
			str2.SetString(input_Str);

			str1.Concat(str2);

			cout << "\nEntered overall string is :	";
			str1.Display();
			cout << "\nReversed string		  :	";
			cout << str1.StringReverse();
			_getch();
			break;

		case 4:
			cout << "\nEnter First String	:	";
			cin.ignore();
			cin.getline(input_Str, 100);
			str1.SetString(input_Str);

			cout << "\nEnter Second String	:	";
			cin.getline(input_Str, 100);
			str2.SetString(input_Str);

			str1.Concat(str2);

			cout << "\nConcatenated String is  :	";
			str1.Display();

			_getch();
			break;

		case 5:
			cout << "\nEnter First String   :  ";
			cin.ignore();
			cin.getline(input_Str, 100);
			str1.SetString(input_Str);

			cout << "\nEnter Second String  :  ";
			cin.getline(input_Str, 100);
			str2.SetString(input_Str);

			str1.CopyString(str2);

			cout << "\nCopied String is     :  ";
			str1.Display();
			_getch();
			break;

		case 6:
			cout << "\nEnter Primary String  :  " << endl;
			cin.ignore();
			cin.getline(input_Str, 100);
			str1.SetString(input_Str);

			cout << "\nEnter String to Find in Primary String  :  " << endl;
			cin.getline(input_Str, 100);
			str2.SetString(input_Str);

			cout << "\nEnter String to Replace in Primary String  :  " << endl;
			cin.getline(input_Str, 100);
			str3.SetString(input_Str);

			str1.Replace(str2, str3);

			cout << "\nUpdated Primary String is  :  " << endl << endl;
			str1.Display();
			_getch();
			break;
		case 7:
			exit = true;
			_getch();
			break;
		}

		cout << "\n\n------------------------------------------------------------------------------------\n";
		_getch();
	}

	_getch();
	return 0;
}