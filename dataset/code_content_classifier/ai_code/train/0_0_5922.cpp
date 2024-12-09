#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    int online_count;
    cin >> online_count;
    unordered_set<int> online_users;
    for (int i = 0; i < online_count; i++) {
        int user_id;
        cin >> user_id;
        online_users.insert(user_id);
    }

    unordered_map<int, unordered_set<int>> friends;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        friends[u].insert(v);
        friends[v].insert(u);
    }

    for (int i = 0; i < q; i++) {
        char query_type;
        cin >> query_type;

        if (query_type == 'O') {
            int u;
            cin >> u;
            online_users.insert(u);
        } else if (query_type == 'F') {
            int u;
            cin >> u;
            online_users.erase(u);
        } else if (query_type == 'A') {
            int u, v;
            cin >> u >> v;
            friends[u].insert(v);
            friends[v].insert(u);
        } else if (query_type == 'D') {
            int u, v;
            cin >> u >> v;
            friends[u].erase(v);
            friends[v].erase(u);
        } else if (query_type == 'C') {
            int u;
            cin >> u;

            int count = 0;
            for (int friend : friends[u]) {
                if (online_users.find(friend) != online_users.end()) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}