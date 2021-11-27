//Conversion of infix to postfix
#include <stdio.h>
#include <string.h>
#include "stackImplement.h"
#include<stdbool.h>

int priority (char token);
bool isOperator (char token);
int main (void)
{

char postfix [80] = {0};
char temp [2] = {0};
char token;
char* dataPtr;
STACK* stack;

stack = createStack ();

printf("Enter an infix formula: ");
while ((token = getchar ())!= '\n')
 {
 if (token == '(')
 {
 dataPtr = (char*) malloc (sizeof(char));
 *dataPtr = token;
 pushStack (stack, dataPtr);
 } 
 else if (token == ')')
 {
 dataPtr = (char*)popStack (stack);
 while (*dataPtr != '(')
 {
 temp [0]= *dataPtr;
 strcat (postfix , temp);
 dataPtr = (char*)popStack (stack);
 } 
}
 else if (isOperator (token))
 {
 
 dataPtr = (char*)stackTop (stack);
 while (!emptyStack (stack) 
 && priority (token) <= priority (*dataPtr))
 {
 dataPtr = (char*)popStack (stack);
 temp [0] = *dataPtr;
 strcat (postfix , temp);
 dataPtr = (char*)stackTop (stack);
 } 
 dataPtr = (char*) malloc (sizeof (char));
 *dataPtr = token;
 pushStack (stack , dataPtr);
 } 
 else
 {
 temp[0]= token;
 strcat (postfix , temp);
 } 
 } 
while (!emptyStack (stack))
 {
 dataPtr = (char*)popStack (stack);
 temp[0] = *dataPtr;
 strcat (postfix , temp);
}
printf ("The postfix formula is: ");
puts (postfix);

destroyStack (stack);
return 0;
} 
/* =================== priority ====================
Determine priority of operator.
 Pre token is a valid operator
 Post token priority returned
*/
int priority (char token)
{

if (token == '*' || token == '/')
 return 2;
if (token == '+' || token == '-')
 return 1;
return 0;
} // priority 
/* =================== isOperator ====================
Determine if token is an operator.
 Pre token is a valid operator
 Post return true if operator; false if not
*/
bool isOperator (char token)
{
 
if (token == '*' 
 || token == '/' 
 || token == '+' 
 || token == '-')
 return true;
return false;
} 
