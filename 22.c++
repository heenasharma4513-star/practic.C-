#include <iostream>
using namespace std;

class BankAccount {
private:
    string acctt;
    long accno;
    double bal;

    bool validamt(double amt) {
        return amt > 0;
    }

public:
    // Constructor
    BankAccount(string n, long m, double ibal) {
        acctt = n;
        accno = m;
        if (ibal >= 0)
            bal = ibal;
        else
            bal = 0;
    }

    string getAccountHolder() {
        return acctt;
    }

    long getAccNumber() {
        return accno;
    }

    double getBalance() {
        return bal;
    }

    void deposit(double amt) {
        if (validamt(amt)) {
            bal += amt;
            cout << "Deposited: " << amt << endl;
        } else {
            cout << "Invalid amount" << endl;
        }
    }

    void withdrawal(double amt) {
        if (validamt(amt) && amt <= bal) {
            bal -= amt;
            cout << "Withdrawn: " << amt << endl;
        } else {
            cout << "Insufficient balance or invalid amount" << endl;
        }
    }
};

int main() {
    BankAccount b("Ashika", 1234, 1000);   // Fixed constructor call

    b.deposit(2000);        // Fixed spelling
    b.withdrawal(3000);

    cout << "Current Balance: " << b.getBalance() << endl;

    return 0;
}
