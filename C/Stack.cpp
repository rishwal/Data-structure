#include <iostream>
using namespace std;

class Stack_operation
{
public:
    int stack[100], n, top = -1;
    void size()
    {
        cout << "Enter the size of the stack:";
        cin >> n;
    }
    void push(int val)
    {
        if (top >= n - 1)
            cout << "Stack Overflow" << endl;
        else
        {
            top++;
            stack[top] = val;
        }
    }
    void pop()
    {
        if (top <= -1)
            cout << "Stack Underflow" << endl;
        else
        {
            cout << "The popped element is " << stack[top] << endl;
            top--;
        }
    }
    void display()
    {
        if (top >= 0)
        {
            cout << "Stack elements are:";
            for (int i = top; i >= 0; i--)
                cout << stack[i] << " ";
            cout << endl;
        }
        else
            cout << "Stack is empty";
    }
};
int main()
{
    int ch, val, n;
    Stack_operation S;
    S.size();
    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Exit" << endl;
    do
    {
        cout << "Enter choice: " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
        {
            cout << "Enter value to be pushed:" << endl;
            cin >> val;
            S.push(val);
            break;
        }
        case 2:
        {
            S.pop();
            break;
        }
        case 3:
        {
            S.display();
            break;
        }
        case 4:
        {
            cout << "Exit" << endl;
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
        }
        }
    } while (ch != 4);
    return 0;
}