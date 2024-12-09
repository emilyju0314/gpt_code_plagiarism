#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k, q;
    cin >> n >> m >> k >> q;

    vector<pair<int, int>> scenario(k);
    for(int i = 0; i < k; i++) {
        cin >> scenario[i].first >> scenario[i].second;
    }

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
    }

    vector<int> status(m + 1, 0); // 0 means toy is free, 1 means child is playing with it
    vector<int> waiting(m + 1, 0); // For each toy, stores the child waiting for it

    for(auto s : scenario) {
        status[s.second] = 1; // Set toy as taken by a child
        waiting[s.second] = s.first; // Set the child who is playing with the toy
    }

    for(auto query : queries) {
        int x = query.first;
        int y = query.second;

        // Check if child x needs to wait for toy y
        if(status[y] == 1) {
            waiting[y] = min(waiting[y], x); // The child who requested the toy first will get it first
        } else {
            status[y] = 1;
            waiting[y] = x;
        }

        // Find the maximal crying set
        int max_waiting = 0;
        for(int i = 1; i <= m; i++) {
            if (waiting[i] > 0 && waiting[i] != x && waiting[i] != waiting[y]) {
                max_waiting++;
            }
        }
        cout << max_waiting << endl;
    }

    return 0;
}