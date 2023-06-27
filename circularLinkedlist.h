/* linkedlist.h */

#include <iostream>
#include <regex>
using namespace std;
/**
 * with structure implementation...
 */
struct University
{
    int rank;
    string institution;
    string locationCode;
    string location;
    double arScore;
    string arRank;
    double erScore;
    string erRank;
    double fsrScore;
    string fsrRank;
    double cpfScore;
    string cpfRank;
    double ifrScore;
    string ifrRank;
    double isrScore;
    string isrRank;
    double irnScore;
    string irnRank;
    double gerScore;
    string gerRank;
    string scoreScaled;

    int data;         // input value
    University *next; // link pointer
};

struct SaveUni
{
    string username;
    string institution;

    SaveUni *next_save; // link pointer
};

struct Feedback
{
    string username;
    int rating;
    string comment;
    string reply;
    Feedback *next_feedback; // link pointer
};

struct customerDetail
{
    string username;
    string password;
    string email;
    int age;
    string status;
    string userType;

    customerDetail *next_customer; // link pointer
};

struct adminDetail
{
    string usesrname_admin;
    string password_admin;
    string email_admin;

    adminDetail *next_admin; // link pointer
};

struct InstitutionCount
{
    string institution;
    int count;
    InstitutionCount *next;
};

class CircularLinkedList
{
private:
public:
    int size;
    University *head;
    int size_save;
    SaveUni *head_save;
    int size_feedback;
    Feedback *head_Feedback;
    int size_customer;
    customerDetail *head_Customer;
    int size_admin;
    adminDetail *head_admin;
    InstitutionCount *head_count;
    int size_count;

    CircularLinkedList()
    {
        this->size = 0;
        this->head = nullptr;
        this->size_save = 0;
        this->head_save = nullptr;
        this->size_feedback = 0;
        this->head_Feedback = nullptr;
        this->head_Customer = nullptr;
        this->size_customer = 0;
        this->head_admin = nullptr;
        this->size_admin = 0;
        this->head_count = nullptr;
        this->size_count = 0;
    }

    //============================university============================================

    // put university info into linkedList
    void insertAtEndUni(int Rank, string Institution, string LocationCode, string Location, double ArScore, string ArRank, double ErScore, string ErRank, double FsrScore,
                        string FsrRank, double CpfScore, string CpfRank, double IfrScore, string IfrRank, double IsrScore, string IsrRank, double IrnScore, string IrnRank,
                        double GerScore, string GerRank, string ScoreScaled)
    {
        University *newNode = new University;
        newNode->rank = Rank;
        newNode->institution = Institution;
        newNode->locationCode = LocationCode;
        newNode->location = Location;
        newNode->arScore = ArScore;
        newNode->arRank = ArRank;
        newNode->erScore = ErScore;
        newNode->erRank = ErRank;
        newNode->fsrScore = FsrScore;
        newNode->fsrRank = FsrRank;
        newNode->cpfScore = CpfScore;
        newNode->cpfRank = CpfRank;
        newNode->ifrScore = IfrScore;
        newNode->ifrRank = IfrRank;
        newNode->isrScore = IsrScore;
        newNode->isrRank = IsrRank;
        newNode->irnScore = IrnScore;
        newNode->irnRank = IrnRank;
        newNode->gerScore = GerScore;
        newNode->gerRank = GerRank;
        newNode->scoreScaled = ScoreScaled;
        newNode->next = nullptr;
        if (head == nullptr) // check list empty or not
        {
            head = newNode; // true : new node = first node
            newNode->next = head;
        }
        else
        {
            University *last = head;
            while (last->next != head) // traverse
                last = last->next;

            last->next = newNode;
            newNode->next = head;
        }
        size++; // increment the size value
    }

    int getSize()
    {
        return size;
    }


    //========================= Sorting algorithm ========================


    /*Bubble sort algorithm*/

