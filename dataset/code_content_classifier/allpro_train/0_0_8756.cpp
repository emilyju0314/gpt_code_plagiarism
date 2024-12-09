#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dislikes(n+1);
    vector<int> salary(n+1, 0);
    vector<int> dangerousTriples(n+1, 0);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dislikes[a].push_back(b);
        dislikes[b].push_back(a);
        if (a < b) {
            salary[a] = a;
            salary[b] = a;
        } else {
            salary[a] = b;
            salary[b] = a;
        }
    }

    long long totalDangerousTriples = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < dislikes[i].size(); j++) {
            if (salary[i] > salary[dislikes[i][j]]) {
                dangerousTriples[dislikes[i][j]]++;
                totalDangerousTriples += dangerousTriples[i];
            }
        }
    }

    cout << totalDangerousTriples << endl;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v;
        cin >> v;

        totalDangerousTriples -= dangerousTriples[v];
        for (int j = 0; j < dislikes[v].size(); j++) {
            if (salary[v] > salary[dislikes[v][j]]) {
                totalDangerousTriples -= dangerousTriples[dislikes[v][j]];
                dangerousTriples[dislikes[v][j]]++;
                totalDangerousTriples += dangerousTriples[dislikes[v][j]];
            }
        }

        salary[v] = n + i + 1;

        cout << totalDangerousTriples << endl;
    }

    return 0;
}
