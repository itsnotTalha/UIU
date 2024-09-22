#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_OPTIONS 6
#define MAX_TRIMESTER 12

const char *LoginInfo = "loginInfo.txt";
    struct Signup
    {
        char Name[50];
        char username[50];
        char password[50];
    };
    struct Login
    {
        char username[50];
        char password[50];
    };       
struct SignIn
{
    struct Signup signup;
    struct Login login;
};

int loginpage ();
int sign_in ();
int sign_up ();
void cleanConsole();
int logout();

int main(void){
    cleanConsole();
    if(!loginpage()){
        printf("Login successful.");
        }
    //else if(loginpage()){}    
    //cleanConsole();
}
int logout (){
     int cmd;
    puts("You wanna leave me?");
    puts("[0] YES\n[1] NO");
    scanf("%d", &cmd);
    if (cmd == 0) {
        puts("I will miss you.");
        exit(0); // End the program
    } else {
        puts("I know you love me.");
    }
}

int loginpage(){
    int input;
    int wheel=1;
    while(wheel){
    puts("[1] LOGIN");
    puts("[2] SIGN UP");
    puts("[0] EXIT");
    printf("\nSELECT :");
    scanf("%d",&input);
    if(input==1){
        if(sign_in()==0){
            wheel=0;
            return 0;
        }
        
    }
    else if(input==2){
        if(!sign_up()){
            cleanConsole();
            puts("Registration Completed Successfully!");
            puts("Login to continue...");
            }
        }
    else if(input==0){
            logout();
        }
    }
}
int sign_in (){
    struct SignIn signin;
    FILE *loginFile= fopen(LoginInfo,"r");
    char Username[50];
      if (loginFile == NULL) {
    printf("Error opening file!\n");
    return -1;
  }
    printf("Username :");
    scanf("%s", signin.login.username);
    printf("Password :");
    scanf("%s", signin.login.password);
     while (fscanf(loginFile, "%s %s", signin.signup.username, signin.signup.password) != EOF) {
    if (strcmp(signin.login.username, signin.signup.username) == 0 &&
        strcmp(signin.login.password, signin.signup.password) == 0) {
      strcpy(Username, signin.signup.Name); // Copy the username to the provided variable
      fclose(loginFile);
      return 0; // Return 0 if credentials match
    }
  }
  fclose(loginFile);
  puts("Wrong Credential, please try again.");
  return -1;
}
int sign_up(){
  FILE *file = fopen(LoginInfo, "a");
    struct SignIn signin;

    if (file == NULL) {
    printf("Error opening file!\n");
    return -1;
    }
    printf("Enter your name: ");
    scanf(" %[^\n]", signin.signup.Name);
    printf("Enter your username: ");
    scanf(" %[^\n]", signin.signup.username);
    printf("Enter your password: ");
    scanf(" %[^\n]", signin.signup.password);
    fprintf(file,"%s %s %s\n",signin.signup.Name,signin.signup.username,signin.signup.password);
    fclose(file);
    return 0;
}
void cleanConsole(){
    printf("\033[H\033[J");
}