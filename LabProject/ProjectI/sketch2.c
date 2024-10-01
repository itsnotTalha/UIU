#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_OPTIONS 6
#define MAX_TRIMESTER 12

const char *LoginInfo = "loginInfo.txt";
const char *About = "AboutUIU.txt";
const char *Courselist = "Courses.txt";
const char *Faclist = "FacultyList\\FacultyList.txt";
const char *tuiFee = "Tuitionfee.txt";

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
struct Option
{
    char name[50];
    const char *file;
};

int loginpage();
int sign_in();
int sign_up();
int Homepage();
void cleanConsole();
int logout();
int takeInput();
int feature_list();
void about_uiu();
int subMenu();
void trimesterList();
int backto();
void removeSpaces(char *str);
void selectTrimesterAndCourses(int choice, struct Option options[]);
void printFiles(int option, char string[], const char *filename);
void fileReader(const char *filename, const char keyword[], int Occurs);
int linePrinter(const char *getfile);

int main(void)
{
    struct SignIn signin;
    // cleanConsole();
    if (!loginpage())
    {
        int wheel = 1;
        while (wheel)
        {
            Homepage();
        }
    }
}
int Homepage()
{
    int wheel = 1;
    while (wheel)
    {
        puts("");
        puts("<<<<<<<<<< [FEATURES] >>>>>>>>>>");
        switch (feature_list())
        {
        case 1:
            cleanConsole();
            about_uiu();
            if (backto())
                wheel = 1;
            break;
        case 2:
            cleanConsole();
            struct Option options[] = {
                {"CSE", "cse.txt"},
                {"EEE", "eee.txt"},
                {"DS", "ds.txt"},
                {"BBA", "bba.txt"},
                {"AIS", "ais.txt"},
                {"BSE", "bse.txt"}};

            int numOptions = sizeof(options) / sizeof(options[0]);
            selectTrimesterAndCourses(subMenu(options, numOptions), options);

            if (backto())
                wheel = 1;
            break;
        case 3:
            cleanConsole();
            int Occurs = 1;
            switch (linePrinter(Courselist))
            {
            case 1:
                fileReader(Faclist, "CSE", Occurs);
            fileReader("FacultyList\\DetCSE.txt", "FAC", takeInput());
                break;
            case 2:
                fileReader(Faclist, "EEE", Occurs);
            fileReader("FacultyList\\DetEEE.txt", "FAC", takeInput());
                break;
            case 3:
                fileReader(Faclist, "DS", Occurs);
            fileReader("FacultyList\\DetCSE.txt", "FAC", takeInput());
                break;
            case 4:
                fileReader(Faclist, "BBA", Occurs);
            fileReader("FacultyList\\DetBBA.txt", "FAC", takeInput());
                break;
            case 5:
                fileReader(Faclist, "AIS", Occurs);
            fileReader("FacultyList\\DetBBA.txt", "FAC", takeInput());
                break;
            case 6:
                fileReader(Faclist, "BSE", Occurs);
            fileReader("FacultyList\\DetBSE.txt", "FAC", takeInput());
                break;
             default:
            puts("Not a 'VALID' input.");   
            }
            if (backto())
                wheel = 1;
            break;
        case 4:
        Occurs=1;
        cleanConsole(); 
        switch (linePrinter(Courselist))
        {
        case 1: fileReader("Tuitionfee.txt","CSE", Occurs);

            break;
        case 2:
                fileReader(tuiFee, "EEE", Occurs);
            break;
        
        default:
            puts("Not a 'VALID' input.");   
            break;
        }
            if (backto())
                wheel = 1;
            break;
        case 0:
            logout();
        default:
            puts("Not a 'VALID' input.");
        }
    }
}
void fileReader(const char *filename, const char keyword[], int Occurs)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Not able to open the file.");
    }
    char line[256];
    int occurrences = 0;
    while (fgets(line, sizeof(line), file))
    {
        if (strstr(line, keyword) != NULL)
        {
            occurrences++;
            // Stop if we reached the max occurrences
            if (occurrences == Occurs+1)
            {
                break;
            }
        }
        else if (occurrences >= Occurs)
        {
            printf("%s", line);
        }
    }

    fclose(file);
}
int linePrinter(const char *getfile)
{
    char line[256];
    FILE *file = fopen(getfile, "r");
    if (file == NULL)
    {
        perror("Error opening file");
    }

    // Read and print each line using a for loop
    for (int i = 0; fgets(line, sizeof(line), file) != NULL; i++)
    {
        if (i == 0)
        {
            printf("%s", line);
        }
        else
        {
            printf("[%d]. %s", i, line);
        }
    }

    // Close the file
    fclose(file);
    int temp;
    printf("\nChoose your option :");
    scanf("%d", &temp);
    return temp; 
}
int backto()
{
    int option;
    puts("\n---------------------------");
    puts("---------------------------");
    puts("[1] Back to Home");
    puts("[0] EXIT");
    printf("SELECT_:");

    scanf("%d", &option);
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
// int subFacultySubmenu(){}

int subMenu(struct Option options[], int numOptions)
{
    int choice, trimChoice;
    puts("<<<<<<<<<<[AVAILABLE SUBJECTS]>>>>>>>>>>");
    for (int i = 0; i < numOptions; i++)
    {
        printf("[%d] %s\n", i + 1, options[i].name);
    }
    while (1)
    {
        printf("Select to learn more: ");
        scanf("%d", &choice);
        if (choice < 1 || choice > numOptions)
        {
            printf("Invalid choice. Please try again.\n");
        }
        else
        {
            cleanConsole();
            return choice - 1;
            break;
        }
    }
}
void selectTrimesterAndCourses(int choice, struct Option options[])
{
    int trimChoice;
    trimesterList();
    scanf("%d", &trimChoice);
    cleanConsole();
    printFiles(trimChoice, "Trimester", options[choice - 1].file);
}

void printFiles(int option, char string[], const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return;
    }

    char line[256];
    int currentTrimester = 0;
    int isInTrimester = 0;
    int trimesterFound = 0;

    while (fgets(line, sizeof(line), file) != NULL)
    {

        // Check for "Trimester" header
        if (strstr(line, string) != NULL)
        {
            currentTrimester++;

            // If we've reached the desired trimester, print the header
            if (currentTrimester == option)
            {
                isInTrimester = 1;
                trimesterFound = 1;
                printf("%s", line);
                continue; // Continue to print the following lines
            }
            else
            {
                if (isInTrimester)
                {
                    // If we are in a previously found trimester, we stop printing
                    break;
                }
            }
        }

        // Print lines only if we are in the requested trimester
        if (isInTrimester)
        {
            printf("%s", line);
        }
    }
    fclose(file);
}

