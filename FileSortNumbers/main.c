#include <stdio.h>
#include <stdlib.h>

int expectedPrintSize(int value) {
    int count = 0;

    if (value == 0) {
        return 2;
    }

    if (value < 0) {
        count++;
        value = -value;
    }

    while (value > 0) {
        count++;
        value /= 10;
    }

    return count + 1;
}
void writeToFp(const char* binaryName, FILE* fp) {
    fp = fopen(binaryName, "wb");
    if(fp == NULL) {
        exit(1);
    }
    int len;
    scanf("%d", &len);
    if(len < 0) {
        exit(2);
    }
    int arr[len];
    for(int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }
    if((fwrite(&len, sizeof(int), 1, fp)) != 1) {
        exit(3);
    }
    if((fwrite(arr, sizeof(arr), 1, fp)) != 1) {
        exit(4);
    }
    if(fclose(fp) != 0) {
        exit(5);
    }
}

void checkEvenOdd(int* even, int* odd, int* arr, int len) {
    for(int i = 0; i < len; i++) {
        if(*(arr + i) % 2 == 0) {
            (*even)++;
        } else {
            (*odd)++;
        }
    }
}

void bubbleSort(int* arr, int len) {
    for(int i = 0; i < len - 1; i++) {
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void writeToTxt(const char* txt, FILE* fp, int* arr, int len) {
    fp = fopen(txt, "w");
    if(fp == NULL){
        exit(10);
    }

    for (int i = 0; i < len; i++) {
        int size = fprintf(fp, "%d ", arr[i]);
        int expected = expectedPrintSize(arr[i]);

        if (size != expected) {
            exit(11);
        }
    }

    if((fclose(fp)) != 0) {
        exit(12);
    }
}

void readFromFp(const char* binaryName, FILE* fp) {
    fp = fopen(binaryName, "rb");
    if(fp == NULL) {
        exit(6);
    }
    int len;
    if((fread(&len, sizeof(int), 1, fp)) != 1) {
        exit(7);
    }
    int arr[len];
    if((fread(arr, sizeof(arr), 1, fp)) != 1) {
        exit(8);
    }
    if(fclose(fp) != 0) {
        exit(9);
    }
    const char* txt = "C:\\Users\\viole\\OneDrive\\Работен плот\\C\\FileSortNumbers\\firstproblem.txt";
    bubbleSort(arr, len);
    writeToTxt(txt, fp, arr, len);
    int even = 0, odd = 0;
    checkEvenOdd(&even, &odd, arr, len);
    printf("Even count %d, odd count %d\n", even, odd);
}

int main()
{
    FILE* fp;
    const char* binaryName = "C:\\Users\\viole\\OneDrive\\Работен плот\\C\\FileSortNumbers\\firstproblem.bin";
    writeToFp(binaryName, fp);
    readFromFp(binaryName, fp);
    return 0;
}
