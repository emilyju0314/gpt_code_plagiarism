#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    string grade;
    cin >> grade;

    int decimalPos = grade.find(".");
    int nextPos = decimalPos + 1;
    int i = 0;

    while (i < t && grade[nextPos] >= '5') {
        if (grade[nextPos] >= '5') {
            grade[nextPos] = '0';
            if (grade[nextPos - 1] == '9') {
                grade[nextPos - 1] = '0';
                nextPos--;
            } else {
                grade[nextPos - 1]++;
            }
            i++;
        }
        nextPos++;
    }

    if (grade[decimalPos + 1] == '0') {
        grade = grade.substr(0, decimalPos);
    } else {
        grade = grade.substr(0, nextPos);
    }

    cout << grade << endl;

    return 0;
}