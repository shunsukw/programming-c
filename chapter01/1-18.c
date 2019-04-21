#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxline);
int cRemove(char s[]);

main()
{
    char line[MAXLINE];

    while (getLine(line, MAXLINE) > 0) {
        if (cRemove(line) > 0) {
            printf("%s", line);
        }
    }
    
    return 0;
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

int cRemove(char s[])
{
    int i;
    i = 0;

    while (s[i] != '\n') {
        i++;
    }
    i--;

    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        i--;
    }
    
    if (i >= 0) {
        i++;
        s[i] = '\n';
        i++;
        s[i] = '\0';
    }

    return i;
}