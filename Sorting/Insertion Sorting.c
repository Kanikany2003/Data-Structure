#include<stdio.h>

int main(){
    int arr[10], i, j,curr;

    printf("-Enter 10 elements-\n");

    for (i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    for(i = 1; i<10 ; i++){
        curr = arr[i];
        j = i-1;

        while(j >= 0 && arr[j]>curr){
                arr[j+1] = arr[j];
                j = j-1;
        }
        arr[j+1] = curr;
    }
    printf("Sorted array: \n");
    for (i = 0; i < 10; i++) {
        printf("Number: %d\n", arr[i]);
    }
    return 0;
}