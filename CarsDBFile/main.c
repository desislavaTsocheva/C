#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Car{
    char brand[20];
    char model[6];
    double volume;
    double price;
    char registration;
} Car;

void fillStruct(Car* car) {
    fgets(car->brand, sizeof(car->brand), stdin);
    if(strlen(car->brand) != sizeof(car->brand) - 1) {
        car->brand[strlen(car->brand) - 1] = '\0';
    }
    fgets(car->model, sizeof(car->model), stdin);
    if(strlen(car->model) != sizeof(car->model) - 1) {
        car->model[strlen(car->model) - 1] = '\0';
    }
    scanf("%lf  %lf", &car->volume, &car->price);
    getchar();
    scanf("%c", &car->registration);
    if(tolower(car->registration) != 'y' && tolower(car->registration != 'n')) {
        exit(1);
    }
}

void printStruct(Car car) {
    printf("Brand: %s\nModel: %s\nVolume: %.2lf\nPrice: %.2lf\nRegistration: %c", car.brand, car.model, car.volume, car.price, car.registration);
}

void writeToFile(FILE* f1, FILE* f2, const char* bin, const char* txt, Car* car) {
    f1 = fopen(bin, "ab");
    if(f1 == NULL) {
        exit(2);
    }
    f2 = fopen(txt, "a");
    if(f2 == NULL) {
        exit(3);
    }

    if((fwrite(car, sizeof(Car), 1, f1)) != 1) {
       exit(4);
    }

    int size = fprintf(f2, "%s %s %lf %lf %c", car->brand, car->model, car->volume, car->price, car->registration);
    if(size != strlen(car->brand) + strlen(car->model) + 2 * sizeof(double) + sizeof(char) + 6) {
        exit(5);
    }
    if(fclose(f1) != 0) {
        exit(6);
    }
}

void readFile(FILE *f1,FILE *f2,const char* bin, const char* txt, Car* car )
{
    f1=fopen(bin,"rb");
    if(f1==NULL)
    {
        exit(1);
    }
    f2 = fopen(txt, "r");
    if(f2 == NULL) {
        exit(3);
    }
     if((fread(car, sizeof(Car), 1, f1)) != 1) {
       exit(4);
    }
    int size = fscanf(f2, "%s %s %lf %lf %c", car->brand, car->model, car->volume, car->price, car->registration);
    //printf("SIZE: %d",size);
    /*if(size != strlen(car->brand) + strlen(car->model) + 2 * sizeof(double) + sizeof(char) + 6) {
        exit(5);
    }*/
    if(size!=5)
    {
    //printf("SIZE: %d",size);
    exit(5);
    }
    if(fclose(f1) != 0) {
        exit(6);
    }
    if(fclose(f2) != 0) {
        exit(7);
    }
}

int main()
{
    Car car;
    FILE *f1, *f2;
    const char* bin = "C:\\Users\\viole\\OneDrive\\Работен плот\\C\\CarsDBFile\\lastproblem.bin";
    const char* txt = "C:\\Users\\viole\\OneDrive\\Работен плот\\C\\CarsDBFile\\lastproblem.txt";
    fillStruct(&car);
    printStruct(car);
    writeToFile(f1,f2,bin,txt,&car);
    readFile(f1, f2, bin, txt, &car);
    return 0;
}
