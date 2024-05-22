#pragma once
#include<string>
using namespace std;


class Student
{
private:
    string m_fname, m_lname;
    int m_rollNumber;
    int m_marathiMarks, m_hindiMarks, m_englishMarks, m_mathsMarks, m_scienceMarks, m_socialScienceMarks;
public:
    Student();
    Student(int rollNumber, string fname, string lname);
    void defaultMarks();
    void setRollNumber(int rollNumber);  //name start with capital letter //pass string by  referrence
    void setMarathiMarks(int mark);
    void setHindiMarks(int mark);
    void setEnglishMarks(int mark);
    void setMathsMarks(int mark);
    void setScienceMarks(int mark);
    void setSocialScienceMarks(int mark);
    int getRollNumber() { return m_rollNumber; }
    string getFName() { return m_fname; }
    string getLName() { return m_lname; }
    int getMarathiMarks() { return m_marathiMarks; }
    int getHindiMarks() { return m_hindiMarks; }
    int getEnglishMarks() { return m_englishMarks; }
    int getMathsMarks() { return m_mathsMarks; }
    int getScienceMarks() { return  m_scienceMarks; }
    int getSocialScienceMarks() { return m_socialScienceMarks; }
    int totalMarks();
    char grade();
};