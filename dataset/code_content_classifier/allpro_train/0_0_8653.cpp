#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int N, M;
vector<vector<int>> formula;
int dp[1001][1 << 10];

int countAllocations(int index, int state) {
    if(index == N) {
        return 1;
    }
    if(dp[index][state] != -1) {
        return dp[index][state];
    }

    int res = 0;
    bool valid = true;

    for(int i = 0; i < M; i++) {
        int x = formula[i][0];
        int y = formula[i][1];
        bool x_val = state & (1 << (abs(x) - 1));
        bool y_val = state & (1 << (abs(y) - 1));

        if(x < 0) {
            x_val = !x_val;
        }
        if(y < 0) {
            y_val = !y_val;
        }

        if(!x_val && !y_val) {
            valid = false;
            break;
        }
    }

    if(valid) {
        res = (res + countAllocations(index + 1, state)) % MOD;
    }

    res = (res + countAllocations(index + 1, state | (1 << index))) % MOD;

    return dp[index][state] = res;
}

int main() {
    cin >> N >> M;
    formula.resize(M, vector<int>(2));

    for(int i = 0; i < M; i++) {
        cin >> formula[i][0] >> formula[i][1];
    }

    memset(dp, -1, sizeof(dp));

    int result = countAllocations(0, 0);
    cout << result << endl;

    return 0;
}