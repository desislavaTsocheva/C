#include <stdio.h>

int main() {
    int len, k;
    printf("Enter len: ");
    scanf("%d", &len);

    int arr[len], temp[len];
    for (int i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter k: ");
    scanf("%d", &k);
    k = k % len;

    for (int i = 0; i < len; i++) {
        temp[(i + k) % len] = arr[i];
    }
    for (int i = 0; i < len; i++) {
        arr[i] = temp[i];
    }
    printf("ARR: \n ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
