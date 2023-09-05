/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: patron_info.cpp
*Description:  This file contains the functions that set and modify information for each of the patron objects
*/ 

#include <iostream>
#include "patron_info.h"

PatronInfo::PatronInfo(){
    name = "none";
    id = 0;
    fines = 0.0;
    booksout = 0;
}

PatronInfo::PatronInfo(string n, int i, double f, int b){
    name = n;
    id = i;
    fines = f;
    booksout = b;
}
void PatronInfo::SetName(string n){
    name = n;
}

string PatronInfo::GetName() const{
    return name;
}

void PatronInfo::SetID(int i){
    id = i;
}

int PatronInfo::GetID() const{
    return id;
}

void PatronInfo::SetBalance(double f){
    fines = f;
}

double PatronInfo::GetBalance() const{
    return fines;
}

void PatronInfo::SetBooksCheckedOut(int b){
    booksout = b;
}

int PatronInfo::GetBooksCheckedOut() const{
    return booksout;
}
