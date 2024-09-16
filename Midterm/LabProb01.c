/******************************************* 
Write a program in C to count occurrences of a word in a string. 
********************************************/
#include <stdio.h>
int countStr(char a[]){
    int count=0;
    while(a[count]!='\0'){
        count++;
    }
    return count;
}
void countOccurs(char A[], char B[]) {
    int count = 0;
    int lenA = countStr(A);
    int lenB = countStr(B);

    for (int i = 0; i <= lenA - lenB; i++) {
        int j = 0;
        while (j < lenB && A[i + j] == B[j]) {
            j++;
        }

        if (j == lenB) {
            int before = (i == 0) || (A[i - 1] == ' ');
            int after = (i + lenB == lenA) || (A[i + lenB] == ' ');
            if (before && after) {
                count++;
            }
        }
    }

    printf("%d\n", count);
}
int main() {
    char str[100];
    char str2[50]; 
    printf("Enter a string: ");
    scanf("%[^\n]", str); 
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF); 
    printf("Enter the word: ");
    scanf("%[^\n]", str2); 
    countOccurs(str,str2);
    return 0;
}
/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/