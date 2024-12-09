#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    deque<pair<long long, long long>> train; // pair of A_i value and car index

    train.push_back({0, 1});

    long long b = 0, s = 0;
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int k;
            cin >> k;
            n += k;
            for (int j = 1; j <= k; j++) {
                train.push_front({b + (j - 1) * s, n - j + 1});
            }
        } else if (type == 2) {
            int k;
            cin >> k;
            for (int j = 1; j <= k; j++) {
                train.push_back({b + (n + j - 1) * s, n + j});
            }
            n += k;
        } else {
            int new_b, new_s;
            cin >> new_b >> new_s;
            b = new_b;
            s = new_s;
            for (int j = 0; j < n; j++) {
                train[j].first = b + j * s;
            }
        }

        auto min_element = min_element(train.begin(), train.end());
        cout << min_element->second << " " << min_element->first << endl;
    }

    return 0;
}