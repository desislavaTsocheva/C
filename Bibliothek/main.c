#include <stdio.h>
#include <stdlib.h>

typedef struct Book{
    int id;
    char title[51];
    char author[31];
    char genre[21];
    int year;
    int isAvailable;
}Book;

int countBooksByGenre(Book *books,int n,char *genre){
    int counter=0;
    for(int i=0;i<n;i++){
        if(strcmp(books[i].genre,genre)==0){
            counter++;
        }
    }
    if(counter==0){
        return 0;
        exit(2);
    }
    printf("Count: %d",counter);
}

int add_to_txt(Book *books,int n,int isAvailable){
    int counter=0;
    FILE *file;
    file=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Bibliothek\\info.txt","a");
    if(file==NULL){
        exit(3);
    }
    for(int i=0;i<n;i++){
        if(books[i].isAvailable==1){
            if(fprintf(file,"<%d>; <%s>; <%s>; <%s>, <%d>\n",books[i].id,books[i].title,books[i].author,books[i].genre,books[i].year)<0){
                fclose(file);
                exit(4);
            }
            counter++;
        }
    }
    fclose(file);
    printf("Counter: %d\n",counter);
    return counter;
}

void write_in_bin(Book *books,int n){
    FILE *file_bin=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Bibliothek\\books.bin","wb");
    if(file_bin==NULL){
        exit(5);
    }
    for(int i=0;i<n;i++){
        if(fwrite(&books[i],sizeof(Book),1,file_bin)!=1){
            exit(6);
        }
    }
}

void filter_bin(Book *books,int n,int id){
    int found=0;
    FILE *file_bin=fopen("C:\\Users\\viole\\OneDrive\\Работен плот\\C\\Bibliothek\\books.bin","rb");
    if(file_bin==NULL){
        exit(6);
    }
    while(fread(books,sizeof(Book),1,file_bin)){
        if(books->id==id){
            printf("Book found:\n");
            printf("ID: %d\n", books->id);
            printf("Title: %s\n", books->title);
            printf("Author: %s\n", books->author);
            printf("Genre: %s\n", books->genre);
            printf("Year: %d\n", books->year);
            printf("Is Available: %d\n", books->isAvailable);
            found=1;
            break;
        }
    }
    if(found==0){
        printf("There's no book with this id in the library");
    }
    fclose(file_bin);
}

int main()
{
    int n;
    printf("Enter length: ");
    scanf("%d",&n);
    Book *books=(Book*)malloc(n*sizeof(Book));
    for(int i=0;i<n;i++){
        printf("Enter id: ");
        scanf("%d",&books[i].id);
        printf("Enter title: ");
        scanf("%s",&books[i].title);
        printf("Enter author: ");
        scanf("%s",books[i].author);
        printf("Enter genre: ");
        scanf("%s",books[i].genre);
        printf("Enter year: ");
        scanf("%d",&books[i].year);
        do{
        printf("IsAvailable: ");
        scanf("%d",&books[i].isAvailable);
        }while(books[i].isAvailable!=0&&books[i].isAvailable!=1);
    }
    if(!books){
        printf("Fail");
        exit(1);
    }

     for(int i=0;i<n;i++){
        printf("%d %s %s %s %d %d\n", books[i].id,books[i].title,books[i].author,books[i].genre,books[i].year,books[i].isAvailable);
    }

    int answer,new_len;
    do{
    printf("Do you want to add more books ?");
    scanf("%d",&answer);
    }while(answer!=0&&answer!=1);
    if(answer==0){
        return;
    }
    else{
        printf("Now much books you want to add? ");
        scanf("%d",&new_len);
    }
    Book *new_books=(Book*)realloc(books,(n+new_len)*sizeof(Book));
    if(new_books!=NULL){
        books=new_books;
    }
    else{
        exit(2);
    }
    for(int i=n;i<(n+new_len);i++){
        printf("Enter id: ");
        scanf("%d",&books[i].id);
        printf("Enter title: ");
        scanf("%s",&books[i].title);
        printf("Enter author: ");
        scanf("%s",&books[i].author);
        printf("Enter genre: ");
        scanf("%s",&books[i].genre);
        printf("Enter year: ");
        scanf("%d",&books[i].year);
        do{
        printf("IsAvailable: ");
        scanf("%d",&books[i].isAvailable);
        }while(books[i].isAvailable!=0&&books[i].isAvailable!=1);
    }
    printf("Books\n");
    for(int i=0;i<n+new_len;i++){
        printf("%d %s %s %s %d %d\n", books[i].id,books[i].title,books[i].author,books[i].genre,books[i].year,books[i].isAvailable);
    }

    countBooksByGenre(books,n+new_len,"horror");
    add_to_txt(books,n,1);
    write_in_bin(books,n);
    filter_bin(&books,n,1);
    return 0;
}
