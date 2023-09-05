/* 
* CSCE 1040 Homeowork 3 
* Section: 001
* Name: Sachi Hansalia
* UNT Email: sachihansalia@my.unt.edu
* Date submitted: 4/25/2022
 
*File name: main.cpp
*Description:  This file contains all of the menus and and is needed to make the
objects for each plural class and used to store information and bring it back. 
*/ 
//#include "books.h"
//#include "patrons.h"
#include "loans.h"
#include <ctime>
#include <fstream>
//#include "book_info.h"
using namespace std;

void storeAll (Books b, Patrons p, Loans l){
    b.store();
    p.store();
    l.store();

    cout<<"All files stored."<<endl<<endl;
}

void loadall (Books b, Patrons p, Loans l){
    b.load();
    p.load();
    l.load();
}
int main(int argc, char *argv[]) {

/*
	if (argc != 2){
	cout<<argc<<endl;
	cout<< "Usage: ./output <filename\n"<<endl;
    	} */
    //vector<Books> b1;
    //BookInfo *B1 = (BookInfo*) malloc(sizeof(BookInfo));
    //Books *b1 = (Books*) malloc(sizeof(Books));
    //vector<Books*> b1;
    Books b1;
    Patrons p1;
    Loans l1;

    //time_t currentTime = time(0);
    //tm *local_time = localtime(&currentTime);
    //time(&currentTime);
    //time_t newtime = currentTime + 864000;
    //tm *local_time2 = localtime(&newtime);

    cout<<"Welcome to the Library!"<<endl;
    //cout<<"Today's Date: "<< local_time->tm_mon+1<<"/"<<local_time->tm_mday<<"/"<<local_time->tm_year+1900<<endl;
    //cout<<"10 days later: "<< local_time2->tm_mon+1<<"/"<<local_time2->tm_mday<<"/"<<local_time2->tm_year+1900<<endl;
    cout<<"How can we help you?"<<endl;

    char userchoice;

    do {
    cout<<"Menu:"<<endl;
    cout<<"b = books"<<endl;
    cout<<"p = patrons"<<endl;
    cout<<"l = loans"<<endl;
    cout<<"s = store all data"<<endl;
    cout<<"u = load all data"<<endl;
    cout<<"q = quit"<<endl;
    cin>>userchoice;
    int userbookchoice;
    int userpatronchoice;
    int userloanchoice;
    
    if (userchoice == 'b'){
        do {
        cout<<endl;
        cout<<"What would you like to do with the books?"<<endl;
        cout<<"1. Add book"<<endl;
        cout<<"2. Edit book info"<<endl;
        cout<<"3. Delete book from catalogue"<<endl;
        cout<<"4. Search by ID"<<endl;
        cout<<"5. Print collection"<<endl;
        cout<<"6. Print book details"<<endl;
        cout<<"7. Store all Book Data"<<endl;
        cout<<"8. Load all Book Data"<<endl;
        cout<<"0. Return"<<endl;
        cin>>userbookchoice;
        
            if (userbookchoice == 1){
                b1.AddBook();
            } else if (userbookchoice == 2){                
                b1.EditBook();
            } else if (userbookchoice == 3){
                //searchbook = b1->SearchByID(id);
                b1.DeleteBook();
            } else if (userbookchoice == 4){
                int id;
                cout<<"Enter ID # of book to search: ";
                cin>>id;
                BookInfo searchbook;
                searchbook = b1.SearchByID(id);

                cout<<searchbook.GetTitle()<<endl;
                cout<<searchbook.GetAuthor()<<endl;
            } else if (userbookchoice == 5){
                b1.PrintCollection();
            } else if (userbookchoice == 6){
                int id;
                cout<<"Enter ID # of book to search: ";
                cin>>id;
                BookInfo searchbook;

                searchbook = b1.SearchByID(id);
                b1.PrintDetails(searchbook);
            } else if (userbookchoice == 7) {
                b1.store();
            } else if (userbookchoice == 8) {
                b1.load();
            }else {
                cout<<"That is not a valid option."<<endl;
            }
        } while (userbookchoice != 0);
    } else if (userchoice == 'p'){
        do {
            cout<<endl;
            cout<<"What would you like to do with the patrons?"<<endl;
            cout<<"1. Add Patron"<<endl;
            cout<<"2. Edit Patron"<<endl;
            cout<<"3. Delete Patron"<<endl;
            cout<<"4. Search by ID"<<endl;
            cout<<"5. Pay Fines"<<endl;
            cout<<"6. Print Patrons"<<endl;
            cout<<"7. Print Individual Details"<<endl;
            cout<<"8. Store all Patron Data"<<endl;
            cout<<"9. Load all Patron Data"<<endl;
            cout<<"0. Return"<<endl;
            cin>>userpatronchoice;

            if (userpatronchoice == 1){
                p1.AddPatron();
            } else if (userpatronchoice == 2){
                p1.EditPatron();
            } else if (userpatronchoice == 3){
                p1.DeletePatron();
            } else if (userpatronchoice == 4){
                int id;
                cout<<"Enter ID # of Patron to search: ";
                cin>>id;
                PatronInfo searchpatron = p1.SearchByID(id);
                cout<<searchpatron.GetName()<<endl;
                cout<<searchpatron.GetID()<<endl;
            } else if (userpatronchoice == 5){
                p1.PayFines();
            } else if (userpatronchoice == 6){
                p1.PrintPatrons();
            } else if (userpatronchoice == 7){
                int id;
                cout<<"Enter ID # of Patron to search: ";
                cin>>id;
                PatronInfo searchpatron = p1.SearchByID(id);
                p1.PrintIndividualDetails(searchpatron);
            } else if (userpatronchoice == 8) {
                p1.store();
            } else if (userpatronchoice == 9) {
                p1.load();
            }else {
                cout<<"This is not a valid option."<<endl;
            }
        } while (userpatronchoice != 0);
    } else if (userchoice == 'l'){
        do {
            cout<<endl;
            cout<<"What would you like to do with the loan?"<<endl;
            cout<<"1. Check-out"<<endl;
            cout<<"2. Check-in"<<endl;
            cout<<"3. Print all overdue"<<endl;
            cout<<"4. Print all of a patron's loans"<<endl;
            cout<<"5. Update loan status"<<endl;
            cout<<"6. Recheck a book"<<endl;
            cout<<"7. Edit Loan"<<endl;
            cout<<"8. Report a book lost."<<endl;
            cout<<"9. Store loan data"<<endl;
            cout<<"10. Load all Loan Data"<<endl;
            cout<<"0. Return"<<endl;
            cin>>userloanchoice;

            if (userloanchoice== 1){
                l1.CheckOutABook(p1, b1);
            } else if (userloanchoice ==2){
		l1.CheckinABook(p1, b1);
            } else if (userloanchoice == 3){
		l1.PrintOverDue();
            } else if (userloanchoice == 4){
		int pid;
		cout<<"Enter ID of patron to search: ";
		cin>>pid;
		l1.PrintAllofPatronLoan(pid);
            } else if (userloanchoice == 5){
		l1.UpdateLoanStatus();
            } else if (userloanchoice == 6){
		l1.RecheckBook();
            } else if (userloanchoice == 7){
		l1.EditLoan();
            } else if (userloanchoice == 8){
		l1.ReportLost(p1, b1);
            } else if (userloanchoice == 9){
                l1.store();
            } else if (userbookchoice == 10) {
                l1.load();
            }else {
                cout<<"That is not a valid option."<<endl;
            }
        } while (userloanchoice != 0);

    } else if(userchoice == 's'){
        storeAll(b1, p1, l1);
    } else if (userchoice == 'u') {
        loadall(b1, p1, l1);
    } else {
        cout<<"That is not a valid option."<<endl;
    }

    } while (userchoice != 'q');

    return 0;
}
