#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
string labels;
unordered_map<char, int> labelCount[N][2];

int answer[N];

void dfs(int u, int parent, vector<int> &palindromeCount) {
    palindromeCount[0][labelCount[u][0][labels[u]]]++;
    for(int v : adj[u]) {
        if(v != parent) {
            vector<int> childPalindromeCount(2);
            dfs(v, u, childPalindromeCount);
            palindromeCount[1][labelCount[v][1][labels[u]]]++;
            for(auto [ch, count] : labelCount[v][0]) {
                answer[u] += count * palindromeCount[0][!labelCount[u][1][ch]];
                answer[u] += count * palindromeCount[1][!labelCount[u][1][ch]];
            }
            for(auto [ch, count] : labelCount[v][1]) {
                answer[u] += count * palindromeCount[0][!labelCount[u][0][ch]];
                answer[u] += count * palindromeCount[1][!labelCount[u][0][ch]];
            }
            for(auto [ch, count] : labelCount[v][0])
                labelCount[u][0][ch] += count;
            for(auto [ch, count] : labelCount[v][1])
                labelCount[u][1][ch] += count;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cin >> labels;

    for(int i = 0; i < n; i++) {
        labelCount[i][0][labels[i]] = 1;
        labelCount[i][1][labels[i]] = 1;
    }

    vector<int> palindromeCount(2);
    dfs(0, -1, palindromeCount);

    for(int i = 0; i < n; i++) {
        cout << answer[i] + palindromeCount[0][labelCount[i][1][labels[i]]] + palindromeCount[1][labelCount[i][0][labels[i]]] << " ";
    }
    cout << endl;

    return 0;
}