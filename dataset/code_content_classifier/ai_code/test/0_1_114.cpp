#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);

        for(int i=0; i<n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        for(int i=1; i<=n/2; i++) {
            cout << a[n-i] << " " << a[i-1] << endl;
        }
    }

    return 0;
}