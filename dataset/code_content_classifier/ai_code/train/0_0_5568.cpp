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

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        long long ugliness = 2; // Start with 2 (for the first and last elements of the histogram)
        long long operations = heights[0]; // Operations needed for the first element

        for (int i = 1; i < n; i++) {
            if (heights[i] < heights[i-1]) {
                ugliness += heights[i-1] - heights[i]; // Add the vertical length needed for current column
            }
            operations += heights[i]; // Increment the total operations needed
        }

        cout << ugliness + operations << endl;
    }

    return 0;
}