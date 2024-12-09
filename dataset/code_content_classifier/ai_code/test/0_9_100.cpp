#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        int maxVal = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            maxVal = max(maxVal, arr[i]);
        }

        cout << maxVal << endl;
    }

    return 0;
}