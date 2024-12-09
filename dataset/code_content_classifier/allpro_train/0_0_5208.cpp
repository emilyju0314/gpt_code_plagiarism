#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> kids(n, vector<int>());
    for(int i = 0; i < n; i++) {
        int k;
        cin >> k;
        kids[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> kids[i][j];
        }
    }

    long long total_items = 0;
    long long possible_items = 0;
    for(int i = 0; i < n; i++) {
        total_items += kids[i].size();
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < kids[i].size(); j++) {
            possible_items += kids[i].size();
        }
    }

    long long x = total_items;
    long long y = possible_items;
    
    long long ans = 1;
    for(int i = 0; i < y; i++) {
        ans = (ans * x) % MOD;
    }

    cout << ans << endl;

    return 0;
}