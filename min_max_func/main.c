#include <stdio.h>
#include <stdlib.h>

void maxFunc()
{
    int max,num;
    do{
        printf("Enter number: ");
        scanf("%d",&num);
        max=num;
        if(num>max&&num!=0){

            max=num;
        }
    }
    while(num!=0);
    printf("Max: %d",max);
}

void minFunc()
{
    int min=INT_MAX,num;
    do{
        printf("Enter number: ");
        scanf("%d",&num);
        min=num;
        if(num<min&&num!=0){
            min=num;
        }
    }
    while(num!=0);
    printf("Min: %d",min);
}

int main()
    {
        minFunc();
        printf("\n");
        maxFunc();
        return 0;
    }
