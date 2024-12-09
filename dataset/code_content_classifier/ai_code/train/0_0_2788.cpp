#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> ratings(n);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> ratings[i];
            sum += ratings[i];
        }

        if (sum == x * n) {
            cout << "0\n";
        } else if (sum == x * n || sum - x == 0) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }

    return 0;
}