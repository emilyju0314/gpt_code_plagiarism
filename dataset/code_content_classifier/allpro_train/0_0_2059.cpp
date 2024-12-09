#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> D(n);
    for(int i = 0; i < n; i++) {
        cin >> D[i];
    }

    vector<int> order(n);
    for(int i = 0; i < n; i++) {
        order[i] = i + 1;
    }

    sort(order.begin(), order.end(), [&](int a, int b) {
        return D[a - 1] < D[b - 1];
    });

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum += D[i];
    }

    if(D[order[0] - 1] != 0 || D[order[n - 1] - 1] * 2 > sum) {
        cout << -1 << endl;
        return 0;
    }

    vector<pair<int, int>> edges;
    for(int i = 1; i < n; i++) {
        edges.emplace_back(order[i - 1], order[i]);
    }

    cout << edges.size() << endl;
    for(auto edge : edges) {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}