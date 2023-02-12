#include <stdio.h>
#include <stdlib.h>

int main(){
    int n = 100;
    long long int sum = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            sum+= i*j;
        }
        sum-=i*i;
    }
    printf("%lld", sum);
}