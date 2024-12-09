#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int jumps = 0;
        int currentHeightA = 0, currentHeightB = 0;
        while (currentHeightA < n && currentHeightB < n) {
            if (a[currentHeightA] == 0 && b[currentHeightB] == 0) {
                currentHeightA++;
                currentHeightB++;
            } else if (a[currentHeightA] == 1 && b[currentHeightB] == 1) {
                currentHeightA++;
                currentHeightB++;
            } else if (a[currentHeightA] == 2 && b[currentHeightB] == 2) {
                currentHeightA++;
                currentHeightB++;
            } else if (a[currentHeightA] == 0 && b[currentHeightB] == 1) {
                currentHeightA++;
            } else if (a[currentHeightA] == 1 && b[currentHeightB] == 0) {
                currentHeightB++;
            } else if (a[currentHeightA] == 0 && b[currentHeightB] == 2) {
                currentHeightA++;
            } else if (a[currentHeightA] == 2 && b[currentHeightB] == 0) {
                currentHeightB++;
            } else {
                jumps++;
                currentHeightA += 2;
                currentHeightB += 2;
            }
        }

        if (currentHeightA >= n || currentHeightB >= n) {
            cout << jumps << endl;
        } else {
            cout << "NA" << endl;
        }
    }
    return 0;
}