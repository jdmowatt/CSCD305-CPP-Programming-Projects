//Jake Mowatt
//How to compile:
//g++ -Wall -std=c++20 grade_tester.cpp -o grade_tester

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int students = 0;
    string input;

    cout << "Please enter the number of students: ";
    //Input Validation
    while (true) {
        getline(cin, input);
        stringstream ss(input);

        if (ss >> students && ss.get() == EOF && students > 0) {
            break;
        }

        cerr << "Please enter a valid number of students: ";
    }

    double grades[students];
    for (int i = 0; i < students; i++) {
        cout << "Enter a score for student " << i + 1 << ": ";
        //Input Validation
        while (true) {
            getline(cin, input);
            stringstream ss(input);

            if (ss >> grades[i] && ss.get() == EOF && grades[i] <= 100 && grades[i] >= 0) {
                break;
            }

            cerr << "Enter a valid score for student " << i + 1 <<": ";
        }
    }

    //Calculate Average Score, Minimum Score, and Maximum Score
    double average = 0, minScore = 100, maxScore = 0;
    for (int i = 0; i < students; i++) {
        average = average + grades[i];

        if (grades[i] < minScore) {
            minScore = grades[i];
        }

        if (grades[i] > maxScore) {
            maxScore = grades[i];
        }
    }
    average = average / students;

    cout << "The average score was " << average << endl;
    cout << "The minimum score was " << minScore << endl;
    cout << "The maximum score was " << maxScore << endl;

    return 0;
}