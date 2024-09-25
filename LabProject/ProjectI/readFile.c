#include <stdio.h>
#include <string.h>

const char *About = "AboutUIU.txt";

void fileReader(const char *filename, const char *keyword, int maxOccurrences)
{
    FILE *file = fopen(About, "r");
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
            if (occurrences == maxOccurrences+1)
            {
                break;
            }
        }else if (occurrences>=maxOccurrences) {
             printf("%s", line);
        }
    }

    fclose(file);
}

int main()
{
    const char *filename = "example.txt";
    const char *keyword = "Stop";
    int maxOccurrences = 3;

    fileReader(filename, keyword, maxOccurrences);
    return 0;
}