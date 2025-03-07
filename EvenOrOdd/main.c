#include <stdio.h>
#include <stdlib.h>

int even_or_odd(int num)
{
    if(num % 2 == 0)
    {
        return "The number is even!";
    }
    else
    {
        return "The number is odd!";
    }
}
int main()
{
  int num;
   printf("Enter number: ");
   scanf("%d", &num);

   printf(even_or_odd(num));
   return 0;
}
