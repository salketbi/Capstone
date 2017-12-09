#include "book.h"
#include<iostream>
#include<fstream>
#include<vector>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include<string>
#include <cstdlib>

using namespace std;

book::book(){
bookName = "";
authorName="";
price = 0.0;
pages = 0;
copies = 0;
}

book::book(string bName, string aName, double pr, int pg, int cp)
{
bookName = bName;
authorName = aName;
price = pr;
pages = pg;
copies = cp;

}

void book::getBookDetail()
{
book b1;
cout<<"Book Name : ";
cin>>bookName;
cout<<"\nAuthor Name : ";
cin>>authorName;
cout<<"Price : ";
cin>>price;
cout<<"Enter Number of Pages : ";
cin>>pages;
cout<<"Enter Number of Copies : ";
cin>>copies;
}

void book::listBooks()
{
ifstream inputFile;
std::vector<book> bookVector;
inputFile.open("lists.txt", ios::in);
if (inputFile.fail())
{
cout << "Unable to open or process the file.\n";
exit(EXIT_FAILURE);
}
else
{
string line;
int counter = 0; //counts the number of elements in vector
while (getline(inputFile, line))
{
//split the string by commas
//there are 4 commas, so we can declare array with 4 indexes
//that hold the position of each comma
int commaPos[4];
int posIndex = 0;
counter++;

for (int i = 0; i < line.length(); i++)
{
if (line[i] == ',')
{
commaPos[posIndex] = i;
posIndex++;
}
}

string bookName = line.substr(0, commaPos[0]); //starts from zero, goes to first index in commaPos[]
string authorName = line.substr(commaPos[0] + 1, commaPos[1] - commaPos[0] - 1);
float price = stof(line.substr(commaPos[1]+1, commaPos[2] - commaPos[1] - 1));//convert to double
int pages = stoi(line.substr(commaPos[2]+1,commaPos[3] - commaPos[2] - 1));
int copies = stoi(line.substr(commaPos[3]+1,line.length()));
book b = book(bookName, authorName, price, pages, copies);
bookVector.push_back(b);
}
inputFile.close();
displayBooks(bookVector);
}
}

double book::orderBook()
{
string bName;
double amount;
int avail,i;
cout<<"Enter the book name you want to order : "<<endl;
cin>>bName;
ifstream inputFile;
std::vector<book> bookVector;
int reqd_copies, rem_copies, oldCopies;
bool found_book;
found_book=false;
inputFile.open("lists.txt", ios::in);
if (inputFile.fail())
{
cout << "Unable to open or process the file.\n";
exit(EXIT_FAILURE);
}
else
{
string line;
int counter = 0;
while (getline(inputFile, line))
{
int commaPos[4];
int posIndex = 0;
counter++;
for (int i = 0; i < line.length(); i++)
{
if (line[i] == ',')
{
commaPos[posIndex] = i;
posIndex++;
}
}
//now we have position of the spaces, so we can delimit the line into 3 words
string bookName = line.substr(0, commaPos[0]); //starts from zero, goes to first index in commaPos[]
//last name starts from first space + 1, and the length is second space position - first space position minus 1
string authorName = line.substr(commaPos[0] + 1, commaPos[1] - commaPos[0] - 1);
float price = stof(line.substr(commaPos[1]+1, commaPos[2] - commaPos[1] - 1));//convert to double
int pages = stoi(line.substr(commaPos[2]+1,commaPos[3] - commaPos[2] - 1));
int copies = stoi(line.substr(commaPos[3]+1,line.length()));
book b = book(bookName, authorName, price, pages, copies);
bookVector.push_back(b);
}
inputFile.close();
}

for (i=0; i<bookVector.size() && found_book==false; i++)
{
if (bName==bookVector[i].bookName )
{
cout<<bookVector[i].copies<<" copies of this Book is Available in store."<<endl;
oldCopies = bookVector[i].copies;
cout << "How many copies you need?" << std::endl;
std::cin >> reqd_copies;
while (reqd_copies<=0 || reqd_copies>(bookVector)[i].copies)
{
std::cout << "You can not order book." << std::endl;
cout << "How many copies you need?" << std::endl;
std::cin >> reqd_copies;
}
(bookVector)[i].copies-=reqd_copies;
rem_copies = bookVector[i].copies;
found_book=true;
}

std::fstream dbin("lists.txt");
std::fstream dbout("lists.txt");
std::string bname;
std::string aname;
double bprice;
int bpages,bcopies;
std::stringstream ns,os;
std::string Temp;
if(!dbin && !dbout)
{
std::cout << "Error !! File could not be opened for writing!" <<std:: endl;
exit(1);
}
else
{
for (int i=0; i<bookVector.size(); i++)
if (bName==(bookVector)[i].bookName)
{
bname=(bookVector)[i].bookName;
aname = (bookVector)[i].authorName;
bprice = (bookVector)[i].price;
bpages = (bookVector)[i].pages;
bcopies= (bookVector)[i].copies;
amount = bprice*reqd_copies;
}

os<<bname <<","<<aname<<","<<bprice<<","<<bpages<<","<<oldCopies;
std::string olddata = os.str();
ns<<bname <<","<<aname<<","<<bprice<<","<<bpages<<","<<rem_copies;
std::string updated = ns.str();

while(dbin >> Temp)
{
if(Temp == olddata)
{
Temp = updated;
}
Temp += "\n";
dbout<<Temp;
}
}
}

return amount;

}

void book::storeBook()
{
if(price==0.0)
{
cout<<"Book data not initialized."<<endl;
}
else
{
string str1;
fstream fout;
fout.open("lists.txt",ios::app);
fout <<bookName<<","<<authorName<<","<<price <<","<<pages<<","<<copies<<"\n";
cout<<"Book Added in the Store Succesfully. !!"<<endl;
}
}

void book::displayBooks(vector <book> book_vector)
{
cout<< "List of Books :" <<endl;
cout<<setw(7)<< " Book #"<<setw(20)<<"Book Name"<<setw(20)<<"Author Name"<<setw(8)<<"Price"<<setw(7)<<"Pages"<<setw(7)<<"Copies" <<endl;
for (int i = 0; i < book_vector.size(); i++)
{
cout<<setw(7)<< i + 1<<setw(20)<<book_vector[i].getbookName()<<setw(20)<<book_vector[i].getauthorName()<<setw(8)<<book_vector[i].getPrice()<<setw(7)<<book_vector[i].getPages()<<setw(7)<<book_vector[i].getCopies() <<endl;
}
}

book::~book()
{
}

