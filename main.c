#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void GET(char *request) ;

int main() {
    int listening = 1;

    printf("Listening ... Type QUIT to exit!\n");

    while (listening == 1) {
        char *input = malloc(100);
        gets(input);

        if (strncmp(input, "GET", 3) == 0) { //strncmp compares first 3 characters of input
            printf("\nGET REQUEST\n");
            input += 4; // trim GET from the request and following space
            GET(input);
        }
        if (strcmp(input, "QUIT") == 0 || strcmp(input, "quit") == 0) {
            printf("\nQuiting ...");
            listening = 0;
        }
    }
    return 0;
}

void GET(char *request) {
    FILE *fp;
    int c;
    fp = fopen(request, "r"); //assuming request contains the file name and extension
    if (fp) {
        while ((c = getc(fp)) != EOF)
            putchar(c);
        fclose(fp);
    } else { //file not found
        FILE *errorFP;
        errorFP = fopen("404.html", "r");
        if (errorFP) {
            while ((c = getc(errorFP)) != EOF)
                putchar(c);
            fclose(errorFP);
        }
    }
    printf("\n\n");
}