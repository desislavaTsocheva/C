#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Structure layout
typedef struct Medicine{
    char name[31];
    char durability[8];
    long int id;
    double price;
    int quantity;
}Medicine;


// Initialy when you need to fill in the structure -> not needed for the test
void fill_struct(Medicine* medicine){
    fgets(medicine->name, sizeof(medicine->name), stdin);
    if (medicine->name[strlen(medicine->name) - 1] == '\n'){medicine->name[strlen(medicine->name) - 1] = '\0';}
    fgets(medicine->durability, sizeof(medicine->durability), stdin);
    if (medicine->durability[strlen(medicine->durability) - 1] == '\n'){medicine->durability[strlen(medicine->durability) - 1] = '\0';}
    scanf("%ld %lf %d", &medicine->id, &medicine->price, &medicine->quantity);
    getchar();
}


// For debugging purposes -> not needed for the test
void print_struct(Medicine* medicines, const int length){
    for (int i = 0; i < length; i++){
        printf("Name: %s\n", (medicines+i)->name);
        printf("Durability: %s\n", (medicines+i)->durability);
        printf("ID: %ld\n", (medicines+i)->id);
        printf("Price: %.2lf\n", (medicines+i)->price);
        printf("Quantity: %d\n\n", (medicines+i)->quantity);
    }
}


// Initially when you need to write in the binary file -> not needed for the test
void writing_to_bin(FILE* fp, const char* bin_file, Medicine* medicines, const int length){
    fp = fopen(bin_file, "wb");
    if (fp == NULL){
        printf("Couldn't open the file successfully for writing!\n");
        exit(2);
    }
    if (fwrite(medicines, sizeof(Medicine) * length, 1, fp) != 1){
        printf("Couldn't write to the file correctly!\n");
        fclose(fp);
        exit(3);
    }
    fclose(fp);

}


// First problem
Medicine* reading_from_binary(FILE* fp, const char* bin_file){
    fp = fopen(bin_file, "rb");
    if (fp == NULL){
        printf("Couldn't open the file successfully for reading!\n");
        exit(4);
    }

    if (fseek(fp, 0, SEEK_END) != 0){
        printf("Couldn't go to the EOF!\n");
        fclose(fp);
        exit(5);
    }

    size_t size_bytes = ftell(fp);
    if (size_bytes == -1){
        printf("Couldn't get the total bytes!\n");
        fclose(fp);
        exit(6);
    }

    int length = size_bytes/sizeof(Medicine);
    Medicine* medicines = (Medicine*)malloc(length*sizeof(Medicine));
    if (!medicines){
        printf("Couldn't allocate enough memory!\n");
        exit(7);
    }
    rewind(fp);

    if (fread(medicines, sizeof(Medicine) * length, 1, fp) != 1){
        printf("Couldn't read from the binary file!\n");
        fclose(fp);
        exit(8);
    }

    fclose(fp);

    return medicines;
}


// Helper function for the second problem's condition
double get_date(Medicine* medicine, int i){
    return ((((double)medicine[i].durability[0] - 48) * 10 +
    (double)medicine[i].durability[1] - 48) / 12.0) +
    ((double)medicine[i].durability[3] - 48) * 1000 + ((double)medicine[i].durability[4] - 48) * 100 +
    ((double)medicine[i].durability[5] - 48) * 10 + ((double)medicine[i].durability[0] - 48);
}


// Second problem
Medicine* get_medicines(Medicine* medicine, const int length, const char* date){
    int initial_length = 0;
    Medicine* medicines = (Medicine*)malloc(initial_length * sizeof(Medicine));
    double ref_value = ((((double)date[0]- 48)*10 + (double)date[1]-48) / 12.0) + ((double)date[3]- 48)*1000 + ((double)date[4]- 48)*100+ ((double)date[5]- 48)*10 + (double)date[6]-48;

    for (int i = 0; i < length; i++){
        if (ref_value > get_date(medicine, i)){
            initial_length++;
            medicines = (Medicine*)realloc(medicines, initial_length * sizeof(Medicine));
            if (!medicines){
                printf("Couldn't reallocate memory!\n");
                free(medicines);
                exit(9);
            }
            medicines[initial_length - 1] = medicine[i];
        }
    }

    if(!initial_length){
        return NULL;
    }
    return medicines;
}


// Third problem
int writing_to_txt(Medicine* medicines, const int length, double min_price, double max_price){
    FILE* fp;
    int found_matches = 0;
    fp = fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Medicine_new\\offer.txt", "w");
    if (fp == NULL){
        printf("Couldn't open the text file successfully!\n");
        exit(10);
    }

    for (int i = 0; i < length; i++){
        if (min_price <= medicines[i].price && max_price >= medicines[i].price){
            if(fprintf(fp, "%s\n%s\n%ld\n%.2lfleva\n\n\n", medicines[i].name, medicines[i].durability, medicines[i].id, medicines[i].price) < 0){
                printf("Couldn't write to the text file successfully!\n");
                fclose(fp);
                exit(11);
            }
            found_matches++;
        }
    }

    fclose(fp);
    return found_matches;
}


// Forth problem
void deleting_medicines(Medicine** medicines, const int length, const char* name, const char* durability){
    int size = length;
    bool is_Found = false;

    for (int i = 0; i < size; i++){
        if (!(strcmp((*medicines)[i].name, name)) && !(strcmp((*medicines)[i].durability, durability))){
            for (int j = i; j < size-1; j++){
                (*medicines)[j] = (*medicines)[j+1];
            }
            size--;
            (*medicines) = (Medicine*)realloc(*medicines, size * sizeof(Medicine));
            if (!medicines){
                printf("Couldn't reallocate the memory!\n");
                exit(12);
            }
            is_Found = true;
        }
    }

    if (!is_Found){
        printf("There were no such records that have %s name and %s durability!\n", name, durability);
    }

    print_struct(*medicines, size); // For debugging purposes, can be removed
}

int main(){
    FILE* fp;
    const char* bin_file = "C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Medicine_new\\medicines.bin";

    // The next lines are additional and are needed for checking if the test problems are running correctly!
    // It is only needed to be ran the first time, then you can comment the code again
    /*const int length = 2;
    Medicine* medicines = (Medicine*)malloc(length* sizeof(Medicine));
    if (!medicines){
         printf("Couldn't allocate the memory!\n");
         exit(1);
     }
     for (int i = 0; i < length; i++){
         fill_struct(&medicines[i]);
     }
    writing_to_bin(fp, bin_file, medicines, length); // Only needed for writing in the binary file
    free(medicines);*/

    // First problem calling
    Medicine* medicine = reading_from_binary(fp, bin_file); // It wasn't said if first problem should be a seperate function, so i did it as a seperate one
    const int size = 2; // needed for the second problem from the test


    // Second problem calling, I'm using the same array from the first problem in the following problems. You can create other arrays for the problems.
    Medicine* get_meds = get_medicines(medicine, size, "05.2024"); // example value for calling


    // Third problem calling
    int count_txt = writing_to_txt(medicine, size, 5, 10); // example values for the calling
    printf("%d medicines were added to the text file.\n", count_txt); // example for using the returning value, not needed for the problem

    // Forth problem calling
    deleting_medicines(&medicine, size, "analgin", "10.2024"); // example for deleting a medicine record

    free(medicine);
    if (get_meds){
        free(get_meds);
    }

    return 0;
}
