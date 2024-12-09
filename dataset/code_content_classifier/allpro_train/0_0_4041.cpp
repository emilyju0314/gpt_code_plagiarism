#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

#define MOD 1000000007

using namespace std;

vector<int> fibonacci;

int f(int n) {
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(n < fibonacci.size() && fibonacci[n] != -1) {
        return fibonacci[n];
    }
    
    int ans = (f(n - 1) + f(n - 2)) % MOD;
    if(n < fibonacci.size()) {
        fibonacci[n] = ans;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    fibonacci.resize(2 * n + 1, -1);
    
    long long result = 0;
    
    for(int i = 0; i < 17; i++) {
        int count = 0;
        for(int j = 0; j < n; j++) {
            if((s[j] & (1 << i))) {
                count++;
            }
        }
        
        long long pow2a = 1 << count;
        long long pow2b = pow2a - count;
        long long pow2c = f(n - count) - 1;
        long long pow2d = f(n - count);
        
        long long contribution = pow2a * pow2b % MOD * pow2c % MOD * pow2d % MOD * f(i) % MOD;
        result = (result + contribution) % MOD;
    }
    
    cout << result << endl;
    
    return 0;
}