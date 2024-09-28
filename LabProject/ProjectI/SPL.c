#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *url = "https://www.facebok.com";

    // Construct the command to open the URL in the default web browser
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

    return 0;
}