    void swap(University *i, University *j)
    {
        int swapRank;
        string swapInstitution, swapLocationCode, swapLocation;
        double swapArScore, swapErScore, swapFsrScore, swapCpfScore, swapIfrScore, swapIsrScore, swapIrnScore, swapGerScore;
        string swapArRank, swapErRank, swapFsrRank, swapCpfRank, swapIfrRank, swapIsrRank, swapIrnRank, swapGerRank, swapScoreScaled;

        swapRank = j->rank;
        swapInstitution = j->institution;
        swapLocationCode = j->locationCode;
        swapLocation = j->location;
        swapArScore = j->arScore;
        swapArRank = j->arRank;
        swapErScore = j->erScore;
        swapErRank = j->erRank;
        swapFsrScore = j->fsrScore;
        swapFsrRank = j->fsrRank;
        swapCpfScore = j->cpfScore;
        swapCpfRank = j->cpfRank;
        swapIfrScore = j->ifrScore;
        swapIfrRank = j->ifrRank;
        swapIsrScore = j->isrScore;
        swapIsrRank = j->isrRank;
        swapIrnScore = j->irnScore;
        swapIrnRank = j->irnRank;
        swapGerScore = j->gerScore;
        swapGerRank = j->gerRank;
        swapScoreScaled = j->scoreScaled;

        j->rank = i->rank;
        j->institution = i->institution;
        j->locationCode = i->locationCode;
        j->location = i->location;
        j->arScore = i->arScore;
        j->erScore = i->erScore;
        j->fsrScore = i->fsrScore;
        j->cpfScore = i->cpfScore;
        j->ifrScore = i->ifrScore;
        j->isrScore = i->isrScore;
        j->irnScore = i->irnScore;
        j->gerScore = i->gerScore;
        j->arRank = i->arRank;
        j->erRank = i->erRank;
        j->fsrRank = i->fsrRank;
        j->cpfRank = i->cpfRank;
        j->ifrRank = i->ifrRank;
        j->isrRank = i->isrRank;
        j->irnRank = i->irnRank;
        j->gerRank = i->gerRank;
        j->scoreScaled = i->scoreScaled;

        i->rank = swapRank;
        i->institution = swapInstitution;
        i->locationCode = swapLocationCode;
        i->location = swapLocation;
        i->arScore = swapArScore;
        i->erScore = swapErScore;
        i->fsrScore = swapFsrScore;
        i->cpfScore = swapCpfScore;
        i->ifrScore = swapIfrScore;
        i->isrScore = swapIsrScore;
        i->irnScore = swapIrnScore;
        i->gerScore = swapGerScore;
        i->arRank = swapArRank;
        i->erRank = swapErRank;
        i->fsrRank = swapFsrRank;
        i->cpfRank = swapCpfRank;
        i->ifrRank = swapIfrRank;
        i->isrRank = swapIsrRank;
        i->irnRank = swapIrnRank;
        i->gerRank = swapGerRank;
        i->scoreScaled = swapScoreScaled;
    }

    //bubble sort main function
    void bubbleSort(string searchType)
    {
        University *i, *j;
        if (searchType == "UNINAME")
        {
            int loopCount1 = 0;
            int loopCount2;
            for (i = head; loopCount1 < getSize() - 1; i = i->next)
            {
                loopCount2 = 0;
                for (j = head; loopCount2 < getSize() - 1 - loopCount1; j = j->next)
                {
                    int length = j->institution.length();
                    char *char_array = new char[length + 1];
                    strcpy(char_array, j->institution.c_str());

                    int length2 = j->next->institution.length();
                    char *char_array2 = new char[length2 + 1];
                    strcpy(char_array2, j->next->institution.c_str());

                    if (strcmp(char_array, char_array2) > 0)
                    {
                        swap(j, j->next);
                    }
                    loopCount2 = loopCount2 + 1;
                    delete char_array;
                    delete char_array2;
                }
                loopCount1 = loopCount1 + 1;
            }
        }
        else
        { 
            // sort descending
            int loopCount1 = 0;
            int loopCount2;
            for (i = head; loopCount1 < getSize() - 1; i = i->next)
            {
                loopCount2 = 0;
                for (j = head; loopCount2 < getSize() - 1 - loopCount1; j = j->next)
                {
                    if (searchType == "ARSCORE" && (j->arScore < j->next->arScore))
                    {
                        swap(j, j->next);
                    }
                    else if (searchType == "ERSCORE" && (j->erScore < j->next->erScore))
                    {
                        swap(j, j->next);
                    }
                    else if (searchType == "FSRCORE" && (j->fsrScore < j->next->fsrScore))
                    {
                        swap(j, j->next);
                    }
                    loopCount2 = loopCount2 + 1;
                }
                loopCount1 = loopCount1 + 1;
            }
        }
    }



    /*merge sort algorithm*/

    //remove circular connection in order for merge sort to work
    void removeLast(University *head)
    {
        University *last = head;
        while (last->next != head) // traverse
        {
            last = last->next;
        }
        last->next = nullptr;
    }


