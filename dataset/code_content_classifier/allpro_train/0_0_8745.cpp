#include <iostream>
using namespace std;

int main() {
    int m, f, r;

    while (true) {
        cin >> m >> f >> r;

        if (m == -1 && f == -1 && r == -1) {
            break; // exit the loop when encountering three -1s
        }

        if (m == -1 || f == -1) {
            cout << "F" << endl;
        } else {
            int totalScore = m + f;
            if (totalScore >= 80) {
                cout << "A" << endl;
            } else if (totalScore >= 65) {
                cout << "B" << endl;
            } else if (totalScore >= 50) {
                cout << "C" << endl;
            } else if (totalScore >= 30 && r >= 50) {
                cout << "C" << endl;
            } else {
                cout << "F" << endl;
            }
        }
    }

    return 0;
}