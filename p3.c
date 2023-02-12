#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(long long int n);

int main(){
    long long int n = 600851475143;
    long long int max = 0;
    for(long long int i = 3; n!=1; i+=2){
        if(isPrime(i)){
            if(n%i==0){
                n = n/i;
                max = i;             
                i -= 2;
            }
        }
    }
    printf("%lld", max);
}

int isPrime(long long int n){
    long long int i = 3;
    float cap = sqrtf((float)n);
    if(n%2==0)
        return 0;
    while(i<cap){
        if(n%i==0){
            return 0;
        }
        i+=2;
    }
    return 1;
}