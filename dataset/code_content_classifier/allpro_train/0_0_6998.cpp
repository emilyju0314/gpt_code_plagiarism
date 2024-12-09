#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int A[20], B[20], C[20];
int dp[20][20][15000001];

int solve(int a, int b, int rem) {
    if (rem < 0) return -1;
    if (rem == 0) return 0;
    if (dp[a][b][rem] != -1) return dp[a][b][rem];

    int min_moves = 1e9;

    vector<pair<int, string>> moves;
    moves.push_back({A[a], "AB"});
    moves.push_back({B[b], "AC"});
    moves.push_back({C[rem-1], "BC"});

    do {
        int next_a = a + (moves[0].second[0] == 'A');
        int next_b = b + (moves[1].second[0] == 'A');
        int next_rem = rem + (moves[2].second[0] == 'C') - 1;

        int cur_moves = solve(next_a, next_b, next_rem);
        if (cur_moves != -1) {
            min_moves = min(min_moves, cur_moves + max({A[a], B[b], C[rem-1]}));
        }
    } while (next_permutation(moves.begin(), moves.end()));

    return dp[a][b][rem] = (min_moves == 1e9) ? -1 : min_moves;
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> B[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> C[i];
        }

        fill(&dp[0][0][0], &dp[0][0][0] + 20*20*15000001, -1);

        int ans = solve(0, 0, n);
        cout << ans << endl;
    }

    return 0;
}