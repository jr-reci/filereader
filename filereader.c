#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void readFile(FILE* fp);     //function reads file and seperates three sections of info: name, age and grade until the end of the file
int checkgrade(char* GRADE); //function takes in grade from the readfile and outputs if the student has passed or failed

int main(){
    
    char* fileName;
    printf("\nInput name of file to be analysed:\t");
    scanf("%s",fileName);
    printf("\n");

    FILE* fp = fopen(fileName,"r");

    if(fp==NULL){
        printf("error opening file\n");
        exit(1);
    }

    readFile(fp);
    
    return(0);
}

void readFile(FILE* fp){
    char name[20];
    int age;
    char grade[2];
    while( fscanf(fp,"%s %d %s \n", name, &age, grade)!=EOF){////splits up each line into two strings and an integer
        if(checkgrade(grade)==1){                                                       //using checkgrade one of two statements is printed depending on the grade
            printf("Name: %s\tAge: %d\tGrade: %s Outcome: PASS\n", name, age, grade);
        }
        else{
            printf("Name: %s\tAge: %d\tGrade: %s Outcome: Fail\n", name, age, grade);
        } 
    }
}

int checkgrade(char* GRADE){
//grade is compared with the letters A and B and if they match this results
//in a pass which returns a value that tells programm 
//to print out the student info and their outcome

    if(strcmp(GRADE,"A")==0){
        return(1);
    }
    else 
    if(strcmp(GRADE,"B")==0){
        return(1);
    }
    else{
        return(0);
    }

}