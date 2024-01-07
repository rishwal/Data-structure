#include <iostream>
using namespace std;
class Bubble_sort
{
public:
    int a[100];
    void insert(int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Enter the " << i << " th elemnt" << endl;
            cin >> a[i];
        }
    }
    void display(int size)
    {

        for (int i = 0; i < size; i++)
        {
            cout << a[i] << endl;
        }
    }
    void Bubblesort(int size)
    {
        int i, j, temp, com = 0, ex = 0;
        for (i = 0; i < size - 1; i++)
        {

            for (j = 0; j < size - i - 1; j++)
            {
                com++;
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                    ex++;
                }
               
            }
        }
        cout << "Total no of comparisons: " << com  << endl;
        cout << "Total no of exchanges: " << ex << endl;
    }
};

int main()
{
    int size;
    Bubble_sort b;
    cout << "Enter the number of elements to sort" << endl;
    cin >> size;
    b.insert(size);
    cout << "*****BUBBLE SORT*****" << endl;
    cout << "Elements before sorting" << endl;
    b.display(size);
    b.Bubblesort(size);
    cout << "Elements after sorting" << endl;
    b.display(size);
    return 0;
}