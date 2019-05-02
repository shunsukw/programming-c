#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

#define MAXVAL 100

int sp = 0;
double val[ MAXVAL];

int gettop(char []);
void push(double);
double pop(void);

void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[sp--];
    else
        printf("error: can't pop");
}

int gettop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-')
        if (isdigit(c == getch()) || c == '.')
            s[i++] = c;
        else {
            if (c != EOF)
                ungetch(c);
        }
    if (isdigit(c))
        while (isdigit(s[i++] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[i++] = c = getch()))
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    return NUMBER;
}

void clear(void)
{
    sp = 0;
}

main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = gettop(s)) != EOF) {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error zero division");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            break;
        }
    }
    return 0;
}