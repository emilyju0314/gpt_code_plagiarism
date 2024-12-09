#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int min_element = *min_element(a.begin(), a.end());
        bool possible = true;
        
        for (int i = 0; i < n; i++) {
            if (a[i] % min_element != 0 && a[i] != min_element) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}