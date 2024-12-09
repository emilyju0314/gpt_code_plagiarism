#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m, h, t;
    cin >> n >> m >> h >> t;

    vector<pair<int, int>> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].first >> edges[i].second;
    }

    set<int> nodes;
    for (auto edge : edges) {
        nodes.insert(edge.first);
        nodes.insert(edge.second);
    }

    bool foundHydra = false;
    for (auto edge : edges) {
        int u = edge.first;
        int v = edge.second;

        vector<int> heads;
        vector<int> tails;

        for (auto node : nodes) {
            if (node != u && node != v && (int)heads.size() < h) {
                heads.push_back(node);
            } else if (node != u && node != v) {
                tails.push_back(node);
            }
        }

        if ((int)heads.size() == h && (int)tails.size() == t) {
            cout << "YES" << endl;
            cout << v << " " << u << endl;
            for (auto head : heads) {
                cout << head << " ";
            }
            cout << endl;
            for (auto tail : tails) {
                cout << tail << " ";
            }
            cout << endl;
            foundHydra = true;
            break;
        }
    }

    if (!foundHydra) {
        cout << "NO" << endl;
    }

    return 0;
}