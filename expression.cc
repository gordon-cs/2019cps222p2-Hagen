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
    if(ch == '+')
    {
        return 1; 
    } 
    if(ch == '-')
    {
        return 1;
    }
    if(ch == '*')
    { 
        return 2;
    }
    if(ch == '/')
    {
        return 2;
    }
    return 0;
}



string Expression::convertToPostfix(string infix) throw (SyntaxError)
{ 
    stack<char> operators; // a stack of char
    
    string postfix;

    for(int x = 0; x < infix.length(); x++)
    {
       
        // case: operand
        if (isdigit(infix[x]))
        {
            // output immediately to the postfix
            postfix += infix[x];
        }

        // case: '('
        else if (infix[x] == '(')
        {
            // push character scanned
            operators.push('(');
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
        
        // while stack is not empty
        while(!operators.empty())
        {
            // pop top character from the stack and output it to the postfix
            postfix += operators.top();
            operators.pop();
        }
    }  
}
// throw (Syntax Error) - outside for loop possibly



int Expression::evaluate(string postfix) throw (DivideByZeroError)
{
    stack<int> solution; // a stack of int
    
    string operands;

    for(int i = 0; i < postfix.length(): i++)
    {

        if(isdigit(postfix[i]))
        {
            operands += postfix.push();
        }
        else if(operands.pop.())
        {
            operands += postfix.push();
        }
        else if(solution != postfix[i])
        {
            throw DivideByZeroError;
        }
    }
    else
    {
        solution  = postfix[i]
    }

}
    


/*string Expression::convertToPrefix(string postfix) 
// convert postfix to prefix by doing a reverse
{ return string(""); } // Students: replace return code and remove this comment*/