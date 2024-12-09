#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }

    // Check if there are two non-overlapping parallel lines that cover all points
    bool possible = false;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int diff = points[i] - points[j];
            bool valid = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                if ((points[i] - points[k]) * diff != (points[i] - points[j]) * (points[i] - points[k])) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                possible = true;
                break;
            }
        }
        if (possible) {
            break;
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}