/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: patron_info.h
*Description:  This file contains the class definition of the patron object class 
*/ 

#include <iostream>
using namespace std;

class PatronInfo{
    public:
        PatronInfo();
        PatronInfo(string n, int i, double f, int b);
        void SetName(string n);
        string GetName() const;
        void SetID(int i);
        int GetID() const;
        void SetBalance(double f);
        double GetBalance() const;
        void SetBooksCheckedOut(int b);
        int GetBooksCheckedOut() const;

    private:
        string name;
        int id;
        double fines;
        int booksout;
};