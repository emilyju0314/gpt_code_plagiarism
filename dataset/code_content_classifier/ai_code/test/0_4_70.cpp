#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    vector<int> cites(N);
    for(int i = 0; i < N; i++) {
        cin >> cites[i];
    }

    for(int i = 0; i < Q; i++) {
        int L, R, D;
        cin >> L >> R >> D;

        bool possible = false;
        int max_diff = 0;
        for(int j = L-1; j < R; j++) {
            max_diff = max(max_diff, abs(cites[j] - cites[j + 1]));
        }

        if(max_diff <= D) {
            possible = true;
        }

        if(possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}