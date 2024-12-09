#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 998244353;

long long sumOfExtremeValues(vector<int>& a) {
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        int left = a[i], right = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] <= a[j+1]) {
            left = min(left, a[j]);
            sum = (sum + left) % MOD;
            j--;
        }
        j = i + 1;
        while (j < a.size() && a[j] <= a[j-1]) {
            right = min(right, a[j]);
            sum = (sum + right) % MOD;
            j++;
        }
    }
    return sum;
}

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
        long long result = sumOfExtremeValues(a);
        cout << result << endl;
    }

    return 0;
}