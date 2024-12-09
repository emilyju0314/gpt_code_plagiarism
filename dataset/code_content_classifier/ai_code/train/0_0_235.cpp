#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, E, T;
    cin >> N >> E >> T;

    vector<int> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    long long totalTime = 0;
    long long minTime = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) {
            totalTime = E - x[i];
        } else {
            totalTime += x[i+1] - x[i];
        }

        minTime = max(minTime, totalTime + T);
    }

    cout << minTime << endl;

    return 0;
}