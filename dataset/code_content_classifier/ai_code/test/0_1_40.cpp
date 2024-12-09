#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1); // 1-based indexing
    unordered_map<int, int> edgeCount;

    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
        edgeCount[x]++;
        edgeCount[y]++;
    }

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        queries[i] = make_pair(a, b);
    }

    vector<pair<int, vector<int>>> pathChoices;

    for(auto query : queries) {
        int a = query.first;
        int b = query.second;

        vector<bool> visited(n + 1, false);
        vector<int> path;

        visited[a] = true;
        path.push_back(a);

        bool found = false;

        while(a != b) {
            for(int neighbor : graph[a]) {
                if(!visited[neighbor]) {
                    visited[neighbor] = true;
                    path.push_back(neighbor);
                    a = neighbor;
                    found = true;
                    break;
                }
            }

            if(!found) {
                path.pop_back();
                a = path.back();
            }
        }

        for(int i = 0; i < path.size() - 1; i++) {
            edgeCount[path[i]]++;
            edgeCount[path[i+1]]++;
        }

        path.pop_back();
        pathChoices.push_back(make_pair(path.size(), path));
    }

    bool possible = true;
    for(auto count : edgeCount) {
        if(count.second % 2 != 0) {
            possible = false;
            break;
        }
    }

    if(possible) {
        cout << "YES" << endl;
        for(auto choice : pathChoices) {
            cout << choice.first << endl;
            for(int node : choice.second) {
                cout << node << " ";
            }
            cout << endl;
        }
    } else {
        cout << "NO" << endl;
        // Calculate minimum number of added queries and output it
        int addedQueries = 0;
        for(auto count : edgeCount) {
            if(count.second % 2 != 0) {
                addedQueries++;
            }
        }
        cout << addedQueries << endl;
    }

    return 0;
}