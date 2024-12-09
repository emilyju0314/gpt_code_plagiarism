#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int m;
    cin >> m;

    unordered_map<string, unordered_set<string>> friends;

    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        friends[a].insert(b);
        friends[b].insert(a);
    }

    cout << friends.size() << endl;

    for (auto& user : friends) {
        string name = user.first;
        int suggested_friends = 0;

        unordered_set<string> user_friends = user.second;

        for (auto& friend : friends) {
            if (friend.first != name && user_friends.find(friend.first) == user_friends.end()) {
                int common_friends = 0;

                for (auto& mutual_friend : friend.second) {
                    if (user_friends.find(mutual_friend) != user_friends.end()) {
                        common_friends++;
                    }
                }

                suggested_friends = max(suggested_friends, common_friends);
            }
        }

        cout << name << " " << suggested_friends << endl;
    }

    return 0;
}