#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int strokes = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            strokes += heights[i];
        } else {
            strokes += abs(heights[i] - heights[i-1]);
        }
    }

    cout << strokes << endl;

    return 0;
}