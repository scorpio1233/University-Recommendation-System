#include <iostream>
#include <chrono>

using namespace std;

struct logevent{
    string username;
    string status;
    string timestamp;
};
class NodeStack
{
public:
    string userName_stack;
    string status_stack;
    string  timestamp_stack;
    NodeStack *next;
};

class MyStackLinked
{
public:
    NodeStack *top = nullptr;

public:
    bool isEmpty() { return (top == nullptr) ? true : false; }
    //  bool isFull(){}

    // int peek()
    // {
    //     return top->data;
    // }

    void push(string usernm, string status, string timestamp)
    {
        NodeStack *newNode = new NodeStack();
        newNode->userName_stack = usernm;
        newNode->status_stack = status,
        newNode->timestamp_stack = timestamp;
        newNode->next = top;

        top = newNode;
    }

    // int pop()
    // {
    //     int elem = -1;
    //     if (isEmpty()) // empty stack
    //         cout << "Stack is empty!" << endl;
    //     else
    //     {
    //         elem = top->data;
    //         top = top->next;
    //     }
    //     return elem;
    // }

    void show()
    {
        NodeStack *node;
        if (!isEmpty())
        {
            cout << "This is customer login and logout log: \n " << endl;
            cout << "username            | status    |  timestamp " << endl;
            cout << "---------------------------------------------------------" << endl;

            node = top;
            while (node != nullptr)
            {
                cout.width(20); cout << left << node->userName_stack << "|";
                cout.width(11); cout << left << node->status_stack << "|";
                cout.width(20); cout << left << node->timestamp_stack ;
                node = node->next;
            }
            cout << endl;
        }
        else
            cout << "Stack is empty!" << endl;
    }
};
