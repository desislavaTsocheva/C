#include <stdio.h>
#include <stdlib.h>

int main()
{
    int len,number;
    printf("Enter array length: ");
    scanf("%d",&len);
    int arr[len];
    for(int i=0;i<len;i++){
         scanf("%d",&arr[i]);
    }
    for(int i=0;i<len-1;i++){
        if((i%2==0 && arr[i] >= arr[i + 1]) || (i % 2 == 1 && arr[i] <= arr[i + 1])){
            printf("Yes"); break;
        }
        else{
            printf("No"); break;
        }
    }
    return 0;
}
