#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;

        if (k > (n-1)/2) {
            cout << -1 << endl;
            continue;
        }

        vector<int> permutation(n);
        for (int j = 0; j < n; j++) {
            permutation[j] = j + 1;
        }

        int peakCount = 0;
        for (int j = 1; j < n-1; j += 2) {
            if (peakCount == k) {
                break;
            }
            swap(permutation[j], permutation[j+1]);
            peakCount++;
        }

        for (int j = 0; j < n; j++) {
            cout << permutation[j] << " ";
        }
        cout << endl;
    }

    return 0;
}