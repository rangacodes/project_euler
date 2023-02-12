#include <stdio.h>
#include <stdlib.h>

int main(){

    FILE* fptr;
    fptr = fopen("p081_matrix.txt", "r");
    if(fptr==NULL){
        printf("Cannot open file");
        return 0;
    }

    int arr[80][80];
    for(int i = 0; i<80; i++){
        for(int j = 0; j<79; j++){
            fscanf(fptr, "%d %*c", &arr[i][j]);
        }
        fscanf(fptr, "%d", &arr[i][79]);
    }
    for(int i = 0; i<80; i++){
        for(int j = 0; j<80; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");    
    }
}