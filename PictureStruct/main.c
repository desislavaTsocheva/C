#include <stdio.h>
#include <stdlib.h>

struct Picture
{
    int id[4];
    char painterName[30];
    char paintName[30];
    double price;
};

void printInFile(struct Picture * arr,int n){
    FILE *fileCount;
    fileCount=fopen("C:\\Users\\viole\\OneDrive\\Ðàáîòåí ïëîò\\C\\IceCream\\info.txt","w");
    if(fileCount==NULL){
        printf("Error");
    }
    int counter=0;
    for(int i=0;i<n;i++){
            fprintf(fileCount, "%d; %c; %c; %.2f\n",arr[i].id,arr[i].painterName,arr[i].paintName,arr[i].price);
    }
fclose(fileCount);
}

double AveragePaintsPrice(struct Picture *arr,int n,double price)
{
    int counter=0;
    int sum=0;
    double avr=0;

    for(int i=0;i<n;i++)
    {
            if(arr[i].price>price)
            {
                    sum+=arr[i].price;
                    counter++;
            }

    }
    avr=sum/counter;
    return "Average price of the painting is: %.2lf",avr;
}

double CountFiles(struct Picture *arr,int n,char letter)
{
    FILE *file;
    int counter=0;
    file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\PictureStruct\\info.txt","w");
    if(file==NULL)
    {
            printf("Error");
    }
    else
    {
            printf("File is fine\n");
    }
    for(int i=0;i<n;i++)
    {
            if(arr[i].painterName[0]==letter)
            {
                    fprintf(file, "%d  - %s  - %s  - %.2lf\n",arr[i].id,arr[i].painterName,arr[i].paintName,arr[i].price);
                    counter++;
                    printf("Painter: %c",arr[i].painterName[0]);
            }
    }
    return counter;
}

void WriteBin(struct Picture *arr,int counter)
{
    FILE *fileBin=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\PictureStruct\\infoBin.bin","wb");
    for(int i=0;i<counter;i++)
    {
            if(fileBin==NULL){
                printf("Error");
            }
            else{
                fwrite(&arr[i],sizeof(struct Picture),counter,fileBin);
            }
    }
}

void FilterBin(struct Picture *arr,int counter, char name[30])
{
    FILE *fileBin=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\PictureStruct\\infoBin.bin","rb");
     if(fileBin==NULL)
    {
        printf("Error");
    }
    for(int i=0;i<counter;i++)
    {
           if(strcmp(arr[i].painterName,name)==0){
                 printf("%d  - %s  - %s  - %.2lf\n",arr[i].id,arr[i].painterName,arr[i].paintName,arr[i].price);
           }
    }
     printf("Nothing was found");
}

int main()
{
    int n;
    struct Picture *arr;
    printf("Enter array count: ");
    scanf("%d",&n);

    while(n<3||n>30){
        printf("Enter number between 3 and 30! \n");
         scanf("%d",&n);
    }

    arr=(struct Picture*)calloc(n,sizeof(struct Picture));

    if(arr==NULL){
        printf("Error");
    }
    else{
        printf("Array is ready\n");
    }

    //arr input
    for(int i=0;i<n;i++)
    {
            printf("Enter id: ");
            scanf("%d",&arr[i].id);
            printf("Enter painter name: ");
            scanf("%s",&arr[i].painterName);
            printf("Enter picture name: ");
            scanf("%s",&arr[i].paintName);
            printf("Enter price: ");
            scanf("%lf",&arr[i].price);
    }

    //arr print
    for(int i=0;i<n;i++)
    {
            printf("\nID of picture %d is %d",i+1,arr[i].id);
            printf("\nPainter of picture %d is %s",i+1,arr[i].painterName);
            printf("\nName of picture %d is %s",i+1,arr[i].paintName);
            printf("\nPrice of picture %d is %.2lf",i+1,arr[i].price);
    }
    printInFile(*arr,n);

    double price;
    printf("\n\nEnter price for filtering: ");
    scanf("%lf",&price);
    double filter=AveragePaintsPrice(arr,n,price);
    printf("%.2lf",filter);

    char letter;
    printf("Enter letter: \n");
    scanf(" %c",&letter);
    //fgets(letter, sizeof(letter),stdin);
    printf("%c",letter);
    int counter=CountFiles(arr,n,letter);
    printf("\nCounter paintings with char %c is %d",letter,counter);

    WriteBin(arr,n);
    FilterBin(arr,n,'desi');
    return 0;
}
