#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int max_val = 0;
    for (int i = 0; i < n-2; i++) {
        for (int j = i + 1; j < n-1; j++) {
            for (int k = j + 1; k < n; k++) {
                int val = a[i] | (a[j] & a[k]);
                max_val = max(max_val, val);
            }
        }
    }

    cout << max_val << endl;

    return 0;
}