#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int k = 0;
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            if (2 * a[i] <= sum) {
                b[i] = a[i] * 2;
                k++;
            } else {
                b[i] = a[i] / 2;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << b[i] << " ";
        }
        cout << endl;
    }

    return 0;
}