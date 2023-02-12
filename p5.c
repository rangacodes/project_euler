#include <stdio.h>
#include <stdlib.h>


int isPrime(int n){
    int i = 3;
    if(n!=2){
        if(n%2==0)
        return 0;
        while(i<n){
            if(n%i==0){
                return 0;
            }
            i+=2;
        }
    }    
    return 1;
}

int main(){
    int n = 20;
    int npr = 0;
    int primes[21] = {0};
    int factors[21] = {0};
    printf("Filling the primes array:\n");
    for(int i = 2; i<=n; i++){
        if(isPrime(i)){
            primes[i] = 1;
            npr++;
            printf("\t%d is a prime\n", i);
        }
    }
    for(int i = 2; i<=n; i++){                  //for each number between 1 and 20
        for(int j = 2; j<=i; j++){              //calculate prime factors for given i
            if(primes[j]){
                int num = i;
                int count = 0;
                while(num%j==0){
                    count++;
                    num = num/j;
                }
                if(count>factors[j]){
                    factors[j] = count;
                }
            }
        }
    }
    long int product  = 1;
    for(int i = 1; i<=n; i++){
        while(factors[i]!=0){
            factors[i]--;
            product = product*i;
        }
    }
    printf("\nAnswer is %ld\n", product);

}