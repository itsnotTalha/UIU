#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_OPTIONS 6
#define MAX_TRIMESTER 12

const char *LoginInfo = "loginInfo.txt";
const char *About = "AboutUIU.txt";

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
struct Option {
    char name[50];          
    const char *file;
};

int loginpage ();
int sign_in ();
int sign_up ();
int Homepage ();
void cleanConsole();
int logout();
int feature_list ();
void about_uiu ();
int subMenu();
void trimesterList();
int backto ();

int main(void){
    struct SignIn signin;
    cleanConsole();
    if(!loginpage()){
        int wheel=1;
        while(wheel){
        Homepage();
            }
        }
    //else if(loginpage()){}    
    //cleanConsole();
}
int Homepage (){
    int wheel=1;
    while (wheel)
    {
        puts("");
    puts("----------FEATURES----------");
    switch (feature_list())
        {
    case 1:
        cleanConsole();
        about_uiu();
        if(backto())
        wheel=1;
        break;
    case 2:
        cleanConsole();
        subMenu();
        if(backto())
        wheel=1;
        break;
    case 0:
    logout();
    default:
    puts("Not a 'VALID' input.");
        }
    }
}
int backto(){
    int option;
    puts("");
    puts("");
    puts("[1] Back to Home");
    puts("[0] EXIT");
    printf("SELECT_:");

    scanf("%d",&option);
    switch (option)
    {
    case 0:
    puts("");
    puts("");
    logout();
        break;
    case 1:
    cleanConsole();
        return 0;
    default:
    puts("INVALID option");
        break;
    }
}
int subMenu (){
    int choice;
    int trimChoice;
    struct Option options[] = {
        {"CSE", "cse.txt"},
        {"EEE", "eee.txt"},
        {"DS", "ds.txt"},
        {"BBA", "bba.txt"},
        {"EDS", "eds.txt"},
        {"MSJ", "msj.txt"}
    };
    puts("----------[AVAILABLE SUBJECTS]----------");
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("[%d] %s\n", i + 1, options[i].name);
    }
     while (1) {  // Loop until a valid choice is made
        printf("Select to learn more: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_OPTIONS) {
            printf("Invalid choice. Please try again.\n");
        } else {
            cleanConsole();
            break;}
    }
     trimesterList();
     scanf("%d",&trimChoice); 
   cleanConsole();
  // trimesterWisedCourses(trimChoice,options[choice-1].file);
}
void trimesterList () {
    puts("Select your Desired trimester to get offered course list:");
    for(int i = 1; i <= 12; i++) {
        printf("[%d]\tTrimester %d\n", i, i);
    }
}
void about_uiu (){
    FILE *file = fopen(About, "r");
 if (file == NULL) {
        printf("Error opening file: %s\n", About);
        return;
    }
    puts("");
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }

    fclose(file);
}
int feature_list (){
    int option;
    puts("[1] About UIU");
    puts("[2] Available Subjects");
    puts("[0] EXIT");
    printf("SELECT_:");
    scanf("%d",&option);
    return option;
}
int logout (){
     int cmd;
    puts("You wanna leave me?");
    puts("[0] YES\n[1] NO");
    printf("SELECT :");
    scanf("%d", &cmd);
    if (cmd == 0) {
        cleanConsole();
        puts("I will miss you.");
        exit(0); // End the program
    } else {
        cleanConsole();
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
     while (fscanf(loginFile, "%s %s %s", signin.signup.Name, signin.signup.username, signin.signup.password) != EOF) {
     if (strcmp(signin.login.username, signin.signup.username) == 0 &&
            strcmp(signin.login.password, signin.signup.password) == 0) {
            strcpy(Username, signin.signup.Name); // Copy the user's name
            fclose(loginFile);
            cleanConsole();
            printf("Welcome Back, ");
            puts(Username);
      return 0;
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