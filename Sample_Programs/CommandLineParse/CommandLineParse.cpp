/**
 *  CommandsLineArgument.cpp - This program provides an example on how to 
 *         extract single letter commands along with two integer variables.
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */


#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{
   if (argc == 1)
   {
      cout << "Run the program with command line arguments." << endl;
      cout << "   " << argv[0] << " arg1 arg2 etc." << endl;
      exit(1);
   }

   // The value of argc is the number of arguments that were passed in. The
   // for-loop prints all of the arguments that we passed in on command line.
   // The arguments are in argv and argv[0] is always the name of the program.
   for (int i=0; i < argc; i++)
   { 
      cout << "argv[" << i << "]=";
      cout << argv[i] << endl;
   }

   return 0;
}

