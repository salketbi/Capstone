#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <vector>
using namespace std;

class book
{
private:
string bookName;
string authorName;
double price;
int pages;
int copies;

public:
book(); //defualt constructor
book(string, string, double,int,int);
~book();

//getting values
string getbookName()  { return bookName; }
string getauthorName() { return authorName; }
double getPrice()  { return price; }
int getPages()  {return pages; }
int getCopies() {return copies;}

void listBooks();
void getBookDetail();

double orderBook();
void displayBooks(vector <book>);
void storeBook();
};

#endif
