/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: book_info.cpp
*Description:  This file contains all of the member functions of the singular book class that creates a book object
that can be used to populate a catalogue class. 
*/ 
#include "book_info.h"
using namespace std;

BookInfo::BookInfo(){
    author = "none";
    title = "none";
    ibsn = 0;
    id = 0;
    cost = 0.0;
    status = "IN";
}

BookInfo::BookInfo(string author, string title, int ibsn, int id, double cost, string status){
    this->author = author;
    this->title = title;
    this->ibsn = ibsn;
    this->id = id;
    this->cost = cost;
    this->status = status;
}

void BookInfo::SetAuthor(string authorname){
   author = authorname;
}
string BookInfo::GetAuthor() const{
    return author;
}

void BookInfo::SetTitle(string booktitle){
    title = booktitle;
}
string BookInfo::GetTitle() const{
    return title;
}

void BookInfo::SetIBSN(int numibsn){
    ibsn = numibsn;
}
int BookInfo::GetIBSN() const{
    return ibsn;
}

void BookInfo::SetID(int idnum){
    id = idnum;
}
int BookInfo::GetID() const{
    return id;
}
        
void BookInfo::SetCost(int newcost){
    cost = newcost;
}
double BookInfo::GetCost() const{
    return cost;
}

void BookInfo::SetStatus(string newstat){
    status = newstat;
}
string BookInfo::GetStatus() const{
    return status;
}
