/**
 *  TextLineParse.cpp - This program provides an example on how to 
 *                      extract single letter commands along with two 
 *                      integer variables.
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int getCommand(string text, char &command, int &n, int &m);

int main(int argc, char **argv)
{
   string userString;
   char command = '\0';
   int n = -1;
   int m = -1;

   cout << "Enter a letter and two number for valid commands." << endl;
   cout << "> ";
   getline(cin, userString, '\n');
  
   cout << "You entered: '" << userString << "'" << endl;

   int rc = getCommand(userString, command, n, m);

   if (rc)
   {
      cout << "No command was given." << endl;
   }
   else
   {
      cout << "Command: " << command << endl;
      cout << "n: " << n << endl;
      cout << "m: " << m << endl;
   }

   return 0;
}


/*
 * Extract a single character command and two numbers from a given
 * line of text.
 *
 * input   : text
 * output  : command, n, and m
 * returns : -1 if there is no single letter at the 
 */
int getCommand(string text, char &command, int &n, int &m)
{
   // Check if this is a valid command by check if the second character
   // in the text is a space or a null character. 
   if (text[0] == ' ' || text[0] == '\0');
   {
      // Parse the text by storing the single letter command and up to 
      // two numbers
      sscanf(text.c_str(), "%c %d %d", &command, &n, &m);   

      // Return without an error
      return 0;
   }
   
   // Return with an error code, since no command letter was found
   return -1;
}

