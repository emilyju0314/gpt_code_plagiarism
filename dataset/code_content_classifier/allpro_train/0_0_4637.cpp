#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;

    string grade;
    cin >> grade;

    int decimalIndex;
    for (int i = 0; i < grade.length(); i++) {
        if (grade[i] == '.') {
            decimalIndex = i;
            break;
        }
    }

    int roundIndex = decimalIndex + t;
    if (grade[roundIndex + 1] >= '5') {
        while (roundIndex >= 0 && grade[roundIndex] == '9') {
            grade[roundIndex] = '0';
            roundIndex--;
        }
        if (roundIndex >= 0) {
            grade[roundIndex]++;
        } else {
            grade = "1" + grade;
        }
    }

    int finalIndex = roundIndex;
    if (grade[finalIndex] == '.') {
        finalIndex--;
    }

    cout << grade.substr(0, finalIndex + 2) << endl;

    return 0;
}