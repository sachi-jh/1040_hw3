/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: book_info.cpp
*Description:  This file is the header for book_info.h. Here we declare the class and all of the members 
*/ 
#include <iostream>
using namespace std;

class BookInfo{
    public:
        BookInfo();
        BookInfo(string author, string title, int ibsn, int id, double cost, string status);
        void SetAuthor(string authorname);
        string GetAuthor() const;
        void SetTitle(string booktitle);
        string GetTitle() const;
        void SetIBSN(int numibsn);
        int GetIBSN() const;
        void SetID(int idnum);
        int GetID() const;
        void SetCost(int newcost);
        double GetCost() const;
        void SetStatus(string newstat);
        string GetStatus() const;

    private:
        string author;
        string title;
        int ibsn;
        int id;
        double cost;
        string status;
};