#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> groups(n);
    for(int i = 0; i < n; i++) {
        cin >> groups[i];
    }

    vector<unordered_set<int>> adjList(n);
    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // 0-indexed
        if(groups[a] != groups[b]) {
            adjList[a].insert(b);
            adjList[b].insert(a);
        }
    }

    unordered_map<int, int> groupSize;
    for(int i = 0; i < n; i++) {
        groupSize[groups[i]]++;
    }

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        int groupA = groups[i];
        for(int j : adjList[i]) {
            int groupB = groups[j];
            if(groupA == groupB) continue;
            ans += (n - groupSize[groupA] - groupSize[groupB] + 1);
        }
    }

    ans /= 2; // Each pair of groups is counted twice

    cout << ans << endl;

    return 0;
}