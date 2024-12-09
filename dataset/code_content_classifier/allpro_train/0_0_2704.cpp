#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int countLonelyNumbers(int n) {
    vector<bool> isFriend(n+1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j && gcd(i, j) == 1) {
                int side1 = gcd(i, j);
                int side2 = i / gcd(i, j);
                int side3 = j / gcd(i, j);

                if ((side1 + side2 > side3) && (side2 + side3 > side1) && (side3 + side1 > side2)) {
                    isFriend[i] = true;
                    isFriend[j] = true;
                }
            }
        }
    }

    int lonelyCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!isFriend[i]) lonelyCount++;
    }

    return lonelyCount;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << countLonelyNumbers(n) << endl;
    }

    return 0;
}