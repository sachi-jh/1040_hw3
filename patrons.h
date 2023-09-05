/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: patrons.h
*Description:  This file contains the class definition of the Loans plural class and allows us to modify
the vector we created in the main function. 
*/ 

#include <iostream>
#include "patron_info.h"
#include <vector>
using namespace std;

class Patrons {
    public:
        void load();
        void store();
        bool NumberCheckedOut(int patid);
        bool ReturnBook(int patid);
        void SetFine(int id, double fine);
        void AddPatron();
        void EditPatron();
        //void EditCheckOuts(PatronInfo person);
        //void EditBalance();
        void EditPatrons();
        void DeletePatron();
        PatronInfo SearchByID(int id);
        void PayFines();
        void PrintPatrons();
        void PrintIndividualDetails(PatronInfo patron);
    
    private:
        int count;
        vector<PatronInfo> patronlist;

};