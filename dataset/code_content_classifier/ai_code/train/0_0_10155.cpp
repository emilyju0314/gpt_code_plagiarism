#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, T;
        cin >> n >> T;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> colors(n, 0); // Initialize all elements to white

        // Find a pair that sums up to T
        bool found = false;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (a[i] + a[j] == T) {
                    colors[i] = 1; // Set color of a[i] to black
                    colors[j] = 1; // Set color of a[j] to black
                    found = true;
                    break;
                }
            }

            if (found) {
                break;
            }
        }

        // Print the colors
        for (int i = 0; i < n; i++) {
            cout << colors[i] << " ";
        }
        cout << endl;
    }

    return 0;
}