void trimesterList()
{
    puts("Select your Desired trimester to get offered course list:");
    for (int i = 1; i <= 12; i++)
    {
        printf("[%d]\tTrimester %d\n", i, i);
    }
    printf("\nSELECT_:");
}
void about_uiu()
{
    FILE *file = fopen(About, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", About);
        return;
    }
    puts("");
    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch);
    }

    fclose(file);
}
int feature_list()
{
    int option;
    puts("[1] About UIU");
    puts("[2] Available Subjects");
    puts("[3] Faculty Details");
    puts("[3] Tuition Fee");
    puts("[0] EXIT");
    printf("SELECT_:");
    scanf("%d", &option);
    return option;
}
int logout()
{
    int cmd;
    puts("You wanna leave me?");
    puts("[1] YES\n[0] NO");
    printf("SELECT :");
    scanf("%d", &cmd);
    if (cmd == 1)
    {
        cleanConsole();
        puts("I will miss you.");
        exit(0); // End the program
    }
    else
    {
        cleanConsole();
        puts("I know you love me.");
    }
}

int loginpage()
{
    int input;
    int wheel = 1;

    while (wheel)
    {
        puts("[1] LOGIN");
        puts("[2] SIGN UP");
        puts("[0] EXIT");
        printf("\nSELECT: ");

        if (scanf("%d", &input) != 1)
        {
            cleanConsole();
            printf("Invalid input. Please enter an integer.\n");
            // Clear the input buffer
            while (getchar() != '\n')
                ;     // discard invalid input
            continue; // Prompt the user again
        }

        switch (input)
        {
        case 1:
            if (sign_in() == 0)
            {
                wheel = 0; // Exit loop on successful login
                return 0;  // Return to caller
            }
            else
            {
                printf("Login failed. Please try again.\n");
            }
            break;

        case 2:
            if (!sign_up())
            {
                cleanConsole();
                puts("Registration Completed Successfully!");
                puts("Login to continue...");
            }
            else
            {
                printf("Registration failed. Please try again.\n");
            }
            break;

        case 0:
            logout();
            wheel = 0; // Exit loop after logout
            break;

        default:
            printf("Invalid selection. Please try again.\n");
            break;
        }
    }

    return 1; // Optionally return a status if needed
}

int sign_in()
{
    struct SignIn signin;
    FILE *loginFile = fopen(LoginInfo, "r");
    char Username[50];

    if (loginFile == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }

    cleanConsole();
    printf("USERNAME : ");
    scanf("%s", signin.login.username);
    printf("PASSWORD : ");
    scanf("%s", signin.login.password);

    char line[256];
    while (fgets(line, sizeof(line), loginFile))
    {
        // Adjust the format for your specific case
        if (sscanf(line, "%49s %49s %49s",
                   signin.signup.Name, signin.signup.username, signin.signup.password) == 3)
        {
            if (strcmp(signin.login.username, signin.signup.username) == 0 &&
                strcmp(signin.login.password, signin.signup.password) == 0)
            {
                strcpy(Username, signin.signup.Name); // Copy the user's name
                fclose(loginFile);
                cleanConsole();
                printf("\tWelcome Back, ");
                puts(Username);
                return 0; // Successful login
            }
        }
    }

    fclose(loginFile);
    cleanConsole();
    puts("Wrong Credential, please try again.");
    return -1;
}
int sign_up()
{
    FILE *file = fopen(LoginInfo, "a");
    struct SignIn signin;

    if (file == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }
    printf("Enter your name: ");
    scanf(" %[^\n]", signin.signup.Name);
    printf("Enter your username: ");
    scanf(" %[^\n]", signin.signup.username);
    printf("Enter your password: ");
    scanf(" %[^\n]", signin.signup.password);

    removeSpaces(signin.signup.Name);

    fprintf(file, "%s %s %s\n", signin.signup.Name, signin.signup.username, signin.signup.password);
    fclose(file);
    return 0;
}
void cleanConsole()
{
    printf("\033[H\033[J");
}
int takeInput()
{
    int input;
    printf("\nSelect to learn more :");
    scanf("%d",&input);
    cleanConsole();
    return input;
}
void removeSpaces(char *str)
{
    char temp[50];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        temp[j] = str[i]; // Add it to the temp array
        if (str[i] == ' ')
        {
            temp[j] = '_';
        }
        j++;
    }
    temp[j] = '\0';
    strcpy(str, temp); // Copy the modified string back to the original
}

/*******************************************
 * Author- Talha Jubayer
 * talhajubayer737@gmail.com
 * BSCSE@United International University
 ********************************************/
