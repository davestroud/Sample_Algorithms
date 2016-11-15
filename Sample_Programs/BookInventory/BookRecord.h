/**
 *  BookRecord.h - Class definition for a book record.  This class will be
 *                 a single node in the linked list.
 *
 * Course: CS3330 Data Structures and Algorithms.
 * Instructor: Dr. Jack Davault
 */

#ifndef _BOOK_RECORD_H_
#define _BOOK_RECORD_H_

#include <iostream>
#include <string>

using namespace std;

class BookRecord
{
public:
  BookRecord();
  BookRecord(const BookRecord &bookRecord);
  ~BookRecord();

  void setIsbn(const string isbn);
  string getIsbn() const;

  void setAuthor(const string author);
  string getAuthor() const;

  void setTitle(const string title);
  string getTitle() const;

  void setYear(const string year);
  string getYear() const;

  void setPublisher(const string publisher);
  string getPublisher() const;

private:
  string isbn;
  string author;
  string title;
  string year;
  string publisher;
};

#endif

