#include <stdio.h>
#include <stdlib.h>

#define MAX_FILENAME_LENGTH 100
#define BUFFER_SIZE 1024

int main() 
{
    char sourceFilename[MAX_FILENAME_LENGTH];
    char destinationFilename[MAX_FILENAME_LENGTH];
    FILE *sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    printf("Enter the source file name: ");
    scanf("%s", sourceFilename);

    sourceFile = fopen(sourceFilename, "r");
    
    if (sourceFile == NULL) 
    {
        perror("Error opening source file");
        return 1;
    }

    printf("Enter the destination file name: ");
    scanf("%s", destinationFilename);

    destinationFile = fopen(destinationFilename, "w");

    if (destinationFile == NULL) 
    {
        perror("Error opening destination file");
        fclose(sourceFile);
        return 1;
    }

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0) 
    {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    fclose(sourceFile);
    fclose(destinationFile);

    printf("File copied successfully.\n");

    return 0;
}
