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
        // case: operand
        if (isdigit(infix[x]))
        {
            // if character is an operand output it to postfix
            postfix += infix[x];
        }

        // case: '('
        else if (infix[x] == '(')
        {
            // push character scanned
            operators.push(infix[x]);
        }
        
        // case: ')'
        else if(infix[x] == ')')
        {
            // while top of stack is not a '('
            while(operators.top() != '(')
            {
                // pop top operator from the stack and output it to the postfix
                postfix += operators.top();
                operators.pop();
            }
            // pop the '(' from the stack and discard it
            operators.pop();
        }

        // case: operator
        else 
        {
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

    // while stack is not empty
    while(!operators.empty())
    {
        // pop top character from the stack and output it to the postfix
        postfix += operators.top();
        operators.pop();
    }
    return postfix; 
}


int Expression::evaluate(string postfix) throw (DivideByZeroError)
{
    stack<int> solution; // a stack of int
    
    int operands = 0;
    int length = postfix.length();
    for(int i = 0; i < length; i++)
    {
        cout << "checks to see if the first value in the postfix is a digit" << endl;
        // when an operand is encountered in postfix
        if(isdigit(postfix[i]))
        {
            int x;
            x = (int)postfix[i]-48;
            x++;
            // push that operand onto the stack
            solution.push(x);
        }

         else if(postfix[i] == '+')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();
            cout <<"pops first operand from the stack" << endl;
            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // operand2 at the top of the stack
            int operand2 = solution.top();
            cout <<"pops second operand from the stack"<< endl;
            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // add both operand2 and operand1 together and then push it to stack
            solution.push(operand2 + operand1);
            cout << "prints both the operands together" << endl;
            cout << solution.size() << endl;
            cout << postfix << endl;
        }

        else if(postfix[i] == '-')
        {
            cout << "checks the first operand on top of the stack" << endl;
            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // operand2 at the top of the stack
            int operand2 = solution.top();
            cout <<"pops second operand from the stack" << endl;
            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // subtract both operand2 and operand1 together and then push it to stack
            solution.push(operand2 - operand1);
            cout << "prints both the operands subtracted together" << endl;
            cout << solution.size() << endl;
        }

        else if( postfix[i] == '*')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();
            cout <<"checks that the first operand is a digit" << endl;
            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            cout <<"pops second operand from the stack" << endl;
            // multiple both operand2 and operand1 together and then push it to stack
            solution.push(operand2 * operand1);
            cout << "prints both the operands multipled together" << endl;
            cout << solution.size() << endl;
        }

        else if( postfix[i] == '/')
        {
            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();
            cout << solution.size() << endl;

            // divide both operand2 and operand1 together and then push the result to the stack
            solution.push(operand2 / operand1);
            cout << "prints both the operands divided together" << endl;
            cout << solution.size() << endl;
        }
    }
    cout << operands << endl;

    return operands;
}

string Expression::convertToPrefix(string postfix)
// convert postfix to prefix by doing a reverse 
{return string("");}


