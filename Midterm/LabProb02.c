/******************************************* 
Write a program in C to reverse the words in a string.
********************************************/
#include<stdio.h>
int countStr(char a[]){
    int count=0;
    while(a[count]!='\0'){
        count++;
    }
    return count;
}
int main(){
    char str[100];
    char str2[100][100]; 
    printf("Enter a string: ");
    scanf("%[^\n]", str);
    int k = 0, j = 0;

  for (int i = 0; i <= countStr(str); i++) {
        if (str[i] != ' ' && str[i] != '\0') {
            str2[k][j++] = str[i];
        } else {
            if (j > 0) { 
                str2[k][j] = '\0';
                k++;
                j = 0;
            }
        }
    }
    for (int i=k-1; i>=0; i--) {
        printf("%s ", str2[i]);
    }
}
/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/