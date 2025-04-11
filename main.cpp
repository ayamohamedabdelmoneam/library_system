#include <iostream>
#include <cstdlib>
using namespace std;


/*
    function to do

    1- Display
    2- add
    3- Boroow
    4- Return 
    5- Update
    6- Delete
    7- Exit

*/


// titles author id status
const int sizeOfLibrary = 10;

string Titles[sizeOfLibrary] = { "C++", "Java","Python" };
string Author[sizeOfLibrary] = { "Ahmed", "Ehab","Mohy" };
int Ids[sizeOfLibrary] = { 1,2,3 };
bool Status[sizeOfLibrary] = { true,false,true };

int numOfBooks = 3;



void mainMenu() {
    cout << "1- Display All Books" << endl;
    cout << "2- Add New Book" << endl;
    cout << "3- Borrow Book" << endl;
    cout << "4- Return Book" << endl;
    cout << "5- Update Book" << endl;
    cout << "6- Delete Book" << endl;
    cout << "7- Exit" << endl;
    cout << "\nEnter Your Choice: ";
}

void cinfirmMenu() {
    cout << "\nDo you want to confirm\n";
    cout << "1- yes/n" << endl;
    cout << "2- No/n" << endl;
    cout << "\nYour Choice : ";
}

void updateMenu() {
    cout << "\nWhat do you want to update\n";
    cout << "1- Book Title" << endl;
    cout << "2- Book Author" << endl;
    cout << "\nEnter choice: ";
}


// 1- Display
void displayOneBook(string t, string a, int i, bool s) {
    string bookstatus = (s) ? "Avalilable" : "Not Avalible";
    cout << "Book Info\n\n";
    cout << "Title : " << t << endl;
    cout << "Author : " << a << endl;
    cout << "Id : " << i << endl;
    cout << "Status : " << bookstatus << endl;
    cout << "\n=========================================\n";
}

void displayAllBooks() {
    for (int i = 0; i < numOfBooks; i++) {
        displayOneBook(Titles[i], Author[i], Ids[i], Status[i]);
    }
}


// 2- Add
void addNewBook() {
    if (numOfBooks == sizeOfLibrary) {
        cout << "\nYou Can`t Add New Book\n";
    }
    else {
        string title, author;
        cout << "\nEnter Book Name\n";
        cin >> title;
        Titles[numOfBooks] = title;
        cout << "\nEnter Book Author\n";
        cin >> author;
        Author[numOfBooks] = author;
        Status[numOfBooks] = true;
        Ids[numOfBooks] = numOfBooks + 1;
        numOfBooks++;
        cout << "\nBook Added Successfully\n";
    }
}
