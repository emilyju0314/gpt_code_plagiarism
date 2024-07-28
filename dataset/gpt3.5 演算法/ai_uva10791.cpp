#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n, caseNum = 1;
    
    while (cin >> n) {
        if (n == 0) break;
        
        cout << "Case " << caseNum << ": ";
        
        if (n == 1) {
            cout << 2 << endl;
        } else {
            if (n <= 2) {
                cout << n + 1 << endl;
            } else {
                long long ans = 0;
                for (long long i = 2; i <= sqrt(n); i++) {
                    if (n % i == 0) {
                        ans += i;
                        if (i != n/i) {
                            ans += n/i;
                        }
                    }
                }
                if (ans == 0) {
                    cout << n + 1 << endl;
                } else {
                    cout << ans << endl;
                }
            }
        }
        
        caseNum++;
    }
    
    return 0;
}
