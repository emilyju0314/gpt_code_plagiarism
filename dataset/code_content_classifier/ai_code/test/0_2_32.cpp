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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int maxK = 1;
        int lastSum = a[0];
        int currentK = 1;

        for (int i = 1; i < n; i++) {
            if (a[i] > lastSum) {
                currentK++;
                lastSum += a[i];
                maxK = max(maxK, currentK);
            } else {
                lastSum = a[i];
                currentK = 1;
            }
        }

        cout << maxK << endl;
    }

    return 0;
}