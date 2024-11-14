// student.h
#include <stdio.h>
#include <stdlib.h>
#ifndef STUDENT_H
#define STUDENT_H

#define MAX_STUDENTS 30

typedef struct
{
  int id;
  float score;
} Student;

extern Student students[MAX_STUDENTS];
extern int studentCount;

void inputScores();
void calculateTotalAndAverage();
void sortByScore();
void sortByID();
void searchByID();
void statistics();
void displayAllScores();

#endif