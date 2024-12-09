#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int l = 0, r = 1;
        int max_diff = numeric_limits<int>::min(); // Initialize to negative infinity
        for(int i = 0; i < n-1; i++) {
            if(a[i] < a[i+1]) {
                if(a[i+1] - a[l] >= r-l) {
                    max_diff = a[i+1] - a[l];
                    r = i+2;
                }
            } else {
                l = i;
            }
        }

        if(max_diff < r-l) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << l+1 << " " << r << endl;
        }
    }

    return 0;
}