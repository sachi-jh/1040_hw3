/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: loan_info.h
*Description:  This file contains the class definition and all of the member functions of the singular loan object class 
*/ 
//TIME TIME TIMME TIME TIME DO THE TIME 
//do the crime do the time
#include <iostream>
using namespace std;
#include <time.h>

class LoanInfo {
    public:
        LoanInfo();
        LoanInfo(int l, int b, int p, string s, bool recheck, time_t c, time_t d);
        void SetLoanID(int id);
        int GetLoanID();
        void SetBookID(int id);
        int GetBookID();
        void SetPatronID(int id);
        int GetPatronID();
        void SetStatus(string stat);
        string GetStatus();
        void SetRechecked(int r);
        int GetRechecked();

        void SetCheckoutDate(time_t coDate);
        time_t GetCheckoutDate();
        void SetDueDate(time_t dd);
        time_t GetDueDate();

    private:
        int loanid;
        int bookid;
        int patronid;
        string status;
        int recheck;
        time_t checkout;
        time_t due;        
};