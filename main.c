#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to display propmt 
void displayPrompt(){
    printf("> ");
}

// Function to parse user input 
void parseInput(char* userInput,char* command, char* parameter){
    sscanf(userInput,"%s %s",command,parameter);
    for(int i=0;i<command[i];i++){
        command[i] = tolower(command[i]);
    }
}

// Function to execute command 
void executCommand(char* command,char* parameter){
    if(strcmp(command,"create") == 0){
        createFile(parameter);
    }else{
        printf("Executing command: %s \"%s\"\n", command, parameter);
    }
}
// Function to handle invalid input
void displayErrorMessage(){
    printf("Error: Invalid input\n");
}

// Function Create File 
void createFile(const char* filename){
    FILE* file = fopen(filename,"w");
    if(file != NULL){
        fclose(file);
        printf("File '%s' created successfully.\n", filename);
    }else{
        printf("Error: Unable to create file '%s'.\n", filename);
    }
}

int main(){
    char userInput[100];
    char command[50];
    char parameter[50];
    while (1)
    {
        displayPrompt();
        fgets(userInput,sizeof(userInput),stdin);
        userInput[strcspn(userInput,"\n")] = '\0';

        if(sscanf(userInput,"%s %s",command,parameter) == 2){
            parseInput(userInput,command,parameter);
            executCommand(command,parameter);
        }else{
            displayErrorMessage();
        }
    }
    return 0;
}