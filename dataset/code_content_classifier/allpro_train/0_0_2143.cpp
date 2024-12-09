#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> P(N);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
    }

    int K = 0;
    for (int i = 0; i < N; i++) {
        if (P[i] == -1) K++;
    }

    long long result = 0;
    for (int i = 0; i < K; i++) {
        long long count = 1;
        for (int j = 0; j < N; j++) {
            if (P[j] == -1) {
                count = (count * (N - 1)) % MOD;
            }
        }
        result = (result + count) % MOD;

        for (int j = 0; j < N; j++) {
            if (P[j] != -1) {
                P[P[j] - 1] = -1;
            }
        }
    }

    cout << result << endl;

    return 0;
}