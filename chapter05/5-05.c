void strncpy(char *s, char *t, int n)
{
    while (*t && n-- > 0)
        *s++ = *t++;
    while (n-- > 0)
        *s++ = '\0';
}

void strncat(char *s, char *t, int n)
{
    int strlen(char *);
    strncpy(s + strlen(s), t, n);
}

int strncomp(char *s, char *t, int n)
{
    for ( ; *s == *t; s++, t++)
        if (*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}