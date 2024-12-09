#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long d = 0;
        bool found = false;
        
        for (int i = 0; i < n - 1; i++) {
            if (a[i] % a[i+1] != 0 && a[i+1] % a[i] != 0) {
                d = a[i];
                found = true;
                break;
            }
        }
        
        if (found) {
            cout << d << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}