#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, A, R, M;
    cin >> N >> A >> R >> M;

    vector<int> heights(N);
    for(int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    sort(heights.begin(), heights.end());

    long long totalCost = LLONG_MAX;

    for(int targetHeight = heights[0] - 1; targetHeight <= heights[N-1] + 1; targetHeight++) {
        long long cost = 0;

        for(int i = 0; i < N; i++) {
            if(heights[i] < targetHeight) {
                cost += (targetHeight - heights[i]) * A;
            } else if(heights[i] > targetHeight) {
                cost += (heights[i] - targetHeight) * R;
            }
        }

        for(int i = 0; i < N; i++) {
            cost = min(cost, (long long)abs(targetHeight - heights[i]) * M);
        }

        totalCost = min(totalCost, cost);
    }

    cout << totalCost << endl;

    return 0;
}