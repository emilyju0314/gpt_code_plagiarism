#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> a(n+1);
    vector<int> k(n);
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i < n; i++) {
        cin >> k[i];
    }
    
    int q;
    cin >> q;
    
    while (q--) {
        char type;
        cin >> type;
        
        if (type == '+') {
            int i, x;
            cin >> i >> x;
            a[i] += x;
            
            for (int j = i; j < n; j++) {
                if (a[j] + k[j] < a[j+1]) {
                    a[j+1] = a[j] + k[j];
                } else {
                    break;
                }
            }
        } else if (type == 's') {
            int l, r;
            cin >> l >> r;
            
            long long sum = 0;
            for (int j = l; j <= r; j++) {
                sum += a[j];
            }
            cout << sum << endl;
        }
    }
    
    return 0;
}