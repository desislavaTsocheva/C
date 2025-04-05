#include <stdio.h>
#include <stdlib.h>

 struct IceCream{
    char id[15];
    char name[21];
    int weigth;
    float kgPrice;
};

float printPrice(struct IceCream * arr, int n, char letter){
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i].name[0]==letter){
            count+=arr[i].kgPrice*arr[i].weigth;
        }
    }
    return count;
}

int printInFile(struct IceCream * arr,int n,float price, int weigth){
    FILE *fileCount;
    fileCount=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\IceCream\\info.txt","w");
    if(fileCount==NULL){
        printf("Error");
    }
    int counter=0;
    for(int i=0;i<n;i++){
        if(arr[i].kgPrice<price&&arr[i].weigth>weigth){
            fprintf(fileCount, "%s; %s; %d; %.2f\n",arr[i].id,arr[i].name,arr[i].weigth,arr[i].kgPrice);
            counter++;
    }
fclose(fileCount);
}
return counter;
}

struct IceCream ice;

void printIcecreamId(char * id){
    FILE *file = fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\index.bin", "rb");
    if (file == NULL) {
        printf("ERROR!\n");
        return;
    }
     while (fread(&ice, sizeof(struct IceCream), 1, file)) {
        if (strcmp(ice.id, id) == 0) {
            printf("ID: %s, Name: %s, Weight: %d, Price: %.2f\n", ice.id, ice.name, ice.weigth, ice.kgPrice);
            fclose(file);
            return;
        }
    }
    fclose(file);
}


int main()
{
    struct IceCream * arr;
    int n;
    printf("Enter n= ");
    scanf("%d",&n);

    while(n<2){
        printf("Enter n= ");
        scanf("%d",&n);
    }

    arr=(struct IceCream*) malloc(n*sizeof(struct IceCream));

    if(arr==NULL){
        printf("There's not enough space");
        exit(1);
    }

    for(int i=0;i<n;i++){
        printf("Enter id: ");
        scanf("%s",&arr[i].id);
        printf("Enter name: ");
        scanf("%s",&arr[i].name);
        printf("Enter weigth: ");
        scanf("%d",&arr[i].weigth);
        printf("Enter kgPrice: ");
        scanf("%f",&arr[i].kgPrice);
    }

    char letter;
    printf("Enter letter: \n");
    scanf(" %c",&letter);

    float totalPrice= printPrice(arr,n,letter);
    printf("%.2f", totalPrice);

    float price=0;
    int weigth=0;
    printf("Enter price: \n");
    scanf(" %f",&price);
    printf("Enter weigth: \n");
    scanf(" %d",&weigth);
    int print=printInFile(arr,n,price,weigth);
    printf("%d",print);

    char id[3];
    printf("Enter id: \n");
    scanf(" %s",&id);
    printIcecreamId(id);

    free(arr);
    return 0;

}
