/**
 * FILENAME: admin.h
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

// #include "linkedlist copy.h"
extern MyStackLinked stack_log;
CircularLinkedList generate_report;

class admin
{
private:
    // Declare variable
    std::string username;
    string arr_each_uni[21];

public:
    // constructor
    admin(std::string username_con)
    {
        this->username = username_con;
    }
    // show menu
    void showAdminMenu()
    {
        system("cls");
        char option;
        while (1)
        {
            CircularLinkedList dupSaveList;
            CircularLinkedList tempCountList;
            cout << "\nWelcome to Top University Recommendation Admin System" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "Hi, " << this->username << endl;
            cout << "(1) All Registered User's Details" << endl;
            cout << "(2) Modify Customer's Detail" << endl;
            cout << "(3) Delete User Accounts Based on Inactivity Status" << endl;
            cout << "(4) User's Feedback According the Latest Date" << endl;
            cout << "(5) Print customer login log" << endl;
            cout << "(6) Generate Top 10 University" << endl;
            cout << "(7) Logout" << endl;
            cout << "-------------------------------------------------------" << endl;
            cout << "Enter your action: ";

            cin >> option;

            switch (option)
            {
            case '1':
                cusdetailstyle();
                break;
            case '2':
                updateCus();
                break;
            case '3':
                customerDetail_list.checkStatus();
                break;
            case '4':
                saveFeedback.adminFeedback();
                break;
            case '5':
                printLog();
                break;
            case '6':
                dupSaveList = saveList;
                dupSaveList.sortTop10();
                dupSaveList.storeTop10();
                dupSaveList.bubbleSortAdminReport();
                dupSaveList.printTop10();
                break;
            case '7':
                system("cls");
                return;
            default:
                cout << "\nPlease input number (1-7).\n";
                break;
            }
        }

        return;
    }

    void printLog()
    {
        system("cls");
        string back;
        stack_log.show();
        cout << "Enter any key to back......." << endl;
        cin >> back;
    }

    void cusdetailstyle() {
        int choice;
        
        cout << "How would you like to print the customer details?" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "1. Print in a bundle" << endl;
        cout << "2. Print in a table" << endl;
        cout << "3. Back to menu" << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "Enter your choice (1,2,3): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                // Call a function to print customer details in a bundle format
                customerDetail_list.printCustomerDetailsBundle();
                break;
            case 2:
                // Call a function to print customer details in a table format
                customerDetail_list.printCustomerDetailsTable();
                break;
            case 3:
                return;
            default:
                cout << "Invalid choice. Please enter 1 to 2." << endl;
                break;
        }
    }

    void updateCus()
    {
        string usernameCus;
        cout << "\nEnter the username of the customer you want to update: ";
        cin >> usernameCus;

        if (customerDetail_list.userfound(usernameCus))
        {
            cout << "---------------------------------------" << endl;
            customerDetail_list.printCustomerProfile(usernameCus, "admin"); // username, usertype
        }
        else
        {
            cout << "\nUser not found." << endl;
        }
    }
};