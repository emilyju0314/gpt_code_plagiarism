#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool rearrangePatterns(int n, int m, int k, vector<string>& patterns, vector<pair<string, int>>& strings) {
    vector<unordered_set<int>> adjList(n);
    vector<int> inDegree(n, 0);
    vector<int> order;
    
    for (int i = 0; i < m; i++) {
        int index = strings[i].second - 1;
        for (int j = 0; j < n; j++) {
            if (j != index) {
                bool matchesFirst = true, matchesOther = true;
                for (int p = 0; p < k; p++) {
                    if (patterns[index][p] != '_' && patterns[j][p] != '_' && patterns[index][p] != patterns[j][p]) {
                        matchesFirst = false;
                        break;
                    }
                    if (patterns[index][p] != '_' && patterns[j][p] != '_' && patterns[index][p] == patterns[j][p]) {
                        matchesOther = false;
                        break;
                    }
                }
                if (matchesFirst) {
                    adjList[index].insert(j);
                    inDegree[j]++;
                } else if (matchesOther) {
                    adjList[j].insert(index);
                    inDegree[index]++;
                }
            }
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        order.push_back(node);
        for (int neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    
    return order.size() == n;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> patterns(n);
    vector<pair<string, int>> strings(m);
    
    for (int i = 0; i < n; i++) {
        cin >> patterns[i];
    }
    
    for (int i = 0; i < m; i++) {
        cin >> strings[i].first >> strings[i].second;
    }
    
    if (rearrangePatterns(n, m, k, patterns, strings)) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << i + 1 << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}