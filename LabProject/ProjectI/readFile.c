#include <stdio.h>
#include <string.h>

const char *About = "Courses.txt";
const char *Faculty = "FacultyList.txt";
const char *FacMore= "FacultyList\\FacultyDetails.txt";
struct readFile
{
    char fileName[50];
    char *file;
};

int linePrinter(const char *getfile)
{
    char line[256];
    FILE *file = fopen(getfile, "r");
    if (file == NULL) {
        perror("Error opening file");
    }

    // Read and print each line using a for loop
    for (int i = 0; fgets(line, sizeof(line), file) != NULL; i++) {
        if (i==0){
        printf("%s", line);
        }else{
        printf("[%d]. %s", i, line);
        }
    }

    // Close the file
    fclose(file);
    int temp;
    printf("\nChoose your option :");
    scanf("%d",&temp);
    return temp;
    
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
int takeInput()
{
    int input;
    printf("\nSelect to learn more :");
    scanf("%d",&input);
    return input;
}
int main()
{
    const char *filename = About;
    int opt;
    //=linePrinter(Faculty);
    //printf("%d",opt);
    struct readFile readfile[]={
        {"VC","Faculty.txt"}
    };
    char keyword[] = "EEE";
    int Occurs = 1;
    switch(linePrinter(About)){
        case 1: fileReader(Faculty,"CSE", Occurs);
        break;
        case 2: fileReader(Faculty,"EEE",Occurs);
        break;
        case 3: fileReader(Faculty,"DS",Occurs);
        break;
        case 4: fileReader(Faculty,"BBA",Occurs);
        break;
        case 5: fileReader(Faculty,"AIS",Occurs);
        break;
        case 6: fileReader(Faculty,"BSE",Occurs);
        break;
    }
   fileReader(FacMore, "FAC", takeInput());
    return 0;
}