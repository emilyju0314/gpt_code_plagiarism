#include <bits/stdc++.h>
using namespace std;

long long int mod = 998244353;

int main() {
    int N;
    string X;
    cin >> N >> X;
    
    vector<int> ans(X.size(), 0);
    
    for(int i=1; i<=X.size(); i++) {
        int x = X[i-1] - '0';
        for(int j=0; j<=i; j++) {
            ans[j] = (ans[j]*2 + (j%2==0 ? 1 : -1)) % mod;
        }
        if(x == 1) {
            ans[0]++;
        }
    }
    
    long long int sum = 0;
    for(int i=0; i<X.size(); i++) {
        if(i > 0) {
            sum = (sum + (long long int) ans[i]*i) % mod;
        }
    }
    
    cout << sum << endl;
    
    return 0;
}