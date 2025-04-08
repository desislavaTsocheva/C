#include <stdio.h>
#include <stdlib.h>


struct Medicine
{
    char name[31];
    char expiryDate[8];
    int id;
    double price;
    int amount;
};

void discount(struct Medicine *arr, int counter, char date[8])
{
    int month, year;
    int x,y;
    sscanf(date, "%2d.%4d", &month, &year);
    for(int i=0;i<counter;i++)
    {
        sscanf(arr[i].expiryDate,"%d.%d",&x,&y);
        if (y==year&&x<month||y<year)
        {
            float oldPrice = arr[i].price;
            arr[i].price *= 0.80;

            printf("%s - %s - %.2f lv -> %.2f lv\n",
                   arr[i].name, arr[i].expiryDate, oldPrice, arr[i].price);
        }
    }
}

void writeBin(struct Medicine *arr,int counter,int quantity)
{
     FILE *fileBin = fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Medicine\\medicine.bin", "wb");
     for(int i=0;i<counter;i++){
        if(arr[i].amount>quantity){
            if(fileBin==NULL){
                printf("Error");
            }
            else{
                fwrite(&arr[i],sizeof(struct Medicine),counter,fileBin);
            }
        }
     }
}

void DeleteId(struct Medicine **arr,int *counter, int id)
{
    for(int i=0;i<*counter;i++){
        printf("%d\n",(*arr)[i].id);
    }
     int found=0;
    for(int i=0;i<*counter;i++)
    {
        if((*arr)[i].id==id)
        {
            found=1;
            for(int j=i;j<*counter-1;j++)
            {
                (*arr)[j]=(*arr)[j+1];
            }

            *arr=(struct Medicine*)realloc(*arr,(*counter-1)*sizeof(struct Medicine));

            if (*arr == NULL && *counter > 1) {
                printf("Error!\n");
                exit(1);
            }

            (*counter)--;
            printf("Medicine ID %d was deleted.\n", id);
            break;
        }
    }
        if(found==0){
            printf("Medicine was not found");
        }
         for(int i=0;i<*counter;i++){
        printf("%d\n",(*arr)[i].id);
    }
}


int main()
{
    FILE *file = fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Medicine\\medicine.txt", "r");
    struct Medicine *arr;
    //int counter = 0;
    char ch;
    if (file == NULL) {
        printf("File not found\n");
        return 1;
    }

    int counter = 0;
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        counter++;
    }

    rewind(file);
    printf("Counter: %d\n",counter);
    arr = malloc(counter * sizeof(struct Medicine));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }
    for (int i = 0; i < counter; i++) {
        int result = fscanf(file, "%30[^;];%7[^;];%d;%lf;%d\n",
            arr[i].name,
            arr[i].expiryDate,
            &arr[i].id,
            &arr[i].price,
            &arr[i].amount);
    }
    for (int j = 0; j < counter; j++) {
        printf("Name: %s, Expiry Date: %s, ID: %d, Price: %.2f, Amount: %d \n",
            arr[j].name, arr[j].expiryDate, arr[j].id, arr[j].price, arr[j].amount);
    }

    char date[8];
    printf("Enter date: ");
    scanf("%s", &date);
    printf("\n");
    discount(arr,counter,date);
    writeBin(arr,counter,5);
    int id;
    printf("Enter id: ");
    scanf("%d", &id);
    DeleteId(&arr,&counter,id);

    free(arr);
    fclose(file);

    return 0;
}
