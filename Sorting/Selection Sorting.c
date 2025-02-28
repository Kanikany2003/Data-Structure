#include<stdio.h>
int main(){ 
    int arr[10],i,j, min,temp;

    printf("Enter 10 elements\n");
    for(i=0 ; i<10 ; i++){
        printf("Number %d :", i+1);
        scanf("%d", &arr[i]);
    }
   
    for(int i=0; i < 9; i++){
        min = i;
        for(int j=i+1 ; j < 10 ; j++){
            if (arr[j] < arr[min]){
                min = j;
            }
        }
                
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted array:\n");
    for (i = 0; i < 10; i++) {
        printf("Number : %d\n", arr[i]);
    }
    return 0;
}