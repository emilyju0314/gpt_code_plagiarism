#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Diamond {
    int a, w, v;
};

bool comparator(const Diamond& d1, const Diamond& d2) {
    if (d1.v == d2.v) {
        return d1.w < d2.w;
    }
    return d1.v > d2.v;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Diamond> diamonds(n);
    for (int i = 0; i < n; i++) {
        cin >> diamonds[i].a >> diamonds[i].w >> diamonds[i].v;
    }

    sort(diamonds.begin(), diamonds.end(), comparator);

    vector<pair<int, int>> sold(n, make_pair(0, 0)); // sold[k] = {count, remaining}
    long long totalValue = 0;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int k, d;
            cin >> k >> d;
            d--;
            diamonds[d].a += k;
        } else if (t == 2) {
            int k, d;
            cin >> k >> d;
            d--;
            int soldCount = min(k, diamonds[d].a);
            sold[d].first += soldCount;
            sold[d].second = diamonds[d].a - soldCount;
            diamonds[d].a -= soldCount;
            totalValue += soldCount * diamonds[d].v;
        } else {
            long long c;
            cin >> c;
            long long currentWeight = c;
            long long currentValue = 0;
            for (int j = 0; j < n && currentWeight > 0; j++) {
                int amount = min(sold[j].first, static_cast<int>(currentWeight / diamonds[j].w));
                currentWeight -= amount * diamonds[j].w;
                currentValue += amount * diamonds[j].v;
            }
            cout << currentValue << endl;
        }
    }

    return 0;
}