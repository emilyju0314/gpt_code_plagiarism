#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }

    vector<pair<int, int>> edges;
    for(int i = 1; i < n; i++) {
        if(p[i-1] > p[i]) {
            cout << "NO" << endl;
            return 0;
        }
        edges.push_back({p[i-1], p[i]});
    }

    cout << "YES" << endl;
    for(int i = 0; i < n-1; i++) {
        cout << edges[i].first << " " << edges[i].second << endl;
    }

    return 0;
}