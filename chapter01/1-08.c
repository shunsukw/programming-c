#include <stdio.h>

main()
{
    int c, nl, nt, nb;
    nl = 0;
    nt = 0;
    nb = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++nb;
        if (c == '\t')
            ++nt;
        if (c == '\n')
            ++nl;
    }

    printf("blank: %d, tab: %d, new line: %d", nb, nt, nl);
    
}