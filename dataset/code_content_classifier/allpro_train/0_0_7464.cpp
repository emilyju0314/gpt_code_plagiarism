#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

using namespace std;

int main() {
    int N, M, R;
    cin >> N >> M >> R;

    vector<pair<pair<int, int>, pair<int, int>>> madSnakes; // (X, Y), (danger level, score)
    for (int i = 0; i < N; i++) {
        int X, Y, dan, B;
        cin >> X >> Y >> dan >> B;
        madSnakes.push_back({{X, Y}, {dan, B}});
    }

    long long totalScore = 0;

    // For each possible attack strategy
    for (int mask = 0; mask < (1 << N); mask++) {
        if (__builtin_popcount(mask) != M) continue;

        // Calculate the total sum of danger levels of attacked snakes
        long long sumDanger = 0;
        for (int i = 0; i < N; i++) {
            if (mask & (1 << i)) {
                sumDanger += madSnakes[i].second.first;
            }
        }

        // Calculate the total score for this attack strategy
        long long score = sumDanger * sumDanger % MOD;
        totalScore = (totalScore + score) % MOD;
    }

    cout << totalScore << endl;

    return 0;
}