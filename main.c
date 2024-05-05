#include <stdio.h>

// Function to display propmt 
void displayPrompt(){
    printf("> ");
}

// Function to read user input
char* getUserInput(){
    char* input = (char*)malloc(sizeof(char) * 100);
    fgets(input,100,stdin);
    return input;
}

// Function to parse user input 
void parseInput(char* userInput,char* command, char* parameter){
    sscanf(userInput,"%s %s",command,parameter);
}

// Function to execute command 
void executCommand(char* command,char* parameter){
    printf("Executing command : %s %s\n",command,parameter);
}
// Function to handle invalid input
void displayErrorMessage(){
    printf("Error: Invalid input\n");
}
int main(){
    char command[50];
    char parameter[50];
    while (1)
    {
        displayPrompt();
        char* userInput = getUserInput();
        if(sscanf(userInput,"%s %s",command,parameter) == 2)
    }
    

    return 0;
}