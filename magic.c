#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void findMagic(int * arr, int N, int i);
void rotateR(int* arr, int N, int i);
int checkCost(int* arr, int N);
int checkMagic(int* arr, int N);

int res = 100;
int s[2][2] = { {1, 2}, {3, 4} };

void main(){
    int N = 4;
    int arr[4] = {1, 1, 1, 1};
    findMagic(arr, N, N);
}

void findMagic(int * arr, int N, int i){
    if(i == 1)
        return;
    for(int j = 0; j<i; j++){
        int magic = checkMagic(arr, N);
        if(magic==1){
            int cost = checkCost(arr, N);
            if(cost>res){
                res = cost;
            }
        }
        findMagic(arr, N, i-1);
        printf("%d, %d, %d, %d\n", arr[0], arr[1], arr[2], arr[3]);
        rotateR(arr, N, i);
    }
}

int checkCost(int * arr, int N){
    int cost = 0;
    int size = sqrt(N);
    for(int i = 0; i<N; i++){
        cost += abs(arr[i] - s[i%size][i/size]);
    }
    return cost;
}

int checkMagic(int * arr, int N){
    int size = sqrt(N);
    int * row = calloc(size, sizeof(int));
    int * col = calloc(size, sizeof(int));
    int d1 = 0, d2 = 0;
    for(int i = 0; i< size; i++){
        for(int j = 0; j<size; j++){
            row[i] += arr[i+size*j];
            col[j] += arr[i+size*j];
            if(i==j){
                d1 += arr[i+size*j];
            }
            if(i==size-j-1){
                d2 += arr[i+size*j];
            }
        }
    }
    int flag = 1;
    for(int i = 0; i<size-1; i++){
        if(row[i]!=row[i+1] || col[i]!=col[i+1]){
            flag = 0;
        }
    }
    if(row[0]!=col[0] || row[0]!=d1 || d1!=d2){
        flag = 0;
    }
    return flag;
}

void rotateR(int* arr, int N, int i){
    int temp = arr[N-1];
    int j;
    for(j = N-1; j>N-i; j--){
        arr[j] = arr[j-1];
    }
    arr[j] = temp;
}

// 1, 2, 3, 4
// 1, 2, 4, 3
// 1, 4, 2, 3
// 1, 4, 3, 2
// 1, 3, 4, 2
// 1, 3, 2, 4

// 4, 1, 2, 3
// 4, 1, 3, 2
// 4, 3, 1, 2
// 4, 3, 2, 1
// 4, 2, 3, 1
// 4, 2, 1, 3

// 3, 4, 1, 2
// 3, 4, 1, 2
// 3, 4, 1, 2
// 3, 4, 1, 2
// 3, 4, 2, 1
// 3, 4, 2, 1
// 3, 2, 4, 1
// 3, 2, 4, 1
// 3, 2, 4, 1
// 3, 2, 1, 4
// 3, 2, 1, 4
// 3, 1, 2, 4
// 3, 1, 2, 4
// 3, 1, 2, 4
// 3, 1, 4, 2
// 3, 1, 4, 2
// 2, 3, 4, 1
// 2, 3, 4, 1
// 2, 3, 4, 1
// 2, 3, 4, 1
// 2, 3, 1, 4
// 2, 3, 1, 4
// 2, 1, 3, 4
// 2, 1, 3, 4
// 2, 1, 3, 4
// 2, 1, 4, 3
// 2, 1, 4, 3
// 2, 4, 1, 3
// 2, 4, 1, 3
// 2, 4, 1, 3
// 2, 4, 3, 1
// 2, 4, 3, 1