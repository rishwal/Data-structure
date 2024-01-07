#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

class Merge_sorted_linkedlist
{
public:
    node *createList(int *arr, int n)
    {
        node *head, *p;
        p = head = new node;
        head->data = arr[0];
        head->next = NULL;
        for (int i = 1; i < n; ++i)
        {
            p->next = new node;
            p = p->next;
            p->data = arr[i];
            p->next = NULL;
        }
        return head;
    }
    void displayList(node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
    node *mergeSortedLists(node *head1, node *head2)
    {
        node *result = NULL;
        if (head1 == NULL)
        {
            return head2;
        }
        if (head2 == NULL)
        {
            return head1;
        }
        if (head1->data < head2->data)
        {
            result = head1;
            result->next = mergeSortedLists(head1->next, head2);
        }
        else
        {
            result = head2;
            result->next = mergeSortedLists(head1, head2->next);
        }
        return result;
    }
};
int main()
{
    Merge_sorted_linkedlist m;
    int n1, n2;
    node *head1, *head2, *result = NULL;
    cout << "Enter the number of elements in the first linked list" << endl;
    cin >> n1;
    int arr1[n1];
    cout << "Enter the elements of first linkedlist" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in the second linked list" << endl;
    cin >> n2;
    int arr2[n2];
    cout << "Enter elements of second linked list" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr2[i];
    }

    head1 = m.createList(arr1, n1);
    head2 = m.createList(arr2, n2);

    cout << "First sorted list: " << endl;
    m.displayList(head1);
    cout << "Second sorted list: " << endl;
    m.displayList(head2);
    result = m.mergeSortedLists(head1, head2);
    cout << "Final sorted list: " << endl;
    m.displayList(result);
    return 0;
}