#define _CRT_SECURE_NO_WARNINGS
#include "File.h"
#include "DayWork.h"

char* makeWorkToString(Work* w) {
    char* str = (char*)calloc(15, sizeof(char));
    // Add function that return if statment in work as a string
    // cmpcat to -str- and finally return the pointer of -str-
    // don't forget to free the pointer in the second function (after using the text in the string).
}

void openFile() {
    //char data[DATA_SIZE];
    char data[DATA_SIZE] = "This is a test\nNew line.";

    /* File pointer to hold reference to our file */
    FILE* fPtr;


    /*
     * Open file in w (write) mode.
     * "data/file1.txt" is complete path to create file
     */
    fPtr = fopen("//Mac/Home/Desktop/visual_studio_projects/Check_Wolt/file.txt", "w");


    /* fopen() return NULL if last operation was unsuccessful */
    if (fPtr == NULL)
    {
        /* File not created hence exit */
        printf("Unable to create file.\n");
        exit(EXIT_FAILURE);
    }


    /* Input contents from user to store in file */
    /*printf("Enter contents to store in file : \n");
    fgets(data, DATA_SIZE, stdin);*/
    


    /* Write data to file */
    fputs(data, fPtr);


    /* Close file to save file data */
    fclose(fPtr);


    /* Success message */
    printf("File created and saved successfully. :) \n");
}

void printFile() {
    FILE* ptr;
    char ch;

    // Opening file in reading mode
    ptr = fopen("//Mac/Home/Desktop/visual_studio_projects/Check_Wolt/DB/22022022.txt", "r");

    if (NULL == ptr) {
        printf("file can't be opened \n");
    }

    printf("content of this file are \n");

    // Printing what is written in file
    // character by character using loop.
    do {
        ch = fgetc(ptr);
        printf("%c", ch);

        // Checking if character is not EOF.
        // If it is EOF stop eading.
    } while (ch != EOF);

    // Closing the file
    fclose(ptr);
}