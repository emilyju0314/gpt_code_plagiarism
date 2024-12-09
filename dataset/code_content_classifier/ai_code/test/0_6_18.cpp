#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d;
        cin >> n >> d;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> b = a;
        int steps = 0;
        int count_of_ones = count(a.begin(), a.end(), 1);

        if (count_of_ones == 0) {
            cout << "0" << endl;
            continue;
        }

        while (true) {
            steps++;
            vector<int> b_new(n, 0);
            for (int i = 0; i < n; i++) {
                b_new[i] = a[i] & b[(i + n - d) % n];
            }

            swap(b, b_new);

            if (b == a) {
                cout << "-1" << endl;
                break;
            }

            count_of_ones = count(b.begin(), b.end(), 1);
            if (count_of_ones == 0) {
                cout << steps << endl;
                break;
            }
        }
    }

    return 0;
}