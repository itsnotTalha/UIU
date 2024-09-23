/******************************************* 
Intro
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_OPTIONS 6
#define MAX_TRIMESTER 12

struct SignUp {
    char name[50];
    char username[50];
    char password[50];
};

struct Login {
    char Username[50];
    char Passuwu[50];
};

struct Option {
    char name[50];          
    const char *file;
};

void login();
void signup(void);
void cleanConsole();
void taking_User_Pass (int *Bhago);
void list_of_features ();
void aboutUIU ();
void subjectLists();
void displaySubMenu();
void trimesterList ();
void trimesterWisedCourses(int option, const char *filename);


int signIn(struct Login login, char *name);

const char *usersFile = "UserInfo.txt";
const char *About = "AboutInfo.txt";
const char *subjects = "SubjectList.txt";
const char *ofrdCourse = "OfferedCourse.txt";

int main() {
    
    cleanConsole();
    puts("Hola Fella!");
    puts("Welcome to UIU Info Desk");
    login();
    
    
    return 0;
}
void login(){
    int choice;
    int Bhaago = 1;
    int *BhaagoPtr=&Bhaago;
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
        displaySubMenu();
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
    getchar();
}

void subjectLists(){
FILE *file = fopen(subjects, "r");
 if (file == NULL) {
        printf("Error opening file: %s\n", subjects);
        return;
    }
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
}

void displaySubMenu(){
    int choice;
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
    printf("Select to learn more :");
    scanf("%d", &choice);
     while (1) {
        printf("Select to learn more: ");
        scanf("%d", &choice);

        if (choice < 1 || choice > MAX_OPTIONS) {
            printf("Invalid choice. Please try again.\n");
        } else {
            break;  // Exit the loop if input is valid
        }
    }
   trimesterList();
   int trimChoice;
   scanf("%d",&trimChoice); 
   cleanConsole();
trimesterWisedCourses(trimChoice,options[choice-1].file);

}

void trimesterList () {
    puts("Select your Desired trimester to get offered course list:");
    for(int i = 1; i <= 12; i++) {
        printf("[%d]\tTrimester %d\n", i, i);
    }
}

void trimesterWisedCourses(int option, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int currentTrimester = 0; 
    int isInTrimester = 0; 
    int trimesterFound = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        
         // Check for "Trimester" header
        if (strstr(line, "Trimester") != NULL) {
            currentTrimester++;

            // If we've reached the desired trimester, print the header
            if (currentTrimester == option) {
                isInTrimester = 1;
                trimesterFound = 1;
                printf("%s", line);
                continue; // Continue to print the following lines
            } else {
                if (isInTrimester) {
                    // If we are in a previously found trimester, we stop printing
                    break; 
                }
            }
        }

        // Print lines only if we are in the requested trimester
        if (isInTrimester) {
            printf("%s", line);
        }
    }
    fclose(file);
}


/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/
