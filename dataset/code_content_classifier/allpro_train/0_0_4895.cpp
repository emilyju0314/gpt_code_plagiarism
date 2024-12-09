#include <iostream>
#include <vector>
#include <unordered_map>
#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> posVarMap; // map to store counts of positive occurrences
    unordered_map<int, int> negVarMap; // map to store counts of negative occurrences

    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        int a, b;
        
        if(k == 1) {
            cin >> a;
            if(a > 0) {
                posVarMap[a]++;
            } else {
                negVarMap[-a]++;
            }
        } else {
            cin >> a >> b;
            if(a > 0) {
                posVarMap[a]++;
            } else {
                negVarMap[-a]++;
            }
            if(b > 0) {
                posVarMap[b]++;
            } else {
                negVarMap[-b]++;
            }
        }
    }

    long long ans = 1;
    for(auto it : posVarMap) {
        int cnt = it.second;
        ans = (ans * ((1LL << cnt) % MOD)) % MOD;
    }

    for(auto it : negVarMap) {
        int cnt = it.second;
        ans = (ans * ((1LL << cnt) % MOD)) % MOD;
    }

    cout << ans << endl;

    return 0;
}