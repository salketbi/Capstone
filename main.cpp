#include <iostream>
#include "book.h"

using namespace std;

int main()
{
book b1;
int activity=0;
double amount;
while (activity!=4)
{
cout<<"Book Shop Menu"<<endl;
cout<<"1. List All Books  " <<endl;
cout<<"2. Add Books to the Shop. " <<endl;
cout<<"3. Order Books. "<<endl;
cout<<"4. Quit. "<<endl;
cin >> activity;
if (activity==1)
{
b1.listBooks();
}
else if (activity==2)
{
b1.getBookDetail();
b1.storeBook();
}
else if (activity==3)
{
amount = b1.orderBook();
std::cout<<"Amount to be Paid :  $"<<amount<<std::endl;
std::cout<<"Thanks for shopping."<< std::endl;
}
}
return 0;
}

