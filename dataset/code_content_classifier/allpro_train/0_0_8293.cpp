#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int gcd = A[0];
    for (int i = 1; i < N; i++) {
        gcd = __gcd(gcd, A[i]);
    }
    
    int ans = 1;
    for (int i = 1; i * i <= gcd; i++) {
        if (gcd % i == 0) {
            ans = max(ans, i);
            if (gcd / i != i) {
                ans = max(ans, gcd / i);
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}