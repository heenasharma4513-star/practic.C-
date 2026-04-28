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
    tm = 0;   // reset total for each student

    cout << "\nEnter student details " << endl;
    cout << "Enter id : " ;
    cin >> id;

    cout <<"Enter name : ";
    cin >> name ;

    cout <<"Enter 5 marks : " << endl;
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
    else if(p > 80)
        g = 'A';
    else if(p > 70)
        g = 'B';
    else if(p > 60)
        g = 'C';
    else
        g = 'F';
}

void student :: print()
{
    cout << id << "\t" << name << "\t" 
         << tm << "\t" << p << "\t" << g << endl;
}

int main(){

    int n;
    cout << "How many students? ";
    cin >> n;

    student s[n];   // array of objects

    // Input + Calculation
    for(int i = 0; i < n; i++){
        s[i].input();
        s[i].cal();
    }

    cout << "\nID\tName\tTotal\tPercentage\tGrade\n";

    // Print all students
    for(int i = 0; i < n; i++){
        s[i].print();
    }

    return 0;
}
