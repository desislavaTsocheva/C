#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[7];
    int length=sizeof(numbers) / sizeof(numbers[0]);
    int number,sum;
    float average,blizko,a,b;
    for(int i=0;i<length;i++)
    {
            printf("Enter number: ");
            scanf("%d",&number);
            if(number>-5000&&number<5000)
            {
             numbers[i]=number;
            sum+=number;
            }
            else{
                    printf("Enter new number: ");
                    scanf("%d",&number);
                    sum+=number;
            }
    average=sum/7;

        if(average>numbers[i]){
            a=numbers[i];
            b=numbers[i+1];
            blizko=average-numbers[i];
            if(blizko>(average-numbers[i+1]))
               {
               blizko=b;
               }
               else{
                blizko=numbers[i]-average;
                if(blizko>(average-numbers[i+1])){
                    blizko=b;
                }
                else{
                    blizko=a;
                }
                               }
        }
    }
    float closest=blizko+a;
    printf("SUM IS: %d\n",sum);
    printf("AVERAGE IS: %.2f",average);
    printf("Closest to average IS: %.2f",closest);



    return 0;
}
