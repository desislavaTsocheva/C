#include <stdio.h>
#include <stdlib.h>

int main()
{
    char number;
    printf("Enter char:");
    scanf("%c",&number);
    printf("Char %c --> %d \n",number,number);

    for(char c='0';c<='9';c++){
        printf("Char %c--> %d \n",c,c);
    }
    for(char c='a';c<='z';c++){
        printf("Char %c--> %d \n",c,c);
    }
    for(char c='A';c<='Z';c++){
        printf("Char %c--> %d \n",c,c);
    }

}
