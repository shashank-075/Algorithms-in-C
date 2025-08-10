#include <stdio.h>
void sort(int arr[], int n){
    for (int i=0; i<n; i++){
        for (int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main(){
    int arr[5] = {8,6,2,5,11};
    sort(arr, 5);
    for (int i=0;i<5;i++){
        printf("%d ", arr[i]);
    }
    return 0;
}