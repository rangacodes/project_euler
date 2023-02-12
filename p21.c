#include <stdio.h>
#include <stdlib.h>

int sumD(int n){
    int count = 1;
    for(int i = 2; i<n; i++){
        if(n%i==0){
            count+=i;
        }
    }
    return count;
}

int main(){
    int N = 10000;
    int *arr = calloc(N, sizeof(int));
    int res=0;
    for(int i = 2; i<N; i++){
        arr[i+1] = sumD(i);
        //printf("%d, %d\n", i, arr[i+1]);
    }
    for(int i = 2; i<N; i++){
        if(arr[i+1]!=i && arr[arr[i+1]+1] == i){
            res+=i;
            //printf("%d,  %d\n", i, arr[i+1]);
        }
    }
    printf("\nres: %d\n", res);
}