#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> x(n);
        for (int j = 0; j < n; j++) {
            cin >> x[j];
        }

        int count = 0;
        for (int j = 0; j < n - 2; j++) {
            for (int k = j + 1; k < n - 1; k++) {
                for (int l = k + 1; l < n; l++) {
                    double area = 0.5 * abs((x[j] - x[k]) * (1 - x[l]) + (x[k] - x[l]) * (1 - x[j]));
                    if (area > 0) {
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}