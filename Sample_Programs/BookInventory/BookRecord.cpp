/**
 *  BookRecord.h - Class implementation for a book record.  This class 
 *                 will be a single node in the linked list.
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */

#include "BookRecord.h"

BookRecord::BookRecord()
{
   // Currently does nothing ...
}

// Copy constructor
BookRecord::BookRecord(const BookRecord &bookRecord)
{
   this->isbn = bookRecord.isbn;
   this->author = bookRecord.author;
   this->title = bookRecord.title;
   this->year = bookRecord.year;
   this->publisher = bookRecord.publisher;
}

BookRecord::~BookRecord()
{
   // Currently does nothing ...
}

void BookRecord::setIsbn(const string isbn)
{
   this->isbn = isbn;
}

string BookRecord::getIsbn() const
{
   return isbn;
}

void BookRecord::setAuthor(const string author)
{
   this->author = author;
}

string BookRecord::getAuthor() const
{
   return author;
}

void BookRecord::setTitle(const string title)
{
   this->title = title;
}

string BookRecord::getTitle() const
{
   return title;
}

void BookRecord::setYear(const string year)
{
   this->year = year;
}

string BookRecord::getYear() const
{
   return year;
}

void BookRecord::setPublisher(string publisher)
{
   this->publisher = publisher;
}

string BookRecord::getPublisher() const
{
   return publisher;
}

