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
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }

        long double k = (long double)sum / n;

        int count = 0;
        long long sum2 = 0;
        int i = 0, j = 0;

        while (j < n) {
          sum2 += a[j];

          if ((sum2 - a[i]) / (n - 2) == k && i < j-1) {
              count++;
              j++;
          } else if ((sum2 - a[i+1]) / (n - 2) == k) {
              count++;
              j++;
              i++;
          } else {
             sum2 -= a[i++];
             sum2 -= a[j];
          }
        }

        cout << count << endl;
    }

    return 0;
}