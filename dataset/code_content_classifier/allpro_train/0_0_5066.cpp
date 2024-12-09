#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> coefficients(n+1);
    for(int i = 0; i <= n; i++) {
        cin >> coefficients[i];
    }
    
    long long ans = 0;
    for(int i = 0; i <= n; i++) {
        if(i == n) {
            if(abs(coefficients[i]) + 1 <= k) {
                ans++;
            }
        } else {
            long long change = pow(2, n-i);
            if(abs(coefficients[i]) + 1 <= k) {
                ans += change;
            }
            if(abs(coefficients[i]) - 1 >= -k) {
                ans += change;
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}