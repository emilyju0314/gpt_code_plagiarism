#include <iostream>
#include <vector>

using namespace std;

char getStudentClass(int pm, int pe, int pj) {
    int average = (pm + pe + pj) / 3;
    if (pm >= 90 && pe >= 90 && pj >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'A';
    } else if (average >= 70) {
        return 'B';
    } else if (average >= 50 && (pm >= 80 || pe >= 80 || pj >= 80)) {
        return 'B';
    } else {
        return 'C';
    }
}

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }

        vector<int> pm(n);
        vector<int> pe(n);
        vector<int> pj(n);

        for (int i = 0; i < n; i++) {
            cin >> pm[i] >> pe[i] >> pj[i];
        }

        for (int i = 0; i < n; i++) {
            char studentClass = getStudentClass(pm[i], pe[i], pj[i]);
            cout << studentClass << endl;
        }
    }

    return 0;
}