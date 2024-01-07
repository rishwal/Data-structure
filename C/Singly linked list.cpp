#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    // A constructor is called here
    node(int value)
    {

        // It automatic assigns the
        // value to the data
        data = value;

        // Next pointer is pointed to NULL
        next = NULL;
    }
};

class Singly_linkedlist
{
public:
    // Function to insert an element
    // at head position
    void insertathead(node *&head, int val)
    {
        node *n = new node(val);
        n->next = head;
        head = n;
        cout << val << " inserted at the beggining" << endl;
    }

    // Function to insert a element
    // at a specified position
    void insertafter(node *head, int key, int val)
    {
        cout << val << " inserted after " << key << endl;
        node *n = new node(val);
        if (key == head->data)
        {
            n->next = head->next;
            head->next = n;
            return;
        }

        node *temp = head;
        while (temp->data != key)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                return;
            }
        }
        n->next = temp->next;
        temp->next = n;
    }

    // Function to insert an
    // element at the end
    void insertattail(node *&head, int val)
    {
        node *n = new node(val);
        if (head == NULL)
        {
            head = n;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        cout << val << " inserted at the end" << endl;
    }

    void deleteAtFirst(node *&head)
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    void deleteatTail(node *head)
    {
        node *prev = NULL;
        node *temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        delete temp;
        prev->next = NULL;
        return;
    }

    // Function to print the
    // singly linked list
    void print(node *&head)
    {
        cout << "****Singly linked list****" << endl;
        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
// Main function
int main()
{

    // Declaring an empty linked list
    node *head = NULL;
    int op, e, n;
    Singly_linkedlist s;

    do
    {

        cout << endl
             << "1.insert at the beginning\n2.insert at any position\n3.insert at the end \n4.delete at beginning\n5.delete at end\n6.display\n7.exit " << endl;
        cout << "enter your choice:" << endl;
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Enter the element to be inserted at the beggining:";
            cin >> e;
            s.insertathead(head, e);
            break;
        case 2:
            cout << "Enter the element to be inserted:";
            cin >> e;
            cout << "Enter the postion of new node (previuos node): ";
            cin >> n;
            s.insertafter(head, n, e);
            break;
        case 3:
            cout << "Enter element to be inserted at the end:";
            cin >> e;
            s.insertattail(head, e);
            break;
        case 4:
            s.deleteAtFirst(head);
            break;
        case 5:
            s.deleteatTail(head);
            break;
        case 6:
            s.print(head);
            break;
        case 7:
            return 0;
            break;
        default:
            cout << "invalid choice!" << endl;
        }
    } while (op != 7);
}
