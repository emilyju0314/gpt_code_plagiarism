#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bitwiseOR(vector<int>& a, vector<int>& b) {
    int n = a.size();
    int maxSum = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int sum = 0;
            for (int i = l; i <= r; i++) {
                sum |= a[i];
            }
            for (int i = l; i <= r; i++) {
                sum |= b[i];
            }
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int result = bitwiseOR(a, b);
    cout << result << endl;

    return 0;
}