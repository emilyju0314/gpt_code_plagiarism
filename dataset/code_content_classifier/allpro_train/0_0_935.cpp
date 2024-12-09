#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> D(N);
    for(int i = 0; i < N; i++) {
        cin >> D[i];
    }

    int max_gap = 0;

    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            int time_gap = abs(D[i] - D[j]);
            time_gap = min(time_gap, 24 - time_gap);
            max_gap = max(max_gap, time_gap);
        }
    }

    cout << max_gap << endl;

    return 0;
}