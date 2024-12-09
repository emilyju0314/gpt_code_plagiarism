#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = a[0];
    for(int i = 1; i < n; i++) {
        result = gcd(result, a[i]);
    }

    cout << result << endl;

    return 0;
}