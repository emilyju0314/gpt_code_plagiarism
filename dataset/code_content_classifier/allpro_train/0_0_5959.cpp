#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> timings(N);
    for (int i = 1; i < N; i++) {
        cin >> timings[i];
    }

    int min_seconds = 1e9; // Initialize to a large value

    for (int i = 1; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int total_seconds = timings[i] + timings[j];
            min_seconds = min(min_seconds, total_seconds);
        }
    }

    cout << min_seconds << endl;

    return 0;
}