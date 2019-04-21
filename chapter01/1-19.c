#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
void reverse(char s[]);

main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) {
        reverse(line);
        printf("%s", line);
    }
}

int getLine(char s[], int lim)
{
    int c, i, j;

    j = 0;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++) {
        if (i < lim - 2) {
            s[j] = c;
            j++;
        }
    }

    if (c == '\n') {
        s[j] = c;
        i++;
        j++;
    }

    s[j] = '\0';
    return i;
}

void reverse(char s[])
{
    int i, j;
    char temp;

    i = 0;
    while (s[i] != '\0') {
        i++;
    }
    i--;
    if (s[i] == '\n') {
        i--;
    }

    j = 0;
    while (j < i) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i--;
        j++;
    }
}