#include <cstdio>

class Account {

protected:
    
    double mBalance;

public:
    
    Account (double balance) {
        if (balance > 0.0) mBalance = balance;
        else mBalance = 0.0;
    }
    
    virtual bool debit (double value) {
        if (value <= mBalance) mBalance -= value;
        else {
            mBalance = 0.0;
            printf ("Debit amount exceeded account balance\n");
        }
    }
    
    virtual void credit (double value) {
        mBalance += value;
    }
    
    double getBalance () {
        return mBalance;
    }
};

class SavingsAccount : public Account {
    
    double mInterest;
    
public:
    
    SavingsAccount (double balance, double interest) : Account (balance) {
        mInterest = interest / 100;
    }
    
    double calculateInterest () {
        return mInterest * mBalance;
    }
};

class CheckingAccount : public Account {
    
    double mFee;
    
public:
    
    CheckingAccount (double balance, double fee) : Account (balance) {
        mFee = fee;
    }
    
    bool debit (double value) {
        if (value + mFee <= mBalance) {
            mBalance -= (value + mFee);
            return true;
        }
        else {
            mBalance = 0.0;
            return false;
        }
    }
    
    void credit (double value) {
        mBalance += value;
        mBalance -= mFee;
    }
};

int main () {
    SavingsAccount ronald (10.0, 15.0);
    ronald.credit (ronald.calculateInterest ());
    printf ("%lf", ronald.getBalance ());
}