#include <iostream>
#include <vector>

using namespace std;

int countSimpleSegments(int n, vector<int>& a, string& b) {
    int count = 0;
    vector<double> products(n);
    products[0] = a[0];

    for (int i = 1; i < n; i++) {
        if (b[i] == '/') {
            products[i] = products[i-1] / a[i];
        } else {
            products[i] = products[i-1] * a[i];
        }
    }

    for (int l = 0; l < n; l++) {
        double x = 1;
        for (int r = l; r < n; r++) {
            x *= a[r];
            if (r > l) x /= products[r-1];
            if (x == (int)x) count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    string b;
    cin >> b;

    int result = countSimpleSegments(n, a, b);
    cout << result << endl;

    return 0;
}