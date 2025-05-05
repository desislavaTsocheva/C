#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct Car{
    char id[9];
    char brand[21];
    char model[21];
    char date[11];
    int km;
    double expense;
}Car;

float Fullexpense(Car *arr,int n){
    double expense=0;
    for(int i=0;i<n;i++){
        expense+=(arr[i].km*arr[i].expense)/100;
    }
    printf("FULL EXPENSE: %.2lf \n",expense);
    return expense;
}

int FilterByBrand(Car *arr,int n,char *brand,FILE *file){
    int counter=0;
    //file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Cars\\cars.txt","w");
    if(file==NULL){
        printf("Error occure");
        exit(2);
    }
    for(int i=0;i<n;i++){
        if(strcmp(arr[i].brand,brand)==0){
            counter++;
            if(fprintf(file,"%s;%s;%s,%s,%d,%.2lf",arr[i].id,arr[i].brand,arr[i].model,arr[i].date,arr[i].km,arr[i].expense)<0){
                printf("Error");
                fclose(file);
                exit(3);
            }
        }
    }
    fclose(file);
    if(counter==0){
        return 0;
    }
    else{
        printf("Counter cars : %d \n",counter);
        return counter;
    }


}

Car car;
void SearchCar(char *id){
    int found=0;
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Cars\\carsbin.bin","rb");
    if(file==NULL){
        printf("Error");
        exit(4);
    }
    if(fseek(file,0,SEEK_END)!=0){
        printf("SEEK EEROR");
         fclose(file);
         exit(5);

    }
    size_t size=ftell(file);
    if(size==-1){
        printf("TELL ERROR");
        fclose(file);
        exit(6);
    }
    while(fread(&car,sizeof(Car),1,file)){
        if(strcmp(car.id,id)==0){
            printf("%s;%s;%s;%s;%d;%.2lf",car.id,car.brand,car.model,car.date,car.km,car.expense);
            found=1;
        }
    }
    if(found==0){
        printf("Nothing was found");
    }
    fclose(file);
}

void SortData(Car *arr,int n, char *data){
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Cars\\cars.txt","w");
    if(file==NULL){
        exit(7);
    }
    int counter=0;
    for(int i=0;i<n;i++){
        if(strcmp(arr[i].date,data)==0){
            if(fprintf(file,"%s %s %s %s %d %.2lf", arr[i].id,arr[i].brand,arr[i].model,arr[i].date,arr[i].km,arr[i].expense)<0){
                printf("error");
                exit(8);
            }
            counter++;
        }
    }
    printf("Counter sort: %d",counter);
}




int main()
{
    int n;
    do{
    printf("Enter n: ");
    scanf("%d",&n);
    }while(n<0||n>100);

    Car *arr=(Car*)malloc(n*sizeof(Car));
    if(!arr){
        free(arr);
        printf("Coundn't allocate memory");
        exit(1);
    }
    for(int i=0;i<n;i++){
        printf("Enter id: ");
        scanf("%s",&arr[i].id);
        printf("Enter brand: ");
        scanf("%s",&arr[i].brand);
        printf("Enter model: ");
        scanf("%s",&arr[i].model);
        printf("Enter date: ");
        scanf("%s",&arr[i].date);
        printf("Enter km: ");
        scanf("%d",&arr[i].km);
        printf("Enter expanse: ");
        scanf("%lf",&arr[i].expense);
    }
    Fullexpense(arr,n);
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Cars\\cars.txt","w");
    FilterByBrand(arr,n,"Mercedes",file);
    SortData(arr,n,"22");
    SearchCar(1);
    return 0;
}
