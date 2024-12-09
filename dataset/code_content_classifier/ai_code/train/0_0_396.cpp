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

    long long sum = 0;
    long long diff = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i] * (i + 1) - diff;
        diff += a[i];
    }

    cout << sum << endl;
    return 0;
}