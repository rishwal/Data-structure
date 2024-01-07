#include <iostream>
using namespace std;

class sequential_and_binary
{
public:
    int Binary_search(int a[], int start, int end, int item, int iter)
    {
        int i, mid;
        cout << "\niteration " << iter + 1;
        iter++;
        mid = start + (end - start + 1) / 2;
        if (item > a[end] || item < a[start] || mid == end)
        {
            cout << "\nNot found";
            return iter;
        }
        else if (item == a[mid])
        {
            cout << "\n item found at " << mid << " index."<<endl;
            return iter;
        }
        else if (item == a[start])
        {
            cout << "\n item found at " << start << " index."<<endl;
            return iter;
        }
        else if (item == a[end])
        {
            cout << "\n item found at " << end << " index."<<endl;
            return iter;
        }
        else if (item > a[mid])
            Binary_search(a, mid, end, item, iter);
        else
            Binary_search(a, start, mid, item, iter);
    }

    int Sequentai_search(int a[], int n, int item)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            cout << "iteration :" << i + 1 << endl;
            if (a[i] == item)
            {
                cout << item << " Found at " << i << " index" << endl;
                return i + 1;
            }
        }
        cout << "Item not found"<<endl;
    }
};

int main()
{
    int B, S, i, n, a[100], item;
    cout << "Enter the total number of elements in the array" << endl;
    cin >> n;
    cout << "Enter the elements to craete array" << endl;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the element to be searched :" << endl;
    cin >> item;
    sequential_and_binary obj;
    cout << "********BINARY SEARCH********" << endl;
    B=obj.Binary_search(a, 0, n - 1, item, 0);
    cout << "*******SEQUENTIAL SEARCH*******" << endl;
    S = obj.Sequentai_search(a, n, item);

    if (B > S)
        cout << "Seqential search is better for this";
    else if (B < S)
        cout << "Binary search is better for this";
    else
        cout << "Both are equal for this";
    return 0;
}