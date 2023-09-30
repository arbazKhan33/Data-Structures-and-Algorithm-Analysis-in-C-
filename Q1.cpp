#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

template <class T>
class LinkedStack
{
private:
    struct Node
    {
        T value;
        Node* next;
    };
    Node* top;
    size_t size;

public:
    LinkedStack()
    {
        top = NULL;
        size = 0;
    }
    ~LinkedStack()
    {
        Node* p = top;
        while (p != NULL)
        {
            Node* temp = p;
            p = p->next;
            delete temp;
        }
        size = 0;
    }
    void push(T item)
    {
        Node* newNode = new Node;
        newNode->value = item;
        newNode->next = top;
        top = newNode;
        size++;
    }
    void pop()
    {
        if (top == NULL)
            return;

        Node* temp = top;
        T item = temp->value;
        top = top->next;

        size--;
        delete temp;
        return;
    }
    T peek()
    {
        return top->value;
    }

    bool isEmpty()
    {
        return top == NULL;
    }
};

int main()
{

    ifstream file("input.txt");
    if (!file.is_open())
    {
        cout << "Error opening file" << endl;
        return 0;
    }

    string line;

    while (getline(file, line))
    {
        istringstream iss(line);
        int num;



        LinkedStack<int> oddStack;
        LinkedStack<int> evenStack;
        while (iss >> num)
        {
            if (num % 2 == 0)
            {
                if (evenStack.isEmpty())
                {
                    evenStack.push(num);
                }
                else
                {
                    if (evenStack.peek() == num)
                    {
                        evenStack.pop();
                    }
                    else
                    {
                        evenStack.push(num);
                    }
                }
            }
            else
            {
                if (oddStack.isEmpty())
                {
                    oddStack.push(num);
                }
                else
                {
                    if (oddStack.peek() == num)
                    {
                        oddStack.pop();
                    }
                    else
                    {
                        oddStack.push(num);
                    }
                }
            }
        }

        cout << "Odd Top: ";
        cout << setw(10) << left;
        if (oddStack.isEmpty())
        {
            cout << "NULL";
        }
        else
        {
            cout << oddStack.peek();
        }

        cout << "Even Top: ";
        cout << setw(10) << left;
        if (evenStack.isEmpty())
        {
            cout << "NULL";
        }
        else
        {
            cout << evenStack.peek();
        }

        cout << endl;
    }

    return 0;
}