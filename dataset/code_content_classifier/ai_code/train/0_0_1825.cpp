#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<string, int> friendsMap;
    vector<string> friendsList(m);

    int happyFriends = 0;
    string currentHandle;
    bool changed = false;

    for (int i = 0; i < n; i++) {
        int event;
        cin >> event;

        if (event == 1) {
            if (changed) {
                for (int j = 0; j < m; j++) {
                    if (friendsList[j] != currentHandle) {
                        friendsMap[friendsList[j]] = 0;
                    }
                }
                currentHandle = "";
            }
            changed = true;
        } else {
            string friendName;
            cin >> friendName;

            if (friendsMap[friendName] == 0) {
                happyFriends++;
                friendsMap[friendName] = 1;
            }

            friendsList.push_back(friendName);
            if (currentHandle == "") {
                currentHandle = friendName;
            }
        }
    }

    cout << happyFriends << endl;

    return 0;
}