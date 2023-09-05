/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: loans.cpp
*Description:  This file contains all of the member functions of the Loans plural class and allows us to modify
the vector we created in the main function. 
*/ 

#include <iostream>
#include "loans.h"
#include "fstream"
//#include "patrons.h"
//0#include "books.h"
using namespace std;

void Loans::load(){
    int vectorsize;
    ifstream fin;
    fin.open("loans.dat");
    if (fin.fail()){
        cout<<"file failure";
        exit(1);
    }
    int loanid;
    int patronid;
    int bookid;
    string status;
    int recheck;
    time_t checkout;
    time_t due;

    fin>>vectorsize;
    for (int i=0; i< vectorsize; i++){
        fin>> loanid;
        fin>>patronid;
        fin>>bookid;
        fin>> status;
        fin>> recheck;
        fin>>checkout;
        fin>>due;
        LoanInfo loan(loanid, bookid, patronid, status, recheck, checkout, due);
        loanlist.push_back(loan);
    }
    fin.close();
}

void Loans::store(){
    ofstream fout;
    fout.open("loans.dat");
    fout<<loanlist.size()<<endl;

    for (int i = 0; i < loanlist.size(); i++){
        fout<<loanlist.at(i).GetLoanID()<<endl;
        fout<<loanlist.at(i).GetPatronID()<<endl;
        fout<<loanlist.at(i).GetBookID()<<endl;
        fout<<loanlist.at(i).GetStatus()<<endl;
        fout<<loanlist.at(i).GetRechecked()<<endl;
        fout<<loanlist.at(i).GetCheckoutDate()<<endl;
        fout<<loanlist.at(i).GetDueDate()<<endl;
    }
    fout.close();
}

void Loans::CheckOutABook(Patrons &p1, Books &b1){
    time_t checkoutDate, checkinDate;
    int loanid;
    int patid;
    int bookid;
    //LoanInfo newloan;
    checkoutDate = time(0);
    checkinDate = checkoutDate + 864000;
    char* due = ctime(&checkinDate);

    cout<<"Create new Loan"<<endl;
    cout<<"Enter loan ID: ";
    cin>>loanid;
    LoanInfo newloan;
    cout<<"Enter patron ID: ";
    cin>>patid;
    cout<<"Enter book ID: ";
    cin>>bookid;

    bool x = b1.CheckBookStatus(bookid);
    bool y = p1.NumberCheckedOut(patid);

    if (x && y){
        LoanInfo newloan(loanid, bookid, patid, "normal", 0, checkoutDate, checkinDate);
	loanlist.push_back(newloan);
        cout<<"Your items are due "<<due<<endl;
    } else {
        cout<<"Try again"<<endl;
    }
    
    //cout<<"Enter ID of book: ";
    //cin>>bid;

}
/*
void Loans::CheckOutABook(Patrons *p1, Books *b1){
    LoanInfo* loan;
    BookInfo* book;
    PatronInfo* patron;
    int loanID, bookID, patronID;
    int numbooks;

}*/

void Loans::CheckinABook(Patrons &p1, Books &b1){
    int loanid;
    int patid;
    time_t now = time(0);
    time_t due;
    time_t timedif;
    double fine;
    cout<<"Enter Loan ID: ";
    cin>>loanid;

    for(int i = 0; i< loanlist.size(); i++){
        if (loanlist.at(i).GetLoanID() == loanid){
            b1.ReturnBooks(loanlist.at(i).GetBookID());
            p1.ReturnBook(loanlist.at(i).GetPatronID());

            due = loanlist.at(i).GetDueDate();
            timedif = now - due;
            if (timedif > 0) {
                fine = (timedif/86400) * 0.25;
                cout<<"You have been fined $"<<fine<<endl;
                p1.SetFine(loanlist.at(i).GetPatronID(), fine);
            } else {
                cout<<"You turned in your items on time. There are no fines."<<endl;
            }
        }
    }

}

