#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> S(N);
    vector<int> T(N);
    vector<uint64_t> U(N);
    vector<uint64_t> V(N);

    for (int i = 0; i < N; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> T[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> U[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // Check if a matrix satisfying the conditions exists
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            uint64_t val = 0;
            if (S[i] == 0) {
                val = U[i];
            } else {
                val = ~U[i];
            }

            if (T[j] == 0) {
                val &= V[j];
            } else {
                val |= V[j];
            }

            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}