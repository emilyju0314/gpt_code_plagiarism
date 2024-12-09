#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int g = arr[0];
    for (int i = 1; i < n; i++) {
        g = gcd(g, arr[i]);
    }

    if (g > 1) {
        cout << "NO" << endl;
    } else {
        int group = 1;
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << group << " ";
            group = 3 - group;
        }
    }

    return 0;
}