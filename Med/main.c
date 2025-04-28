#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine{
    char name[31];
    char date[8];
    long int id;
    double price;
    int quantity;
}Medicine;


void fill_structure(Medicine* medicines){
    printf("Enter name: ");
    fgets(medicines->name,sizeof(medicines->name),stdin);
    if(medicines->name[strlen(medicines->name)-1]=='\n'){
            medicines->name[strlen(medicines->name)-1]='\0';
    }
    printf("Enter date: ");
    fgets(medicines->date,sizeof(medicines->date),stdin);
    if(medicines->date[strlen(medicines->date)-1]=='\n'){
            medicines->date[strlen(medicines->date)-1]='\0';
    }
    printf("Enter id: ");
    scanf("%ld",&medicines->id);
    getchar();
    printf("Enter price: ");
    scanf("%lf ",&medicines->price);
    getchar();
    printf("Enter quantity:\n ");
    scanf("%d",&medicines->quantity);
    //getchar();
}

void print_structure(Medicine *medicines){
    for(int i=0;i<1;i++){
        printf("Name: %s \n",medicines[i].name);
        printf("Date: %s \n",medicines[i].date);
        printf("Id: %ld\n",medicines[i].id);
        printf("Price: %.2lf\n",medicines[i].price);
        printf("Quantity: %d\n",medicines[i].quantity);
    }
}

//Problem 1
Medicine *add_to_array(char*file_bin){
    FILE* file=fopen(file_bin,"rb");
    if(file==NULL){
        exit(1);
    }
    if(fseek(file,0,SEEK_END)!=0){
        exit(2);
    }
    int size=ftell(file);
    if(size==-1){
        exit(3);
    }
    int len=size/sizeof(Medicine);
    Medicine *arr=(Medicine*)malloc(len*sizeof(Medicine));
    if(!arr){
        exit(4);
    }
    rewind(file);
    if(fread(arr,sizeof(Medicine)*len,1,file)!=1){
        fclose(file);
        exit(5);
    }
    fclose(file);
    printf("OKEY\n");
    for(int i=0;i<len;i++){
        printf("%s, %s, %ld, %lf, %d",arr[i].name,arr[i].date,arr[i].id,arr[i].price,arr[i].quantity);
    }
    return arr;
}

//Problem 2
double get_date(Medicine *arr,int i){
        return (((double)arr[i].date[0]-48)*10+
        (double)arr[i].date[1]-48)/12.0+
        ((double) arr[i].date[3]*1000)+
        ((double) arr[i].date[4]*100)+
        ((double) arr[i].date[5]*10)+
        (double)arr[i].date[0]-48;
}

Medicine * get_medicines(Medicine *arr, int len, char *date){
    int initial_len=0;
    Medicine *arr_med=(Medicine*)malloc(initial_len*sizeof(Medicine));
    double ref_date=(((double)date[0]-48)*10+
        (double)date[1]-48)/12.0+
        ((double)date[3]*1000)+
        ((double)date[4]*100)+
        ((double)date[5]*10)+
        (double)date[6]-48;
    for(int i=0;i<len;i++){
        if(ref_date>get_date(arr_med,i)){
            initial_len++;
            arr_med=(Medicine*)realloc(arr_med,initial_len*sizeof(Medicine));
                if(!arr_med){
                    free(arr_med);
                    exit(6);
                }
            arr_med[initial_len-1]=arr[i];
        }
    }
    if(!initial_len){
        exit(7);
        return NULL;
    }
    for(int i=0;i<len;i++){
        printf("%s, %s, %ld, %lf, %d", arr_med[i].name, arr_med[i].date, arr_med[i].id, arr_med[i].price, arr_med[i].quantity);
    }
    return arr_med;
}


//Problem 3
int write_to_txt(Medicine *arr,int len, double min_price, double max_price){
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\������� ����\\C\\Med\\offer.txt","w");
    int maches=0;
    if(file==NULL){
        exit(8);
    }
    for(int i=0;i<len;i++){
        if(min_price<=arr[i].price&&max_price>=arr[i].price){
            if(fprintf(file,"%s\n%s\n%ld\n%lf\n%d\n",arr[i].name,arr[i].date,arr[i].id,arr[i].price,arr[i].quantity)<0){
                printf("ERROR");
                exit(9);
            }
            maches++;
        }
    }
    if(!maches){
        return NULL;
    }
    fclose(file);
    printf("\n%d",maches);
    return maches;

}

void delete_medicine(Medicine **medicines,int len, char *name, char* date){
    int is_found=0;
    for(int i=0;i<len;i++){
         if (!(strcmp((*medicines)[i].name, name)) && !(strcmp((*medicines)[i].date, date))){{
            for(int j=i;j=len-1;j++){
                (*medicines)[j]=(*medicines)[j+1];
            }
            len--;
            (*medicines)=(Medicine*)realloc(*medicines,len*sizeof(Medicine));
            if(!medicines){
                exit(10);
            }
            is_found=1;
        }
        if(!is_found){
            printf("Nothing was founded");
            exit(11);
        }


    }
    //printf("%s, %s, %ld, %.2lf, %d",*medicines.name,*medicines.date,*medicines.id,*medicines.price,*medicines.quantity);
    print_structure(*medicines);
    printf("Okey");
}
}




int main()
{
    FILE *fp;
    Medicine* medicines=(Medicine*)malloc(sizeof(Medicine));
    fill_structure(medicines);
    print_structure(medicines);

    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\������� ����\\C\\Med\\medicines.bin","wb");
    const char *filename = "C:\\Users\\viole\\OneDrive\\������� ����\\C\\Med\\medicines.bin";
    if(file==NULL){
        exit(1);
    }
    if(fwrite(medicines,sizeof(Medicine),1,file)!=1){
        fclose(file);
        exit(2);
    }
    fclose(file);
    add_to_array(filename);
    printf("\n");
    get_medicines(medicines,1,"03.2024");
    write_to_txt(medicines,1,30,60);
    delete_medicine(&medicines,1,"aspirin","03.2024");
    return 0;
}
