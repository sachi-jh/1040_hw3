/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: loan_info.cpp
*Description:  This file contains all of the function definitions of the singular loan object class, including default constructors.
*/ 

#include <iostream>
#include "loan_info.h"

LoanInfo::LoanInfo(){
    loanid = 0;
    bookid = 0;
    patronid = 0;
    status = "none";
    recheck = false;
}
LoanInfo::LoanInfo(int l, int b, int p, string s, bool recheck, time_t c, time_t d){
    loanid = l;
    bookid = b;
    patronid = p;
    status = s;
    recheck = false;
    checkout = c;
    due = d;
}
void LoanInfo::SetLoanID(int id){
    loanid = id;
}

int LoanInfo::GetLoanID(){
    return loanid;
}

void LoanInfo::SetBookID(int id){
    bookid = id;
}

int LoanInfo::GetBookID(){
    return bookid;
}

void LoanInfo::SetPatronID(int id){
    patronid = id;
}

int LoanInfo::GetPatronID(){
    return patronid;
}

void LoanInfo::SetStatus(string stat){
    status = stat;
}

string LoanInfo::GetStatus(){
    return status;
}

void LoanInfo::SetRechecked(int r){
    recheck = r;
}

int LoanInfo::GetRechecked(){
    return recheck;
}

void LoanInfo::SetCheckoutDate(time_t coDate){
    checkout = coDate;
}

time_t LoanInfo::GetCheckoutDate(){
    return checkout;
}

void LoanInfo::SetDueDate(time_t dd){
    due = dd;
}

time_t LoanInfo::GetDueDate(){
    return due;
}