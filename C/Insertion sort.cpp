#include <iostream>
using namespace std;
class insertion
{
    int a[50];

public:
    void readelements(int s);
    void display(int s);
    void insertionsort(int s);
};
void insertion::readelements(int s)
{
    for (int i = 0; i < s; i++)
    {
        cin >> a[i];
    }
}
void insertion::display(int s)
{
    for (int i = 0; i < s; i++)
    {
        cout << " " << a[i];
        cout << endl;
    }
}
void insertion::insertionsort(int s)
{
    int key, position, com = 0, ex = 0;
    for (int i = 1; i < s; i++)
    {
        com++;
        key = a[i];
        position = i - 1;
        while ((position >= 0) && (a[position] > key))
        {
            a[position + 1] = a[position];
            position = position - 1;
            ex++;
        }
        a[position + 1] = key;
    }
    cout << "Total number of comparisons: " << com << endl;
    cout << "Total number of exchanges: " << ex << endl;
}
int main()
{
    int size;
    cout << "Enter the size of list " << endl;
    cin >> size;
    insertion s;
    cout << "Enter the elements to the list " << endl;
    s.readelements(size);
    cout << "The list before sorting " << endl;
    s.display(size);
    s.insertionsort(size);
    cout << "List after sorting " << endl;
    s.display(size);
    return 0;
}