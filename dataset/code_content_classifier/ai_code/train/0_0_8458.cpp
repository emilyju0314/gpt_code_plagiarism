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

    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            r--;

            bool almostCorrect = false;
            for (int i = l; i <= r; i++) {
                int temp = arr[i];
                arr[i] = x;

                int currentGcd = arr[l];
                for (int j = l + 1; j <= r; j++) {
                    currentGcd = gcd(currentGcd, arr[j]);
                }

                if (currentGcd == x) {
                    almostCorrect = true;
                }

                arr[i] = temp;
            }

            if (almostCorrect) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else if (type == 2) {
            int i, y;
            cin >> i >> y;
            i--;

            arr[i] = y;
        }
    }

    return 0;
}