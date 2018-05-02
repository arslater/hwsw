#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "student.h"

/* Given the student values, initialize a structure,
   and return a pointer to the struct */
Student *makeStudent(char name[16], int age, double gpa)
{
    Student *newStudent = (Student *) malloc(sizeof(Student));
    strcpy(newStudent   -> name, name);
    newStudent -> age = age;
    newStudent -> gpa = gpa;

    return newStudent;
}


/* Inserts an element to the front of the linkedList */
void push(Student *student)
{
    student -> next = &head;
    head = *student;
}


/* Traverses the linked list and returns the student with the best GPA */
Student *findTopStudent()
{
    Student * top = head.next;
    Student * tmp = head.next;

    printf("HEAD: %s\n", head.name);

    while(tmp -> next != NULL)
    {
        if(tmp->gpa > top->gpa)
        {
            //printf("%f > %f\n",tmp->gpa,top->gpa);
            top = tmp;
        }
        tmp = tmp ->next;
    }
    return(top);
}

/* Traverses the linked list and returns the average GPA across all students */
float getAverageGPA()
{
    float   total = 0;
    int     count = 0;
    Student *tmp  = &head;

    while(tmp -> next != NULL)
    {
        total+= tmp -> gpa;
        count++;
        tmp  = tmp -> next;
    }
    return(  (total/count));
}

