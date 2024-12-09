#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    while (true) {
        string query;
        cin >> query;
        
        if (query == "done") {
            cout << "done" << endl;
            cout.flush();
            break;
        }
        
        if (query == "stop") {
            break;
        }
        
        vector<vector<int>> groups;
        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            string group;
            cin >> group;
            vector<int> players;
            for (char c : group) {
                players.push_back(c - '0');
            }
            groups.push_back(players);
        }
        
        if (groups.size() == 1) {
            // All players are in the same vertex
            vector<int> to_move = groups[0];
            cout << "next ";
            for (int player : to_move) {
                cout << player << " ";
            }
            cout << endl;
            cout.flush();
        } else {
            // Move players to reduce the number of groups
            int i = 0;
            for (auto& group : groups) {
                if (group.size() == 1) {
                    cout << "next " << group[0] << " ";
                    cout.flush();
                } else {
                    cout << "next ";
                    for (int player : group) {
                        cout << player << " ";
                    }
                    cout.flush();
                }
            }
            cout << endl;
            cout.flush();
        }
    }

    return 0;
}