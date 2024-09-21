/******************************************* 
Intro
********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Home {
    char name[50];
    char username[50];
    char password[50];
};

struct Login {
    char Username[50];
    char Passuwu[50];
};

void signup(void);
void cleanConsole();
int signIn(struct Login login, char *name);

const char *usersFile = "UserInfo.txt";

int main() {
    int choice;
    int Bhaago = 1;
    struct Login login;
    char userName[50];

    puts("Hola Fella!");
    puts("Welcome to UIU Info Desk");
    
    while (Bhaago==1) {
        puts("");
        puts("[1]\tLogin\n[2]\tSign Up\n[3]\tExit");
        printf("Type option: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter your username: ");
            scanf(" %[^\n]", login.Username);
            printf("Enter your password: ");
            scanf(" %[^\n]", login.Passuwu);
            if (signIn(login, userName)) {
                printf("Login successful! Welcome, %s!\n", userName);
                Bhaago=0;
            } else {
                printf("Invalid username or password.\n");
            }
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
    struct Home user;
    FILE *file = fopen(usersFile, "a");

    // Input user information
    printf("Enter your name: ");
    scanf(" %[^\n]", user.name); // Read string with spaces
    printf("Enter your username: ");
    scanf(" %[^\n]", user.username);
    printf("Enter your password: ");
    scanf(" %[^\n]", user.password);

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Write user information to the file
    fprintf(file, "Name: %s\nUsername: %s\nPassword: %s\n", user.name, user.username, user.password);

    fclose(file);
    cleanConsole();
    printf("Signup successful!\n");
    printf("Welcome to UIU %s! Please Login to explore.\n", user.name);
}

void cleanConsole() {
    printf("\033[H\033[J");
}

int signIn(struct Login login, char *name) {
    FILE *file = fopen(usersFile, "r");
    char fileName[50];
    char fileUsername[50];
    char filePassword[50];

    if (file == NULL) {
        printf("Error opening file!\n");
        return 0; // Indicate error
    }

    // Read and check each line in the file
    while (fscanf(file, "Name: %[^\n]\nUsername: %49s\nPassword: %49s\n", fileName, fileUsername, filePassword) != EOF) {
        if (strcmp(login.Username, fileUsername) == 0 && 
            strcmp(login.Passuwu, filePassword) == 0) {
            strcpy(name, fileName); // Copy the name to the provided variable
            fclose(file);
            return 1; // Credentials match
        }
    }

    fclose(file);
    return 0; // Credentials do not match
}

/******************************************* 
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
********************************************/
