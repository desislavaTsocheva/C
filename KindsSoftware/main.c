#include <stdio.h>
#include <stdlib.h>

int main()
{
    int commands, comInx;
    printf("Enter commands count: ");
    scanf("%d",&commands);
    printf("Enter command index: ");
    scanf("%d",&comInx);
    int array[commands];
    switch(comInx){
        case 1:
            printf("Enter number: ");
            int number;
            scanf("%d",&number);
            array[size++]+=number;
            printf("You add number to array!");
        case 2:
            printf("Enter number: ");
            int number;
            scanf("%d",&number);
            array[size--]-=number;
            printf("You delete number!");
        case 3:
            int min=0;
            for(int i=0;i<commands;i++){
                if(array[i]>array[i+1]){
                    min=array[i+1];
                    int minInx=i+1;break;
                    printf("X index of number is: %d ",minInx);
                }
            }
    }
    return 0;
}
