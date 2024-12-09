#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

long long get_min_coins(vector<int>& a, vector<int>& b, vector<vector<int>>& sets) {
    int m = a.size();
    int n = b.size();

    // Sort elements of a and assign them index
    vector<pair<int, int>> sorted_a;
    for (int i = 0; i < m; i++) {
        sorted_a.push_back({a[i], i});
    }
    sort(sorted_a.begin(), sorted_a.end());

    // Sort elements of b and assign them index
    vector<pair<int, int>> sorted_b;
    for (int i = 0; i < n; i++) {
        sorted_b.push_back({b[i], i});
    }
    sort(sorted_b.begin(), sorted_b.end());

    // Initialize total coins needed
    long long total_coins = 0;

    // Create a mapping for set elements to index
    map<int, int> index_map;
    for (int i = 0; i < m; i++) {
        for (int element : sets[i]) {
            index_map[element] = i;
        }
    }

    // Iterate through sorted_b and find all elements to delete from sets
    vector<int> can_delete(m, 0);
    int ptr_a = 0, ptr_b = 0;
    while (ptr_b < n) {
        while (ptr_a < m && sorted_a[ptr_a].first <= sorted_b[ptr_b].first) {
            can_delete[sorted_a[ptr_a].second] = 1;
            ptr_a++;
        }
        ptr_b++;
    }

    // Calculate total coins needed to delete elements from sets
    for (int i = 0; i < m; i++) {
        for (int element : sets[i]) {
            if (can_delete[i]) {
                total_coins += a[i] + b[element-1];
            }
        }
    }

    return total_coins;
}

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<vector<int>> sets(m);
    for (int i = 0; i < m; i++) {
        int s;
        cin >> s;
        sets[i].resize(s);
        for (int j = 0; j < s; j++) {
            cin >> sets[i][j];
        }
    }

    long long result = get_min_coins(a, b, sets);
    cout << result << endl;

    return 0;
}