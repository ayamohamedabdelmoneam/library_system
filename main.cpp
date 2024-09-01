#include <iostream>
# include <string>
# include <cstdlib>
using namespace std;
// You need to store Information about book {name , title , author ,status }
const int librarySize =10;
string titles[librarySize] = {"c++ " , "Java " , "Python"};
string authors [librarySize] = {"Ahmed" , "Aya" , "Ali"};
int id_Books [librarySize] ={1, 2, 3};
bool statusOfBook [librarySize] = {true , false , true};
// make variable that show number of books in library
int numOfBooks = 3;
 // function main menue
 void mainMenue() {
     char b ;
     cout << "Hello To Our Library system \n \n";
     cout << "You Would Like To Make An Operation with in our system \n \n";
     cout << "Choose By Writing y or n \n";
     cin >> b;
     if (b == 'y' || b == 'Y') {
     cout << "Please Choose An Operation To Perform \n";
     cout << " 1- Display All Books \n";
cout << " 2- Add New Book \n";
cout << " 3- Borrow A Book \n";
cout << " 4- Return A Book \n";
cout << " 5- Update A Book \n";
cout << " 6- Remove A Book \n";
cout << " 7- Exist The System \n";
cout << "Enter Your Choice\n";
 }else if (b == 'N' ||  b== 'n') {
  cout << " Thank You Good Bye \n";
  system("pause");
  system("cls"); }}

//Display function that display all data about books in system:
void displayOneBook (string t , string a, int i , bool s){
      string bookStatus =(s) ? "Available" : "Not Available";
    cout << "Book Information \n\n";
    cout<< "Title Of Book Is: "  << t<< endl;
    cout<< "The Author of Book: " <<a<< endl;
    cout<< "The Id Of Book Is:  =  " <<i << endl;
    cout<< " The Status Of Book: " <<bookStatus << endl;
    cout << "\n ====================================================\n";
}
void display_Info () {
for(int i = 0; i < numOfBooks ; i++) {
      displayOneBook(titles[i], authors[i],id_Books[i], statusOfBook[i]);
}
}
//                            2- Add New book to the system
void addNewBook() {
    if(numOfBooks == librarySize) {
        cout << "You can not add new book \n";
    }
    else{
    string title, author;
    cout << "Enter Book Name \n";
    cin>> title;
    titles[numOfBooks] = title;
    cout << " Enter Book Author Name \n";
    cin >> author;
    authors [numOfBooks] = author;
    statusOfBook [numOfBooks] = true;
    id_Books[numOfBooks] = numOfBooks +1;
    numOfBooks++;
    cout << "Your Book Is Added Successfully";
}}
//                   3- search book
int searchBook (int id) {
    for(int i =0 ; i< numOfBooks ; i ++) {
        if (id == id_Books[i]){
            return i;
        }
    }
    return -1;
}
//      4- Borrow Book
void borrowBook( ) {
int id , index;
char choice;
cout << "Enter The Id Of Book You Want To Borrow \n";
cin >> id;
 index = searchBook(id);
 if(index == -1) {
    cout << " Sorry This Book Is Not Found\n";
 }else {
 if (statusOfBook[index]) {
    displayOneBook(titles[index],authors[index], id_Books[index], statusOfBook[index]);
    cout << "\n That Is Book You want To Borrow\n";
cout << "Choice By writing Yes or No\n";
cin >> choice;
if (choice == 'y' || choice == 'Y') {
    cout << "\nYour Book Is Borrowed Successfully\n";
    statusOfBook[index] = false;
}
 }else {
 cout << "\n Sorry This Book Is already Borrowed \n"; }}
 cout << "\n =============================================================\n";}

 //              5- Return Book
 void returnBook () {
 int id , index;
 char choice;
 cout << "Enter The Id Of Book You Want To Return \n";
cin >> id;
 index = searchBook(id);
 if(index == -1) {
    cout << " Sorry This Book Is Not Found\n";
 }else {
 if (statusOfBook[index] == false) {
    displayOneBook(titles[index],authors[index], id_Books[index], statusOfBook[index]);
    cout << "\n That Is Book You want To Return\n";
cout << "Choice By writing Yes or No\n";
cin >> choice;
if (choice == 'y' || choice == 'Y') {
    cout << "\nYour Book Is Returened Successfully\n";
    statusOfBook[index] = true;
}
 }else {
 cout << "\n Sorry This Book Is already Returned \n"; }}
 cout << "\n =============================================================\n";}
 //                       6-Update Function :
 void updateBook () {
 int id , index;
 char choice;
 string str , bookTitleU, bookAuthorU;
 cout << "Enter The Id Of Book You Want To Update \n";
cin >> id;
 index = searchBook(id);
 if(index == -1) {
    cout << " Sorry This Book Is Not Found\n";
 }else {
    displayOneBook(titles[index],authors[index], id_Books[index], statusOfBook[index]);
    cout << "\n That Is Book You want To Update\n";
cout << "Choice By writing Yes or No\n";
cin >> choice;
if (choice == 'y' || choice == 'Y') {
    cout << "\nEnter What Do You Want To Update Book Title Or Book Author\n";
    cin >> str;
    if(str == "Book Title" || str == "book title" || str == "booktitle" || str =="BookTitle"){
        cout << "\n Please Enter Your BooK Title\n";
        cin >> bookTitleU;
        titles[index] = bookTitleU;
         cout << "\Your Book Title Is Updated Successfully\n";
    } else if (str == "Book Author" || str == "book author" || str == "bookauthor" || str =="Bookauthor"){
         cout << "\n Please Enter Your Book Author\n";
        cin >> bookAuthorU;
        authors [index] = bookAuthorU;
         cout << "\Your Book Author Is Updated Successfully\n";
    }}
  else if (choice == 'n' || choice == 'N')  {
 cout << "Thank you Good Bye \n";}
 }


 cout << "\n =============================================================\n";}

 //                  7- Remove:


  void removeBook () {
 int id , index;
 char choice;
 cout << "Enter The Id Of Book You Want To Remove \n";
cin >> id;
 index = searchBook(id);
 if(index == -1) {
    cout << " Sorry This Book Is Not Found\n";
 }else {

    displayOneBook(titles[index],authors[index], id_Books[index], statusOfBook[index]);
    cout << "\n That Is Book You want To Remove\n";
cout << "Choice By writing Yes or No\n";
cin >> choice;
if (choice == 'y' || choice == 'Y') {
        if (numOfBooks == id ) {
            numOfBooks--;
        }else {
    for(int i =0 ; i < numOfBooks ; i ++) {
        titles[i] = titles[i +1];
        authors[i] = authors[i +1];
        id_Books[i] = id_Books[i+1];
        statusOfBook[i] = statusOfBook[i +1];
    }
    numOfBooks--;
        }
    cout << "\nYour Book Is Removed Successfully\n";

 }}
 cout << "\n =============================================================\n";}

int main()
{
        int userChoice;
bool flag = true;
 while(flag) {
        mainMenue();
   cin >> userChoice;

switch (userChoice) {
case 1 :
    display_Info ();
break;
case 2 :
    addNewBook();
    break;
case 3:
    borrowBook ();
    break;
case 4:
    returnBook();
    break;
case 5:
    updateBook();
    break;
case 6 :
    removeBook();
    break;
case 7 :
    flag = false;
    break;
default:
    cout << "Your Choice Is Not Valid\n";
    break;}
    system("pause");
    system("cls");
 }
}
