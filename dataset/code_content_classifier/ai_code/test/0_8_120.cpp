#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int l, r;
        cin >> l >> r;

        // Find the leftmost bit position where l and r differ
        int diff = r - l;
        int bit = 0;
        while ((diff >> bit) > 0) {
            bit++;
        }

        // Calculate the minimum number of elements to delete
        int answer = (1 << bit) - 1;
        cout << answer << endl;
    }

    return 0;
}