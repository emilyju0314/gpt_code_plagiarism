#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n, m;
    cin >> n >> m;
    
    string a, b;
    cin >> a >> b;
    
    long long answer = 0;
    long long current = 0;
    
    for(int i = 0; i < m; i++) {
        current = (current * 2 + (b[i] - '0')) % MOD;
    }
    
    for(int i = 0; i < n; i++) {
        if(b[m-1] == '1') {
            answer = (answer + (current * (a[i] - '0'))) % MOD;
        }
        current = (current * 2 + (a[i] - '0')) % MOD;
        
        if(m > 0) {
            m--;
            current = (current - (b[m] - '0') * (1LL << m) + MOD) % MOD;
        }
    }
    
    cout << answer << endl;
    
    return 0;
}