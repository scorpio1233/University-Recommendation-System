#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;


// calling header file
#include "header.h"

//function definition declaration
void registeredCus(), showadmin(), displayinoneline(), displayinbundle(), normalUser(), exitSystem(string, bool *), displayUni(), mergeSort(), sortUni(), readfile(), searchUniversityInfo(), searchSelection(string, string);


// Global variable
  // Dynamic class inplementation
  DynamicArray *UnivRanking = new DynamicArray;
  CircularLinkedList *utility = new CircularLinkedList;
CircularLinkedList CSVlist;
CircularLinkedList CloneCSV1;
CircularLinkedList CloneCSV2;
CircularLinkedList customerDetail_list;
CircularLinkedList adminDetail_list;
DynamicArray uniArrayRank;
DynamicArray uniArrayRank_clone;
MyStackLinked stack_log;

CircularLinkedList uniList;
DynamicArray uniArray;

static bool initialize_main = false;
void readfile()
{
  if (initialize_main == false)
  {
    // read csv data into linkedlist
    // duplicated normalUser
    ifstream inputFile;
    inputFile.open("2023 QS World University Rankings.csv");

    // vector<UniRanking> rankuni;

    string line = "";

    getline(inputFile, line); // do not read the header line of the csv
    line = "";

    int i = 0;
    // get line one by one from the input file
    while (getline(inputFile, line))
    {

      int Rank;
      string Institution;
      string LocationCode;
      string Location;
      double ArScore;
      string ArRank;
      double ErScore;
      string ErRank;
      double FsrScore;
      string FsrRank;
      double CpfScore;
      string CpfRank;
      double IfrScore;
      string IfrRank;
      double IsrScore;
      string IsrRank;
      double IrnScore;
      string IrnRank;
      double GerScore;
      string GerRank;
      string ScoreScaled;
      string tempString = "";

      stringstream inputString(line);

      getline(inputString, tempString, ',');
      Rank = atof(tempString.c_str());
      getline(inputString, Institution, ',');
      getline(inputString, LocationCode, ',');
      getline(inputString, Location, ',');

      //: atof() - returns float value
      tempString = "";
      getline(inputString, tempString, ',');
      ArScore = atof(tempString.c_str());

      // ranking not sure because of the 601+
      //  to return int value use atoi()
      getline(inputString, ArRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      ErScore = atof(tempString.c_str());
      getline(inputString, ErRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      FsrScore = atof(tempString.c_str());
      getline(inputString, FsrRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      CpfScore = atof(tempString.c_str());
      getline(inputString, CpfRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      IfrScore = atof(tempString.c_str());
      getline(inputString, IfrRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      IsrScore = atof(tempString.c_str());
      getline(inputString, IsrRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      IrnScore = atof(tempString.c_str());
      getline(inputString, IrnRank, ',');
      tempString = "";
      getline(inputString, tempString, ',');
      GerScore = atof(tempString.c_str());
      getline(inputString, GerRank, ',');
      getline(inputString, ScoreScaled, ',');
      getline(inputString, tempString, ',');

      line = "";
      CSVlist.insertAtEndUni(Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore,
                             FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank,
                             GerScore, GerRank, ScoreScaled);

      uniArrayRank.insertNewUniversityIntoArray(Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore,
                                                FsrRank, CpfScore, CpfRank, IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank,
                                                GerScore, GerRank, ScoreScaled);

      uniList.insertAtEndUni(Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank,
                             IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);

      uniArray.insertNewUniversityIntoArray(Rank, Institution, LocationCode, Location, ArScore, ArRank, ErScore, ErRank, FsrScore, FsrRank, CpfScore, CpfRank,
                                            IfrScore, IfrRank, IsrScore, IsrRank, IrnScore, IrnRank, GerScore, GerRank, ScoreScaled);
    }
    initialize_main = true;

    adminDetail_list.insertToAdminDetail("admin", "admin123", "admin@gmail.com");
  }
}

int main()
{
  readfile();
  system("cls");
  char option;
  bool running;
  running = true;
  while (running == true)
  {
    cout << "Welcome to TOP UNIVERSITY RECOMMENDATION SYSTEM :)" << endl;
    cout << " (1) Normal (Guest) user\n (2) Registered Customer\n (3) MoHE admin" << endl;
    cout << " Please choose your option : ";

    cin >> option;

    switch (option)
    {
    case '1':
      normalUser();
      break;

    case '2':
      registeredCus();
      break;

    case '3':
      showadmin();
      break;

    case '4':
      exitSystem("Confirm exit system by enter '1'", &running);
      break;

    default:
      system("cls");
      cout << "Invalid input (Only 1 to 4 option :( )\n\n ----------------------------------------------------" << endl;
      break;
    }
  }
  delete UnivRanking;
  delete utility;
  cout << "thank you" << endl;
  return 0;
}

void registeredCus()
{
  char exit;
  bool running = true;
  string username, password;
  bool usnmfound, passcorr;
  cout << "============ registered user login ============" << endl;
  cout << "Please enter your username:" << endl;
  cin >> username;
  cin.ignore();
  usnmfound = customerDetail_list.userfound(username);
  if (usnmfound == false)
  {
    cout << "No username found" << endl;
    cout << "Key in any character to continue ..." << endl;
    cin >> exit;
    exitSystem("Navigate back by enter '1'", &running);
  }
  else
  {
    cout << "Please enter your password:" << endl;
    cin >> password;
    cin.ignore();
    passcorr = customerDetail_list.passcompare(username, password);

    if (passcorr == false)
    {
      cout << "PASSWORD INCORRECT" << endl;
      cout << "Key in any character to continue ..." << endl;
      cin >> exit;
      exitSystem("Navigate back by enter '1'", &running);
    }
    else
    {
      customer cus1(username);
      time_t now = time(0);
      char *dt = ctime(&now);
      stack_log.push(username, " login", dt);
      cus1.showCusMenu();
    }
  }
}

void showadmin()
{
  char exit;
  bool running = true;
  string username, password;
  bool usnmfound, passcorr;
  cout << "============ admin login ============" << endl;
  cout << "Please enter your username:" << endl;
  cin >> username;
  cin.ignore();
  usnmfound = adminDetail_list.userAdminfound(username);
  if (usnmfound == false)
  {
    cout << "No username found" << endl;
    cout << "Key in any character to continue ..." << endl;
    cin >> exit;
  }
  else
  {
    cout << "Please enter your password:" << endl;
    cin >> password;
    cin.ignore();
    passcorr = adminDetail_list.passcompare_admin(username, password);

    if (passcorr == false)
    {
      cout << "PASSWORD INCORRECT" << endl;
      cout << "Key in any character to continue ..." << endl;
      cin >> exit;
      exitSystem("Navigate back by enter '1'", &running);
    }
    else
    {
      admin adn1(username);
      adn1.showAdminMenu();
    }
  }
}

void displayinoneline()
{
  CSVlist.printInLine();
}

void displayinbundle()
{
  CSVlist.showAll();
}

void normalUser()
{
  string username, password, email, age, status;
  status = "active";

  char option, exit;
  bool running = true;
  while (running == true)
  {
    system("cls");
    cout << "                 ====== Normal user menu ======\n  (1) Display universities' information\n  (2) Search\n  (3) Sort university information in ascending order by university name\n  (4) Register as customer\n  (5) Exit" << endl;
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case '1':
      displayUni();
      break;

    case '2':
      searchUniversityInfo();
      break;

    case '3':
      sortUni();
      break;

    case '4':

      cout << " ====================== Registration Portal ====================== " << endl;
      cout << "PLease key in the credentials and user info for your new account ..." << endl;
      cout << "\n   Precautions: username should be unique between users\n                Password length should have at least 5 characters\n\nLet's get started !\n"
           << endl;
      cout << "PLease key in your username :" << endl;

      cin >> username;
      bool found;
      // validation
      found = customerDetail_list.searchUsernm(username);
      if (found == true)
      {
        cout << "\nREGISTRATION FAIL" << endl;
        cout << "Username already taken, please register again" << endl;
        cout << "Key in any character to continue ..." << endl;
        cin >> exit;
        break;
      }
      else
      {

        cout << "PLease key in your password :" << endl;
        cin >> password;
        if (password.length() < 5)
        {
          cout << "\nREGISTRATION FAIL" << endl;
          cout << "Please have a password that at least have a word count of 5" << endl;
          cout << "Key in any character to continue ..." << endl;
          cin >> exit;
          break;
        }
        else
        {
          cout << "PLease key in your email :" << endl;
          cin >> email;
          if (utility->isValidEmail(email))
          {
            cout << "PLease key in your age :" << endl;
            cin >> age;

            if (utility->isValidAge(age))
            {
              int intage = std::stoi(age);
              customerDetail_list.insertToCustomerDetail(username, password, email, intage, status);
              customerDetail_list.regisConfirmation(username);
            }
            else
            {
              cout << "\nREGISTRATION FAIL" << endl;
              cout << "Age should be number 1 to 99" << endl;
              cout << "Key in any character to continue ..." << endl;
              cin >> exit;
              break;
            }
          }
          else
          {
            cout << "\nREGISTRATION FAIL" << endl;
            cout << "Not email format " << endl;
            cout << "Key in any character to continue ..." << endl;
            cin >> exit;
            break;
          }
        }
      }

    case '5':
      exitSystem("Navigate back by enter '1'", &running);
      break;

    default:
      system("cls");
      cout << "Invalid input (Only 1 to 5 option :( )\n\n ----------------------------------------------------" << endl;
      break;
    }
  }
}

void sortUni()
{
  //establishing clock
  auto startTime = high_resolution_clock::now();
  auto stopTime = high_resolution_clock::now();
	auto durationTime = duration_cast<milliseconds>(stopTime - startTime);
  
  char option;
  bool running = true;
  while (running == true)
  {
    system("cls");
    cout << "                 ====== Sort universities' information by sorting algorithm ======\n  (1) Bubble Sort\n  (2) Merge sort" << endl;
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case '1':

      //clone a new dataset to be used for the algorithm
      CloneCSV1 = CSVlist;

      startTime = high_resolution_clock::now(); //start time
      CloneCSV1.bubbleSort("UNINAME");
      stopTime = high_resolution_clock::now();  //end time

		  durationTime = duration_cast<milliseconds>(stopTime - startTime);
 
      CloneCSV1.showAll();
      while (running == true)
      {
        cout << "Time taken to complete bubble sort algorithm: " << durationTime.count() << " ms" << endl;
        cout << "Confirm exit system by enter pressing any character";
        cin >> option;
        cin.ignore();
        running = false;
        break;
      }
      break;

    case '2':
      CloneCSV2 = CSVlist;
      CloneCSV2.removeLast(CloneCSV2.head);

      startTime = high_resolution_clock::now(); //start time
      CloneCSV2.mergeSort(CloneCSV2.head);
      stopTime = high_resolution_clock::now();  //end time
		  durationTime = duration_cast<milliseconds>(stopTime - startTime);

      CloneCSV2.showAll();

      while (running == true)
      {
        cout << "Time taken to complete merge sort algorithm: " << durationTime.count() << " ms" << endl;
        cout << "Confirm exit system by enter pressing any character";
        cin >> option;
        cin.ignore();
        running = false;
        break;
      }
      break;

    default:
      system("cls");
      cout << "Invalid input (Only 1 to 2 option :( )\n\n ----------------------------------------------------" << endl;
      break;
    }
  }
}

void exitSystem(string msg, bool *running)
{
  int option;
  system("cls");
  cout << msg << endl;
  cin >> option;
  if (option == 1)
  {
    *running = false;
  }
  else
  {
    cout << "Exit cancelled ..." << endl;
  }
}

void displayUni()
{
  char option;
  bool running = true;
  while (running == true)
  {
    system("cls");
    cout << "                 ====== Display universities' information format ======\n  (1) All information in one line\n  (2) Display information in bundle" << endl;
    cin >> option;
    cin.ignore();
    switch (option)
    {
    case '1':
      displayinoneline();

      while (running == true)
      {
        cout << "Confirm exit system by enter pressing any character";
        cin >> option;
        cin.ignore();
        running = false;
        break;
      }
      break;

    case '2':
      displayinbundle();
      while (running == true)
      {
        cout << "Confirm exit system by enter pressing any character";
        cin >> option;
        cin.ignore();
        running = false;
        break;
      }
      break;

    default:
      system("cls");
      cout << "Invalid input (Only 1 to 2 option :( )\n\n ----------------------------------------------------" << endl;
      break;
    }
  }
}

// search university
void searchUniversityInfo()
{
  char option, back;
  string answer;
  string result;
  University result2;
  uniArrayRank_clone = uniArrayRank;

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
      vector<int> indices = uniArrayRank_clone.linearSearch("uni_location", answer);

      for (int i : indices) {
          uniArrayRank_clone.printUniversityInfoArray(i);
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
      auto startTime = chrono::high_resolution_clock::now();
      vector<int> indices = uniArrayRank_clone.linearSearch(type, answer);
      auto endTime = chrono::high_resolution_clock::now();
      auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();

      for (int i : indices) {
          uniArrayRank_clone.printUniversityInfoArray(i);
      }

      cout << "\n\nExecution time: " << duration << " nanoseconds\n"
           << endl;

      break;
    }
    else if (option == '2')
    {
      cout << "Result: " << endl;
      uniArrayRank_clone.sortUniversityArray(type);

      auto startTime = chrono::high_resolution_clock::now();
      vector<int> indices = uniArrayRank_clone.jumpSearch(type, answer);
      auto endTime = chrono::high_resolution_clock::now();
      auto duration = chrono::duration_cast<chrono::nanoseconds>(endTime - startTime).count();
      for (int i : indices) {
          uniArrayRank_clone.printUniversityInfoArray(i);
      }
      cout << "\n\nExecution time: " << duration << " nanoseconds\n"
           << endl;
      break;
    }
    else
    {
      cout << "Please enter number (1 or 2).\n";
    }
  }
}
