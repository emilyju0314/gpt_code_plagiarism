#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    long long sumA = 0, sumB = 0;
    int countA = 0, countB = 0;
    int maxLength = 0;

    for (int i = 0, j = 0; i < n && j < m;) {
        if (sumA == sumB) {
            sumA = 0;
            sumB = 0;
            maxLength += max(countA, countB);
            countA = 0;
            countB = 0;
        }
        
        if (sumA <= sumB) {
            sumA += a[i++];
            countA++;
        }
        else {
            sumB += b[j++];
            countB++;
        }
    }

    if (sumA == sumB) {
        maxLength += max(countA, countB);
        cout << maxLength << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}