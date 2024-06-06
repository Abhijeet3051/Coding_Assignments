#pragma once
#include <iostream>
#include<conio.h>
#include<iomanip>


using namespace std;

class MyString

{
private:

	char* m_ptr;
	int m_length;

public:

	MyString(void);
	~MyString(void);
	void SetString(char str[]);
	int Length_of_string();
	void Display();
	void Concat(MyString& str);
	char* ToUpper();
	char* ToLower();
	char* StringReverse();
	void CopyString(MyString& str);
	int Find(MyString& to_find);
	void Replace(MyString& to_find, MyString& to_replace);


};
