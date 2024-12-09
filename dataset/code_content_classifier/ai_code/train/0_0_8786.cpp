#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> misha(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        misha[i] = make_pair(x, y);
    }

    vector<pair<int, int>> sasha(m);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        sasha[i] = make_pair(x, y);
    }

    // Check if it is possible to build a fence
    bool possible = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int dist_sq = (misha[i].first - sasha[j].first) * (misha[i].first - sasha[j].first) +
                          (misha[i].second - sasha[j].second) * (misha[i].second - sasha[j].second);
            if(dist_sq == 0) {
                possible = false;
                break;
            }
        }
        if(!possible) {
            break;
        }
    }

    if(possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}