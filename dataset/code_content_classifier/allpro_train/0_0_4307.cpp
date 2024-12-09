#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> P(N), C(N);
    for(int i = 0; i < N; i++) {
        cin >> P[i];
        P[i]--; // Adjusting zero-based indexing
    }

    for(int i = 0; i < N; i++) {
        cin >> C[i];
    }

    long long maxScore = LLONG_MIN;

    for(int start = 0; start < N; start++) {
        vector<int> visited(N, 0);
        int current = start;
        long long score = 0;
        int moves = 0;

        while(visited[current] == 0) {
            visited[current] = 1;
            score += C[current];
            current = P[current];
            moves++;

            if(moves == K) {
                break;
            }
        }

        if(moves > 0) {
            long long cycleScore = score;
            if(score > 0) {
                cycleScore += score * ((K - moves) / moves);
            }
            maxScore = max(maxScore, cycleScore);
        }
    }

    cout << maxScore << endl;

    return 0;
}