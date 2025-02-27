#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a,b,f=0;
    printf("Enter a= ");
    scanf("%lf",&a);
    printf("Enter b= ");
    scanf("%lf",&b);
    for(double i=a;i<=b;i+=0.01){
        f=i*i-4;
        printf("%.2lf\n",f);
    }
    return 0;
}
