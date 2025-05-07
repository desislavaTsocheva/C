#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Treatment{
    int id;
    char durability[11];
    char name[31];
    char diagnose[51];
}Treatment;

void fill_struct(Treatment* treatement){
    fgets(treatement->name, sizeof(treatement->name), stdin);
    if (treatement->name[strlen(treatement->name) - 1] == '\n'){treatement->name[strlen(treatement->name) - 1] = '\0';}
    fgets(treatement->durability, sizeof(treatement->durability), stdin);
    if (treatement->durability[strlen(treatement->durability) - 1] == '\n'){treatement->durability[strlen(treatement->durability) - 1] = '\0';}
    fgets(treatement->durability, sizeof(treatement->diagnose), stdin);
    if (treatement->diagnose[strlen(treatement->diagnose) - 1] == '\n'){treatement->diagnose[strlen(treatement->diagnose) - 1] = '\0';}
    scanf("%d", &treatement->id);
    getchar();
}



void writing_to_bin(FILE* fp, const char* bin_file, Treatment* treatements, const int length){
    fp = fopen(bin_file, "wb");
    if (fp == NULL){
        printf("Couldn't open the file successfully for writing!\n");
        exit(2);
    }
    if (fwrite(treatements, sizeof(Treatment) * length, 1, fp) != 1){
        printf("Couldn't write to the file correctly!\n");
        fclose(fp);
        exit(3);
    }
    fclose(fp);

}

int count_treatment(Treatment*arr,int n,char *diagnose,char *name){
    int counter=0;
    for(int i=0;i<n;i++){
        if(strcmp(arr[i].name,name)==0&&strcmp(arr[i].diagnose,diagnose)==0){
            counter++;
            printf("%d",counter);
        }
    }
    if(counter==0){
        printf("Not Found");
        return 0;
    }
    else{
        printf("%d", counter);
        return counter;
    }

}

int write_text_file(Treatment *arr,int n,char *diagnose){
    int counter=0;
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Treatment\\illness.txt","a");
    if(file==NULL){
        exit(10);
    }
    for(int i=0;i<n;i++){
        if(!(strcmp(arr[i].diagnose,diagnose)==0)){
            if(fprintf(file,"%d %s %s %s",&arr[i].id,arr[i].name,arr[i].durability,arr[i].diagnose)<0){
                exit(11);
            }
            counter++;
        }
    }
    if(counter!=0){
        return counter;
    }
    else{
        printf("NOT FOUNDED");
        return 0;
    }

}

Treatment* add_new_treatment(Treatment *arr,int* n){
    Treatment treatment;
    scanf("%d",&treatment.id);
    getchar();
   /* scanf("%s",treatment.name);
    scanf("%s",treatment.durability);
    scanf("%s",treatment.diagnose);*/
    fgets(treatment.name,sizeof(treatment.name),stdin);

    if(treatment.name[strlen(treatment.name)-1]=='\n'){
        treatment.name[strlen(treatment.name)-1]=='\0';
    }

    fgets(treatment.durability,sizeof(treatment.durability),stdin);
    fgets(treatment.diagnose,sizeof(treatment.diagnose),stdin);
    Treatment *arr_new=(Treatment*)realloc(arr,sizeof(Treatment)*(*n+1));

    if(!arr_new){
        exit(12);
    }
    arr_new[*n]=treatment;
    (*n)++;

    for(int i=0;i<*n;i++){
        printf("%d %s %s %s \n",arr_new[i].id,arr_new[i].name,arr_new[i].durability,arr_new[i].diagnose);
    }

    return arr_new;
}

int main()
{
    /*FILE* fp;
    const char* bin_file = "C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Treatment\\treatment.bin";
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    const int length = 2;
    Treatment* medicines = (Treatment*)malloc(length* sizeof(Treatment));
    if (!medicines){
         printf("Couldn't allocate the memory!\n");
         exit(1);
     }
     for (int i = 0; i < length; i++){
         fill_struct(&medicines[i]);
     }
    writing_to_bin(fp, bin_file, medicines, length); // Only needed for writing in the binary file
    free(medicines);
    */

    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    FILE *file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Treatment\\treatment.bin","rb");
    if(file==NULL){
        exit(1);
    }
    if (fseek(file, 0, SEEK_END) != 0){
        printf("Couldn't go to the EOF!\n");
        fclose(file);
        exit(5);
    }

    size_t size_bytes = ftell(file);
    if (size_bytes == -1){
        printf("Couldn't get the total bytes!\n");
        fclose(file);
        exit(6);
    }

    int length = size_bytes/sizeof(Treatment);
    Treatment *arr=(Treatment*)malloc(length*sizeof(Treatment));
    if(!arr){
        exit(8);
    }
    rewind(file);

    if(fread(arr,sizeof(Treatment)*length,1,file)!=1){
        exit(9);
    }
    printf("ARRAY: \n");
    for(int i=0;i<n;i++){
        printf("%d %s %s %s \n",arr[i].id,arr[i].name,arr[i].durability,arr[i].diagnose);
    }
    count_treatment(arr,n,"ivan","kashlica");
    write_text_file(arr,n,"kashlica");
    add_new_treatment(arr,&n);
}
