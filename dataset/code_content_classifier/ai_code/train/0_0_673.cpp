#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> idx(N + 1);
    for (int i = 0; i < N; i++) {
        idx[P[i]] = i;
    }

    for (int i = 1; i <= N; i++) {
        while (idx[i] > 0 && P[idx[i]] < P[idx[i] - 1] && idx[i] - 1 + K >= idx[i]) {
            swap(P[idx[i]], P[idx[i] - 1]);
            idx[P[idx[i]]]++;
            idx[P[idx[i] - 1]]--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << P[i] << endl;
    }

    return 0;
}