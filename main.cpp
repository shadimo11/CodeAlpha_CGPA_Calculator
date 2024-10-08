#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>

using namespace std;

// Function to get the grade point based on letter grade
double getGradePoint(string grade) {
    map<string, double> gradePoints = {
        {"A+", 4.0}, {"A", 4.0}, {"A-", 3.7},
        {"B+", 3.3}, {"B", 3.0}, {"B-", 2.7},
        {"C+", 2.3}, {"C", 2.0}, {"C-", 1.7},
        {"D+", 1.3}, {"D", 1.0}, {"F", 0.0}
    };
    return gradePoints[grade];
}

int main() {
    int numberOfSemesters;
    cout << "Welcome to the Multi-Semester CGPA Calculator!\n";
    cout << "------------------------------------------------\n";
    cout << "Enter the number of semesters: ";
    cin >> numberOfSemesters;

    double cumulativeGradePoints = 0.0;
    double cumulativeCredits = 0.0;

    // Loop through each semester
    for (int semester = 1; semester <= numberOfSemesters; semester++) {
        int numCourses;
        cout << "\nEntering data for Semester " << semester << ":\n";
        cout << "Enter the number of courses in this semester: ";
        cin >> numCourses;

        double semesterGradePoints = 0.0;
        double semesterCredits = 0.0;

        // Loop through each course in the semester
        for (int course = 1; course <= numCourses; course++) {
            double courseCredit;
            string grade;
            cout << "\nCourse " << course << ":\n";
            cout << "  Enter the course credit: ";
            cin >> courseCredit;
            cout << "  Enter the grade (A+, A, A-, B+, B, etc.): ";
            cin >> grade;

            // Calculate grade points for the course
            double gradePoint = getGradePoint(grade);
            semesterGradePoints += gradePoint * courseCredit;
            semesterCredits += courseCredit;
        }

        // Calculate GPA for the semester
        double semesterGPA = semesterGradePoints / semesterCredits;
        cout << fixed << setprecision(2);
        cout << "\nGPA for Semester " << semester << ": " << semesterGPA << "\n";

        // Update cumulative totals
        cumulativeGradePoints += semesterGradePoints;
        cumulativeCredits += semesterCredits;

        // Calculate current CGPA up to this semester
        double currentCGPA = cumulativeGradePoints / cumulativeCredits;
        cout << "Current CGPA after Semester " << semester << ": " << currentCGPA << "\n";
    }

    // Calculate and display the overall CGPA
    double overallCGPA = cumulativeGradePoints / cumulativeCredits;
    cout << "\n---------------------------------------------\n";
    cout << "Overall CGPA: " << overallCGPA << "\n";
    cout << "---------------------------------------------\n";

    return 0;
}
