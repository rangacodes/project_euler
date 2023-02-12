#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

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

int main(){
    clock_t start, end;
    double cpu_time_used;
     
    start = clock();
    
    int n = 10001;
    int count = 1;
    int i;
    for(i = 3; count!=n; i+=1){
        if(isPrime(i)){
            count++;
        }
    }
    printf("%lld\n", i-2);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %lf\n", cpu_time_used);
}