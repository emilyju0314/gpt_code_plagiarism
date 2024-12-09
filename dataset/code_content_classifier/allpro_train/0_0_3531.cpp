#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int N, M;
vector<int> A;

int countPermutations(int player, int mask) {
    if (player == (1 << N)) {
        return 1;
    }

    int result = 0;
    for (int i = 1; i < (1 << N); i++) {
        if (((mask >> i) & 1) == 0) {
            bool wins_with_player = true;
            for (int j = 0; j < M; j++) {
                if (i == A[j]) {
                    wins_with_player = false;
                    break;
                }
            }
            if (wins_with_player && i < player) {
                result = (result + countPermutations(player + 1, mask | (1 << i))) % MOD;
            }
        }
    }

    return result;
}

int main() {
    cin >> N >> M;
    A.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> A[i];
    }

    int totalPermutations = 1;
    for (int i = 1; i <= N; i++) {
        totalPermutations = (totalPermutations * i) % MOD;
    }

    int result = countPermutations(2, 1);
    result = (result * totalPermutations) % MOD;

    cout << result << endl;

    return 0;
}