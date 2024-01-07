#include <iostream>
using namespace std;
class linklist
{
private:
    struct node
    {
        int data;
        node *link;
    } * start;

public:
    linklist()
    {
        start = NULL;
    }
    void append(int);
    void display();
    void merge(linklist, linklist, linklist &);
    ~linklist()
    {
        node *q;
        while (start != NULL)
        {
            q = start->link;
            delete start;
            start = q;
        }
    }
};
void linklist::append(int num)
{
    node *temp, *r;
    temp = start;
    if (start == NULL)
    {
        temp = new node;
        temp->data = num;
        temp->link = NULL;
        start = temp;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        r = new node;
        r->data = num;
        r->link = NULL;
        temp->link = r;
    }
}
void linklist::display()
{
    node *temp;
    temp = start;
    cout << "Linked list is" << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}
void linklist::merge(linklist l1, linklist l2, linklist &l3)
{
    node *p, *q;
    p = l1.start;
    q = l2.start;
    int dat;
    while (p != NULL && q != NULL)
    {
        if (p->data > q->data)
        {
            dat = q->data;
            l3.append(dat);
            q = q->link;
        }
        else
        {
            dat = p->data;
            l3.append(dat);
            p = p->link;
        }
    }
    if (p == NULL)
    {
        while (q != NULL)
        {
            dat = q->data;
            l3.append(dat);
            q = q->link;
        }
    }
    else
    {
        while (p != NULL)
        {
            dat = p->data;
            l3.append(dat);
            p = p->link;
        }
    }
    cout << "lists merged" << endl;
}
int main()
{
    linklist l1, l2, l3;
    int n1, n2, ele1, ele2;
    cout << "enter the number of elements in the first linked list\n";
    cin >> n1;
    cout << "enter the elements of first linkedlist\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> ele1;
        l1.append(ele1);
    }
    cout << "enter the number of elements in the second linked list\n";
    cin >> n2;
    cout << "enter elements of second of second linked list\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> ele2;
        l2.append(ele2);
    }
    l3.merge(l1, l2, l3);
    l3.display();
    return 0;
}