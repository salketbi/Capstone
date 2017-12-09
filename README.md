# Book Shop Project

## Input/Output
#### Input
[book.cpp lines 31-44](/book.cpp)
</br>I created a getBookDetail() function which is used to take input when the user want to add the book in the store.
#### Output
[book.cpp lines 221-229](/book.cpp)
</br>I created a displayBooks() function which is used to display all the book details in formatted output.

## Control Flow
#### if
[book.cpp lines 174-182](/book.cpp)
</br>I used if control structure to compare the entered bookname with the book which are stored in the book Vector.

#### else if
[main.cpp lines 19-33](/main.cpp)
</br>I used else if control structure to check the user input against the menu activity.

#### else
[book.cpp lines 104-137](/book.cpp)
</br>I used if else control structure to check the file can be opened or not. If file not able to open, display the error message, Otherwise after opening the file, the file can be read and manipulated as per the project requirement.

## Iteration
#### for
[book.cpp lines 69-76](/book.cpp)
</br>I created a for loop to iterate over the line which is read from the text data file. In the line, the book details are separated by the comma, this loop will help in to store the position of comma in the array line.

#### while
[main.cpp lines 11-34](/main.cpp)
</br>I used while loop iteration to show the book shop menu to the user untill the user quit the menu.

## Data Structure
#### vectors
[book.cpp line 49](/book.cpp)
</br>I created a bookVector variable of type books which stores all the details of the books like book name, author name, pages, price and copies.

## Function
#### void return type
[book.cpp lines 205-219](/book.cpp)
</br>I created a storeBook() function which returns nothing, i.e void type. This function helps to add the book in the store.

#### non-void return type
[book.cpp lines 90-202](/book.cpp)
</br>I created a orderBook() function which return the variable of double type i.e the amount, the user have to be paid after ordering the book.

#### pass-by-value
[book.cpp lines 220-228](/book.cpp)
</br>I created a displayBooks(vector <book> book_vector) which takes argument, i.e vector of type books as a pass by value. It returns no value. This function helps to display all the details of the books to the user.

## File IO
#### File Input
[book.cpp lines 48-86](/book.cpp)
</br>I created a inputFile variable of type ifstream for reading the text data file which stores the list of books.

#### File Output
[book.cpp lines 158-197](/book.cpp)
</br>I created a dbin,dbout variable of type fstream for both reading and writing purpose. To place the order of the book, these file I/O update the text data file.

## Class
[book.h lines 8-35](/book.h)
</br>I created a book class which contains private and public members related to the book shop. This class contains bookName, authorName, price, pages, copies as private data member. It also contain some public member like listBooks(), orderBook(),
storeBook() and more which does the functionality of the book shop project.


