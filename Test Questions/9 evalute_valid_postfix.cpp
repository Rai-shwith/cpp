// Write a C++ program, to evaluate a valid postfix expression and display the result.
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class Stack
{
public:
    char postfix[30];
    int s[30];
    int result;
    int top;
    Stack()
    {
        top = -1;
    }

    // Fuction to evaluate postfix expression
    void evaluateExpressions()
    {
        for (int i = 0; i < strlen(postfix); i++)
        {
            char ch = postfix[i];
            if (isdigit(ch))
            {
                s[++top] = ch - '0';
            }
            else
            {
                int op2 = s[top--];
                int op1 = s[top--];
                performOperation(op1, op2, ch);
                s[++top] = result;
            }
        }
    }

    void performOperation(int op1,int op2,char symbol){
        switch (symbol)
        {
        case '+':
            result = op1 + op2;
            break;
        case '-':
            result = op1 - op2;
            break;
        case '*':
            result = op1 * op2;
            break;
        case '/':
            result = op1 / op2;
            break;
        case '^':
        case '$':
            result = pow(op1, op2);
            break;
        }
    }
};

int main()
{
    Stack ob;
    cout << "Enter the postfix expression: ";
    cin >> ob.postfix;
    ob.evaluateExpressions();
    cout << "Result: " << ob.result << endl;
    return 0;
}

/*
OUTPUT:

*/