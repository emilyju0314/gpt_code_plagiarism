#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    string p;
    cin >> p;
    
    vector<int> positions(m);
    for(int i = 0; i < m; i++) {
        cin >> positions[i];
    }
    
    long long ans = 1;
    int last = 0;
    
    for(int i = 0; i < m; i++) {
        ans = (ans * (positions[i] - last)) % MOD;
        last = positions[i];
    }
    
    ans = (ans * (n - last)) % MOD;
    
    cout << ans << endl;

    return 0;
}