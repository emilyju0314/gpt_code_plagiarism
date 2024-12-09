#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> P(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    vector<int> O(N, 0);
    for (int bit = 29; bit >= 0; bit--) {
        for (int i = 0; i < N; i++) {
            if ((A[i] & (1 << bit)) != 0) {
                O[i] |= (1 << bit);
            }
        }

        vector<int> sortedP = P;
        sort(sortedP.begin(), sortedP.end());

        vector<int> candidate(N, 0);
        for (int i = 0; i < N; i++) {
            candidate[i] = O[i] ^ sortedP[i];
        }

        bool valid = true;
        sort(P.begin(), P.end());
        for (int i = 0; i < N; i++) {
            if (P[i] != candidate[i]) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            for (int i = 0; i < N; i++) {
                O[i] ^= (1 << bit);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << O[i] << " ";
    }
    cout << endl;

    return 0;
}