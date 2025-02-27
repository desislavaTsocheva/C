#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,sum;
    printf("A= ");
    scanf("%i",&a);
    printf("B= ");
    scanf("%i",&b);
    if(a<b){
        for(int i=a+1;i<=b-1;i++){
        sum+=i;
    }
    }
    else{
         for(int i=b+1;i<=a-1;i++){
        sum+=i;
    }
}
    printf("%i",sum);

}
