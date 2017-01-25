/*
 EEE2039G Assignment 2016 - eLog
 eLog class declaration
*/

// Standard includes
#include <cstdlib>
#include <iostream>
#include <stdio.h>

// Join the std namespace
using namespace std;

#ifndef ELOGH
#define ELOGH 1

struct ElogEntry {
    int    priority; // a value 0 to 10 for priority of this entry
    string notes ;    // the notes to be recorded
};

class eLog {
 public:

  /** Default constructor for eLog class */
  eLog ();

  /** Load eLog from a csv file.
      Returns true if file was loaded.
      Returns false if file not found. */
  int load ( const char* filename );

  /** Save eLog to a csv file.
      Returns true if successfully saved, otherwise false. */
  int save ( const char* filename );

  /** Function to add an entry */
  int add ( int priority, string notes );

  /**Function to list all entries, i.e. Menu option '2' */
  int listfunc () ;
  int readinFile( const char* filename ) ;
  int prioirityList(int priorityNum) ;
  int searchfunc(string keyword) ;
  int deleteFunc (int deleteNum, const char* filename) ;

private:
    struct NewEntries{
        int priority1[100] ;
        string notes1[50] ;
    };
    ElogEntry logentries[20] ;
    int nlogs ;
    int isEmpty ;
    string str ;
};


#endif // ELOGH
