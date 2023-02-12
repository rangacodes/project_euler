#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int isPrime(int n);
void fillprime(int * prime, int n);
void fillfactors(int *arri, int i, int *prime);
float phibyn(int i, int** arr);
int areRP(int n1, int n2, int**arr);
void fillprime2(int * prime, int n);
void fillprime3(int * prime, int n);

int main(){
    printf("starting:\n");
    int n = 100;
    int * arr[n];
    int * prime = (int*)calloc(n, sizeof(int));
    fillprime3(prime, n);
    printf("Primes done\n");
    // for(int i= 0; i<n; i++){
    //     arr[i] = (int*)calloc((i+1), sizeof(int));
    //     arr[i][0] = 1;
    // }

    // for(int i = 1; i<n; i++){
    //     fillfactors(arr[i], i, prime);
    // }

    // int max, phibynmax = 0;

    // for(int i = 1; i<=n; i++){
    //     float temp = phibyn(i, arr);
    //     if(temp>phibynmax){
    //         max = i;
    //         phibynmax = temp; 
    //     }
    // }
    // printf("Finally, it is: %d", max);
    // printf("\nPrinting primes:\n");
    // for(int i = 0; i<n; i++){
    //     printf("%d ", i+1);
    // }
    // printf("\n");
    // for(int i = 0; i<n; i++){    
    //     printf("%d ", prime[i]);
    // }
    // printf("\nPrinting prime factors for each number less than %d\n", n);
    // for(int i = 0; i<n; i++){
    //     printf("n:%d\n", i+1);
    //     for(int j = 0; j<=i; j++){
    //         printf("%d ", j+1);
    //     }
    //     printf("\n");
    //     for(int j = 0; j<=i; j++){
    //         printf("%d ", arr[i][j]);
    //     }
    //     printf("\n");
    // }
    
}

int areRP(int n1, int n2, int**arr){
    int min;
    if(n1<n2)
        min = n1;
    else
        min = n2;
    for(int i = 1; i<min; i++){
        if(arr[n1-1][i]>0 && arr[n2-1][i]>0){
            return 0;
        }
    }
    return 1;    
}



float phibyn(int i, int** arr){
    float phi=1;
    for(int j = 2; j<i; j++){
        if(areRP(j, i, arr))
            phi++;
    }
    return i/phi;
}

void fillfactors(int *arri, int i, int * prime){
    int n = i+1;
    //printf("n = %d\n", n);
    for(int j = 1; j<=i; j++){
        if(prime[j]){
            //printf("%d is prime\n", j+1);
            while(n%(j+1)==0){
                n = n/(j+1);
                arri[j]++;
                //printf("arri[%d] = %d\n", j, arri[j]);
            }
        }
        // else{
        //     printf("%d is not a prime\n", j+1);
        // }
    }
}

void fillprime3(int * prime, int n){
    for(int i = 0; i<n; i++){
        prime[i] = 1;
    }
    for(int i = 1; i<n; i++){
        int num = i+1;
        int j = num*num - 1;
        if(prime[i]==1){
            prime[j] = 0;
            j+=num;
            while(j<n){
                prime[j] = 0;
                j+=num;
            }
        }
    }
}

void fillprime2(int * prime, int n){
    // clock_t start, end;
    // double time;
    // start = clock();
    for(int i = 0; i<n; i++){
        prime[i] = 1;
    }
    for(int i = 1; i<n; i++){
        int num = i+1;
        int j = i;
        if(prime[i]==1){
            j+=num;
            while(j<n){
                prime[j] = 0;
                j+=num;
            }
        }
    }
    // end = clock();
    // time = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Fill prime 2 ran for %lf\n", time);
}

void fillprime(int * prime, int n){
    // clock_t start, end;
    // start = clock();
    // double time;
    prime[0] = 1;
    prime[1] = 1;
    for(int i = 2; i < n; i++){
        if(isPrime(i+1)){
            prime[i] = 1;
        }
    }
    // end = clock();
    // time = ((double) (end - start)) / CLOCKS_PER_SEC;
    // printf("Fill prime ran for %lf\n", time);
}

int isPrime(int n){
    int i = 3;
    if(n%2==0)
    return 0;
    while(i<n){
        if(n%i==0){
            return 0;
        }
        i+=2;
    }
    return 1;
}