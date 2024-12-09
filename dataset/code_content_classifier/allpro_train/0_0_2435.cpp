#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int curr_gcd = a[i];
            for (int k = i + 1; k <= j; k++) {
                curr_gcd = gcd(curr_gcd, a[k]);
            }
            b.push_back(curr_gcd);
        }
    }

    sort(b.begin(), b.end());

    vector<int> c;
    for (int i = 0; i < b.size(); i++) {
        int sum = 0;
        for (int j = i; j < b.size(); j++) {
            sum += b[j];
            c.push_back(sum);
        }
    }

    sort(c.begin(), c.end());

    int lower_median = c[(c.size() + 1) / 2 - 1];
    cout << lower_median << endl;

    return 0;
}