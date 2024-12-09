#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int N, M, K;
vector<vector<int>> conditions;
map<pair<int, int>, int> cache;

int dp(int idx, int bitmask) {
    if (idx == M) {
        return 1;
    }
    
    if (cache.count({idx, bitmask})) {
        return cache[{idx, bitmask}];
    }
    
    int res = 0;
    for (int i = 0; i < (1 << (N-1)); i++) {
        bool valid = true;
        for (auto& condition : conditions) {
            int A = condition[0], B = condition[1], C = condition[2];
            if (C == 0 && !(i & (1 << (B-1))) && (bitmask & (1 << (B-1)))) {
                valid = false;
                break;
            }
            if (C == 1 && (i & (1 << (B-1))) && !(bitmask & (1 << (B-1)))) {
                valid = false;
                break;
            }
        }
        
        if (valid) {
            int new_bitmask = 0;
            for (int j = 0; j < N-1; j++) {
                if (i & (1 << j)) {
                    new_bitmask |= (1 << j);
                }
            }
            res = (res + dp(idx+1, new_bitmask)) % MOD;
        }
    }
    
    return cache[{idx, bitmask}] = res;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        conditions.push_back({A, B, C});
    }
    
    int result = dp(0, 0);
    cout << result << endl;
    
    return 0;
}