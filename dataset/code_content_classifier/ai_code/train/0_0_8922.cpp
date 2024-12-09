#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<pair<int, int>> knights;
    vector<bool> canceled(q, false);

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if (type == '+') {
            int t, d;
            cin >> t >> d;
            knights.push_back({t, d});
        } else if (type == '-') {
            int i;
            cin >> i;
            canceled[i - 1] = true;
        } else {
            int t;
            cin >> t;

            int waiting_time = 0;
            for (int j = 0; j < knights.size(); j++) {
                if (!canceled[j] && knights[j].first <= t) {
                    waiting_time += max(0, knights[j].second - (t - knights[j].first));
                }
            }

            cout << waiting_time << endl;
        }
    }

    return 0;
}