/******************************************* 
Simple Output
********************************************/
#include<stdio.h>
int main(){
    //Last 4 Digit=0062 --> 62
    int const n=62;
    int a= n/7;
    int b= n%7;
    float c= (float)n/7;
    float d= (float)(n/7);
    int e= (a-b)<0&&c;
    puts("");
    printf("%d\n%d\n%f\n%f\n%d\n",a,b,c,d,e);
    puts("");
    puts("");
    puts("");
    puts("");
    puts("");
    {
        int n=62%66;
        printf("%d\n",n);
        int i=0,value_final=0;
        for(i=n-4;i<=n;i++){
            value_final+=i*i;
            ++i;
        printf("%d %d\n",i,value_final);
        }
    }
}
/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/