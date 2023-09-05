/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: patrons.cpp
*Description:  This file contains all of the member functions of the patrons plural class and allows us to modify
the vector we created in the main function. 
*/ 

#include <iostream>
#include <fstream>
#include "patrons.h"
using namespace std;


void Patrons::load(){
    int vectorsize;
    ifstream fin;
    fin.open("patrons.dat");
    if (fin.fail()){
        cout<<"file failure";
        exit(1);
    }
    string name;
    int id;
    double fines;
    int booksout;

    fin>>vectorsize;
    for (int i=0; i< vectorsize; i++){
        fin>> id;
        fin.ignore();
        getline(fin, name);
        fin>> fines;
        fin>> booksout;
        PatronInfo patron (name, id, fines, booksout);
        patronlist.push_back(patron);
    }
    fin.close();
}

void Patrons::store(){
    ofstream fout;
    fout.open("patrons.dat");
    fout<<patronlist.size()<<endl;

    for (int i = 0; i < patronlist.size(); i++){
        fout<<patronlist.at(i).GetID()<<endl;
        fout<<patronlist.at(i).GetName()<<endl;
        fout<<patronlist.at(i).GetBalance()<<endl;
        fout<<patronlist.at(i).GetBooksCheckedOut()<<endl;
    }
    fout.close();
}

bool Patrons::NumberCheckedOut(int patid){
    //int userchoice;
    //cout<<"Would you like to checkout or return and item? (1.out, 2.in):";
    //cin>>userchoice;
    //int bookoutnum;
    
    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == patid){
            int currentbooks = patronlist.at(i).GetBooksCheckedOut();
            if (currentbooks == 6){
                cout<<"You cannot check out more books"<<endl;
                return false;
            } else if (currentbooks < 6){
                currentbooks +=1;
                patronlist.at(i).SetBooksCheckedOut(currentbooks);
                return true;
            }
        }
    }
    return false;
}

bool Patrons::ReturnBook(int patid){
    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == patid){
            patronlist.at(i).SetBooksCheckedOut(patronlist.at(i).GetBooksCheckedOut()-1);
            cout<<"Patron now has "<<patronlist.at(i).GetBooksCheckedOut()<<" books out."<<endl;
            return true;
        }
    }
    return false;
}
void Patrons::SetFine(int id, double fine){
    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == id){
            patronlist.at(i).SetBalance(patronlist.at(i).GetBalance()+fine);
        }
    }
}

void Patrons::AddPatron(){
    string name;
    int id;
    double fine;
    int booksout;

    cout<<"Enter patron name: ";
    cin.ignore();
    getline(cin, name);

    cout<<"Enter patron ID: ";
    cin>>id;

    cout<<"Enter patron account balance in $: ";
    cin>>fine;

    cout<<"Enter # of books checked out by patron: ";
    cin>>booksout;

    PatronInfo newpatron(name, id, fine, booksout);

    patronlist.push_back(newpatron);

}

void Patrons::EditPatron(){
    int userchoice;
    string name;
    int id;
    double fine;
    int booksout;
    cout<<"Enter ID # of patron to search: ";
    cin>>id;

    cout<<"Which part of the patron's info would you like to modify:"<<endl;
    cout<<"1. Name"<<endl;
    cout<<"2. ID"<<endl;
    cout<<"3. Fine Balance"<<endl;
    cout<<"4. Number of books checked out"<<endl;
    cin>>userchoice;

    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == id){
            if (userchoice == 1){
                cout<<"Enter new Name: ";
                cin.ignore();
                getline(cin, name);
                patronlist.at(i).SetName(name);
            } else if (userchoice ==2){
                cout<<"Enter new ID: ";
                cin>>id;
                patronlist.at(i).SetID(id);
            }else if (userchoice ==3){
                cout<<"Enter new Fine Balance: ";
                cin>> fine;
                patronlist.at(i).SetBalance(fine);
            }else if (userchoice ==4){
                cout<<"Enter new Number of Checkouts: ";
                cin>>booksout;
                patronlist.at(i).SetBooksCheckedOut(booksout);
            }else{
                cout<<"That is not a valid option"<<endl;
            }
        }
    }
}

void Patrons::DeletePatron(){
    int id;
    bool found = false;
    cout<<"Enter ID # of patron to delete: ";
    cin>>id;
    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == id){
            cout<<"Deleteing Patron ID#"<<patronlist.at(i).GetID()<<endl;
            patronlist.erase(patronlist.begin() + i);
            found = true;
        }
    }
    if (found = false){
        cout<<"This is an invalid ID"<<endl;
    }
}

PatronInfo Patrons::SearchByID(int id){
    PatronInfo patron;
    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == id){
            patron = patronlist.at(i);
        }
    }
    return patron;
}

void Patrons::PayFines(){
    int id;
    double amountpayed;
    double finetemp;
    bool found = false;
    cout<<"Enter ID # of patron to pay fines: ";
    cin>>id;
    for (int i = 0; i < patronlist.size(); i++){
        if (patronlist.at(i).GetID() == id){
            found = true;
            cout<<"How much money are they paying"<<endl;
            cin>>amountpayed;
            finetemp = patronlist.at(i).GetBalance();
            if(finetemp <= amountpayed){
                patronlist.at(i).SetBalance(0.0);
                cout<<"All fines are payed."<<endl;
            } else {
                patronlist.at(i).SetBalance(finetemp - amountpayed);
                cout<<"Not all the fines are payed"<<endl;
            }
            cout<<"New balace for patron is $"<<patronlist.at(i).GetBalance()<<endl;
        }
    }
    if (found = false){
        cout<<"This is an invalid ID"<<endl;
    }
}

void Patrons::PrintPatrons(){
    cout<<"Current Patron List:"<<endl;
    for (int i = 0; i < patronlist.size(); i++){
        cout<<"Name: "<< patronlist.at(i).GetName()<<endl;
        cout<<"ID#: "<<patronlist.at(i).GetID()<<endl;
    }
}

void Patrons::PrintIndividualDetails(PatronInfo patron){
    cout<<"Details for "<<patron.GetName()<<endl;
    cout<<"ID: "<<patron.GetID()<<endl;
    cout<<"Fine Balance: "<<patron.GetBalance()<<endl;
    cout<<"Number of Books checked out: "<<patron.GetBooksCheckedOut()<<endl;
}