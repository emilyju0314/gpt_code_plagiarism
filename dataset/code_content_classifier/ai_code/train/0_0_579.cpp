#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> switches;
vector<int> bulbs;
int ans = 0;

bool check(int state) {
    for (int i = 0; i < M; i++) {
        int count = 0;
        for (int j = 0; j < switches[i].size(); j++) {
            if (state & (1 << (switches[i][j] - 1))) {
                count++;
            }
        }
        if (count % 2 != bulbs[i]) {
            return false;
        }
    }
    return true;
}

void solve(int i, int state) {
    if (i == N) {
        if (check(state)) {
            ans++;
        }
        return;
    }
    solve(i + 1, state | (1 << i));
    solve(i + 1, state);
}

int main() {
    cin >> N >> M;
    switches.resize(M);
    for (int i = 0; i < M; i++) {
        int k;
        cin >> k;
        switches[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> switches[i][j];
        }
    }
    bulbs.resize(M);
    for (int i = 0; i < M; i++) {
        cin >> bulbs[i];
    }

    solve(0, 0);

    cout << ans << endl;

    return 0;
}