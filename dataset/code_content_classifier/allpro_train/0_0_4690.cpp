#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string x;
    cin >> x;

    // Find the smallest beautiful integer y
    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        y[i] = x[i] - '0';
    }

    for (int i = k; i < n; i++) {
        y[i] = y[i % k];
    }

    // Make sure y >= x
    for (int i = 0; i < n; i++) {
        if (y[i] < (x[i] - '0')) {
            y[k-1]++;
            for (int j = k-1; j >= 0; j--) {
                if (y[j] == 10) {
                    y[j] = 0;
                    y[j-1]++;
                } else {
                    break;
                }
            }
        }
    }

    // Output the result
    cout << n << endl;
    for (int i = 0; i < n; i++) {
        cout << y[i];
    }
    cout << endl;

    return 0;
}