
#include"student.h"
using namespace std;

Student::Student()
{
	defaultMarks();
	m_fname = "\0";
	m_lname = "\0";
	m_rollNumber = NULL;
}

Student::Student(int rollNumber, string fname, string lname)
{
	defaultMarks();
	m_fname = fname;
	m_lname = lname;
	setRollNumber(rollNumber);
}

void Student::defaultMarks()
{
	m_marathiMarks = 0;
	m_hindiMarks = 0;
	m_englishMarks = 0;
	m_mathsMarks = 0;
	m_scienceMarks = 0;
	m_socialScienceMarks = 0;
}

void Student::setRollNumber(int rollNumber)
{
	m_rollNumber = rollNumber;
}

void Student::setMarathiMarks(int mark)
{
	if (mark > 0 && mark <= 100)
	{
		m_marathiMarks = mark;
	}
}

void Student::setHindiMarks(int mark)
{
	if (mark > 0 && mark <= 100)
	{
		m_hindiMarks = mark;
	}
}

void Student::setEnglishMarks(int mark)
{
	if (mark > 0 && mark <= 100)
	{
		m_englishMarks = mark;
	}
}

void Student::setMathsMarks(int mark)
{
	if (mark > 0 && mark <= 100)
	{
		m_mathsMarks = mark;
	}
}

void Student::setScienceMarks(int mark)
{
	if (mark > 0 && mark <= 100)
	{
		m_scienceMarks = mark;
	}
}

void Student::setSocialScienceMarks(int mark)
{
	if (mark > 0 && mark <= 100)
	{
		m_socialScienceMarks = mark;
	}
}

int Student::totalMarks()
{
	return m_marathiMarks + m_hindiMarks + m_englishMarks + m_scienceMarks + m_mathsMarks + m_socialScienceMarks;
}

char Student::grade()
{

	if (totalMarks() > 240)
	{
		return 'P';
	}
	else
		return 'F';
}