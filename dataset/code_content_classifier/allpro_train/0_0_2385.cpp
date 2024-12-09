#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, vector<int>> chains;

    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        vector<int> chain(m);
        for (int j = 0; j < m; j++) {
            cin >> chain[j];
        }
        chains[chain[0]] = chain;
    }

    int total_seconds = 0;

    for (auto it = chains.begin(); it != chains.end(); it++) {
        total_seconds += it->second.size() - 1;
    }

    total_seconds += chains.size() - 1;

    cout << total_seconds << endl;

    return 0;
}