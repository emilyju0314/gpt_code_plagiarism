#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        vector<int> b(7);
        vector<int> a(3);

        for (int i = 0; i < 7; i++) {
            cin >> b[i];
        }

        // From the given array b, we can observe that a[0] = b[0], a[1] = b[1] - a[0], a[2] = b[2] - a[0].
        // Because a is a sorted array, the above logic will hold due to the properties of non-empty subsequences.
        a[0] = b[0];
        a[1] = b[1] - a[0];
        a[2] = b[2] - a[0];

        cout << a[0] << " " << a[1] << " " << a[2] << endl;
    }

    return 0;
}