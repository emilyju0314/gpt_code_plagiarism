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

    vector<pair<int, int>> segments(m);
    for (int i = 0; i < m; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int g = segments[0].second - segments[0].first;
    for (int i = 1; i < m; i++) {
        g = gcd(g, segments[i].second - segments[i].first);
    }

    bool isSymmetrical = false;
    for (int k = 1; k < n; k++) {
        if ((n % gcd(n, k) == 0) && (g % gcd(n, k) == 0)) {
            isSymmetrical = true;
            break;
        }
    }

    if (isSymmetrical) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}