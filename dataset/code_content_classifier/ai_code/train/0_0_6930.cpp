#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> b(n/2);
    for (int i = 0; i < n/2; i++) {
        cin >> b[i];
    }

    sort(b.begin(), b.end());

    vector<long long> a(n);
    for (int i = 0; i < n/2; i++) {
        a[i] = b[i];
        a[n - i - 1] = b[i];
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    
    return 0;
}