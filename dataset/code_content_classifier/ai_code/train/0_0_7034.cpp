#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Check if it is possible to remove all stones
        bool possible = false;
        for(int i = 0; i < n-1; i++) {
            if(a[i] == 0) continue;
            if(a[i] > a[i+1]) {
                swap(a[i], a[i+1]);
            }
            a[i+1] -= a[i];
            a[i] = 0;
        }

        if(a[n-1] == 0) possible = true;

        // Output the result
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}