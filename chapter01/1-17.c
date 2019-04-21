#include <stdio.h>

#define MAXLINE 1000
#define LONGLINE 80

int getLine(char line[], int maxline);

main()
{
    int len;
    char line[MAXLINE];

    while ((len = getLine(line, MAXLINE))) {
        if (len > LONGLINE) {
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
        if (i < lim) {
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