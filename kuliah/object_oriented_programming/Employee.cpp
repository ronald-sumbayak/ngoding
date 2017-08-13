#include <cstdio>
#include <vector>

class Employee {

protected:
    const char *mFirstName, *mLastName, *mSocialSecurityNumber;
    double mWage;

public:
    Employee (const char *firstName, const char *lastName, const char *ssn, double wage) {
        mFirstName = firstName;
        mLastName = lastName;
        mSocialSecurityNumber = ssn;
        mWage = wage;
    }
    
    const char *getFirstName () const { return mFirstName; }
    const char *getLastName () const { return mLastName; }
    const char *getSSN () const { return mSocialSecurityNumber; }
    double getWage () const { return mWage; }
    void setFirstName (const char *firstName) { mFirstName = firstName; }
    void setLastName (const char *lastName) { mLastName = lastName; }
    void setSSN (const char *ssn) { mSocialSecurityNumber = ssn; }
    void setWage (double wage) { mWage = wage; }
    
    virtual void print () {
        printf ("Name: %s %s\n", mFirstName, mLastName);
        printf ("Wage: %lf\n", mWage);
        printf ("Social Security Number: %s\n", mSocialSecurityNumber);
    }
};

class PieceWorker : public Employee {
    
    int mPieces;
    
public:
    PieceWorker (const char *firstName, const char *lastName, const char *ssn, double wage, int pieces) 
        : Employee (firstName, lastName, ssn, wage) {
        mPieces = pieces;
    }
    
    int getPieces () const { return mPieces; }
    void setPieces (int pieces) { mPieces = pieces; }
    
    double earnings () {
        return mWage * mPieces;
    }
    
    void print () {
        Employee::print ();
        printf ("Pieces: %d\n", mPieces);
        printf ("Earnings: %lf", earnings ());
    }
};

class HourlyWorker : public Employee {

    int mHours;

public:
    HourlyWorker (const char *firstName, const char *lastName, const char *ssn, double wage, int hours)
        : Employee (firstName, lastName, ssn, wage) {
        mHours = hours;
    }
    
    double earnings () {
        if (mHours <= 40) return mWage * mHours;
        else return (mWage * 40) + (mWage * 1.5 * (mHours - 40));
    }
    
    int getHours () const { return mHours; }
    void setHours (int hours) { mHours = hours; }
    
    void print () {
        Employee::print ();
        printf ("Pieces: %d\n", mHours);
        printf ("Earnings: %lf", earnings ());
    }
};

int main () {
    std::vector<Employee*> employeeList;
    
    int employeeNumber;
    scanf ("%d", &employeeNumber);
    
    while (employeeNumber--) {
        std::vector<Employee*>::iterator it;
        char *fName, *lName, *ssn;
        fName = new char [20];
        lName = new char [20];
        ssn = new char [20];
        
        double 
    }
    std::vector<Employee*>::iterator it;
    
    it = employeeList.begin ();
    employeeList.insert (it, new HourlyWorker ("Ronald", "Andrean", "xxx", 5000.0, 40));
    it++;
    
    employeeList.operator[] (0)->print ();
    //......
}
