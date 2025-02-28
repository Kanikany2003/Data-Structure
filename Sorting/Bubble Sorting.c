#include<stdio.h>

int main(){
    int arr[10],i,j;
    
    printf("Enter 10 element \n");

    for(int i=0 ; i<10 ; i++){
    printf("Number %d : ", i + 1);
    scanf("%d", &arr[i]);
    }

    for(int i=0;i<9;i++){
        for(j=0;j<10;j++){
            if(arr[j]>arr[j+1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else {
                flag++
            }
            }
        }
}
        printf("Sorted array: ");
        for(int i=0 ; i<10 ; i++){
            printf("%d\n", arr[i]);
        }
    

    return 0;
