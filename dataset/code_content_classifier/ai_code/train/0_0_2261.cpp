#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    int positiveCount = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] > 0) {
            positiveCount++;
        }
    }

    if (positiveCount >= ceil((double)n/2)) {
        cout << 1 << endl;
    } else if (positiveCount == 0) {
        cout << 0 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}