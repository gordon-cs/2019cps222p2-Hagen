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

//RT: Good job writing clear code.

//RT: good helper function.  It needs a comment explaining what it
//does, what it's argument means, and what it returns.

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


//RT: The comments in these methods just explain the next line of code.
//  Once you become more comfortable reading code, you won't need
//  comments like that.  But for now, I can see that it's helping you
//  think about the code you're writing, and that's good.

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
        // when an operand is encountered in postfix
        if(isdigit(postfix[i]))
        {
            int x;
            x = (int)postfix[i]-48;
            // push that operand onto the stack
            solution.push(x);
        }

        //RT: Now that this code is working (see the small fix below),
        // it can be improved by noticing that the top() and pop()
        // code is the same in all 4 cases.  So that can be done just
        // once.  It would look like this:

        /*
        else
        {
            // Get the operands from the stack

            // operand1 at the top of the stack
            int operand1 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // operand2 at the top of the stack
            int operand2 = solution.top();

            // pop the operand from the stack
            solution.pop();

            // Evaluate each operator
            if(postfix[i] == '+')
            {
                solution.push(operand2 + operand1);
            } else if(postfix[i] == '-')
            {
                solution.push(operand2 - operand1);
            } else if( postfix[i] == '*')
            {
                solution.push(operand2 * operand1);
            } else if( postfix[i] == '/')
            {
                solution.push(operand2 / operand1);
            }
        }
        */

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

            // subtract both operand2 and operand1 together and then push it to stack
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

            // multiple both operand2 and operand1 together and then push it to stack
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

            // divide both operand2 and operand1 together and then push the result to the stack
            solution.push(operand2 / operand1);

        }
    }

//RT: This always returns 0, since "operands" is never changed.
// All that work, for nothing. :-(
    //return operands;
// Instead, return the value calculated on the stack.
    return solution.top();
}

string Expression::convertToPrefix(string postfix)
// convert postfix to prefix by doing a reverse
{return string("");}
