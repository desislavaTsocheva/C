#include <stdio.h>
#include <stdlib.h>

typedef struct Course
{
        char name[51];
        char date[11];
        int lecture;
        double price;
} Course;

void WriteInFile()
{
    FILE *file;
    file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Course\\courses.bin","wb");
    if(file==NULL)
    {
            exit(1);
    }
    Course courses[2];
    strcpy(courses[0].name, "C Programming");
    strcpy(courses[0].date, "2025.05.01");
    courses[0].lecture = 10;
    courses[0].price = 120.50;
    strcpy(courses[1].name, "Data Structures");
    strcpy(courses[1].date, "2025.06.15");
    courses[1].lecture = 12;
    courses[1].price = 150.00;
    size_t written = fwrite(courses, sizeof(Course), 2, file);
    if (written != 2)
    {
        fclose(file);
        exit(1);
    }

    fclose(file);
}

void LowerPrice(Course *arr,int n,int i)
{
    if(i<0||i>n)
    {
        printf("Index out of range");
    }
    for(int j=0;j<n;j++)
    {
        if(j==i)
        {
             arr[j].price=arr[j].price*0.9;
        }
    }
  printf("%.2lf lv  -  %50s  -  %10s ",arr[i].price,arr[i].name, arr[i].date);
}

int CountInterval(Course *arr,int n, double minPrice, double maxPrice)
{
    FILE*file;
    file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Course\\offer.txt","w");
    if(file==NULL)
    {
        exit(3);
    }
    int counter=0;
    int found=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].price>minPrice&&arr[i].price<maxPrice)
        {
                counter++;
                found=1;
                fprintf(file,"%50s \n %10s \n %d \n %.2lf",arr[i].name,arr[i].date,arr[i].lecture,arr[i].price);
        }
    }
    if(!found){
        return 0;
    }
    else{
        return counter;
    }
}

Course* returnPointer(Course** arr, int* n, char* name, char* date)
{
    int found = 0;
    for (int i = 0; i < *n; i++)
    {
        if (strcmp((*arr)[i].name, name) == 0 && strcmp((*arr)[i].date, date) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                (*arr)[j] = (*arr)[j + 1];
            }

            (*n)--;

             if (*n > 0) {
                *arr = realloc(*arr, (*n) * sizeof(Course));
                if (*arr == NULL) {
                    perror("realloc failed");
                    exit(3);
                }
            } else {
                free(*arr);
                *arr = NULL;
            }
             return *arr;
        }
    }
    return NULL;
}


int main()
{
    WriteInFile();
    Course *courses;
    FILE *file;
    file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Course\\courses.bin","rb");
    if(file==NULL){
            printf("Error");
            exit(2);
    }
    fseek(file,0,SEEK_END);
    int fileSize=ftell(file);
    int n=fileSize/sizeof(Course);
    rewind(file);
    printf("Counter: %d",n);
    courses=(Course *)malloc(n*sizeof(Course));

    int result=fread(courses,sizeof(Course),n,file);
    if(!courses)
    {
            printf("Error");
    }
    printf("\n");
    LowerPrice(courses,n,1);
    int c=CountInterval(courses,n,100,130);
    printf("\n%d",c);
    printf("\n");
    Course *update = returnPointer(&courses, &n, "C Programming", "2025.05.01");
    printf("%p\n",(void*)update);
     for(int i=0;i<n;i++)
    {
        printf("%50s %10s %d %lf  \n",courses[i].name,courses[i].date,courses[i].lecture,courses[i].price);
    }
    return 0;
}
