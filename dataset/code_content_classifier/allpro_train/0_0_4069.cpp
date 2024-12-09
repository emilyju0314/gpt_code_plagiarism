#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, L, K;
    cin >> N >> L >> K;

    vector<pair<int, int>> sequence;

    for(int i = 0; i < N; i++) {
        int a, d;
        cin >> a >> d;
        sequence.push_back({a, d});
    }

    vector<long long> sum(N * L + 1, 0);

    for(int i = 0; i < N; i++) {
        for(int j = 1; j <= L; j++) {
            sum[i * L + j] = sequence[i].first + (j - 1) * sequence[i].second;
        }
    }

    vector<long long> prefix_sum(N * L + 1, 0);

    for(int i = 1; i <= N * L; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + sum[i];
    }

    long long max_sum = 0;

    for(int i = K; i <= N * L; i++) {
        max_sum = max(max_sum, prefix_sum[i] - prefix_sum[i - K]);
    }

    cout << max_sum << endl;

    return 0;
}