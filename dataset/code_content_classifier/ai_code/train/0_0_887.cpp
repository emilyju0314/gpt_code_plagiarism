#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxFrequency = *max_element(a.begin(), a.end());
        int uniqueElements = count(a.begin(), a.end(), a[0]);
        
        if (uniqueElements > k) {
            cout << "-1" << endl;
        } else {
            cout << max(1, (maxFrequency + k - 1) / k) << endl;
        }
    }

    return 0;
}