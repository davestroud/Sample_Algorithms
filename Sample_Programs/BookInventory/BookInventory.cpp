/**
 *  BookInventory.cpp - This program provides an example on how to add and 
 *                      delete entries from an STL linked list.
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */

#include <fstream>
#include <iostream>
#include <list>
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "BookRecord.h"

using namespace std;

//
// Prototype declarations 
//
void menu();
void addBook();
void deleteBook();
void modifyBook();
void displayBookInventory();

//
// Declare the book list and an STL linked list variable
//
list <BookRecord> bookList;

/*
 *Main program.  Calls the functions to load the address book into 
 * memory then launches the user menu.
 */
int main(int argc, char **argv)
{
   menu();
      
   return 0;
}

/* 
 *  This function adds a record to the linked list.
 */
void addBook()
{
   BookRecord bookRecord;
   string userInput;

   cout << endl << "** ADD BOOK TO INVENTORY **" << endl << endl;

   cout << "ISBN> ";
   getline(cin, userInput, '\n');
   bookRecord.setIsbn(userInput);

   cout << "Author> ";
   getline(cin, userInput, '\n');
   bookRecord.setAuthor(userInput);

   cout << "Title> ";
   getline(cin, userInput, '\n');
   bookRecord.setTitle(userInput);

   cout << "Year> ";
   getline(cin, userInput, '\n');
   bookRecord.setYear(userInput);

   cout << "Publisher> ";
   getline(cin, userInput, '\n');
   bookRecord.setPublisher(userInput);

   // Add to the linked list
   bookList.push_back(bookRecord);

   return;
}

/* 
 * This function deletes a book from the linked list based on the given
 * ISBN.
 */
void deleteBook()
{
   string isbn;
   bool foundEntry = false;

   cout << endl << "** DELETE BOOK FROM INVENTORY **" << endl << endl;
   cout << "ISBN> ";

   getline(cin, isbn, '\n');

   list<BookRecord>::iterator bookRecord;
   for (bookRecord = bookList.begin(); bookRecord != bookList.end(); ++bookRecord)
   {
      if (bookRecord->getIsbn() == isbn)
      {
        foundEntry = true;
        bookList.erase(bookRecord);
      }
   }
                                                                             
   if (foundEntry)
      cout << "Entry deleted." << endl;
   else
      cout << "Entry not found." << endl;

   return;
}

/* 
 * This function displays all of the books that are contained in the 
 * linked list.
 */
void displayBookInventory()
{
   cout << endl << "** DISPLAY BOOK INVENTORY **" << endl << endl;

   string prompt;

   list<BookRecord>::iterator bookRecord;
   for (bookRecord = bookList.begin(); bookRecord != bookList.end(); ++bookRecord)
   {
      cout << "ISBN:        " << bookRecord->getIsbn() << endl;
      cout << "Author:      " << bookRecord->getAuthor() << endl;
      cout << "Title:       " << bookRecord->getTitle() << endl;
      cout << "Publisher:   " << bookRecord->getPublisher() << endl;
      cout << "---------------------------------------------" << endl;
   }

   return;
}

/* 
 * This function provides the main menu for the user, and display the 
 * options and accepts user input.
 */
void menu()
{
   string userOption;
   bool exitProgram = false;
  
   while (!exitProgram)
   {
      // Allow the user to select options to add, delete, modify, and 
      // list all data in the address book.
      cout << endl << "** BOOK INVENTORY V1.1 MAIN MENU **" << endl << endl;
      cout << "   1. Add entry" << endl;
      cout << "   2. Delete entry" << endl;
      cout << "   3. Display entries" << endl;
      cout << endl << "   99. Exit program" << endl << endl;
   
      cout << "Option> ";
      getline(cin, userOption, '\n');
   
      // Process user entry
      switch (atoi(userOption.c_str()))
      {
          case 1:
            addBook();
            break; 
   
          case 2:
            deleteBook();
            break; 

          case 3:
            displayBookInventory();
            break; 
 
          // Save address book and then exit program
          case 99:
            exitProgram = true;
            break;

          default:
            cerr << "Error: unknown option!" << endl;
            break;
      }
   }

   return;    
}

