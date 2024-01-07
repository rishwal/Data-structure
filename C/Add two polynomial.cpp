#include <iostream>
using namespace std;
const int n = 100;

class poly
{

private:
    int a[n], b[n], add[n], p, q, at;

public:
    void init();
    void input();
    void process();
    void display();
};

void poly::init()

{
    int i;
    for (i = 0; i < n; i++)

    {

        a[i] = b[i] = add[i] = 0;
    }
}

void poly::input()
{

    int i;

    cout << "Enter degree of first polynomial "<<endl;
    cin >> p;
    cout << "Enter degree of second polynomial "<<endl;
    cin >> q;
    cout << "Enter values of first polynomial "<<endl;

    for (i = 1; i <= p; i++)
    {
        cout << "\n enter X^" << i << "the coefficiant "<<endl;;
        cin >> a[i];
    }

    cout << "Enter the values of second polynomial "<<endl;
    for (i = 1; i <= q; i++)
    {
        cout << "\n Enter X^" << i << "the coefficient "<<endl;
        cin >> b[i];
    }
}

void poly::process()
{
    int i;
    if (p < q)

        at = p;
    else
        at = q;

    for (i = 1; i <= at; i++)

        add[i] = a[i] + b[i];
}

void poly ::display()
{
    int i;
    cout <<endl<< "Addition of two polynomial expression is "<<endl;
    for (i = p; i > 0; i--)
    {
        cout << a[i] << "X^" << i;

        if (i != 0)
        {
            cout << "+";
        }
    }

    cout << endl;

    for (i = q; i > 0; i--)
    {
        cout << b[i] << "X^" << i;

        if (i != 1)
        {
            cout << "+";
        }
    }

    cout << endl;
    cout << "------------------";
    cout << endl;

    for (i = at; i > 0; i--)
    {
        cout << "=";
        cout << add[i] << "X^" << i;
        if (i != 1)

        {

            cout << "+";
        }
    }
    cout << endl;
}

int main()

{

    poly p;

    p.init();
    p.input();
    p.process();
    p.display();

    return 0;
}