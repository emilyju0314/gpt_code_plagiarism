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
    int t;
    cin >> t;

    while (t--) {
        int x, p, k;
        cin >> x >> p >> k;

        vector<int> L;

        for (int y = x + 1; L.size() < k; y++) {
            if (gcd(p, y) == 1) {
                L.push_back(y);
            }
        }

        cout << L.back() << endl;
    }

    return 0;
}