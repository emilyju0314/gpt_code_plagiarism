#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void circularShift(vector<int>& a, int l, int r) {
    if (l < r) {
        int tmp = a[r];
        for (int i = r; i > l; i--) {
            a[i] = a[i-1];
        }
        a[l] = tmp;
    }
}

int findMinValue(vector<int>& a, int l, int r) {
    int minVal = a[l];
    for (int i = l+1; i <= r; i++) {
        minVal = min(minVal, a[i]);
    }
    return minVal;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            circularShift(a, y, z);
        } else if (x == 1) {
            cout << findMinValue(a, y, z) << endl;
        } else if (x == 2) {
            a[y] = z;
        }
    }

    return 0;
}