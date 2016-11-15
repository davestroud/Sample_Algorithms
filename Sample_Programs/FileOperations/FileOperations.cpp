/**
 *  FileOperations.cpp - This program provides an example on how 
 *                       to perform various file operations.  The 
 *                       program operates on a standard text file 
 *                       named "myfile.dat"
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

//
// Prototype declarations 
//

// File operation functions
int loadFile();
int saveFile();

// Array functions
void initArray();
void printArray();
void addArray();

//
// Declare a global variable to hold up to 10 different strings
//
const int MAX_ARRAY_SIZE = 10;
string myArray[MAX_ARRAY_SIZE];

/*
 * Main program.  Calls the functions to load the data file into memory
 */
int main(int argc, char **argv)
{
   // Initialize the global array to empty strings
   initArray();

   // Open the file for reading, store the data in the file into the
   // global array, and then close file.
   if (loadFile())
   {
      // If the loadFile() function returns anything other then 0,
      // then we have an error, so print an error message.
      cerr << "Error: could not read from data file!" << endl;
   }

   // Print the data that is now in the array 
   printArray();

   // Could put any type of processing here ... add to, delete from, or
   // modify the data in the array
   addArray();


   // Save the data that is in the array to the file before exiting
   if (saveFile())
   {
      // If the saveFile() function returns anything other then 0,
      // then we have an error, so print an error message.
      cerr << "Error: could not write to data file!" << endl;
   }

   return 0;
}

/* 
 *  This function load all of the data found in "myfile.dat" into
 *  the list data structure.
 */
int loadFile()
{
   fstream dataFile;
   string data;

   // Open the data file for reading
   dataFile.open("myfile.dat", ios_base::in);

   if (!dataFile)
   {
      // Return an error code if we can't open the file
      return -1;
   }

   dataFile.clear();

   while (!dataFile.eof())
   { 
      //Read a line from the data file 
      getline(dataFile, data);
                                                                                
      // TODO: Add the contents of what was read into the data variable to
      // the myArray global variable. Place items in different locations
      // within the array. Use the index variable as an index into the array.
   }

   // Close the data file
   dataFile.close();

   return 0;    
}

/* 
 * This function saves all of the data in the array to the 
 * "myfile.dat" file. 
 */
int saveFile()
{
   fstream dataFile;

   dataFile.open("myfile.dat", ios_base::out);

   if (!dataFile)
   {
      // Return an error code if we can't open the file
      return -1;
   }

   for (int i=0; i < MAX_ARRAY_SIZE; i++)
   {
      // Don't write the data in the array data if it is empty
      if (myArray[i].length() == 0)
      {
         break;
      }
 
      dataFile << myArray[i] << endl;
   }

   // Close the data file
   dataFile.close();

   // Let the user know that we save the data file
   cout << "Data file saved." << endl;

   return 0;    
}

/* 
 * Initialize the global array of strings to the empty string.
 */
void initArray()
{
   // Initialize each element in the array to an empty string
   for (int i=0; i < MAX_ARRAY_SIZE; i++)
   {
      myArray[i] = "";
   }
   
   return;
}

void printArray()
{
   for (int i=0; i < MAX_ARRAY_SIZE; i++)
   {
      // Don't print the array data if it is empty
      if (myArray[i].length() == 0)
      {
         break;
      }
 
      cout << myArray[i] << endl;
   }

   return;
}

void addArray()
{
   string data;
   bool notDone = true;
   int index = 0;

   cout << "Enter some data (type 'DONE' to quit):" << endl;

   while (notDone)
   {
      cout << "> ";
      getline(cin, data, '\n');

      if (data == "DONE" || index+1 >= MAX_ARRAY_SIZE)
      {
          notDone = false;
          continue;
      }

      // Copy the entered data to the global myArray variable
      myArray[index++] = data;
   }

   return;
}

