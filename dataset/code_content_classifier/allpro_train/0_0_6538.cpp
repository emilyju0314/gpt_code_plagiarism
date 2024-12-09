#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<char> s(n+1);
    vector<bool> visited(n+1, false);
    set<int> a, b, c;

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            s[i] = 'a';
            a.insert(i);

            for(int j : adj[i]) {
                s[j] = 'b';
                b.insert(j);
                visited[j] = true;

                for(int k : adj[j]) {
                    if(adj[i].count(k) == 0) {
                        s[k] = 'c';
                        c.insert(k);
                        visited[k] = true;
                    }
                }
            }
        }
    }

    bool valid = true;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'a' && (a.count(i) == 0 || (b.count(i) > 0 || c.count(i) > 0))) {
            valid = false;
            break;
        }
        if(s[i] == 'b' && (b.count(i) == 0 || (a.count(i) > 0 || c.count(i) > 0))) {
            valid = false;
            break;
        }
        if(s[i] == 'c' && (c.count(i) == 0 || (a.count(i) > 0 || b.count(i) > 0))) {
            valid = false;
            break;
        }
    }

    if(valid) {
        cout << "Yes" << endl;
        for(int i = 1; i <= n; i++) {
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}