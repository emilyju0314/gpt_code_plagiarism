#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<set<int>> friends(N + 1);
    vector<set<int>> blocks(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }

    for (int i = 0; i < K; i++) {
        int c, d;
        cin >> c >> d;
        blocks[c].insert(d);
        blocks[d].insert(c);
    }

    for (int user = 1; user <= N; user++) {
        set<int> candidates;
        for (int candidate = 1; candidate <= N; candidate++) {
            if (user == candidate) continue;

            if (friends[user].count(candidate) > 0 || blocks[user].count(candidate) > 0) continue;

            bool reachable = false;
            for (int friend : friends[user]) {
                if (friends[candidate].count(friend) > 0) {
                    reachable = true;
                    break;
                }
            }

            if (reachable) {
                candidates.insert(candidate);
            }
        }

        cout << candidates.size() << " ";
    }

    cout << endl;

    return 0;
}