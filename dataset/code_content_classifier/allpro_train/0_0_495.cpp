#include <iostream>
#include <vector>

using namespace std;

bool isPossible(int N, vector<int>& P, vector<int>& X) {
    vector<vector<int>> children(N);
    for (int i = 0; i < N; i++) {
        if (i != 0) {
            children[P[i-1]-1].push_back(i);
        }
    }

    vector<int> black(N, 0);
    vector<int> white(N, 0);

    for (int i = N-1; i >= 0; i--) {
        int sum_black = 0;
        int sum_white = 0;
        for (int j : children[i]) {
            sum_black += black[j];
            sum_white += white[j];
        }

        if (X[i] < sum_black || X[i] > sum_black + white[i]) {
            return false;
        }

        black[i] = max(0, X[i] - sum_white);
        white[i] = max(0, sum_black + white[i] - X[i]);
    }

    return black[0] == white[0];
}

int main() {
    int N;
    cin >> N;

    vector<int> P(N-1);
    for (int i = 0; i < N-1; i++) {
        cin >> P[i];
    }

    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    if (isPossible(N, P, X)) {
        cout << "POSSIBLE" << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}