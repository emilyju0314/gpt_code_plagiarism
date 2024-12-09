#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        unordered_map<int, int> role; // 0: undecided, 1: crewmate, 2: imposter
        vector<vector<pair<int, string>>> comments(n + 1);

        for (int i = 0; i < m; i++) {
            int x, y;
            string c;
            cin >> x >> y >> c;
            comments[x].push_back({y, c});
            comments[y].push_back({x, (c == "crewmate" ? "imposter" : "crewmate")});
        }

        queue<int> q;
        for (int i = 1; i <= n; i++) {
            if (role[i] == 0) {
                q.push(i);
                role[i] = 1;

                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();

                    for (auto comment : comments[cur]) {
                        int next = comment.first;
                        string c = comment.second;

                        if (role[next] == 0) {
                            role[next] = (c == "crewmate" ? 1 : 2);
                            q.push(next);
                        } else if (role[next] != (c == "crewmate" ? 1 : 2)) {
                            cout << "-1\n";
                            goto end;
                        }
                    }
                }
            }
        }

        int imposters = 0;
        for (int i = 1; i <= n; i++) {
            imposters += (role[i] == 2);
        }
        cout << imposters << "\n";

        end: continue;
    }

    return 0;
}