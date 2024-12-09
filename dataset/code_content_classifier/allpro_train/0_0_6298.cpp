#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> heights(N);
    for (int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    int min_height_diff = 1e9;
    for (int i = 0; i <= N - K; i++) {
        int height_diff = heights[i + K - 1] - heights[i];
        min_height_diff = min(min_height_diff, height_diff);
    }

    cout << min_height_diff << endl;

    return 0;
}