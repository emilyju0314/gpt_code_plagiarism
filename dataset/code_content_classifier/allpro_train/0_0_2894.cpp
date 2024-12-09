#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> goodPairs;
    for (int i = 0; i < m; i++) {
        int ik, jk;
        cin >> ik >> jk;
        goodPairs.push_back({ik, jk});
    }

    int maxOperations = 0;
    for (int i = 0; i < m; i++) {
        int ik = goodPairs[i].first;
        int jk = goodPairs[i].second;

        int commonDivisor = gcd(a[ik - 1], a[jk - 1]);
        while (commonDivisor != 1) {
            a[ik - 1] /= commonDivisor;
            a[jk - 1] /= commonDivisor;
            maxOperations++;
            commonDivisor = gcd(a[ik - 1], a[jk - 1]);
        }
    }

    cout << maxOperations << endl;

    return 0;
}