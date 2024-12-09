#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        int prefix_sum = 0;
        int remaining_sum = 0;

        for (int j = 0; j < n; j++) {
            prefix_sum += a[j];
            remaining_sum += j;
            if (prefix_sum < remaining_sum) {
                cout << "NO" << endl;
                break;
            }
        }

        if (prefix_sum >= remaining_sum) {
            cout << "YES" << endl;
        }
    }

    return 0;
}