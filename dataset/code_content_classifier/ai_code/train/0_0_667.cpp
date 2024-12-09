#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, A, B, C;
    cin >> N >> A >> B >> C;

    vector<int> bamboo_lengths(N);
    for (int i = 0; i < N; i++) {
        cin >> bamboo_lengths[i];
    }

    int min_mp = INT_MAX;

    // Iterate through all possible combinations of bamboos to form A, B, C
    for (int i = 0; i < (1 << N); i++) {
        vector<int> lengths_used;
        int mp = 0;
        int sumA = 0, cntA = 0;
        int sumB = 0, cntB = 0;
        int sumC = 0, cntC = 0;

        for (int j = 0; j < N; j++) {
            if (i & (1 << j)) {
                lengths_used.push_back(bamboo_lengths[j]);
            }
        }

        for (int len : lengths_used) {
            if (len == A) sumA += len, cntA++;
            else if (len == B) sumB += len, cntB++;
            else if (len == C) sumC += len, cntC++;
            else {
                if (len < A) { mp += A - len; sumA += A; cntA++; }
                else if (len < B) { mp += B - len; sumB += B; cntB++; }
                else if (len < C) { mp += C - len; sumC += C; cntC++; }
            }
        }

        if (cntA >= 1 && cntB >= 1 && cntC >= 1) {
            mp += abs(A - sumA) + abs(B - sumB) + abs(C - sumC) - 2 * 3; // Removing extra 3 from combined bamboos
            min_mp = min(min_mp, mp);
        }
    }

    cout << min_mp << endl;

    return 0;
}