#include <string.h>

#define MAXLEN 1000
#define MAXSTOR 5000

int getline(char *, int);

int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLEN];
    char *p = lineptr;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;

    while ((len = gfetline(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || p+len > linestop)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }

    return nlines;
}