#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> s(n);

    for (int step = 0; step < k; step++) {
        s[0] = a[0];
        for (int i = 1; i < n; i++) {
            s[i] = (s[i-1] + a[i]) % 1000000007;
        }

        a = s;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}