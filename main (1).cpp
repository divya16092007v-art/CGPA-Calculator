/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct Course {
    double grade;
    double credit;
};

double calculateGPA(vector<Course>& courses) {
    double totalCredits = 0, totalGradePoints = 0;

    for (auto &c : courses) {
        totalCredits += c.credit;
        totalGradePoints += c.grade * c.credit;
    }

    return totalGradePoints / totalCredits;
}
int main() {
    int numSemesters;
    cout << "Enter number of semesters completed: ";
    cin >> numSemesters;

    double overallCredits = 0, overallGradePoints = 0;
    vector<double> semesterGPAs;

    for (int s = 1; s <= numSemesters; ++s) {
        int numCourses;
        cout << "\n--- Semester " << s << " ---\n";
        cout << "Enter number of courses: ";
        cin >> numCourses;

        vector<Course> courses(numCourses);

        for (int i = 0; i < numCourses; ++i) {
            cout << "\nCourse " << i + 1 << ":\n";
            cout << "Enter grade (e.g., 4.0, 3.7, 3.3): ";
            cin >> courses[i].grade;

            cout << "Enter credit hours: ";
            cin >> courses[i].credit;
        }
        double semesterGPA = calculateGPA(courses);
        semesterGPAs.push_back(semesterGPA);

        // Add to overall totals for CGPA
        double semCredits = 0, semGradePoints = 0;
        for (auto &c : courses) {
            semCredits += c.credit;
            semGradePoints += c.grade * c.credit;
        }

        overallCredits += semCredits;
        overallGradePoints += semGradePoints;

        cout << "\nSemester " << s << " GPA: " << semesterGPA << endl;
        cout << "Course Details:\n";
        for (int i = 0; i < numCourses; ++i) {
            cout << "  Course " << i + 1 
                 << ": Grade = " << courses[i].grade 
                 << ", Credit Hours = " << courses[i].credit << endl;
        }
    }

    // Compute final CGPA
    double CGPA = overallGradePoints / overallCredits;

    cout << "\n==============================\n";
    cout << "        FINAL REPORT          \n";
    cout << "==============================\n";

    for (int i = 0; i < semesterGPAs.size(); i++) {
        cout << "Semester " << i + 1 << " GPA: " << semesterGPAs[i] << endl;
    }

    cout << "\nFinal CGPA: " << CGPA << endl;
    cout << "==============================\n";

    return 0;
}

