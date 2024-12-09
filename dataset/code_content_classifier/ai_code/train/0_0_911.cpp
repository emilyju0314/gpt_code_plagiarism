#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> cowbells(n);
    for(int i = 0; i < n; i++) {
        cin >> cowbells[i];
    }

    int min_box_size = 0;
    int left = 0, right = k;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        bool possible = true;
        int j = 0, l = n - mid * 2;
        for (int i = 0; i < mid && possible; i++) {
            while (j < l && cowbells[j] + cowbells[l-1] <= cowbells[n-mid+i]) {
                j++;
            }
            l--;
            if (j >= l) {
                possible = false;
            }
        }
        if (possible) {
            min_box_size = cowbells[n-mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << min_box_size << endl;

    return 0;
}