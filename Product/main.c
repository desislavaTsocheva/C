#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Problem 1
typedef struct Product{
    char name[21];
    int id;
    char date[11];
    double price;
}Product;

//Problem 2
double avrg_by_price(Product *arr,int n,double price){
    int counter=0;
    double sum, avr;
    for(int i=0;i<n;i++){
        if(arr[i].price<price){
            counter++;
            sum+=arr[i].price;
        }
    }
    if(counter==0){
        printf("No products");
        return 0;
    }
    else{
    avr=sum/counter;
    printf("Average price of products with price < price is: %.2lf",avr);
    return avr;
    }
}

//Problem 3
int write_text_file(Product *arr,int n,char *date,double price){
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Product\\product.txt","a");
    if(file==NULL){
        printf("Couldn't open the file");
        exit(2);
    }
    if(fseek(file,0,SEEK_END)!=0){
        printf("Seek error");
        fclose(file);
        exit(3);
    }
    int size=ftell(file);
    if(size==-1){
        printf("Tell error");
        fclose(file);
        exit(4);
    }
    int counter=0;
    for(int i=0;i<n;i++){
        if(!(strcmp(arr[i].date,date)<0)&&(arr[i].price>price)){
                if(fprintf(file,"%s-%d-%s-%.2lf lv. \n",arr[i].name, arr[i].id,arr[i].date,arr[i].price)<0){
                    printf("Error!");
                    exit(5);
                }
                counter++;
                //printf("%d",counter);
            }
        }
        if(counter==0){
            printf("\nNothing was written in the file");
            return 0;
        }
        else{
            printf("\nCounter lines in the file: %d",counter);
            return counter;
        }
}

//Problem 4

void add_to_bin(Product *arr,int n){
FILE *bin=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Product\\print_info.bin","wb");
    if(bin==NULL){
        printf("Couldn't open file ");
        exit(6);
    }
    //for(int i=0;i<n;i++){
        if(fwrite(arr,sizeof(Product)*n,n,bin)!=n){
            printf("\nCouldn't write to the file correctly!\n");
            fclose(bin);
            exit(7);
        }
        else{
            printf("\nEverything is ok \n");
        }
        fclose(bin);
    }


Product product;
void print_info(char *name,int id){
    FILE *bin=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Product\\print_info.bin","rb");
    if(bin==NULL){
        printf("Couldn't open file ");
        exit(6);
    }
     while (fread(&product, sizeof(Product), 1, bin)) {
        if (product.id==id&&strcmp(product.name,name)==0) {
            printf("ID: %d, Name: %s, Date: %s, Price: %.2lf\n", product.id, product.name, product.date, product.price);
            fclose(bin);
            return;
        }
        else{
            printf("Nothing was found");
        }
    }
}

int main()
{
    int n;
    do{
        printf("Enter count numbers: ");
        scanf("%d",&n);
    }while(n<10&&n>30);

    Product *arr=(Product*)malloc(n*sizeof(Product));
    if(!arr){
        printf("Memory error");
        exit(1);
    }
    else{
        printf("Memory is allocated\n");
    }

    for(int i=0;i<n;i++){
        printf("Enter name: ");
        scanf("%s",&arr[i].name);
        printf("Enter id: ");
        scanf("%d",&arr[i].id);
        printf("Enter date: ");
        scanf("%s",&arr[i].date);
        printf("Enter price: ");
        scanf("%lf",&arr[i].price);
    }

    printf("---PRODUCTS---");
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%s   %d   %s   %.2lf'\n",arr[i].name,arr[i].id,arr[i].date,arr[i].price);
    }

    avrg_by_price(arr,n,30);
    write_text_file(arr,n,"2024.12.01",40);
    add_to_bin(arr,n);
    print_info("aaa",1);
    return 0;
}
