#include <iostream>
#include <stack>
#include <locale>
using namespace std;
class infix_to_postfix
{
public:
    int preced(char ch)
    {
        if (ch == '+' || ch == '-')
        {
            return 1; // Precedence of + or - is 1
        }
        else if (ch == '*' || ch == '/')
        {
            return 2; // Precedence of * or / is 2
        }
        else if (ch == '^')
        {
            return 3; // Precedence of ^ is 3
        }
        else
        {
            return 0;
        }
    }

    string inToPost(string infix)
    {
        stack<char> stk;
        stk.push('#');       // add some extra character to avoid underflow
        string postfix = ""; // initially the postfix string is empty
        string::iterator it;

        for (it = infix.begin(); it != infix.end(); it++)
        {
            if (isalnum(char(*it)))
                postfix += *it; // add to postfix when character is letter or((a+(b*c))-d) number
            else if (*it == '(')
                stk.push('(');
            else if (*it == '^')
                stk.push('^');
            else if (*it == ')')
            {
                while (stk.top() != '#' && stk.top() != '(')
                {
                    postfix += stk.top(); // store and pop until ( has found
                    stk.pop();
                }
                stk.pop(); // remove the '(' from stack
            }
            else
            {
                if (preced(*it) > preced(stk.top()))
                    stk.push(*it); // push if precedence is high
                else
                {
                    while (stk.top() != '#' && preced(*it) <= preced(stk.top()))
                    {
                        postfix += stk.top(); // store and pop until higher precedence is found
                        stk.pop();
                    }
                    stk.push(*it);
                }
            }
        }

        while (stk.top() != '#')
        {
            postfix += stk.top(); // store and pop until stack is not empty.
            stk.pop();
        }

        return postfix;
    }
};
int main()
{
    string infix;
    infix_to_postfix i;
    cout << "Enter the infix notation ( Use -,+,*,/,^,() ): ";
    cin >> infix;
    cout << "Postfix form is: " << i.inToPost(infix) << endl;
}