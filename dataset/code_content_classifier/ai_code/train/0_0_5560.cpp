#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        bool possible = false;
        int left = 0, right = n - 1;
        while (left <= right) {
            if (a[left] == k || a[right] == k) {
                possible = true;
                break;
            }
            left++;
            right--;
        }

        if (possible) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }

    return 0;
}