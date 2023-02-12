#include <stdio.h>
#include <stdlib.h>

int isPalindrome(int n);

int main(){
    int min = 10000;
    int max = 998001;
    printf("997799: %d", isPalindrome(997799));
    for(int i = 998001; i>10000; i--){
        //printf("i=%d\n", i);
        if(isPalindrome(i)){
            printf("\tPalindrome! %d\n\n", i);
            for(int j=100; j<=999; j++){
                if(i%j==0 && i/j>=100 && i/j<=999){
                    printf("%d", i);
                    return 1;
                }                    
            }
        }
    }
    printf("none found\n");
}
//123456

int isPalindrome(int n){
    if(n<100000){
        int n0 = n%10;
        int n1 = (n%100 - n%10)/10;
        int n2 = (n%1000 - n%100)/100;
        int n3 = (n%10000 - n%1000)/1000;
        int n4 = (n%100000 - n%10000)/10000;
        if(n0 == n4 && n1==n3)
            return 1;
        else
        {
            return 0;
        }
    }
    else{
        int n0 = n%10;
        int n1 = (n%100 - n%10)/10;
        int n2 = (n%1000 - n%100)/100;
        int n3 = (n%10000 - n%1000)/1000;
        int n4 = (n%100000 - n%10000)/10000;
        int n5 = (n%1000000 - n%100000)/100000;
        if(n0 == n5 && n1 == n4 && n2==n3)
            return 1;
        else
        {
            return 0;
        }
        
    }
}