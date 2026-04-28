#include<iostream>
using namespace std;

class student 
{
    int id, tm = 0;
    char name[30];
    int marks[5];
    float p;
    char g;

public:
    void input();
    void cal ();
    void print();
};

void student :: input(){
    cout << "enter student details " << endl;
    cout << "enter id : " ;
    cin >> id;

    cout <<"enter name : ";
    cin >> name ;

    cout <<"enter marks : " << endl;
    for(int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }
}

void student :: cal()
{
    for(int i = 0 ; i < 5; i++)
        tm += marks[i];

    p = tm / 5.0;

    if(p > 90)
        g = 'O';
    else if(p > 80 && p <= 90)
        g = 'A';
    else if(p > 70 && p <= 80)
        g = 'B';
    else if(p > 60 && p <= 70)
        g = 'C';
    else
        g = 'F';
}

void student :: print()
{
    cout << "id" << "\tname\tTotal marks\tpercentage\tgrade" << endl;
    cout << id << "\t" << name << "\t" << tm << "\t\t" << p << "\t\t" << g << endl;
}

int main(){
    student s;
    s.input();
    s.cal();
    s.print();
    return 0;
}