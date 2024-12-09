#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<bool> happy(n, false);

        int smallest = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < smallest) {
                smallest = a[i];
            }
            if (smallest == 1 && i+1 == smallest) {
                happy[i] = true;
            }
        }

        smallest = a[1];
        for (int i = 2; i < n; i++) {
            if (a[i] < smallest) {
                smallest = a[i];
            }
            if (smallest == 2 && i+1 == smallest) {
                happy[i] = true;
            }
        }

        smallest = a[2];
        for (int i = 3; i < n; i++) {
            if (a[i] < smallest) {
                smallest = a[i];
            }
            if (smallest == 3 && i+1 == smallest) {
                happy[i] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (happy[i]) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }

    return 0;
}