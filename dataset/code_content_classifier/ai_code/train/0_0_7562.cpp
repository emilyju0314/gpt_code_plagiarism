#include <iostream>

using namespace std;

int main() {
    long long n, t;
    cin >> n >> t;
    
    int cnt = 0;
    for (int m = 1; m <= n; m++) {
        long long sum = 0;
        for (int i = 0; i <= m; i++) {
            sum ^= (m + 1 + i);
        }
        if (sum == t) {
            cnt++;
        }
    }
    
    cout << cnt << endl;
    
    return 0;
}