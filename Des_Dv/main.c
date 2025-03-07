#include <stdio.h>
#include <stdlib.h>

int decimal_to_binary(int num)
{
    int binary [32];
    int i = 0;

    if(num == 0)
    {
        printf("0");
        return;
    }

    while (num > 0)
    {
        binary[i] = num % 2;
        num = num / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binary[j]);
    }

    printf("\n");
}
int main()
{
int num;
   printf("Enter number: ");
   scanf("%d", &num);

   printf("The decimal number %d in binary is: ", num);
   decimal_to_binary(num);
   return 0;
}
