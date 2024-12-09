#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    int n = A.size();
    int shifts = n; // Shifts needed to make strings equal

    for (int i = 0; i < n; i++) {
        if (B[i] == '1') {
            if (A[i] == B[i]) {
                shifts = min(shifts, min(i, n - i));
            }
        }
    }

    int flips = 0;
    for (int i = 0; i < n; i++) {
        if (B[i] == '1' && A[i] != B[i]) {
            flips++;
        }
    }

    if (flips == 0) {
        cout << 0 << endl;
    } else if (shifts == n) {
        cout << -1 << endl;
    } else {
        cout << shifts + flips << endl;
    }

    return 0;
}