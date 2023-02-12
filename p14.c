#include <stdio.h>
#include <stdlib.h>

int main(){
    int N = 1000000;
    int nummax = 1;
    int lenmax = 1;
    int* arr = (int*)calloc(N+1, sizeof(int));

    for(int i = 2; i<N; i++){
        int len = 1;
        long int n = i;
        while(n!=1){
            if(n%2==0){
                n = n/2;
                if(n<N && arr[n+1]!=0){
                    len += arr[n+1];
                    break;
                }
            }
            else{
                n = 3*n + 1;
                if(n<N && arr[n+1]!=0){
                    len += arr[n+1];
                    break;
                }
            }
            len++;
        }
        arr[i+1] = len;
    }
    for(int i = 2; i<N; i++){
        //printf("%d: %d\n", i, arr[i+1]);
        if(arr[i+1]>lenmax){
            lenmax = arr[i+1];
            nummax = i;
        }
    }
    printf("\nNumber: %d\n Length:%d\n", nummax, lenmax);
}






// #include <stdio.h>
// #include <stdlib.h>

// int main(){
//     int N = 1000000;
//     int nummax = 1;
//     int lenmax = 1;

//     for(int i = 2; i<N; i++){
//         int len = 1;
//         int n = i;
//         while(n!=1){
//             if(n%2==0){
//                 n = n/2;
//             }
//             else{
//                 n = 3*n + 1;
//             }
//             len++;
//         }
//         if(len>lenmax){
//             lenmax = len;
//             nummax = i;
//         }
//     }

//     printf("\nAnswer: %d\n", nummax);
// }
