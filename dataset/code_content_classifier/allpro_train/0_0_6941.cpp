#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> projects;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        projects.push_back({a, i});
    }

    sort(projects.begin(), projects.end(), greater<pair<int, int>>());

    vector<int> b(n, 0);
    int remaining = k;
    for(auto p : projects) {
        int a = p.first;
        int idx = p.second;
        b[idx] = min(a, remaining);
        remaining -= b[idx];
    }

    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }

    return 0;
}