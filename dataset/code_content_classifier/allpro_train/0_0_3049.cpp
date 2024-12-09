#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int jumps = 1; // At least one jump needed to reach the last skyscraper
    int max_height = heights[0];
    int min_height = heights[0];

    for(int i = 1; i < n - 1; i++) {
        if(max(heights[i], heights[i+1]) < min(max_height, min_height)) {
            max_height = max(max_height, heights[i]);
            min_height = min(min_height, heights[i]);
        } else {
            max_height = min(max_height, heights[i]);
            min_height = max(min_height, heights[i]);
            jumps++;
        }
    }

    cout << jumps << endl;

    return 0;
}