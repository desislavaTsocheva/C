#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b, sum = 0, multiply = 1;
    printf("A= ");
    scanf("%i", &a);
    printf("B= ");
    scanf("%i", &b);
    if (a < b) {
        for (int i = a + 1; i <= b - 1; i++) {
            if (i % 2 == 0) {
                sum += i;
            } else {
                multiply *= i;
            }
        }
    }

    printf("SUM: %i\n",sum);
    printf("MULTIPLY: %i",multiply);
    return 0;
}
