/**
 * RandomString.cpp - This program produces a random string of the length
 *                    provided.
 *
 * Course: CS3330 Data Structures and Algorithms
 * Author: Dr. Jack Davault
 */

using namespace std;

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randomNumber(int maxNumber);
char getCharByNumber(int number);
string getRandomString(int lengthOfString);

const int START_ASCII_LETTERS=65;
const int NUM_LETTERS=26;

int main(int argc, char **argv)
{

   // Initialize the random number generator
   srand(time(NULL)); 

   cout << getRandomString(10) << endl;

   return 0;
}

/*
 * Get a random number between 1 and maxNumber
 */
int randomNumber(int maxNumber)
{
   return (rand() % maxNumber + 1); 
}

/*
 * Convert a given number between 1 and 26 to the equivolent character.
 * For example, 1 is A, 2 is B, etc.
 */
char getCharByNumber(int number)
{
   return number+START_ASCII_LETTERS-1;
}

/*
 * Generate a random string of specified length lengthOfString.
 */
string getRandomString(int lengthOfString)
{
   string randomString = "";

   for (int i=0; i < lengthOfString; i++)
   {
      randomString +=  getCharByNumber(randomNumber(NUM_LETTERS));
   }

   return randomString;
}

