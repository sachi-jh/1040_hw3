//work on Delete, Search, and Prints Collection
/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: books.cpp
*Description:  This file contains all of the member functions of the Books plural class and allows us to modify
the vector we created in the main function. We can perform various functions on the catalogue as a whole and on individual books
*/ 
#include <fstream>
#include "books.h"
using namespace std;

void Books::load(){
    int vectorsize;
    ifstream fin;
    fin.open("books.dat");
    if (fin.fail()){
        cout<<"file failure";
        return;
    }
    string title;
    string author;
    int ibsn;
    int id;
    string status;
    double cost;
    BookInfo book;

    fin>>vectorsize;
    for (int i=0; i< vectorsize; i++){
        fin>> id;
        fin.ignore();
        getline(fin, author);
	//fin.ignore();
        getline(fin, title);
	//fin.ignore();
        getline(fin, status);
        fin>> cost;
        fin>> ibsn;
        fin.ignore();
        BookInfo book(author, title, ibsn, id, cost, status);
        catalogue.push_back(book);
    }
    fin.close();
}

void Books::store(){
    ofstream fout;
    fout.open("books.dat");
    fout<<catalogue.size()<<endl;

    for (int i = 0; i < catalogue.size(); i++){
        fout<<catalogue.at(i).GetID()<<endl;
        fout<<catalogue.at(i).GetAuthor()<<endl;
        fout<<catalogue.at(i).GetTitle()<<endl;
        fout<<catalogue.at(i).GetStatus()<<endl;
        fout<<catalogue.at(i).GetCost()<<endl;
        fout<<catalogue.at(i).GetIBSN()<<endl;
    }
    fout.close();
}

bool Books::CheckBookStatus(int bid){
    for (int i = 0; i <catalogue.size(); i++){
        if (catalogue.at(i).GetID() == bid){
            if (catalogue.at(i).GetStatus() != "in"){
                cout<<"This book is currently unavailable for checkout"<<endl;
                return false;
            } else {
                catalogue.at(i).SetStatus("out");
                return true;
            }
        }
    }
    return false;
}

bool Books::ReturnBooks(int bid){
    for (int i = 0; i <catalogue.size(); i++){
        if (catalogue.at(i).GetID() == bid){
            cout<<"Thank you for returning "<<catalogue.at(i).GetTitle()<<endl;
            catalogue.at(i).SetStatus("in");
            return true;
        }
    }
    return false;
}

double Books::returnPrice(int id){
    double price = 0;
    for (int i = 0; i < catalogue.size(); i++){
        if (catalogue.at(i).GetID() == id){
            price = catalogue.at(i).GetCost();
        }
    }
    return price;
}


void Books::AddBook(){      //asks user for info on book then appends the 
    string name;            //appends books to back of an array with all the books
    string author;
    int ibsn;
    int id;
    double cost;
    string status;
    cout<<"Enter book name: ";
    cin.ignore();
    getline(cin, name);
    //cin.ignore();

    cout<<"Enter book author: ";
    getline(cin, author);
    

    cout<<"Enter book IBSN #: ";
    cin>>ibsn;
    //cin.ignore();

    cout<<"Enter book ID: ";
    cin>>id;
    //cin.ignore();
    
    cout<<"Enter book cost: ";
    cin>>cost;
    //cin.ignore();

    cout<<"Enter book status (in/out/lost): ";
    cin>>status;
    //cin.ignore();
    BookInfo newbook(author, name, ibsn, id, cost, status);

    catalogue.push_back(newbook);
}

void Books::EditBook(){         //search book in main here we only edit
    int userchoice;
    string name;            //appends books to back of an array with all the books
    string author;
    int ibsn;
    int id;
    double cost;
    string status;
    cout<<"Enter ID # of book to search: ";
    cin>>id;

    cout<<"Which part of the book's info would you like to modify:"<<endl;
    cout<<"1. Title"<<endl;
    cout<<"2. Author"<<endl;
    cout<<"3. IBSN #"<<endl;
    cout<<"4. ID"<<endl;
    cout<<"5. Cost"<<endl;
    cout<<"6. Status"<<endl;
    cin>>userchoice;

    for (int i = 0; i < catalogue.size(); i++){
        if (catalogue.at(i).GetID() == id){
            if (userchoice == 1){
                cout<<"Enter new Title: ";
                cin.ignore();
                getline(cin, name);
                catalogue.at(i).SetTitle(name);
            } else if (userchoice ==2){
                cout<<"Enter new Author: ";
                cin.ignore();
                getline(cin, author);
                catalogue.at(i).SetAuthor(author);
            }else if (userchoice ==3){
                cout<<"Enter new IBSN: ";
                cin>> ibsn;
                catalogue.at(i).SetIBSN(ibsn);
            }else if (userchoice ==4){
                cout<<"Enter new ID: ";
                cin>>id;
                catalogue.at(i).SetID(id);
            }else if (userchoice ==5){
                cout<<"Enter new Cost: ";
                cin>>cost;
                catalogue.at(i).SetCost(cost);
            }else if (userchoice ==6){
                cout<<"Enter new Status: ";
                cin>> status;
                catalogue.at(i).SetStatus(status);
            }else {
                cout<<"That is not a valid option"<<endl;
            }
        }
    }
}

void Books::DeleteBook(){
    int id;
    cout<<"Enter ID # of book to delete: ";
    cin>>id;
    for (int i = 0; i < catalogue.size(); i++){
        if (catalogue.at(i).GetID() == id){
            cout<<"Deleteing Book ID#"<<catalogue.at(i).GetID()<<endl;
            catalogue.erase(catalogue.begin() + i);
        }
    }

    //BookInfo searchbook;
    //catalogue.erase(catalogue.begin() + )   //how to point to location of book?
}

BookInfo Books::SearchByID (int id){
    BookInfo book;
    for (int i = 0; i < catalogue.size(); i++){
        if (catalogue.at(i).GetID() == id){
            book = catalogue.at(i);
            //cout<<"Info for Book ID# "<<catalogue.at(i).GetID()<<endl;
            //cout<<"Title: "<<catalogue.at(i).GetTitle()<<endl;
            //cout<<"Author: "<<catalogue.at(i).GetAuthor()<<endl;
            //cout<<"Status: "<<catalogue.at(i).GetStatus()<<endl;
            //cout<<"Cost: $"<<catalogue.at(i).GetCost()<<endl<<endl;
        }
    }
    return book;

}
void Books::PrintCollection(){          //how much info to print?
    cout<<"Current Catalogue: "<<endl;
    for(int i = 0; i < catalogue.size(); i++){
        cout<<"Title: "<<catalogue.at(i).GetTitle()<<endl;
        cout<<"Author: "<<catalogue.at(i).GetAuthor()<<endl;
        //cout<<"IBSN #: "<<catalogue.at(i).GetIBSN()<<endl;
        //cout<<"ID #: "<<catalogue.at(i).GetID()<<endl;
        //cout<<"Cost: $"<<catalogue.at(i).GetCost()<<endl<<endl;
    }
}
void Books::PrintDetails(BookInfo book){
    cout<<"Details for "<<book.GetTitle()<<endl;
    cout<<"Author: "<<book.GetAuthor()<<endl;
    cout<<"IBSN: "<<book.GetIBSN()<<endl;
    cout<<"ID: "<<book.GetID()<<endl;
    cout<<"Cost: "<<book.GetCost()<<endl<<endl;
}