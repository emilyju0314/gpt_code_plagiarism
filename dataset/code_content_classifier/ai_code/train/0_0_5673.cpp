#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int changes = 0;
    for (int i = 0; i < n / 2; i++) {
        int target_height = min(heights[i], heights[n - 1 - i]);
        changes += abs(heights[i] - target_height);
        heights[i] = target_height;
        heights[n - 1 - i] = target_height;
    }

    cout << changes << endl;

    return 0;
}