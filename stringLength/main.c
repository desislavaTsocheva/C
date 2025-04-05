#include <stdio.h>
#include <stdlib.h>

void stringLen(char * str){
int length=0;
while(str[length]!='\0'&&str[length]!='\n'){
    length++;
}
printf("Length is: %d",length);
}


int main()
{
     int len;
    printf("Enter string length: ");
    scanf("%d", &len);
    getchar();
    char *str = (char *)malloc((len + 1) * sizeof(char));
    printf("Enter string: ");
    fgets(str,len+1,stdin);
    stringLen(str);
    return 0;
}
