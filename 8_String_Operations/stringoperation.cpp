#include "stringoperation.h"

MyString::MyString(void)
{
	m_ptr = nullptr;
	m_length = 0;
}

MyString :: ~MyString(void)
{
	delete m_ptr;
}

void MyString::SetString(char str[])
{
	int size = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		size++;
	}

	m_ptr = new char[size + 1];

	for (int i = 0; i <= size; i++)
	{
		m_ptr[i] = str[i];
	}

	this->m_length = size;
}

int MyString::Length_of_string()
{
	return m_length;
}

void MyString::Display()
{
	cout << m_ptr << endl;
}




//Lower case to Upper case function
char* MyString::ToUpper()
{
	char* ans = m_ptr;
	for (int i = 0; *ans != '\0'; ans++)
	{
		if (*ans >= 'a' && *ans <= 'z')
		{
			*ans = *ans - 32;
		}
	}
	return m_ptr;
}

// Upper case to Lower case function
char* MyString::ToLower()
{
	char* ans = m_ptr;
	for (int i = 0; *ans != '\0'; ans++)
	{
		if (*ans >= 'A' && *ans <= 'Z')
		{
			*ans = *ans + 32;
		}
	}
	return m_ptr;
}


// String reverse operation function
char* MyString::StringReverse()
{
	int k = m_length - 1;
	char temp;
	for (int i = 0; i <= k / 2; i++)
	{
		temp = *(m_ptr + i);
		*(m_ptr + i) = *(m_ptr + k - i);
		*(m_ptr + k - i) = temp;
	}
	return m_ptr;
}


void MyString::Concat(MyString& str)
{
	int i = m_length, k = 0;

	while (str.m_ptr[k] != '\0')
	{
		m_ptr[i] = str.m_ptr[k];
		i++;
		k++;
	}

	m_ptr[i] = '\0';
	m_length = m_length + str.m_length;
}


void MyString::CopyString(MyString& str)

{
	int i = 0, k = 0;
	while (str.m_ptr[k] != '\0')
	{
		m_ptr[i] = str.m_ptr[k];
		k++;
		i++;
	}
	m_ptr[i] = '\0';
}

//Finding substring in primary string

int MyString::Find(MyString& to_find)
{
	int j = 0, i = 0, position;
	bool notfound = false;

	while (m_ptr[j] != '\0')
	{
		if (m_ptr[j] == to_find.m_ptr[i])
		{
			position = j + 1;
			i++;

			while (to_find.m_ptr[i] != '\0')
			{
				j++;

				if (to_find.m_ptr[i] != m_ptr[j])
				{
					notfound = true;
					break;
				}

				i++;
			}

			if (notfound == true)
			{
				notfound = false;
				i = 0;
			}

			if (notfound == false && to_find.m_ptr[i] == '\0')
			{
				return position;
			}
		}

		j++;
	}

	if (m_ptr[j] == '\0')
		return -1;
}

//Replacing substring in primary string

void MyString::Replace(MyString& to_find, MyString& to_replace)
{
	int size = 0;

	if (to_find.m_length > to_replace.m_length)
	{
		size = m_length;
	}

	else
	{
		size = m_length + (to_replace.m_length - to_find.m_length);
	}

	MyString updatedstring;
	updatedstring.m_ptr = new char[size];

	int i = 0;
	int ans = Find(to_find);
	int j = 0;

	while (ans != -1)
	{
		while (m_ptr[i] != '\0')
		{
			if (i < ans - 1)
			{
				updatedstring.m_ptr[j++] = m_ptr[i];
			}

			if (i == ans - 1)
			{
				int k = 0;

				while (to_replace.m_ptr[k] != '\0')
				{
					updatedstring.m_ptr[j++] = to_replace.m_ptr[k];
					k++;
				}
			}

			if (i >= (ans - 1 + to_find.m_length))
			{
				updatedstring.m_ptr[j++] = m_ptr[i];
			}

			i++;
		}

		ans = -1;
	}

	updatedstring.m_ptr[j++] = '\0';
	int m = 0;

	while (updatedstring.m_ptr[m] != '\0')
	{
		m_ptr[m] = updatedstring.m_ptr[m];
		m++;
	}

	m_ptr[m] = '\0';
}