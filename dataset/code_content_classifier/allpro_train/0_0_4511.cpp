#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<double> a(n);
    vector<int> b(n);

    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    for (int i = 0; i < n; i++) {
        b[i] = round(a[i]);
        if (sum < 0 && b[i] < a[i]) {
            b[i]++;
            sum++;
        } else if (sum > 0 && b[i] > a[i]) {
            b[i]--;
            sum--;
        }
        cout << b[i] << endl;
    }

    return 0;
}