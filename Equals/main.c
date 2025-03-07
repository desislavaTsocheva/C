#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3;
    printf("number 1: ");
    scanf("%d",&num1);
    printf("number 2: ");
     scanf("%d",&num2);
    printf("number 3: ");
     scanf("%d",&num3);

     if(num1==num2){
            if(num2==num3){
                printf("YES!");
     }
     }
     else{
        printf("NO!");
     }

    return 0;
}
