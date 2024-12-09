#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long count = 0;

    for (int l = 0; l < n; l++) {
        int min_height = heights[l];
        for (int r = l + 1; r < n; r++) {
            min_height = min(min_height, heights[r]);
            int max_or = heights[l] | heights[r];
            if (min_height > max_or) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}