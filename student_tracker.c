#include <stdio.h>

struct Student
{
    char name[50];
    int rollNo;
    float marks[5];
    float average;
    char grade;
};

// Function to calculate average
float calculateAverage(float marks[])
{
    float sum = 0;

    for(int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }

    return sum / 5;
}

// Function to calculate grade
char calculateGrade(float avg)
{
    if(avg >= 90)
        return 'A';
    else if(avg >= 80)
        return 'B';
    else if(avg >= 70)
        return 'C';
    else if(avg >= 60)
        return 'D';
    else
        return 'F';
}

// Function to display report card
void displayReportCard(struct Student s)
{
    printf("\n====================================");
    printf("\n         STUDENT REPORT CARD");
    printf("\n====================================");

    printf("\nName     : %s", s.name);
    printf("\nRoll No  : %d", s.rollNo);

    printf("\n\nMarks:");

    for(int i = 0; i < 5; i++)
    {
        printf("\nSubject %d : %.2f", i + 1, s.marks[i]);
    }

    printf("\n\nAverage : %.2f", s.average);
    printf("\nGrade   : %c", s.grade);

    printf("\n====================================\n");
}

int main()
{
    struct Student students[100];
    int count = 0;
    int choice;

    while(1)
    {
        printf("\n========== STUDENT GRADE TRACKER ==========");
        printf("\n1. Add Student");
        printf("\n2. View All Report Cards");
        printf("\n3. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:

                printf("\nEnter Student Name: ");
                scanf(" %[^\n]", students[count].name);

                printf("Enter Roll Number: ");
                scanf("%d", &students[count].rollNo);

                printf("\nEnter Marks for 5 Subjects:\n");

                for(int i = 0; i < 5; i++)
                {
                    printf("Subject %d: ", i + 1);
                    scanf("%f", &students[count].marks[i]);
                }

                students[count].average =
                    calculateAverage(students[count].marks);

                students[count].grade =
                    calculateGrade(students[count].average);

                count++;

                printf("\nStudent Record Saved Successfully!\n");
                break;

            case 2:

                if(count == 0)
                {
                    printf("\nNo Records Found!\n");
                }
                else
                {
                    for(int i = 0; i < count; i++)
                    {
                        displayReportCard(students[i]);
                    }
                }

                break;

            case 3:

                printf("\nThank You For Using Student Grade Tracker!\n");
                return 0;

            default:

                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}