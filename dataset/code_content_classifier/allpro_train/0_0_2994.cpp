#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> left(n), right(n);

    for (int i = 0; i < n; i++) {
        cin >> left[i] >> right[i];
    }

    long long totalLength = 0;
    for (int i = 1; i <= m; i++) {
        int cntEven = 0, cntOdd = 0;
        for (int j = 0; j < n; j++) {
            if (left[j] <= i && right[j] >= i) {
                if ((right[j] - i) % 2 == 0) {
                    cntEven++;
                } else {
                    cntOdd++;
                }
            }
        }
        if (cntEven == 0 || cntOdd == 0) {
            totalLength += m - i + 1;
        }
    }

    cout << totalLength << endl;

    return 0;
}