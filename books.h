/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: books.h
*Description:  This file defines the books class and shows all its member functions. Some of them were added later on so they do not 
exactly match the planning 
*/ 
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "book_info.h"
using namespace std;

class Books {
    public:
        void load();
        void store();
        bool CheckBookStatus(int bid);
        bool ReturnBooks(int bid);
        double returnPrice(int id);
        void AddBook();
        void EditBook();
        void DeleteBook();
        BookInfo SearchByID(int id);
        void PrintCollection();
        void PrintDetails(BookInfo book);

    private:
        int count;
        vector<BookInfo> catalogue;
};