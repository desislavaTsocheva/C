#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;

    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);

     int array[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("Enter numbers: ");
            scanf("%d",&array[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }


    //int swap[1][1];
    int flagRoll=1;
    int flagColl=1;
   for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (array[i][j] > array[i][j + 1]) {
                flagRoll = 0;
                break;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++) {
            if (array[i][j] < array[i + 1][j]) {
                flagColl = 0;
                break;
            }
        }
    }
    if(flagRoll&&flagColl){
        printf("Matrix is sort");
    }
    else if(!flagRoll&&!flagColl){
          printf("Matrix is not sort");
    }
    else if(!flagRoll){
          printf("Matrix is not sort");
    }
    else if(!flagColl){
          printf("Matrix is not sorted");
    }
    return 0;
}
