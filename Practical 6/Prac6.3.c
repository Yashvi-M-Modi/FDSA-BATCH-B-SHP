#include <stdio.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch)
{
    top++;
    stack[top] = ch;
}
char pop()
{
    char ch = stack[top];
    top--;
    return ch;
}
char peek()
{
    return stack[top];
}
int precedence(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    if (ch == '*' || ch == '/')
        return 2;
    return 0;
}
int main()
{
    char infix[MAX];
    char postfix[MAX];
    int i = 0;
    int j = 0;
    printf("Enter infix expression: ");
    scanf("%s", infix);
    while (infix[i] != '\0')
    {
        char ch = infix[i];
        /* If operand */
        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        /* If opening bracket */
        else if (ch == '(')
        {
            push(ch);
        }
        /* If closing bracket */
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
            {
                postfix[j] = pop();
                j++;
            }
            if (top != -1)
                pop();   // Remove (
        }
        else
        {
            while (top != -1 &&
                   peek() != '(' &&
                   precedence(peek()) >= precedence(ch))
            {
                postfix[j] = pop();
                j++;
            }
            push(ch);
        }
        i++;
    }
    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
    printf("Postfix expression: %s\n", postfix);
    return 0;
}