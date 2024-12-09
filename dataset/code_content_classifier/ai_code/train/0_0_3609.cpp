#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<pair<int, char>>> tree(n);
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        char c;
        cin >> v >> u >> c;
        v--; u--;
        tree[v].push_back({u, c});
        tree[u].push_back({v, c});
    }

    vector<string> special_words(m);
    for (int i = 0; i < m; i++) {
        cin >> special_words[i];
    }

    vector<vector<int>> power(n, vector<int>(m, 0));
    for (int k = 0; k < m; k++) {
        string sk = special_words[k];
        unordered_map<string, int> sk_counts;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < tree[i].size(); j++) {
                int u = tree[i][j].first;
                char c = tree[i][j].second;
                string f_ij = "";

                if (i > u) {
                    f_ij = sk_counts[to_string(u) + "-" + to_string(i) + "-" + c];
                } else {
                    f_ij = sk_counts[to_string(i) + "-" + to_string(u) + "-" + c];
                }

                f_ij += c;

                if (f_ij.length() > sk.length()) {
                    f_ij = f_ij.substr(1);
                }

                sk_counts[to_string(i) + "-" + to_string(u) + "-" + c] = f_ij;
                sk_counts[to_string(u) + "-" + to_string(i) + "-" + c] = f_ij;

                if (f_ij == sk) {
                    power[i][k]++;
                    power[u][k]++;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int a, b, k;
        cin >> a >> b >> k;
        a--; b--; k--;

        cout << power[a][k] + power[b][k] << endl;
    }

    return 0;
}