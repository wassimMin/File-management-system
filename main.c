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

// Function Open File
void openFile(const char* filename){
    FILE* file = fopen(filename,"r");
    if(file != NULL){

        printf("File '%s' opened successfully.\n", filename);
        char buffer[1000];
        while(fgets(buffer,sizeof(buffer),file) != NULL){
            printf("\n");
            printf("%s",buffer);
            printf("\n");
        }
        fclose(file);
    }else{
        printf("Error: Unable to open file '%s'.\n", filename);
    }
}
// Function Wrine in file 
void writeFile(const char* filename,const char* content){
    FILE* file = fopen(filename,"a");
    if(file != NULL){
        fprintf(file,"%s\n",content);
        fclose(file);
        printf("Content written to file '%s'.\n",filename);
    }else{
        printf("Error: Unable to write to file '%s'. \n",filename);
    }
}
// Delete File
void deleteFile(char* filename){
    if(remove(filename) == 0){
        printf("File '%s' deleted successfully \n",filename);
    }else{
        printf("Error: Unable to delete file '%s'. \n",filename);
    }
}
// Function to execute command 
void executCommand(char* command,char* parameter){
    if(strcmp(command,"create") == 0){
        createFile(parameter);
    }else if(strcmp(command,"open") == 0){
        openFile(parameter);
    }else if(strcmp(command,"write") == 0){
        printf("Please Enter the content you wanna write the file. Press Enter on a blank line to finish : \n");
        char content[1000];
        content[0] = '\0';
        char line[1000];
        content[1] = '\n';
        while(fgets(line,sizeof(line),stdin) != NULL){
            if(strcmp(line,"\n") == 0 || line[0] == '\0'){
                break;
            }
            strcat(content,line);
        }
        writeFile(parameter,content);
    }else if(strcmp(command,"delete") == 0){
        deleteFile(parameter);
    }else{
        printf("Executing command: %s \"%s\"\n", command, parameter);
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