void Loans::PrintOverDue(){
    time_t now = time(0);
    
    for(int i = 0; i < loanlist.size(); i++){
        time_t due = loanlist.at(i).GetDueDate();
        time_t timediff = now - due;
        if (timediff > 0){
            cout<<"Over Due Items:"<<endl;
            cout<<"Loan ID: "<<loanlist.at(i).GetLoanID()<<" Book ID: "<<loanlist.at(i).GetBookID()
            <<" Patron ID: "<<loanlist.at(i).GetPatronID()<<endl;
        }
    }
}

void Loans::PrintAllofPatronLoan(int patid){
    for(int i = 0; i <loanlist.size(); i++){
        if (loanlist.at(i).GetPatronID() == patid){
            cout<<"Loan ID: "<<loanlist.at(i).GetLoanID()<<" Book ID: "<<loanlist.at(i).GetBookID()<<endl;
        }
    }
}

void Loans::UpdateLoanStatus(){
int loanid;
string newstat;
	cout<<"Enter ID # of loan to search: ";
    	cin>>loanid;
	for(int i = 0; i <loanlist.size(); i++){
        	if (loanlist.at(i).GetLoanID() == loanid){
			cout<<"Enter new status: (noraml/overdue)"<<endl;
			cin>>newstat;
			loanlist.at(i).SetStatus(newstat);
		}
	}
}

void Loans::RecheckBook(){
    int loanid;
    cout<<"Enter Load ID of the loan you would like to renew:";
    cin>>loanid;
    for(int i = 0; i <loanlist.size(); i++){
        if (loanlist.at(i).GetLoanID() == loanid){
            loanlist.at(i).SetDueDate(loanlist.at(i).GetDueDate() + 864000);
        }
    }
}
        
void Loans::EditLoan(){
    int userchoice;
    int loanid;
    int bookid;
    int patronid;
    string status;
    char re;
    bool recheck;
    time_t checkout;
    time_t duedate;

    cout<<"Enter ID # of loan to search: ";
    cin>>loanid;

    cout<<"Which part of the loan's info would you like to modify:"<<endl;
    cout<<"1. Loan ID"<<endl;
    cout<<"2. Patron ID"<<endl;
    cout<<"3. Book ID"<<endl;
    cout<<"4. Status"<<endl;
    cout<<"5. Recheck "<<endl;
    cout<<"6. Checkout Date"<<endl;
    cout<<"7. Due Date"<<endl;
    cin>>userchoice;

    for (int i = 0; i<loanlist.size(); i++){
        if (loanlist.at(i).GetLoanID() == loanid){
            if (userchoice ==1){
                cout<<"Enter new loan ID: ";
                cin>>loanid;
                loanlist.at(i).SetLoanID(loanid);
            } else if (userchoice ==2){
                cout<<"Enter new patron ID: ";
                cin>>patronid;
                loanlist.at(i).SetPatronID(patronid);
            } else if (userchoice ==3){
                cout<<"Enter new book ID: ";
                cin>>bookid;
                loanlist.at(i).SetBookID(bookid);
            } else if (userchoice == 4){
                cout<<"Enter new status (in/out/lost/repair): ";
                cin>>status;
                loanlist.at(i).SetStatus(status);
            }else if (userchoice == 5){
                cout<<"How many rechecks? (0/1): ";
                cin>>re;
                loanlist.at(i).SetRechecked(re);
            } else if (userchoice == 6){
                //TIME TIME TIME tmeyysse
            } else if (userchoice == 7){
                //LADJFAASLKIEOAAARGA
            }
        }
    }
}

void Loans::ReportLost(Patrons &p1, Books &b1){
    int bookid;
    int loanid;
    double lostfine;
    cout<<"Enter Loan ID of lost item:";
    cin>>loanid;

    for(int i =0; i<loanlist.size(); i++){
        if (loanlist.at(i).GetLoanID() == loanid){
            lostfine = b1.returnPrice(loanlist.at(i).GetBookID());
            p1.SetFine(loanlist.at(i).GetPatronID(), lostfine);
        }
    }    
}
