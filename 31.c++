[12:04, 17/03/2026] Heena Sharma: #include <iostream>
using namespace std;

class Bankaccount
{
protected:
    double balance;

public:
    Bankaccount(double bal)
    {
        balance = bal;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void withdraw(double amount)
    {
        balance -= amount;
    }

    void checkbal()
    {
        cout << "Balance: " << balance << endl;
    }
};

class savingaccount : public Bankaccount
{
public:
    savingaccount(double bal) : Bankaccount(bal) {}

    void interest()
    {
        balance += balance * 0.05;
    }
};

int main()
{
    savingaccount SA(10000);

    SA.deposit(5000);
    SA.withdraw(2000);
    SA.checkbal();

    SA.interest();
    SA.checkbal();

    return 0;
}
