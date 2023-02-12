#include <stdio.h>
#include <stdlib.h>

int main(){
    long int n1 = 1;
    long int n2 = 2;

    long int sum = 0;

    while(n2<=4000000){
        if(n2%2==0)
            sum+=n2;
        int temp = n2;
        n2 = n1 + n2;
        n1 = temp;
    }

    printf("%ld", sum);

}