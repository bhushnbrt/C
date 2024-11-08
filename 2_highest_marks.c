#include <stdio.h>

int main() {
    // Define the number of students and subjects
    int numStudents = 5;
    int numSubjects = 3;

    // Declare a 2D array to store marks
    int marks[numStudents][numSubjects];

    // Input marks for each student and subject
    for (int i = 0; i < numStudents; i++) {
        printf("Enter marks for Student %d:\n", i + 1);
        for (int j = 0; j < numSubjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    // Initialize variables to track the student with maximum total marks
    int maxTotalMarks = 0;
    int studentIndex = 0;

    // Calculate total marks for each student and find the maximum
    for (int i = 0; i < numStudents; i++) {
        int totalMarks = 0;
        for (int j = 0; j < numSubjects; j++) {
            totalMarks += marks[i][j];
        }

        // Check if the current student's total marks are the highest
        if (totalMarks > maxTotalMarks) {
            maxTotalMarks = totalMarks;
            studentIndex = i;
        }
    }

    // Print the student with maximum total marks
    printf("Student %d has the maximum total marks: %d\n", studentIndex + 1, maxTotalMarks);

    return 0;
}
