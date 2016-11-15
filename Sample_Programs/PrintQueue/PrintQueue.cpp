/**
 *  PrintQueue.cpp - This program provides an example on how to add and 
 *                   delete entries from an STL queue. The entries in the
 *                   queue are strings, but can be any data type including
 8                   objects.
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

//
// Prototype declarations 
//
void menu();
void addItem();
void deleteItem();
void displayQueue();

//
// Declare an STL queue variable
//
queue <string> itemsInQueue;

int main(int argc, char **argv)
{
   menu();
      
   return 0;
}

void addItem()
{
   string documentName;

   cout << "Document name> ";
   getline(cin, documentName, '\n');

   itemsInQueue.push(documentName);

   return;
}

void deleteItem()
{
   queue <string> tmpQueue = itemsInQueue;
   queue <string> resultQueue;

   string documentName;
   string item;

   bool foundEntry = false;

   cout << "Doucment name> ";
   getline(cin, documentName, '\n');

   while (!tmpQueue.empty())
   {
      item = tmpQueue.front();

      if (item != documentName)
         resultQueue.push(item);

      tmpQueue.pop();
   }

   if (foundEntry)
      cout << "Entry deleted." << endl;
   else
      cout << "Entry not found." << endl;

   itemsInQueue = resultQueue;

   return;
}

void displayQueue()
{
   queue <string> tmpQueue = itemsInQueue;
   string item;
   
   cout << endl << "Document names in queue:" << endl;

   while (!tmpQueue.empty())
   {
      item = tmpQueue.front();

      cout << " " << item << endl; 

      tmpQueue.pop();
   }

   return;
}

void menu()
{
   string userOption;
   bool exitProgram = false;
  
   while (!exitProgram)
   {
      cout << endl << "** PRINT QUEUE V1.1 MAIN MENU **" << endl << endl;
      cout << "   1. Add item" << endl;
      cout << "   2. Delete item" << endl;
      cout << "   3. Display queue items" << endl;
      cout << endl;
      cout << "   99. Exit program" << endl << endl;
   
      cout << "Option> ";
      getline(cin, userOption, '\n');
   
      switch (atoi(userOption.c_str()))
      {
          case 1:
            addItem();
            break; 
   
          case 2:
            deleteItem();
            break; 

          case 3:
            displayQueue();
            break; 
 
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

