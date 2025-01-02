// Write a C++ program, to convert the given infix expression to postfix expression.
#include <iostream>
#include <stack>
#include <conio.h>
#include <string>

using namespace std;

// Function to return precedence of operators
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    else
        return -1;
}

// Function to convert infix to postfix
void infixToPostfix(string s)
{
    stack<char> st;
    string result = "";
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        // If the scanned character is an operand, add it to output
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        // If the scanned character is an '(', push it to the stack
        else if (c == '(')
            st.push(c);
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop();
        }
        // If the scanned character is an operator, pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
        else
        {
            while (!st.empty() && precedence(c) <= precedence(st.top()))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    cout << "Postfix expression: " << result << endl;
}

// Main function
int main(){
    string exp;
    cout << "Enter the infix expression: ";
    cin >> exp;
    infixToPostfix(exp);
    getch();
    return 0;
}

/*
OUTPUT:
Enter the infix expression: A+B+C/D*E(F+G)/H
Postfix expression: AB+CD/EFG+*H/+
*/