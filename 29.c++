*#include <iostream>
using namespace std;

class BankAcc
{
protected:
    double balance;

public:
    BankAcc(double bal)
    {
        balance = bal;
    }
    void deposit(double amount)
    {
        balance += amount;   
    }
    void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;  
        }
        else
        {
            cout << "Insufficient balance!" << endl;
        }
    }
    void checkBal()
    {
        cout << "Balance: " << balance << endl;
    }
};

class SavingAcc : public BankAcc
{
public:
    SavingAcc(double bal) : BankAcc(bal) {}
    void intRate()
    {
        balance += balance * 0.05;   
    }
};
int main()
{
    SavingAcc SA(10000);

    SA.checkBal();       // 10000
    SA.deposit(5000);
    SA.checkBal();       // 15000
    SA.withdraw(2000);
    SA.checkBal();       // 13000
    SA.intRate();
    SA.checkBal();       // 13650

    return 0;
}
