#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> path;
vector<int> occurrences;
map<int, int> count;

void dfs(vector<vector<int>>& tree, vector<int>& values, int node) {
    path.push_back(values[node]);
    count[values[node]]++;
    for(int i = 0; i < tree[node].size(); i++) {
        dfs(tree, values, tree[node][i]);
    }
    occurrences.push_back(count[values[node]]);
    count[values[node]]--;
    if(count[values[node]] == 0) {
        count.erase(values[node]);
    }
    path.pop_back();
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        vector<int> values(n);
        for(int i = 0; i < n; i++) {
            cin >> values[i];
        }

        vector<vector<int>> tree(n);
        for(int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            tree[parent - 1].push_back(i);
        }

        for(int i = 0; i < q; i++) {
            int v, l, k;
            cin >> v >> l >> k;
            v--;

            path.clear();
            occurrences.clear();
            count.clear();

            dfs(tree, values, v);

            map<int, vector<int> > occurrence_map;
            for(int j = 0; j < path.size(); j++) {
                if(occurrences[j] >= l) {
                    occurrence_map[occurrences[j]].push_back(path[j]);
                }
            }

            vector<int> remaining_values;
            for(auto it = occurrence_map.begin(); it != occurrence_map.end(); it++) {
                for(int val : it->second) {
                    remaining_values.push_back(val);
                }
            }

            sort(remaining_values.begin(), remaining_values.end());

            if(k <= remaining_values.size()) {
                cout << remaining_values[k - 1] << " ";
            } else {
                cout << "-1 ";
            }
        }
        cout << endl;
    }

    return 0;
}