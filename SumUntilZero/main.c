#include <stdio.h>
#include <stdlib.h>

int main()
{
    int  number,sum=0;
    do
    {
        printf("Enter number: ");
        scanf("%i", &number);
        sum+=number;
    }
    while(number!=0);
    printf("Sum: %i",sum);
    return 0;
}
