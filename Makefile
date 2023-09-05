output: main.o book_info.o books.o patron_info.o patrons.o loan_info.o loans.o
	g++ main.o book_info.o books.o patron_info.o patrons.o loan_info.o loans.o -o output

main.o: main.cpp
	g++ -c main.cpp

book_info.o: book_info.cpp book_info.h
	g++ -c book_info.cpp

books.o: books.cpp books.h
	g++ -c books.cpp

patron_info.o: patron_info.cpp patron_info.h
	g++ -c patron_info.cpp

patrons.o: patrons.cpp patrons.h
	g++ -c patrons.cpp

loan_info.o: loan_info.cpp loan_info.h
	g++ -c loan_info.cpp

loans.o: loans.cpp loans.h
	g++ -c loans.cpp

clean:
	rm *.o output
