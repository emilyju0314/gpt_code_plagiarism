#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    vector<int> fib(n + 2);
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n + 2; i++) {
        fib[i] = (fib[i-1] + fib[i-2]) % 1000000000;
    }
    
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int xi, vi;
            cin >> xi >> vi;
            a[xi-1] = vi;
        } else if (t == 2) {
            int li, ri, sum = 0;
            cin >> li >> ri;
            for (int j = li-1; j < ri; j++) {
                sum = (sum + a[j] * fib[j-li+2]) % 1000000000;
            }
            cout << sum << endl;
        } else if (t == 3) {
            int li, ri, di;
            cin >> li >> ri >> di;
            for (int j = li-1; j < ri; j++) {
                a[j] += di;
            }
        }
    }
    
    return 0;
}