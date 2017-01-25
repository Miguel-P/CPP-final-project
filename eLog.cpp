/*
 EEE2039G Assignment 2016 - eLog
 eLog class implementation
*/

// Standard includes
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <strings.h>
#include <stdio.h>
#include <string>
#include <cerrno>
#include<sstream>
#include <string>

// Join the std namespace
using namespace std;

#include "eLog.h"

/*************************************************************************/
/* Implementation of eLog methods                                        */
/*************************************************************************/

eLog::eLog()
{
    //logentries[19].priority  ;
   // logentries[19].notes ;
    nlogs = 0 ;
    NewEntries num;
    NewEntries plis;
    isEmpty = 0 ;
    str = "" ;
}


int eLog::save ( const char* filename )
{
// save log entries to csv file filename
  NewEntries num ;
  ofstream out ;
  out.open(filename) ;
  if(out.good()){

        for (int i = 0  ; i < nlogs ; i++) {
            out << logentries[i].priority << ","
                << logentries[i].notes << endl ;
        };

  out.close();
  cout << "SAVED SUCCESFULLY" << endl ;

  }
  else {
    cout << "AN ERROR HAS OCCURED. FILE NOT SAVED." << endl ;
  };
  return 0;
         // return 0 to indicate no error */
}

int eLog::add ( int priority, string notes )
{
//adding a entries to struck ElogEntry
  logentries[nlogs].priority = priority ;
  logentries[nlogs].notes = notes ;
  nlogs++ ;
  }

int eLog::listfunc()
//listing all entries with that priority number
{
    for (int i = 0  ; i < nlogs ; i++) {
        if (logentries[i].priority >= 10) {       //This is to ensure that for two digit priority nums, the output is still justified
            cout << logentries[i].priority << "         "
                 << logentries[i].notes << endl ;
        }
        else {
            cout << logentries[i].priority << "          "
                 << logentries[i].notes << endl ;
        };
    };
}

int eLog::readinFile( const char* filename )
//This function checks if the file is empty or not and if not empty, loads the entries into the ElogEntry struct
{
    int j = 0 ;
    string priorityNum = "" ;
    string allNotes = "" ;
    ifstream inFile ;
    inFile.open(filename) ;//open the input file
    //Reference: the following block of code comes from: http://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
    //*********************************************************************
    std::stringstream strStream ;
    strStream << inFile.rdbuf( ); //read the file as a a string
    str = strStream.str() ; //str holds the content of the file
    //*********************************************************************
    if (str == "" ) return 0 ;
    inFile.close() ;
    while (j<str.length()+1) {    //the main overarching loop
        if (j != 0) j--;
        while (str[j] != ',') {   //Collect the digits digit by digit and then immediately add it to the list of priortity numbers in the struct ElogEntries
            priorityNum = priorityNum + str[j] ;
            j++ ;
        } ;
        j++ ;
        logentries[nlogs].priority = atoi(priorityNum.c_str()) ;
        priorityNum = "" ;
        while (str[j] != '\n') {  //Collect all the text letter by letter and then add it to notes under the same nlog entry as the priority number above
            allNotes = allNotes +str[j] ;
            j++ ;
        }
        j++ ;
        j++ ;
        logentries[nlogs].notes = allNotes ;
        nlogs++ ;
        allNotes = "" ;
    }
    return 1 ; //tells us that file was non-empty

}

int eLog::prioirityList(int priorityNum)
{
  cout << "ENTRIES WITH THAT NUMBER" << endl ;
  for (int i = 0  ; i < nlogs ; i++) {
      if (logentries[i].priority == priorityNum) {
            cout << logentries[i].priority << "          "
                 << logentries[i].notes << endl ;
    };
  };
}

int eLog::searchfunc(string keyword)
{
    int  i = 0 ;
    size_t found = str.find(keyword) ;  //find function returns bool to say if keyword found

    if (found != -1 ) {
        cout << "SEARCH RESULT" << endl ;
        while (i < nlogs+1) {
            while (logentries[i].notes.find(keyword) != -1) {
                if (logentries[i].priority >= 10) {       //This is to ensure that for two digit priority nums, the output is still justified
                    cout << logentries[i].priority << "         "
                    << logentries[i].notes << endl ;
                    i++ ;
                }
                else {
                     cout << logentries[i].priority << "          "
                     << logentries[i].notes << endl ;
                     i++ ;
                } ;
            };
            i++ ;
        } ;
    }
    else {
        cout << "COULD NOT BE FOUND" << endl ;
    }
}

int eLog::deleteFunc(int deleteNum, const char* filename)
{
  deleteNum = deleteNum - 1 ; //So that user can type the entry number in intuitively
  if (deleteNum < nlogs ) {
  ofstream out ;
  out.open(filename) ;
  for (int i = 0  ; i < nlogs ; i++) {
    if (i == deleteNum){
    out << "" ;
  }
    else if (nlogs == 1) break ;
    else {
        out << logentries[i].priority << ","
            << logentries[i].notes << endl ;
    } ;
  };
  out.close() ;
  cout << "DELETED" << endl ;
  nlogs = 0 ;
  eLog::readinFile(filename) ;  //Changing the contents of the ElogEntries Struct to update it to take account of the deletion
 }
 else {
    cout << "THAT ENTRY DOES NOT EXIST" << endl ;
   } ;

}
