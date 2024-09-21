/******************************************* 
Intro
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SignUp {
    char name[50];
    char username[50];
    char password[50];
};

struct Login {
    char Username[50];
    char Passuwu[50];
};

struct Trimester {
    char name[50];          
    const char *file;
};


void signup(void);
void cleanConsole();
void taking_User_Pass (int *Bhago);
void list_of_features ();
void aboutUIU ();
void subjectLists();
void trimesterWisedCourses(int opt);

int signIn(struct Login login, char *name);

const char *usersFile = "UserInfo.txt";
const char *About = "AboutInfo.txt";
const char *subjects = "SubjectList.txt";
const char *ofrdCourse = "OfferedCourse.txt";

int main() {
    int choice;
    int Bhaago = 1;
    int *BhaagoPtr=&Bhaago;
    cleanConsole();
    puts("Hola Fella!");
    puts("Welcome to UIU Info Desk");
    
    while (Bhaago==1) {
        puts("");
        puts("[1]\tLogin\n[2]\tSign Up\n[3]\tExit");
        printf("\nType option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            taking_User_Pass(BhaagoPtr);
        } else if (choice == 2) {
            signup();
        } else if (choice == 3) {
            cleanConsole();
            puts("Take care until we meet again...");
            Bhaago = 0;
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void signup(void) {
    struct SignUp user;
    FILE *file = fopen(usersFile, "a");

    printf("Enter your name: ");
    scanf(" %[^\n]", user.name);
    printf("Enter your username: ");
    scanf(" %[^\n]", user.username);
    printf("Enter your password: ");
    scanf(" %[^\n]", user.password);

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "Name: %s\nUsername: %s\nPassword: %s\n", user.name, user.username, user.password);

    fclose(file);
    cleanConsole();
    printf("Signup successful!\n");
    printf("Welcome to UIU %s! Please Login to explore.\n", user.name);
}

void cleanConsole() {
    printf("\033[H\033[J");
}

void taking_User_Pass (int *Bhago){
    struct Login login;
    char userName[50];
    printf("Enter your username: ");
            scanf(" %[^\n]", login.Username);
            printf("Enter your password: ");
            scanf(" %[^\n]", login.Passuwu);
            if (signIn(login, userName)) {
                cleanConsole();
                printf("Login successful!\nWelcome, %s!\nLet's Explore-\n", userName);
                list_of_features ();
                *Bhago=0;
            } else {
                printf("Invalid username or password.\n");
            }
}


int signIn(struct Login login, char *name) {
    FILE *file = fopen(usersFile, "r");
    char fileName[50];
    char fileUsername[50];
    char filePassword[50];

    if (file == NULL) {
        printf("Error opening file!\n");
        return 0; 
    }

    while (fscanf(file, "Name: %[^\n]\nUsername: %49s\nPassword: %49s\n", fileName, fileUsername, filePassword) != EOF) {
        if (strcmp(login.Username, fileUsername) == 0 && 
            strcmp(login.Passuwu, filePassword) == 0) {
            strcpy(name, fileName);
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0; // Credentials do not match
}

void list_of_features (){
    int wheel=1;
    int feature1;
    puts("[1]\tAbout UIU");
    puts("[2]\tAvailable Subjects");
    printf("Your option :");
    scanf("%d",&feature1);
    while(wheel)
        {
    switch (feature1){
    case 1:
    cleanConsole();
        aboutUIU ();
        wheel=0;
        break;
    case 2: 
    cleanConsole();
        subjectLists();
        wheel=0;
        break;
    default:
        puts("Invalid input");
        break;
    }
        }
}

void aboutUIU (){
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

void subjectLists(){
FILE *file = fopen(subjects, "r");
 if (file == NULL) {
        printf("Error opening file: %s\n", subjects);
        return;
    }
    puts("----------[AVAILABLE SUBJECTS]----------");
    char line[256];
    int count=1;
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("[%d] %s",count++, line);
    }
    fclose(file);
puts("");
int option;
printf("Enter index Number to learn more- ");
scanf("%d", &option);
trimesterWisedCourses(option);
}

void trimesterWisedCourses(int opt){
FILE *file = fopen(subjects, "r");
FILE *file2 = fopen(ofrdCourse, "r");
if (file == NULL) {
        printf("Error opening file: %s\n", subjects);
        return;
    }
if (file2 == NULL) {
        printf("Error opening file: %s\n", ofrdCourse);
        return;
    }
    char line[256];
    int count=1;
    while (fgets(line, sizeof(line), file) != NULL) {
        if(count==opt)
        printf("%s\n", line);
        count++;
        }
    fclose(file);
    cleanConsole();
    puts("Select your Desired trimester to get offered course list-");
    for(int i=1;i<=12;i++){
        printf("[%d]\tTrimester %d",i,i);
        puts("");
    }
    int option;
    scanf("%d",&option);
cleanConsole();
    char line2[256];
    int currentTrimester = 0; 
    int inTrimester = 0; 

    while (fgets(line2, sizeof(line2), file2) != NULL) {
        if (strstr(line2, "Trimester") != NULL) {
            currentTrimester++;
            if (currentTrimester == option) {
                inTrimester = 1; 
                printf("%s", line2); 
                continue; // Go to the next line
            } else {
                inTrimester = 0;
            }
        }

        // Print lines only if we are in the requested trimester
        if (inTrimester) {
            printf("%s", line2); // Print the line
        }
    }
    fclose(file2);
}


/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/
