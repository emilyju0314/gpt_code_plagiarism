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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> segments(m);

    for (int i = 0; i < m; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int dist = segments[0].second - segments[0].first;
    if (dist < 0) {
        dist += n;
    }

    for (int i = 1; i < m; i++) {
        int new_dist = segments[i].second - segments[i].first;
        if (new_dist < 0) {
            new_dist += n;
        }
        dist = gcd(dist, new_dist);
    }

    if (dist > 1 && n % dist == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}