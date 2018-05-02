//
// Created by anita on 5/1/18.
// @formatter:off
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "student.h"

int main(int argc, char **argv)
{
    if(argc != 2){
        perror("ERROR: Wrong number of command line args!\n");
        return -1;
    }

    head.next = NULL; //initialize that the linked list is empty.
    FILE * file;
    file = fopen(argv[1] , "r");
    if (!file){
        perror("ERROR opening file!\n");
        return -1;
    }

    //-------------------------------------------------
    // TODO:  Change main method code BELOW

    Student *thisStudent;

    char s1[16];
    char s2[16];
    char s3[16];
    int  count = 0;

    while (fscanf(file, "%s %s %s", s1,s2,s3)!=EOF)
    {
        printf("READING FILE LINE: %s %s %s\n",s1, s2, s3);
        if(count == 0)
        {
            thisStudent = makeStudent(s1,strtol(s2,NULL,10),strtof(s3, NULL));
            head.next= thisStudent;
        }
        else
        {
            thisStudent->next = makeStudent(s1, strtol(s2, NULL, 10), strtof(s3, NULL));
            thisStudent = thisStudent->next;
        }
        count++;
    }
    fclose(file);

    // TODO:  Change main method code ABOVE
    //-------------------------------------------------

    Student *topStudent = findTopStudent();
    printf("The Student with the best GPA is: %s\n", topStudent->name);
    printf("The average GPA is: %.2f\n", getAverageGPA());

    return 0;
}