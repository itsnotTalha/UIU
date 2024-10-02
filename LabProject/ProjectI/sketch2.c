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
const char *circular = "Circular.txt";
const char *uiuWeb = "https://www.facebok.com";

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
struct Apply
{
    char name[50];
    char fathername[50];
    char mothername[50];
    float hscResult;
    int passingYear;
    char regID[20];
    char rollNum[20];
    float sscResult;
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
void linkFollower (const char *url);
int programIns(int a);
int applicationForm ();

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
            switch (linePrinter(Courselist))
            {
                case 1: 
                trimesterList();
                fileReader ("CourseList\\cse.txt", "Trimester", takeInput());
                break;
                case 2:
                trimesterList();
                fileReader ("CourseList\\eee.txt", "Trimester", takeInput());
                break;
                case 3:
                trimesterList();
                fileReader ("CourseList\\ds.txt", "Trimester", takeInput());
                break;
                case 4:
                trimesterList();
                fileReader ("CourseList\\bba.txt", "Trimester", takeInput());
                break;
                case 5:
                trimesterList();
                fileReader ("CourseList\\ais.txt", "Trimester", takeInput());
                break;
                case 6:
                trimesterList();
                fileReader ("CourseList\\bse.txt", "Trimester", takeInput());
                break;
                default:
                puts("Not a 'VALID' input.");
            }

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
        case 1: fileReader(tuiFee,"CSE", Occurs);

            break;
        case 2:
                fileReader(tuiFee, "EEE", Occurs);
            break;
        case 3:
                fileReader(tuiFee, "DS", Occurs);
            break;
        case 4:
                fileReader(tuiFee, "BBA", Occurs);
            break;
        case 5:
                fileReader(tuiFee, "AIS", Occurs);
            break;
        case 6:
                fileReader(tuiFee, "BSE", Occurs);
            break;
        
        default:
            puts("Not a 'VALID' input.");   
            break;
        }
            if (backto())
                wheel = 1;
            break;
        case 5:
        cleanConsole(); 
        puts("<<<<<<<<< [Programs] >>>>>>>>>");
        puts("[1] Undergraduate");
        puts("[2] Graduate");
        programIns(takeInput());

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
int programIns(int a)
{
        puts("[1] Ongoing Circular");
        puts("[2] Eligibility Check (Direct Admission)");
        puts("[3] Apply Now");
        switch (takeInput())
        {
            case 1:
            cleanConsole();
            linePrinter(circular);
            break;
            case 2:
            cleanConsole();
            printf("Enter your HSC GPA :");
            if(takeInput()==5){
                puts("Youre eligible for direct admission.");
            }else {
                puts("Youre not eligible for direct admission.");
                break;
            }
            case 3: 
            cleanConsole();
            puts("[1] Online Application");
            puts("[2] Offline Application");
            switch (takeInput())
            {
                case 1:
                linkFollower(uiuWeb);
                break;
                case 2:
                if(applicationForm()==0){
                    puts("You've Successfully applied for this program!");
                }else{
                    puts("Something went wrong:'(");
                }
                break;
                default:
                puts("Invalid Input");
            }
        }
}
int applicationForm ()
{
    struct Apply apply;
    puts("[1]. Full name:");
    scanf(" %[^\n]", apply.name);
    puts("[2]. Father name:");
    scanf(" %[^\n]", apply.fathername);
    puts("[3]. Mother name:");
    scanf(" %[^\n]", apply.mothername);
    puts("[4]. HSC Registration Number:");
    scanf(" %[^\n]", apply.regID);
    puts("[5]. HSC Roll Number:");
    scanf(" %[^\n]", apply.rollNum);
    puts("[6]. HSC Result:");
    scanf("%f", &apply.hscResult);
    puts("[7]. HSC passing year:");
    scanf("%d", &apply.passingYear);
    puts("[8]. SSC Result:");
    scanf("%f", &apply.sscResult);

 FILE *file = fopen("application_data.txt", "a");  // Use "a" to append to the file
    if (file == NULL) {
        perror("Error opening file");
        return 1;  // Return an error code
    }

    // Write the information to the file
    removeSpaces(apply.name);
    removeSpaces(apply.fathername);
    removeSpaces(apply.mothername);
    fprintf(file, "Full Name: %s\n", apply.name);
    fprintf(file, "Father Name: %s\n", apply.fathername);
    fprintf(file, "Mother Name: %s\n", apply.mothername);
    fprintf(file, "HSC Registration Number: %s\n", apply.regID);
    fprintf(file, "HSC Roll Number: %s\n", apply.rollNum);
    fprintf(file, "HSC Result: %.2f\n", apply.hscResult);
    fprintf(file, "HSC Passing Year: %d\n", apply.passingYear);
    fprintf(file, "SSC Result: %.2f\n", apply.sscResult);
    fprintf(file, "-------------------------\n");

    // Close the file
    fclose(file);

    return 0;  // Return success

}
void linkFollower (const char *url)
{
    #ifdef _WIN32
        // For Windows
        puts("Opening your browser...");
        char command[256];
        snprintf(command, sizeof(command), "start %s", url);
        system(command);
    #else
        // For Linux or macOS
        char command[256];
        snprintf(command, sizeof(command), "xdg-open %s", url);
        system(command);
    #endif
}
void fileReader(const char *filename, const char keyword[], int Occurs)
{
    cleanConsole();
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
        if (occurrences == Occurs && strstr(line,"Trimester"))
            {
                printf("%s", line);
                continue; // Continue to print the following lines
            }
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
    int count=0;
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
            printf("[%d]. %s\n", ++count, line);
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
    cleanConsole();
    puts("Select to get offered course list:");
    for (int i = 1; i <= 12; i++)
    {
        printf("[%d]\tTrimester %d\n", i, i);
    }
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
    puts("[4] Tuition Fee");
    puts("[5] Admission Procedure");
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
    printf("\nAwaiting your input:");
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
