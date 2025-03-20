#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number;
    printf("Enter number: ");
    scanf("%d",&number);
    int matrix[number][number];
   for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Matrix: \n");
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Principle diagonal\n");

     for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
                if(i==j)
                {
                    printf("%d", matrix[i][i]);
                }
                else{
                    printf(" ");
                }
        }
        printf("\n");
    }
    printf("Secondary diagonal elements: \n");
    for (int i = 0; i < number; i++) {
        printf("%d ", matrix[i][number - 1 - i]);
        printf("\n");
    }
    printf("\n");

    printf("OVER\n");
      for (int i = 0; i < number; i++) {
        for (int j = 0; j < number-i-1; j++) {
                    printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
       printf("UNDER\n");
      for (int i = 0; i < number; i++) {
        for (int j = number-i-1; j < number; j++) {
                if(j>number-i-1){
                    printf("%d ", matrix[i][j]);
                }
        }
        printf("\n");
    }
    return 0;
      }


