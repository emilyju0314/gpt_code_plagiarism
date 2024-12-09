#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, M, T;
    cin >> N >> M >> T;

    vector<int> x(M), y(M);
    for (int i =0; i < M; i++) {
        cin >> x[i] >> y[i];
    }

    if (T == 1) {
        cout << "^^^^^" << endl; // A uniforming state
    } else {
        unordered_set<int> state;
        for(int i = 0; i < M; i++) {
            if (state.count(x[i])) {
                state.insert(y[i]);
            } else if (state.count(y[i])) {
                state.insert(x[i]);
            } else {
                cout << "v^^^^" << endl; // A non-uniforming state
                return 0;
            }
        }

        cout << -1 << endl; // No non-uniforming state found
    }

    return 0;
}