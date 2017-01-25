 ///EEE2039W Module G Assignment 2016 - eLog

 ///STUDENT NAME: Miguel Pereira , PRRMIG001 */



// Standard includes
#include <cstdlib>
#include <iostream>
//#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<limits>


// Include the eLog class
#include "eLog.h"
//#include "ElogEntry"

// Join the std namespace
using namespace std;

// Program entry point
int main ( int argc, char* argv [] )
{
    int cont = 1; // continue running the program until cont=0
    eLog elog;    // create an instance of the eLog class
    string logname = "log.csv";
    cout << "Welcome to eLog\n";

    // check if a parameter was given for the name of the log file to use
    if (argc>1) logname = argv[1];

    // try to load the log file
    if (!elog.readinFile(logname.c_str())) {
        // if it doesn't load then assume starting with an empty log
        cerr << "Starting with empty eLog\n";
        elog.readinFile(logname.c_str()) ;
    }

    // continuously display the menu and ask user to choose an option

    while (cont) {

        // display the name of the active log file
        cout << "\nLOG : " << logname;

        // Display the menu
        cout << "\nMENU:\n"
            "1:   Add entry\n"
            "2:   List all entries\n"
            "3:   List priority\n"
            "4:   Search\n"
            "5:   Delete\n"
            "6:   Save\n"
            "Esc: Exit\n";
        cout << "Select an option: ";
        // User needs to select one of the options
        char ch = getch();
        switch (ch) {
            case '1': // here is code to ask for a priority and keywords to enter into the log
                      {

                       cout << "1" << endl;
                       cout << "Add Entry..." << endl;
                       cout << "Priority: ";
                       int priority;
                       cin >> priority ;
                       if(cin.fail()) {
                            cout << "Invalid input. Priority must be a number between 0 and 99." << endl ;
                            ///A blcok of code in case the user doesn't input a valid int as a priority number, taken from an online resource. See reference.
                            //refernce: http://stackoverflow.com/questions/5655142/how-to-check-if-input-is-numeric-in-c?noredirect=1&lq=1
                            cin.clear(); // reset failbit
                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input and clear buffer
                            //************************************************************************************************************
                            cout << "Priority: ";
                            cin >> priority ;
                        };
                       string notes ;
                       cout << "Notes: ";
                       cin.ignore() ;
                       getline(cin,notes) ;
                       elog.add(priority,notes);
                       }
                      break;

            // TODO: add code to handle the other operations
            case '2':
                {
                    cout << "2" << endl ;
                    cout << "LISTING ENTRIES " << endl;
                    cout << "PRIORITY   NOTES"  << endl;
                    elog.listfunc() ;

                }
                break;

            case '6':
                {
                    cout << "6" << endl;
                    elog.save(logname.c_str()) ;

                }
                break ;

            case '3' :
                {
                    cout << 3 << endl ;
                    cout << "ENTER A PRIORITY NUMBER: " ;
                    int priorityNum ;
                    cin >> priorityNum ;
                    if (cin.fail()){
                        cout << "Invalid input. Priority must be a number between 0 and 99." << endl ;
                        cin.clear(); // reset failbit
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        cout << "ENTER A PRIORITY NUMBER: " ;
                        cin >> priorityNum ;
                    };
                    elog.prioirityList(priorityNum) ;
                }
                break ;

            case '4' :
                {
                    cout << "ENTER KEYWORD: " ;
                    string keyword ;
                    cin >> keyword ;
                    elog.searchfunc(keyword) ;
                    cin.clear(); // reset failbit
                }
                break ;

            case '5' :
                {
                    const char * filename = logname.c_str() ;
                    int deleteNum ;
                    cout << "SELECT ENTRY NUMBER TO DELETE: " ;
                    cin >> deleteNum ;
                    elog.deleteFunc(deleteNum, filename) ;
                    cin.clear(); // reset failbit
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                break ;
            case 27 : cont=0;
                      break; // Esc key is code 27, exits program.
            default : cout << "Unknown command\n";
        };
    }

    system("PAUSE"); // wait for keypress
    return 0;
}
