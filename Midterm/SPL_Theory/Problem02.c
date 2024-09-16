/******************************************* 
Simple Output
********************************************/
#include<stdio.h>
int main(){
    //Last 4 Digit=0062 --> 62
    int n=62;
    int a= n/7;
    int b= n%7;
    float c= (float)n/7;
    float d= (float)(n/7);
    int e= (a-b)<0&&c;
    printf("%d\n%d\n%f\n%f\n%d\n",a,b,c,d,e);
}
/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/