#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    // Check if current order is nice
    for(int i = 0; i < n; i++) {
        int nearest_smaller = -1;
        for(int j = i+1; j < n; j++) {
            if(heights[j] < heights[i]) {
                nearest_smaller = j;
                break;
            }
        }
        if(nearest_smaller == -1 || nearest_smaller - i > k) {
            // If no smaller height found or distance is more than k, row is not nice
            cout << "YES" << endl;
            return 0;
        }
    }

    // Try one swap
    for(int i = 0; i < n - 1; i++) {
        if(heights[i] < heights[i+1]) {
            if(i + 2 >= n || heights[i] < heights[i+2]) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}