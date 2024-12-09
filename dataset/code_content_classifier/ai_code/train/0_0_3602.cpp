#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#define MOD 1000000007
using namespace std;

int n, m;
vector<vector<int>> gyms;
vector<int> types;

long long factorial(long long n) {
    if (n == 1) return 1;
    return (n * factorial(n - 1)) % MOD;
}

bool check() {
    set<int> before, after;
    for (int i = 1; i <= m; i++) {
        before.insert(i);
        after.insert(i);
    }
    
    for (int i = 0; i < n; i++) {
        set<int> cur_before = before;
        set<int> cur_after = after;
        
        for (int j = 0; j < gyms[i].size(); j++) {
            cur_before.erase(gyms[i][j]);
            if (cur_after.find(types[gyms[i][j]]) == cur_after.end()) {
                return false;
            }
            cur_after.erase(types[gyms[i][j]]);
        }
        if (cur_before.size() != 0 || cur_after.size() != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    
    gyms.resize(n);
    types.resize(m + 1);
    
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        gyms[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> gyms[i][j];
        }
    }
    
    long long ans = 0;
    
    vector<int> perm(m);
    iota(perm.begin(), perm.end(), 1);
    
    do {
        for (int i = 0; i < m; i++) {
            types[perm[i]] = i + 1;
        }
        
        if (check()) {
            ans += 1;
            ans %= MOD;
        }
    } while (next_permutation(perm.begin(), perm.end()));
    
    cout << factorial(ans) << endl;
    
    return 0;
}