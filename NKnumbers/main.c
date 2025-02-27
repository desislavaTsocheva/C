#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberCount,number,counter=0;
    printf("Numbers Count: ");
    scanf("%i",&numberCount);
    printf("Number: ");
    scanf("%i",&number);
    for(int i=1;i<=numberCount;i++){
        int nums;
        printf("Num:\n ");
        scanf("%i",&nums);
        if(nums>number&&nums%3==0){
            counter+=1;
        }
    }
    printf("Counter: %i ",counter);

    return 0;
}
