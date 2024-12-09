#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Coin {
    int radius;
    int initialX;
    int initialY;
    int targetX;
    int targetY;
};

int main() {
    int N;
    cin >> N;

    vector<Coin> coins(N);
    vector<int> maxScore(1 << N, 0);

    for (int i = 0; i < N; i++) {
        cin >> coins[i].radius >> coins[i].initialX >> coins[i].initialY >> coins[i].targetX >> coins[i].targetY;
    }

    for (int mask = 0; mask < (1 << N); mask++) {
        for (int i = 0; i < N; i++) {
            if (((mask >> i) & 1) == 1) {
                continue;
            }

            int newMask = mask | (1 << i);
            int score = 0;
            for (int j = 0; j < N; j++) {
                if (((newMask >> j) & 1) == 1 && (abs(coins[i].initialX - coins[j].targetX) * abs(coins[i].initialX - coins[j].targetX) + abs(coins[i].initialY - coins[j].targetY) * abs(coins[i].initialY - coins[j].targetY) >= (coins[i].radius + coins[j].radius) * (coins[i].radius + coins[j].radius))) {
                    score++;
                }
            }

            maxScore[newMask] = max(maxScore[newMask], maxScore[mask] + score);
        }
    }

    cout << maxScore[(1 << N) - 1] << endl;

    return 0;
}