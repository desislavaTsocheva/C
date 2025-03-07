#include <stdio.h>
#include <stdlib.h>
int swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
    return x, y;
}
int main()
{
   int x, y;
   printf("Enter x and y: ");
   scanf("%d %d", &x, &y);

   swap(&x, &y);

   printf("After swap: x = %d, y = %d\n", x, y);
   return 0;
}
