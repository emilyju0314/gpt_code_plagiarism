#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int X1, X2, X3, X4, X5, X6;
    int Y1, Y2, Y3, Y4, Y5, Y6;
    
    cin >> X1 >> X2 >> X3 >> X4 >> X5 >> X6;
    cin >> Y1 >> Y2 >> Y3 >> Y4 >> Y5 >> Y6;
    
    long long ans = 1;
    
    ans *= (X4 - X3 + 1) * (Y4 - Y3 + 1) % MOD;
    ans %= MOD;
    
    ans *= (X6 - X5 + 1) * (Y6 - Y5 + 1) % MOD;
    ans %= MOD;
    
    cout << ans << endl;
    
    return 0;
}