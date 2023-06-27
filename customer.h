/**
 * FILENAME: customer.h
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>
// #include "linkedlist copy.h"

using namespace std;
extern CircularLinkedList uniList;
CircularLinkedList uniList_clone;
CircularLinkedList saveList;
CircularLinkedList saveFeedback;
extern CircularLinkedList customerDetail_list;
extern DynamicArray uniArray;
DynamicArray uniArray_clone;
extern MyStackLinked stack_log;

class customer
{
private:
    // Declare variable
    std::string username;
    string arr_each_uni[21];

public:
    // constructor
    customer(std::string username_con)
    {
        this->username = username_con;
    }

    // show menu
    void showCusMenu()
    {
        system("cls");
        char option;
        //readfile();
        while (1)
        {

            cout << "===============================================" << endl;
            cout << "Welcome to Top University Recommendation System" << endl;
            cout << "===============================================" << endl;
            cout << "Hi, " << this->username << endl;
            cout << "(1) Sort university information" << endl;
            cout << "(2) Search universities" << endl;
            cout << "(3) Manage favorite universities" << endl;
            cout << "(4) Manage feedback" << endl;
            cout << "(5) My Profile" << endl;
            cout << "(6) Logout" << endl;
            cout << "Enter your action: ";

            cin >> option;

            switch (option)
            {
            case '1':
                system("cls");
                sortUniversity();
                system("cls");
                break;
            case '2':
                system("cls");
                searchUniversity();
                system("cls");
                break;
            case '3':
                system("cls");
                manageSaveUni();
                system("cls");
                break;
            case '4':
                system("cls");
                manageFeedback();
                system("cls");
                break;
            case '5':
                myProfile();
                system("cls");
                break;
            case '6':
                cout << "Thank You for using this system :)" << endl;
                addStamp();
                system("cls");
                return;
            default:
                cout << "\n Invalid Input!! Please input number (1-5).\n\n";
                break;
            }
        }

        return;
    }

    void printUni()
    {
        char option, back;
        while (1)
        {
            cout << "\n====== Display universities' information format ======\n  (1) All information in one line\n  (2) Display information in bundle" << endl;
            cout << "Enter your action: ";
            cin >> option;
            if (option == '1')
            {
                uniList_clone.printInLine();
                cout << "Enter any key to back to the menu.....";
                cin >> back;
                break;
            }
            else if (option == '2')
            {
                uniList_clone.showAll();
                cout << "Enter any key to back to the menu......";
                cin >> back;
                break;
            }
            else
            {
                cout << "Invalid Input!!" << endl;
            }
        }
    }

    // sort university
    void sortUniversity()
    {
        char option, option2;
        uniList_clone = uniList;
        while (1)
        {
            cout << "\nSort university information in descending order based on" << endl;
            cout << "(1) Academic reputation score" << endl;
            cout << "(2) Faculty/student ratio score" << endl;
            cout << "(3) Employer reputation score" << endl;

            cout << "Enter your action: ";

            cin >> option;

            if (option == '1')
            {
                uniList_clone.bubbleSort("ARSCORE");
                printUni();
                break;
            }
            else if (option == '2')
            {
                uniList_clone.bubbleSort("FSRSCORE");
                printUni();
                break;
            }
            else if (option == '3')
            {
                uniList_clone.bubbleSort("ERSCORE");
                printUni();
                break;
            }
            else
            {
                cout << "Invalid Input!! Please enter number (1 - 3).\n";
            }
        }
    }

    // search university
    void searchUniversity()
    {
        char option, back;
        string answer;
        string result;
        University result2;
        uniArray_clone = uniArray;

        while (1)
        {
            cout << "\nSearch universities details based on your own decision" << endl;
            cout << "(1) Name" << endl;
            cout << "(2) Location" << endl;

            cout << "Enter your action: ";

            cin >> option;
            if (option == '1')
            {
                cout << "Search for: ";
                std::getline(std::cin >> std::ws, answer);
                searchSelection("uni_name", answer);
                cout << "Enter any key to return......";
                cin >> back;
                break;
            }
            else if (option == '2')
            {
                cout << "Search for: ";
                std::getline(std::cin >> std::ws, answer);

                cout << "Result: " << endl;
                vector<int> indices = uniArray_clone.linearSearch("uni_location", answer);

                for (int i : indices) {
                    uniArray_clone.printUniversityInfoArray(i);
                }                
                cout << "Enter any key to return......";
                cin >> back;
                break;
            }
            else
            {
                cout << "Please enter number (1 or 2).\n";
            }
        }
    }

    
    void searchSelection(string type, string answer)
{
  while (1)
  {
    char option;
    cout << "(1) Linear Search" << endl;
    cout << "(2) Jump Search" << endl;
    cout << "Enter your option: ";
    cin >> option;

    if (option == '1')
    {
      cout << "Result: " << endl;
      vector<int> indices = uniArray_clone.linearSearch(type, answer);

      for (int i : indices) {
          uniArray_clone.printUniversityInfoArray(i);
      }

      break;
    }
    else if (option == '2')
    {
      cout << "Result: " << endl;
      uniArray_clone.sortUniversityArray(type);

      vector<int> indices = uniArray_clone.jumpSearch(type, answer);
      for (int i : indices) {
          uniArray_clone.printUniversityInfoArray(i);
      }
      break;
    }
    else
    {
      cout << "Please enter number (1 or 2).\n";
    }
  }
}
    
    
    
    void manageSaveUni()
    {
        char option;
        string uniName;
        string *arrSave;
        string back;
        while (1)
        {
            cout << "\nManage your favourite university." << endl;
            cout << "(1) Save your favorite universities" << endl;
            cout << "(2) View your favourite universities" << endl;

            cout << "Enter your action: ";

            cin >> option;

            if (option == '1')
            {
                cout << "\nEnter the university name: " << endl;
                std::getline(std::cin >> std::ws, uniName);
                arrSave = uniList.saveSearchForUni(username, uniName);
                saveList.saveInsertAtEndUni(arrSave[1], arrSave[2]);
                cout << "Enter any key to return......";
                cin >> back;
                return;
            }
            else if (option == '2')
            {
                saveList.saveView(username, uniList.head, uniList.getSize());
                cout << "\nEnter any key to back to the menu......";
                cin >> back;
                return;
            }
            else
            {
                cout << "Please enter number (1 or 2).\n";
                continue;
            }
        }
    }

    void manageFeedback(){
            char option, back;
            int rating;
            string comment, ratingInput;

            while(1)
            {
                cout << "\nManage feedback menu:";
                cout << "\n----------------------" << endl;
                cout << "1. Add feedback\n";
                cout << "2. View My feedbacks\n";
                cout << "3. Read replied feedbacks\n";
                cout << "4. Back to menu\n";
                cout << "\n---------------------" << endl;
                cout << "Enter your action: ";

                cin >> option;

                if (option == '1'){
                    cout << "\nEnter rating (1-5):" << endl;
                    cin >> ratingInput; 
                    std::istringstream iss(ratingInput);
                    if (!(iss >> rating)) {
                        std::cout << "\nInvalid rating! Please enter a number between 1 to 5" << std::endl;
                        continue;
                    }
                    if (rating < 1 || rating > 5){
                        cout << "\nInvalid rating! Please enter a number between 1 to 5" << endl; 
                        continue;
                    }
                    else {
                        cout << "\nEnter comment: "<< endl;
                        cin.ignore(); // To clear the input buffer
                        getline(cin, comment); 
                        if (comment.empty()){
                            cout << "\nPlease don't leave the comment blank" << endl;
                            continue;
                        }
                        else {
                            saveFeedback.addFeedback(username, comment, rating);
                        }
                    }
                }
                else if (option == '2'){
                    saveFeedback.viewAllFeedback(username);
                    cout << "-------------------" << endl;
                    cout << "\nEnter any key to back to the menu......";
                    cin >> back;
                }
                else if (option == '3'){
                    //code to read replied feedback
                    cout << "\nReplied feedbacks from admin:" << endl;
                    cout << "-------------------" << endl;
                    saveFeedback.readRepliedFeedbacks(username);
                    cout << "-------------------" << endl;
                    cout << "\nEnter any key to go back to the menu......";
                    cin >> back;
                }
                else if (option == '4'){
                    return;
                }
                else{
                    cout << "Please enter a valid option (1 to 4).\n";
                }

            }

        }

    void addStamp(){
        time_t now = time(0);
        char* dtout = ctime(&now);
        stack_log.push(username, " logout", dtout);
    }

    void myProfile(){
        customerDetail_list.printCustomerProfile(username, "cus");
    }
};