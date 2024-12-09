#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> ans(N);
    ans[P[0] - 1] = 1;

    int target = 1;
    for (int i = 1; i < N; i++) {
        if (P[i] == target + 1) {
            ans[P[i] - 1] = 1;
            target++;
        } else {
            ans[P[i] - 1] = 0;
        }
    }

    if (target == N) {
        for (int i = 0; i < N; i++) {
            cout << ans[i];
        }
    } else {
        cout << -1;
    }

    return 0;
}