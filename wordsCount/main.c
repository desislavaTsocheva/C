#include <stdio.h>
#include <stdlib.h>

void wordsInString(char *str){
    int length = 0, count = 0;

    if (str[length] == ' ') {
        length++;
    }

    while (str[length] != '\0') {
        if (str[length] == ' ' && str[length - 1] != ' ') {
            count++;
        }
        length++;
    }

    if (str[length - 1] != ' ') {
        count++;
    }

    printf("Number of words: %d\n", count);
}

int main() {
    int len;
    printf("Enter string length: ");
    scanf("%d", &len);
    getchar();

    char *str = (char *)malloc((len + 1) * sizeof(char));
    printf("Enter string: ");
    fgets(str, len + 1, stdin);

    wordsInString(str);

    free(str);
    return 0;
}
