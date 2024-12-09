#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = n - 1;
    int index = -1;

    for (int i = 0; i < n; i++) {
        int sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++) {
            if (j <= i) {
                sum1 += a[j];
            } else {
                sum2 += a[j];
            }
        }

        if (sum1 != sum2 && abs(sum1 - sum2) < ans) {
            ans = abs(sum1 - sum2);
            index = i;
        }
    }

    cout << n - 1 << endl;
    if (index == -1) {
        for (int i = 0; i < n; i++) {
            if (i != 0) cout << " ";
            cout << i+1;
        }
    } else {
        cout << index+1;
    }

    return 0;
}