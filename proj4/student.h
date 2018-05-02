#ifndef PROJ4_LIBRARY_H
#define PROJ4_LIBRARY_H

typedef struct student_struct
{
    char name[16];
    int age;
    double gpa;
    struct student_struct *next;
} Student;

Student head; //The head of the linked list

Student *makeStudent(char name[16], int age, double gpa);
void push(Student *student);
Student *findTopStudent();
float getAverageGPA();



#endif