#include <stdio.h>
#include <stdlib.h>

int findMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

void countSort(int arr[], int n) {
    int i;
    int max = findMax(arr, n);

    int *count = (int *)calloc((max + 1), sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));

    for(i = 0; i < n; i++)
        count[arr[i]]++;

    for(i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for(i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(i = 0; i < n; i++)
        arr[i] = output[i];

    free(count);
    free(output);
}


int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
