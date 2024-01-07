#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;

    node(int value)
    {
        prev = NULL;

        data = value;
        next = NULL;
    }
};
class Doubly_linkedlist
{
public:
    void insert_at_head(node *&head, int value)
    {

        node *n = new node(value);
        n->next = head;

        if (head != NULL)
        {
            head->prev = n;
        }

        head = n;
    }

    void insert_at_tail(node *&head, int value)
    {

        if (head == NULL)
        {
            insert_at_head(head, value);
            return;
        }

        node *n = new node(value);
        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
    }

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

        node *new_node = new node(val);

        new_node->data = val;

        new_node->next = head->next;

        head->next = new_node;

        new_node->prev = head;

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

    void display(node *head)
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " --> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};
int main()
{
    node *head = NULL; // declaring an empty doubly linked list
    int ch;
    do
    {
        int e, n;
        cout << endl
             << "1.insert at the beginning\n2.insert at any position\n3.insert at the end \n4.delete at beginning\n5.delete at end\n6.display\n7.exit " << endl;
        cin >> ch;
        Doubly_linkedlist d;
        switch (ch)
        {
        case 1:
            cout << "Enter the element to be inserted at the beggining:";
            cin >> e;
            d.insert_at_head(head, e);
            break;
        case 2:
            cout << "Enter the element to be inserted:";
            cin >> e;
            cout << "Enter the postion of new node (previuos node): ";
            cin >> n;
            d.insertafter(head, n, e);
            break;
        case 3:
            cout << "Enter element to be inserted at the end:";
            cin >> e;
            d.insert_at_tail(head, e);
            break;
        case 4:
            d.deleteAtFirst(head);
            break;
        case 5:
            d.deleteatTail(head);
            break;
        case 6:
            d.display(head);
            break;
        case 7:
            return 0;
            break;
        default:
            cout << "invalid choice!" << endl;
        }
    } while (ch != 7);

    return 0;
}
