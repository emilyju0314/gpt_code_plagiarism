#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int countLonelyNumbers(int n) {
    vector<bool> isFriend(n + 1, false);

    for (int i = 1; i <= n; i++) {
        for (int j = i * 2; j <= n; j += i) {
            int a = i;
            int b = j;
            int c = j / gcd(i, j);
            if (a + b > c && b + c > a && c + a > b) {
                isFriend[i] = true;
                isFriend[j] = true;
                isFriend[c] = true;
            }
        }
    }

    int lonelyCount = 0;
    for (int i = 1; i <= n; i++) {
        if (!isFriend[i]) {
            lonelyCount++;
        }
    }

    return lonelyCount;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        cout << countLonelyNumbers(n) << endl;
    }

    return 0;
}