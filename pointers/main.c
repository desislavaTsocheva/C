#include <stdio.h>
#include <stdlib.h>

void sum(int * arr)
    {
        int len=sizeof(arr)/sizeof(arr[0]);
        int sum=0,num;
        for(int i=0;i<=4;i++)
            {
            sum+=*(arr+i);
            }
        printf("Sum is: %d",sum);
    }


int main()
{
        int* arr;
        int num;
      for(int i=0;i<=4 ;i++)
            {
            printf("Enter number: ");
            scanf("%d",&num);
            arr[i]=num;
            }
    sum(arr);
    return 0;
}
