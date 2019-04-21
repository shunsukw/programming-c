#include <stdio.h>

float fahrToCelsius(float fahr);

main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    while (fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, fahrToCelsius(fahr));
        fahr += step;
    }
    
}

float fahrToCelsius(float fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}