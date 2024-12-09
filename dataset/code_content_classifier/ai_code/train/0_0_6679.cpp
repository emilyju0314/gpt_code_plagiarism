#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperationsToSort(vector<int>& a) {
    int n = a.size();
    vector<int> freq(n+1, 0);
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }

    int ans = INT_MAX;
    int totalX = 0;
    for (int i = 1; i <= n; i++) {
        totalX += freq[i];
        ans = min(ans, totalX - freq[i]);
    }

    return ans;
}

int main() {
    int q;
    cin >> q;

    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Calculate and print the minimum number of operations
        int result = minOperationsToSort(a);
        cout << result << endl;
    }

    return 0;
}