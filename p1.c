#include <stdio.h>
#include <stdlib.h>

int main(){
    int r3=1, r5 = 1;
    int n = 1000;
    long int sum = 0;
    for(int i = 1; i<n; i++){
        int flag = 0;
        if(r3 == 3){
            r3 = 1;
            flag = 1;
        }
        else{
            r3++;
        }
        if(r5 == 5){
            r5 = 1;
            flag = 1;
        }
        else{
            r5++;
        }
        if(flag==1){
            sum += i;
        }
    }
    printf("%ld", sum);
    return 0;
}