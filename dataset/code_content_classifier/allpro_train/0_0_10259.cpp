#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> onMeeting(n+1, 0);
    set<int> activeUsers;
    set<int> possibleLeaders;

    for (int i = 0; i < m; i++) {
        char sign;
        int id;
        cin >> sign >> id;

        if (sign == '+') {
            if (activeUsers.empty()) {
                possibleLeaders.insert(id);
            }
            activeUsers.insert(id);
        } else {
            activeUsers.erase(id);
            if (activeUsers.empty()) {
                possibleLeaders.erase(id);
            }
        }
    }

    if (possibleLeaders.size() == 0) {
        cout << "0" << endl;
    } else {
        cout << possibleLeaders.size() << endl;
        for (int leader : possibleLeaders) {
            cout << leader << " ";
        }
        cout << endl;
    }

    return 0;
}