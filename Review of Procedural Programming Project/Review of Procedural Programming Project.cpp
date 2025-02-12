#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int NUM_STUDENTS = 5;
const int NUM_TESTS = 3;

void getStudentData(string names[], double scores[][NUM_TESTS]);
void calculateAverages(const double scores[][NUM_TESTS], double averages[]);
void assignGrades(const double averages[], char grades[]);
void displayResults(const string names[], const double scores[][NUM_TESTS], const double averages[], const char grades[]);

int main() {
    string names[NUM_STUDENTS];
    double scores[NUM_STUDENTS][NUM_TESTS];
    double averages[NUM_STUDENTS];
    char grades[NUM_STUDENTS];

    getStudentData(names, scores);
    calculateAverages(scores, averages);
    assignGrades(averages, grades);
    displayResults(names, scores, averages, grades);

    return 0;
}

void getStudentData(string names[], double scores[][NUM_TESTS]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << "Enter name for student " << (i + 1) << ": ";
        cin >> names[i];
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << "Enter score for test " << (j + 1) << ": ";
            cin >> scores[i][j];
        }
    }
}

void calculateAverages(const double scores[][NUM_TESTS], double averages[]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        double total = 0;
        for (int j = 0; j < NUM_TESTS; j++) {
            total += scores[i][j];
        }
        averages[i] = total / NUM_TESTS;
    }
}

void assignGrades(const double averages[], char grades[]) {
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (averages[i] >= 90) grades[i] = 'A';
        else if (averages[i] >= 80) grades[i] = 'B';
        else if (averages[i] >= 70) grades[i] = 'C';
        else if (averages[i] >= 60) grades[i] = 'D';
        else grades[i] = 'F';
    }
}

void displayResults(const string names[], const double scores[][NUM_TESTS], const double averages[], const char grades[]) {
    cout << "\nGrade Book Results:\n";
    cout << left << setw(10) << "Name";
    for (int i = 0; i < NUM_TESTS; i++) {
        cout << setw(8) << ("Test " + to_string(i + 1));
    }
    cout << setw(10) << "Average" << "Grade" << endl;

    for (int i = 0; i < NUM_STUDENTS; i++) {
        cout << left << setw(10) << names[i];
        for (int j = 0; j < NUM_TESTS; j++) {
            cout << setw(8) << scores[i][j];
        }
        cout << setw(10) << averages[i] << grades[i] << endl;
    }
}
//hi this too WAY TOO LONG. I found out I put ISTREAM instead of IOSTREAM.