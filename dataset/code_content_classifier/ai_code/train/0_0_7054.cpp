#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Island {
    long long l, r;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Island> islands(n);
    for (int i = 0; i < n; i++) {
        cin >> islands[i].l >> islands[i].r;
    }

    vector<long long> bridges(m);
    for (int i = 0; i < m; i++) {
        cin >> bridges[i];
    }

    vector<long long> bridge_idx;
    bool possible = true;

    for (int i = 0; i < n - 1; i++) {
        long long dist = islands[i + 1].l - islands[i].r;
        long long bridge = -1;
        
        for (int j = 0; j < m; j++) {
            if (bridges[j] == dist) {
                bridge = j + 1;
                break;
            }
        }

        if (bridge == -1) {
            possible = false;
            break;
        }
        
        bridge_idx.push_back(bridge);
    }

    if (possible) {
        cout << "Yes" << endl;
        for (int i = 0; i < bridge_idx.size(); i++) {
            cout << bridge_idx[i] << " ";
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}