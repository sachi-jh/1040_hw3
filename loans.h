/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: loans.h
*Description:  This file contains the class definition and member functions of the loans container class 
*/ 
#include <iostream>
#include <vector>
#include "loan_info.h"
#include "patrons.h"
#include "books.h"
using namespace std;

class Loans {
    public:
        void load();
        void store();
        void CheckOutABook(Patrons &p1, Books &b1);
        void CheckinABook(Patrons &p1, Books &b1);
        void PrintOverDue();
        void PrintAllofPatronLoan(int patid);
        void UpdateLoanStatus();
        void RecheckBook();
        void EditLoan();
        void ReportLost(Patrons &p1, Books &b1);

    private:
        vector<LoanInfo> loanlist;
        int count;
}; 
