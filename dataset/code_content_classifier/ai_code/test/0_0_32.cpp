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

        int maxSegments = 1;
        int prevSum = 0;
        int currSum = 0;

        for (int i = 0; i < n; i++) {
            currSum += a[i];
            if (currSum <= prevSum) {
                break;
            }
            maxSegments++;
            prevSum = currSum;
        }

        cout << maxSegments - 1 << endl;
    }

    return 0;
}