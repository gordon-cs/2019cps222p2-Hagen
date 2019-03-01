/*
 * expression.cc - Implementation of a class representing simple arithmetic
 *                 expressions, as declared in expression.h.  Part of CPS222
 *                 Project 2.
 *
 * Skeleton copyright (c) 2001, 2013 - Russell C. Bjork
 *
 */

#include "expression.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
using std::stack;
using namespace std;
/* The following methods are to be written by students, and constitute
 * CPS222 Project 2.
 */

int precedence(char ch)
{ 
    if(ch == '+' ||  ch == '-')
    {
        return 1; 
    } 

    if(ch == '*' || ch == '/')
    { 
        return 2;
    }
    return 0;
}


string Expression::convertToPostfix(string infix) throw (SyntaxError)
{ 
    stack<char> operators; // a stack of char
  
    string postfix;
    int length = infix.length();
    for(int x = 0; x < length; x++)
    {
        
        cout << "-----" << endl;
        // case: operand
        if (isdigit(infix[x]))
        {
            cout << "is this a digit" << endl;
            // if character is an operand output it to postfix
            postfix += infix[x];
            cout << "add the digit to the string postfix" << endl;
        }

        // case: '('
        else if (infix[x] == '(')
        {
            cout << "checks to see if this is a open parenthesis" << endl;
            // push character scanned
            operators.push(infix[x]);
            cout << "pushes the open parenthesis onto the stack" << endl;
        }
        
        // case: ')'
        else if(infix[x] == ')')
        {
            cout << "current char was )" << endl;
            // while top of stack is not a '('
            while(operators.top() != '(')
            {
                cout << "while the operator is not a '('" << endl;
                // pop top operator from the stack and output it to the postfix
                cout << "pop the operator from the top of the stack and add it to the string postfix" << endl;
                postfix += operators.top();
                operators.pop();
            }
            // pop the '(' from the stack and discard it
            cout << "the operator gets popped from the stack" << endl;
            cout << operators.size() << endl;
            operators.pop();
        }

        // case: operator
        else 
        {
            cout << "current char is an operator" << endl;
            cout << operators.size() << endl;
            // while stack is not empty & precedence >= precedence character
            while(!operators.empty() && precedence(operators.top())>= precedence(infix[x]))
            {   
                // pop operator from stack and output it to postfix
                postfix += operators.top();
                operators.pop();
            }
            // push character scanned
            operators.push(infix[x]);
        }   
        
    }

    cout << "Finished for loop" << endl;
cout << "operators size " << operators.size();

    // while stack is not empty
    while(!operators.empty())
    {
        cout << "pop the top character from the stack and add it to the string postfix" << endl;
        // pop top character from the stack and output it to the postfix
        postfix += operators.top();
        operators.pop();
        
        
    }

    cout << "returns the string postfix that has the new values from the stack" << endl;
 cout << postfix << endl;
    return postfix; 
}


int Expression::evaluate(string postfix) throw (DivideByZeroError)
{
    stack<int> solution; // a stack of int
    
    int operands = 0;
    int length = postfix.length();
    for(int i = 0; i < length; i++)
    {
        // when an operand is encountered in postfix
        if(isdigit(postfix[i]))
        {
            int x;
            x = (int)postfix[i]-48;
            // push that operand onto the stack
            solution.push(x);
            //cerr << x << endl;
        }
         else if(postfix[i] == '+')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // add both operand2 and operand1 together and then push it to stack
            solution.push(operand2 + operand1);
        }

        else if(postfix[i] == '-')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // add both operand2 and operand1 together and then push it to stack
            solution.push(operand2 - operand1);
        }

        else if( postfix[i] == '*')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // add both operand2 and operand1 together and then push it to stack
            solution.push(operand2 * operand1);
        }

        else if( postfix[i] == '/')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();

        }
    }
    return operands;
}

string Expression::convertToPrefix(string postfix)
// convert postfix to prefix by doing a reverse 
{return string("");}


