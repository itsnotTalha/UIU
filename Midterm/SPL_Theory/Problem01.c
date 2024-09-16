/******************************************* 
Write a C program to print the following pattern. Take n as user input where n =
(LAST_2_DIGITS_OF_YOUR_ ID % 5) + 5.
********************************************/
#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    n=(n%5)+5;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-i;j++)
        printf("  ");
        int count=1;
        for(int j=0;j<i;j++){
            printf("%d ",count);
            count+=2;
            if(count>5)
            count=1;
        }
        puts("");
    }
}
/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/