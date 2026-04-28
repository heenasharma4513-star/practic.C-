#include <iostream>
using namespace std;

class StudentResult
{
private:
    int marks[5];
    float average;
    int highest;

public:
    void input()
    {
        cout << "Enter marks of 5 subjects:\n";
        for(int i = 0; i < 5; i++)
        {
            cin >> marks[i];
        }
    }

    void calculateAverage()
    {
        int sum = 0;
        for(int i = 0; i < 5; i++)
        {
            sum += marks[i];
        }
        average = sum / 5.0;
    }

    void findHighest()
    {
        highest = marks[0];
        for(int i = 1; i < 5; i++)
        {
            if(marks[i] > highest)
            {
                highest = marks[i];
            }
        }
    }

    void displayResult()
    {
        cout << "Average Marks = " << average << endl;
        cout << "Highest Marks = " << highest << endl;
    }
};

int main()
{
    StudentResult s;

    s.input();
    s.calculateAverage();
    s.findHighest();
    s.displayResult();

    return 0;
}