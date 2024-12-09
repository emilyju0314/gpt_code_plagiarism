#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<set<int>> friends(N+1);

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].insert(v);
        friends[v].insert(u);
    }

    for (int i = 1; i <= N; i++) {
        if (friends[i].size() >= 4) {
            cout << i << " ";
            for (int j = 1; j <= N; j++) {
                if (j != i && friends[j].find(i) == friends[j].end() && friends[j].size() >= 4) {
                    cout << j << " ";
                    for (int k = 1; k <= N; k++) {
                        if (k != i && k != j && friends[k].find(i) == friends[k].end() && friends[k].find(j) == friends[k].end() && friends[k].size() >= 4) {
                            cout << k << " ";
                            for (int l = 1; l <= N; l++) {
                                if (l != i && l != j && l != k && friends[l].find(i) == friends[l].end() && friends[l].find(j) == friends[l].end() && friends[l].find(k) == friends[l].end() && friends[l].size() >= 4) {
                                    cout << l << " ";
                                    for (int m = 1; m <= N; m++) {
                                        if (m != i && m != j && m != k && m != l && friends[m].find(i) == friends[m].end() && friends[m].find(j) == friends[m].end() && friends[m].find(k) == friends[m].end() && friends[m].find(l) == friends[m].end()) {
                                            cout << m << endl;
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << -1 << endl;

    return 0;
}