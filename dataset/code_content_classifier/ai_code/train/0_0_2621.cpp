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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int min_operations = n-1;

        int min_val = *min_element(a.begin(), a.end());
        int max_val = *max_element(a.begin(), a.end());

        for(int i = 0; i < n; i++) {
            int ops_needed = max(i, n-1-i);
            int new_val = min(min_val, max_val - ops_needed);
            min_operations = min(min_operations, new_val - a[i]);
        }

        cout << min_operations << endl;
    }

    return 0;
}