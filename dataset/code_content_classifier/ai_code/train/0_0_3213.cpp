#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int mid_idx = n / 2;
    int median = a[mid_idx];
    
    int operations = 0;
    for (int i = mid_idx; i < n - 1; i++) {
        int diff = a[i+1] - a[i];
        operations += diff * (i - mid_idx + 1);
        if (operations > k) {
            int gap = (k - operations + diff - 1) / diff;
            median += gap;
            break;
        }
        median = a[i+1];
    }

    cout << median << endl;

    return 0;
}