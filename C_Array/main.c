#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int numbers[7];
    int length = sizeof(numbers) / sizeof(numbers[0]);
    int number, sum = 0;
    float average, closest;
    int closestIndex = 0;
    for (int i = 0; i < length; i++) {
        printf("Enter number: ");
        scanf("%d", &number);

        while (number < -5000 || number > 5000) {
            printf("Invalid number! Enter a number between -5000 and 5000: ");
            scanf("%d", &number);
        }

        numbers[i] = number;
        sum += number;
    }
    average = sum / (float)length;
    closest = numbers[0];
    for (int i = 1; i < length; i++) {
        if (fabs(numbers[i] - average) < fabs(closest - average)) {
            closest = numbers[i];
            closestIndex = i;
        }
    }
    printf("\nSUM IS: %d\n", sum);
    printf("AVERAGE IS: %.2f\n", average);
    printf("Closest to average IS: %.2f (Index: %d)\n", closest, closestIndex);

    return 0;
}