    University *merge(University *firstNode, University *secondNode)
    {
        University *merged = new University;
        University *temp = new University;

        // Merged is equal to temp so in the end we have the top Node.
        merged = temp;

        // while either firstNode or secondNode becomes NULL
        while (firstNode != NULL &&
               secondNode != NULL)
        {
            if (firstNode->institution < secondNode->institution)
            {
                temp->next = firstNode;
                firstNode = firstNode->next;
            }

            else
            {
                temp->next = secondNode;
                secondNode = secondNode->next;
            }
            temp = temp->next;
        }

        // Any remaining Node in firstNode or secondNode gets inserted in the temp list
        while (firstNode != NULL)
        {
            temp->next = firstNode;
            firstNode = firstNode->next;
            temp = temp->next;
        }

        while (secondNode != NULL)
        {
            temp->next = secondNode;
            secondNode = secondNode->next;
            temp = temp->next;
        }

        // Return the head of the sorted list
        return merged->next;
    }

    //fiding middle node
    University *middle(University *head)
    {
        University *slow = head;
        University *fast = head->next;

        while (slow->next != NULL &&
               (fast != NULL && fast->next != NULL))
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    
    //main merge sort function
    University *mergeSort(University *head)
    {
        if (head->next == NULL)
        {
            return head;
        }
        University *mid = new University;
        University *head2 = new University;
        mid = middle(head);
        head2 = mid->next;
        mid->next = NULL;
        // Recursive call to sort() hence diving the whole list, and then merging the solution
        University *mergeSortResult = merge(mergeSort(head), mergeSort(head2));
        return mergeSortResult;
    }

    // ====================== Validation functions ======================

    // username search validation
    bool searchUsernm(string value)
    {

        int i = 1;
        customerDetail *curr = head_Customer;
        bool found = false;

        while (i <= size_customer)
        {
            if (curr->username == value)
            {
                found = true;
            }
            i++;
            curr = curr->next_customer;
        }

        return found;
    }


    //Email validation
     bool isValidEmail(const std::string &email)
    {
        // Regular expression pattern for email format
        std::regex emailRegex(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");

        return std::regex_match(email, emailRegex);
    }


    //Age validation
    bool isValidAge(const std::string &input)
    {
        if (input.length() < 1 || input.length() > 2)
        {
            return false; // Invalid length
        }

        for (char c : input)
        {
            if (!std::isdigit(c))
            {
                return false; // Non-digit character found
            }
        }

        int age = std::stoi(input);
        if (age < 1 || age > 99)
        {
            return false; // Age is out of range
        }

        return true;
    }

    //============== Printing utility functions ==================

    void showAll()
    {
        int i = 1;
        University *curr = head;
        while (i <= size)
        {
            printUniversityInfo(curr);
            curr = curr->next;
            i++;
        }
    }

    void printUniversityInfo(University *uni)
    {
        cout << "         Rank : " << uni->rank << endl;
        cout << "  Institution : " << uni->institution << endl;
        cout << " LocationCode : " << uni->locationCode << endl;
        cout << "     Location : " << uni->location << endl;
        cout << "      ArScore : " << uni->arScore << endl;
        cout << "       ArRank : " << uni->arRank << endl;
        cout << "      ErScore : " << uni->erScore << endl;
        cout << "       ErRank : " << uni->erRank << endl;
        cout << "     FsrScore : " << uni->fsrScore << endl;
        cout << "      FsrRank : " << uni->fsrRank << endl;
        cout << "     CpfScore : " << uni->cpfScore << endl;
        cout << "      CpfRank : " << uni->cpfRank << endl;
        cout << "     IfrScore : " << uni->ifrScore << endl;
        cout << "      IfrRank : " << uni->ifrRank << endl;
        cout << "     IsrScore : " << uni->isrScore << endl;
        cout << "      IsrRank : " << uni->isrRank << endl;
        cout << "     IrnScore : " << uni->irnScore << endl;
        cout << "      IrnRank : " << uni->irnRank << endl;
        cout << "     GerScore : " << uni->gerScore << endl;
        cout << "      GerRank : " << uni->gerRank << endl;
        cout << "  ScoreScaled : " << uni->scoreScaled << endl
             << endl;
    }

    void printInLine()
    {
        int i = 1;
        University *curr = head;
        while (i <= size)
        {
            cout << curr->rank << "," << curr->institution << "," << curr->locationCode << "," << curr->location << "," << curr->arScore
                 << "," << curr->arRank << "," << curr->erScore << "," << curr->erRank << "," << curr->fsrScore << "," << curr->fsrRank << "," << curr->cpfScore << "," << curr->cpfRank << "," << curr->ifrScore << "," << curr->ifrRank << "," << curr->isrScore << "," << curr->isrRank << "," << curr->irnScore << "," << curr->irnRank << "," << curr->gerScore << "," << curr->gerRank << "," << curr->scoreScaled << endl;

            curr = curr->next;
            i++;
        }
    }

    //=================================save uni=================================
    bool isDuplicate(string UserName, string Institution)
    {
        int i = 1;
        SaveUni *curr = head_save;
        if (head_save != NULL)
        {
            while (i <= size_save)
            {
                if (curr->username == UserName && curr->institution == Institution)
                {
                    return true;
                }
                i++;
                curr = curr->next_save;
            }
        }
        return false;
    }

    void saveInsertAtEndUni(string UserName, string Institution)
    {
        bool isDup;
        isDup = isDuplicate(UserName, Institution);
        if (isDup == false && Institution != "None")
        {
            cout << "\nSaved Successfully!!\n"
                 << endl;
            SaveUni *newNode = new SaveUni;
            newNode->username = UserName;
            newNode->institution = Institution;
            newNode->next_save = nullptr;

            if (head_save == nullptr) // check list empty or not
            {
                head_save = newNode;
                newNode->next_save = head_save;
            }
            else
            {
                SaveUni *last = head_save;
                while (last->next_save != head_save)
                    last = last->next_save;
                last->next_save = newNode;
                newNode->next_save = head_save;
            }
            size_save++;
        }
        else if (isDup == true)
        {
            cout << "\nThis university aldready been saved!\n"
                 << endl;
        }
    }

    string *saveSearchForUni(string UserName, string uniName)
    {
        int i = 1;
        University *curr = head;
        bool isValid;
        static string temp[2];

        while (i <= size)
        {
            if (curr->institution == uniName)
            {
                temp[1] = UserName;
                temp[2] = curr->institution;
                return temp;
            }
            i++;
            curr = curr->next;
        }
        if (isValid == false)
        {
            temp[1] = "None";
            temp[2] = "None";
            cout << "\nNothing found!!\n"
                 << endl;
        }
        return temp;
    }

    void saveView(string UserName, University *list_uni, int sizeOfUni)
    {
        int i = 1;

        SaveUni *curr_save = head_save;
        cout << endl
             << "===================================" << endl;
        if (head_save == nullptr)
        {
            cout << "Nothing found" << endl;
            return;
        }
        cout << "This is your favorite university: " << endl;
        while (i <= size_save)
        {
            if (curr_save->username == UserName)
            {
                saveLinearSearch(list_uni, curr_save->institution, sizeOfUni);
            }
            i++;
            curr_save = curr_save->next_save;
        }
    }

    void saveLinearSearch(University *list_uni, string uniName, int sizeOfUni)
    {
        int i = 1;
        University *curr = list_uni;
        bool isValid = false;
        cout << endl
             << uniName << endl;
        while (i <= sizeOfUni)
        {
            if (curr->institution == uniName)
            {
                printUniversityInfo(curr);
                isValid = true;
            }
            i++;
            curr = curr->next;
        }
        if (isValid == false)
        {
            cout << "Nothing found1" << endl;
        }
    }

    
    //============================feedback====================================

    void addFeedback(string UserName, string comment, int rating)
    {
        cout << "\nSend Feedback Succesfully!\n"
             << endl;
        Feedback *newNode = new Feedback;
        newNode->username = UserName;
        newNode->comment = comment;
        newNode->rating = rating;
        newNode->reply = "";
        newNode->next_feedback = nullptr;

        if (head_Feedback == nullptr) // check list empty or not
        {
            head_Feedback = newNode;
            newNode->next_feedback = head_Feedback;
        }
        else
        {
            Feedback *last = head_Feedback;
            while (last->next_feedback != head_Feedback) // traverse
                last = last->next_feedback;
            last->next_feedback = newNode;
            newNode->next_feedback = head_Feedback;
        }
        size_feedback++;
    }

    void viewAllFeedback(string userName)
    {
        int i = 1;
        Feedback *curr = head_Feedback;
        if (head_Feedback == nullptr)
        {
            cout << "\nNo feedback found for " << userName << "." << endl;
            return;
        }

        while (i <= size_feedback)
        {
            if (curr->username == userName)
            {
                cout << "\nAll my feedbacks:" << endl;
                cout << "-------------------" << endl;
                cout << "UserName: " << curr->username << endl;
                cout << "Comment : " << curr->comment << endl;
                cout << "Rating (1-5) : " << curr->rating << endl;
                if (curr->reply.empty())
                {
                    cout << "Feedback Status: No reply yet!" << endl;
                }
                else
                {
                    cout << "Feedback Status: Admin replied!" << endl;
                    cout << "-------------------" << endl;
                    cout << " Press 'r' to read admin replied! or press 'q' to quit" << endl;
                    char option;
                    cin >> option;
                    if (option == 'r')
                    {
                        cout << "\nReplied feedbacks from admin:" << endl;
                        cout << "-------------------" << endl;
                        readRepliedFeedbacks(userName);   
                    }
                    else if (option == 'q')
                    {
                        return;
                    }
                    else
                    {
                        cout << "\nInvalid choice. Please try again." << endl;
                    }
                }           
            }
            curr = curr->next_feedback;
            i++;
        }

    }

    void readRepliedFeedbacks(string userName)
    {
        int i = 1;
        Feedback *curr = head_Feedback;
        if (head_Feedback == nullptr)
        {
            cout << "No feedback found for " << userName << "." << endl;
            return;
        }
        while (true)
        {
            if (curr->username == userName)
            {
                if (curr->reply.empty())
                {  
                    cout << "\nThere have no feedback been reply by admin yet! \n" << endl;
                    break;
                }else
                {
                    cout << "UserName: " << curr->username << endl;
                    cout << "Comment : " << curr->comment << endl;
                    cout << "Rating (1-5) : " << curr->rating << endl;
                    cout << "Admin reply: " << curr->reply << endl;
                    break;
                }
            }
            curr = curr->next_feedback;
            i++;
        }
    }

    void adminFeedback()
    {
        char choice;
        Feedback *curr = head_Feedback;
        Feedback *prev = nullptr;
        if (curr == nullptr)
        {
            cout << "No feedback available." << endl;
            return;
        }

        while (true)
        {
            cout << "Username: " << curr->username << endl;
            cout << "Comment: " << curr->comment << endl;
            cout << "Rating (1-5): " << curr->rating << endl;
            cout << "Reply: " << curr->reply << endl
                 << endl;

            cout << "Press 'n' for next feedback, 'p' for previous feedback, 'r' for reply feedback, or 'q' to quit: ";
            cin >> choice;
            cout << endl;

            if (choice == 'n')
            {
                prev = curr;
                curr = curr->next_feedback;
                if (curr == head_Feedback)
                {
                    cout << endl
                         << "--------------------------------------" << endl;
                    cout << "No more feedback available." << endl;
                    cout << "--------------------------------------" << endl
                         << endl;
                    break;
                }
            }
            else if (choice == 'p')
            {
                if (curr == head_Feedback)
                {
                    cout << endl
                         << "--------------------------------------" << endl;
                    cout << "This is the first feedback." << endl;
                    cout << "--------------------------------------" << endl
                         << endl;
                    break;
                }
                else
                {
                    prev = findPreviousFeedback(curr);
                    curr = prev;
                }
            }
            else if (choice == 'r')
            {
                cout << "Add Reply: ";
                cin.ignore();
                getline(cin, curr->reply);
                cout << endl
                     << "--------------------------------------" << endl;
                cout << "Reply saved successfully." << endl;
                cout << "--------------------------------------" << endl
                     << endl;
            }
            else if (choice == 'q')
            {
                system("cls");
                break;
            }
            else
            {
                cout << "Invalid choice. Please try again." << endl;
            }
        }
    }

    Feedback *findPreviousFeedback(Feedback *current)
    {
        Feedback *temp = head_Feedback;

        while (temp->next_feedback != current)
        {
            temp = temp->next_feedback;
        }

        return temp;
    }

    //============================customer detail====================================
    void insertToCustomerDetail(string username, string password, string email, int age, string status)
    {
        customerDetail *newNode = new customerDetail;
        newNode->username = username;
        newNode->password = password;
        newNode->email = email;
        newNode->age = age;
        newNode->status = status;
        newNode->next_customer = nullptr;

        if (head_Customer == nullptr) // check list empty or not
        {
            head_Customer = newNode; // true : new node = first node
            newNode->next_customer = head_Customer;
        }
        else
        {
            customerDetail *last = head_Customer;
            while (last->next_customer != head_Customer)
                last = last->next_customer;

            last->next_customer = newNode;
            newNode->next_customer = head_Customer;
        }
        size_customer++; // increment the size value
    }
    bool userfound(string UserName)
    {
        bool found = false;
        int sizeOfCusList = 1;
        customerDetail *curr = head_Customer;
        while (sizeOfCusList <= size_customer)
        {
            if (curr->username == UserName)
            {
                found = true;
            }
            sizeOfCusList++;
            curr = curr->next_customer;
        }
        return found;
    }

    bool passcompare(string UserName, string pass)
    {
        bool found = false;
        int sizeOfCusList = 1;
        customerDetail *curr = head_Customer;
        while (sizeOfCusList <= size_customer)
        {
            if (curr->username == UserName)
            {
                if (curr->password == pass)
                {
                    found = true;
                }
            }
            sizeOfCusList++;
            curr = curr->next_customer;
        }
        return found;
    }

    void regisConfirmation(string UserName)
    {
        bool run = true;
        char exit;
        int sizeOfCusList = 1;
        customerDetail *curr = head_Customer;
        while (sizeOfCusList <= size_customer)
        {
            if (curr->username == UserName)
            {
                while (run)
                {
                    cout << endl
                         << "================== PROFILE SUCCESSFULLY CREATED :) =================\n"
                         << endl;
                    cout << "Welcome, " << endl;
                    cout << "This is your profile: " << endl;
                    cout << " Username : " << curr->username << endl;
                    cout << " Password : " << curr->password << endl;

                    cout << " Email : " << curr->email << endl;
                    cout << " Age : " << curr->age << endl;
                    cout << " Status : " << curr->status << endl;
                    cout << endl
                         << "You can now login with your username and password\n"
                         << endl;
                    cout << "Key in any character to continue ..." << endl;
                    cin >> exit;
                    if (exit != '\0')
                    {
                        run = false;
                    }
                }
            }
            sizeOfCusList++;
            curr = curr->next_customer;
        }
    }

    void printCustomerProfile(string UserName, string userType)
    {
        char option;
        string current_password, new_password, email_input, age_input, current_status, new_status;
        int sizeOfCusList = 1;
        customerDetail *curr = head_Customer;

        if (head_Customer == nullptr)
        {
            cout << "Nothing found" << endl;
            return;
        }

        while (sizeOfCusList <= size_customer)
        {
            if (curr->username == UserName)
            {
                while (1)
                {
                    cout << endl
                         << "===================================" << endl;
                    cout << "This is the profile: " << endl;
                    cout << "(1) Username : " << curr->username << endl;
                    cout << "(2) Password : "
                         << "For secure purpose, not to disclose" << endl;
                    cout << "(3) Email : " << curr->email << endl;
                    cout << "(4) Age : " << curr->age << endl;
                    cout << "(5) Status: " << curr->status << endl;
                    cout << "(6) Exit " << endl;
                    cout << "===================================" << endl;
                    cout << "Which one do you want to edit? Enter the number (1-6):";
                    cin >> option;

                    switch (option)
                    {
                    case '1':
                        cout << "\nYou are not allow to edit this.\n"
                             << endl;
                        break;
                    case '2':
                        cout << "Please enter your current password: ";
                        cin >> current_password;
                        if (current_password == curr->password)
                        {
                            cout << "Please enter your new password (At least 5 characters): ";
                            cin >> new_password;
                            if (new_password.length() >= 5)
                            {
                                curr->password = new_password;
                                cout << "\nSuccessfully Update!\n"
                                     << endl;
                            }
                            else
                            {
                                cout << "\nFail to update! Please enter at least 5 characters!\n"
                                     << endl;
                            }
                        }
                        else
                        {
                            cout << "\nFail to update! Incorrect current password!\n"
                                 << endl;
                        }
                        break;
                    case '3':
                        std::cout << "Enter an email address: ";
                        std::cin >> email_input;
                        if (isValidEmail(email_input))
                        {
                            curr->email = email_input;
                            cout << "\nSuccessfully Update!\n"
                                 << endl;
                        }
                        else
                        {
                            std::cout << "\nFail to update! Invalid email address.\n"
                                      << endl;
                        }
                        break;
                    case '4':
                        std::cout << "Enter age: ";

                        std::cin >> age_input;
                        if (isValidAge(age_input))
                        {
                            curr->age = std::stoi(age_input);
                            cout << "\nSuccessfully Update!\n"
                                 << endl;
                        }
                        else
                        {
                            cout << "\nFail to update! Please enter integer number.\n\n";
                        }
                        break;
                    case '5':
                        if (userType == "admin")
                        {
                            cout << "\nChange to active/inactive" << endl;
                            cout << "(1) Active" << endl;
                            cout << "(2) Inactive" << endl;
                            cout << "Enter the new status (1,2): ";
                            int statusChoice;
                            cin >> statusChoice;
                            if (statusChoice == 1)
                                new_status = "active";
                            else if (statusChoice == 2)
                                new_status = "inactive";
                            else
                            {
                                cout << "\nInvalid choice (Pls choose between 1 or 2)." << endl;
                                return;
                            }
                            curr->status = new_status;
                            cout << "\nSuccessfully Update!\n"
                                 << endl;
                        }
                        else
                        {
                            cout << "\nYou are not allow to edit this.\n"
                                 << endl;
                        }
                        break;
                    case '6':
                        system("cls");
                        return;
                    default:
                        cout << "\n Invalid Input!! Please input number (1-5).\n\n";
                        break;
                    }
                }
            }

            sizeOfCusList++;
            curr = curr->next_customer;
        }
    }

   

    void checkStatus()
    {
        if (head_Customer == nullptr)
        {
            cout << "No customers available." << endl;
            return;
        }

        cout << "Inactive Customers: " << endl;
        customerDetail *curr = head_Customer;
        int cusCount = 1;
        bool inactiveCus = false;

        while (cusCount <= size_customer)
        {
            if (curr->status == "inactive")
            {
                cout << "Username: " << curr->username << endl;
                cout << "Email: " << curr->email << endl;
                cout << "Age: " << curr->age << endl;
                cout << "------------------------------------" << endl;
                inactiveCus = true;
            }
            cusCount++;
            curr = curr->next_customer;
        }

        if (inactiveCus = false)
        {
            cout << "No inactive customers found." << endl;
            cout << "------------------------------------" << endl;
            return;
        }

        deleteCus();
    }

    void deleteCus()
    {
        string usr;
        cout << "(You can only delete inactive customer)" << endl;
        cout << "Enter the username of the customer you wish to delete: ";
        cin >> usr;

        customerDetail *curr = head_Customer;
        customerDetail *prev = nullptr;

        while (curr->username != usr || curr->status != "inactive")
        {
            prev = curr;
            curr = curr->next_customer;

            if (curr == head_Customer)
            {
                cout << "Customer not found or cannot be deleted." << endl;
                return;
            }
        }

        if (prev == nullptr)
        {
            head_Customer = curr->next_customer;
        }
        else
        {
            prev->next_customer = curr->next_customer;
        }

        delete curr;
        cout << "Customer successfully deleted." << endl;
        size_customer--;
    }

    //============================View all user detail=================================
    void printCustomerDetailsBundle()
    {
        if (head_Customer == nullptr)
        {
            cout << "\nNo customers registered." << endl;
            return;
        }
        else
        {
            customerDetail *current = head_Customer;
            int sizeOfCusList = 1;

            do
            {
                cout << "\nCustomer:" << sizeOfCusList << endl;
                cout << "Username: " << current->username << endl;
                cout << "Email: " << current->email << endl;
                cout << "Age: " << current->age << endl;
                cout << "Status: " << current->status << endl;
                cout << endl;

                sizeOfCusList++;
                current = current->next_customer;
            } while (current != head_Customer);
        }
    }

    void printCustomerDetailsTable()
    {
        if (head_Customer == nullptr)
        {
            cout << "\nNo customers registered." << endl;
            return;
        }
        else
        {
            cout << "----------------------------------------------------------------------" << endl;
            cout << " Customer | Username           | Email              | Age | Status   |" << endl;
            cout << "----------------------------------------------------------------------" << endl;

            customerDetail *current = head_Customer;
            int sizeOfCusList = 1;

            do
            {
                cout.width(10);
                cout << left << sizeOfCusList << "|";
                cout.width(20);
                cout << left << current->username << "|";
                cout.width(20);
                cout << left << current->email << "|";
                cout.width(5);
                cout << left << current->age << "|";
                cout.width(10);
                cout << left << current->status << "|";
                cout << endl;
                sizeOfCusList++;
                current = current->next_customer;
            } while (current != head_Customer);

            cout << "------------------------------------------------------------------------" << endl;
        }
    }

    //============================change admin password=================================
    void insertToAdminDetail(string username, string password, string email)
    {
        adminDetail *newNode = new adminDetail;
        newNode->usesrname_admin = username;
        newNode->password_admin = password;
        newNode->email_admin = email;
        newNode->next_admin = nullptr;

        if (head_admin == nullptr) // check list empty or not
        {
            head_admin = newNode; // true : new node = first node
            newNode->next_admin = head_admin;
        }
        else
        {
            adminDetail *last = head_admin;
            while (last->next_admin != head_admin)
                last = last->next_admin;

            last->next_admin = newNode;
            newNode->next_admin = head_admin;
        }
        size_admin++; // increment the size value
    }

    bool userAdminfound(string UserName)
    {
        bool found = false;
        int sizeOfCusList = 1;
        adminDetail *curr = head_admin;
        while (sizeOfCusList <= size_admin)
        {
            if (curr->usesrname_admin == UserName)
            {
                found = true;
            }
            sizeOfCusList++;
            curr = curr->next_admin;
        }
        return found;
    }

    bool passcompare_admin(string UserName, string pass)
    {
        bool found = false;
        int sizeOfCusList = 1;
        adminDetail *curr = head_admin;
        while (sizeOfCusList <= size_admin)
        {
            if (curr->usesrname_admin == UserName)
            {
                if (curr->password_admin == pass)
                {
                    found = true;
                }
            }
            sizeOfCusList++;
            curr = curr->next_admin;
        }
        return found;
    }

    //============================Generate Report=================================
    //======================TOP 10============================================
void swapTop10(SaveUni *i, SaveUni *j)
    {
        string swapUsername, swapUni;

        swapUsername = j->username;
        swapUni = j->institution;
       
        j->username = i->username;
        j->institution = i->institution;
        
        i->username = swapUsername;
        i->institution = swapUni;
    }

    void sortTop10()
    {
        int loopCount1 = 0;
        int loopCount2;
        SaveUni *i, *j;
            for (i = head_save; loopCount1 < size_save ; i = i->next_save)
            { 
                loopCount2 = 0;
                for (j = i->next_save;  loopCount2 < size_save-loopCount1 - 1; j = j->next_save)
                {
                    if ((i->institution > j->institution))
                    {
                        swapTop10(i, j);                        
                    }
                    loopCount2++;
                }
                loopCount1++;
            }
    }


     void storeTop10(){      
         int sizeOfSaveList = 1;

        int rank_num = 1;
        int count = 1;
        string isSameUni;
        if (head_save == nullptr)
        {
            return;
        }
        SaveUni *current = head_save;


        while (sizeOfSaveList <= size_save)
        {            
            if (current -> institution == current -> next_save -> institution && size_count > 1){
                count++;
            } 
            else{
                cout << current->institution << " " << count << endl;
                //store to linkedlist
                InstitutionCount *newNode = new InstitutionCount;
                newNode->count = count;
                newNode->institution = current->institution;
                newNode->next = nullptr;
                if (head_count == nullptr)
                {
                    head_count = newNode;
                    newNode->next = head_count;
                    size_count++;
                }
                else
                {
                    InstitutionCount *last = head_count;
                    while (last->next != head_count)
                        last = last->next;

                    last->next = newNode;
                    newNode->next = head_count;
                    size_count++;
                }
                count = 1;
            }          

            current = current->next_save;
            sizeOfSaveList++;
        }
         
    }


    void printTop10(){
        int rank_num = 1;
        int num = 1;
        string isSameUni;
        if (head_save == nullptr)
        {
            return;
        }

        InstitutionCount *current = head_count;

        cout << "This is TOP 10 Saved Universities: \n " << endl;
            cout << "Rank | University Name                                   | Number of saved" << endl;
            cout << "---------------------------------------------------------------------------" << endl;

            while (num <= 10 && num <= size_count)
            {
                    cout.width(5); cout << left << rank_num << "| ";
                    cout.width(50); cout << left << current->institution << "| ";
                    cout.width(20); cout << left << current->count << endl ;
                    current = current->next;
                    rank_num++;
                    num++;
            }
            cout << endl;
    }

    
    

    void generateTop10Universities()
    {
        // Traverse the circular linked list of favorite universities
        if (head_save == nullptr)
        {
            cout << "No favorite universities found." << endl;
            return;
        }
        SaveUni *temp_save = head_save;
        while (temp_save->next_save != head_save)
        {
            temp_save = temp_save->next_save;
        }
        temp_save->next_save = nullptr;

        SaveUni *curr_save = head_save;
        while (curr_save != nullptr)
        {
            //count how many same uni
            int count = 1;
            SaveUni *cmp_save = curr_save->next_save;
            while (cmp_save != nullptr)
            {
                if (cmp_save->institution == curr_save->institution && cmp_save->institution != "")
                {
                    count++;
                    cmp_save->institution = "";
                }
                cmp_save = cmp_save->next_save;
            }

            //insert data into instutionCount
            if (curr_save->institution != "")
            {
                InstitutionCount *newNode = new InstitutionCount;
                newNode->count = count;
                newNode->institution = curr_save->institution;
                newNode->next = nullptr;
                if (head_count == nullptr)
                {
                    head_count = newNode;
                    newNode->next = head_count;
                    size_count++;
                }
                else
                {
                    InstitutionCount *last = head_count;
                    while (last->next != head_count)
                        last = last->next;

                    last->next = newNode;
                    newNode->next = head_count;
                    size_count++;
                }
            }
            curr_save = curr_save->next_save;
        }
    }



    void bubbleSortAdminReport()
    {
        InstitutionCount *i, *j;
        int loopCount1 = 0;
        int loopCount2;
            for (i = head_count; loopCount1 < size_count -1 ; i = i->next)
            { 
                loopCount2 = 0;
                for (j = i->next;  loopCount2 < size_count-loopCount1 - 1; j = j->next)
                {
                    if ((i->count < j->count))
                    {
                        swapReportOrder(i, j);                        
                    }
                    loopCount2++;
                }
                loopCount1++;
            }            

    }

    void swapReportOrder(InstitutionCount *i, InstitutionCount *j)
    {
        int swapCount;
        string swapInstitution;

        swapCount = j->count;
        swapInstitution = j->institution;

        j->count = i->count;
        j->institution = i->institution;

        i->count = swapCount;
        i->institution = swapInstitution;

    }
};




