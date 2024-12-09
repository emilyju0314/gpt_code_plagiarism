#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

#define MAXN 100005

// Data structure to represent the tree
vector<pair<int, string>> tree[MAXN];
string target;
unordered_map<string, int> substrings;

// Function to traverse the tree and build substrings defined by positions
void dfs(int u, string path) {
    for (auto child : tree[u]) {
        int v = child.first;
        string sv = child.second;

        string new_path = path + sv;

        substrings[new_path]++;

        dfs(v, new_path);
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int p;
        string s;
        cin >> p >> s;
        tree[p].push_back({i + 1, s});
    }

    cin >> target;

    dfs(1, "");

    int result = 0;
    int len = target.length();
    for (int i = 1; i < len; i++) {
        string prefix = target.substr(0, i);
        string suffix = target.substr(i);

        result += substrings[prefix] * substrings[suffix];
    }

    cout << result << endl;

    return 0;
}