#include <iostream>
#include <vector>

using namespace std;

long long mergeAndCount(vector<int>& a, vector<int>& b) {
    vector<int> c;
    long long inversions = 0;

    // Merge the two arrays while counting inversions
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] <= b[j]) {
            c.push_back(a[i]);
            i++;
        } else {
            c.push_back(b[j]);
            inversions += a.size() - i; // Increment inversions by remaining elements in array a
            j++;
        }
    }

    // Add remaining elements from array a
    while (i < a.size()) {
        c.push_back(a[i]);
        i++;
    }

    // Add remaining elements from array b
    while (j < b.size()) {
        c.push_back(b[j]);
        j++;
    }

    // Copy the merged array back to a
    a = c;

    return inversions;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }

        // Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        // Find the minimum possible number of inversions
        long long totalInversions = mergeAndCount(a, b);

        cout << totalInversions << endl;
    }

    return 0;
}