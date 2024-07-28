#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    int t, scenario = 1;
    while (cin >> t && t) {
        cout << "Scenario #" << scenario++ << "\n";

        map<int, int> team_map;
        for (int i = 0; i < t; ++i) {
            int n, num;
            cin >> n;
            while (n--) {
                cin >> num;
                team_map[num] = i;
            }
        }

        queue<int> team_queue, team_member[1001];
        string cmd;
        while (cin >> cmd && cmd != "STOP") {
            if (cmd == "ENQUEUE") {
                int num;
                cin >> num;
                int team = team_map[num];
                if (team_member[team].empty()) {
                    team_queue.push(team);
                }
                team_member[team].push(num);
            }
            else if (cmd == "DEQUEUE") {
                int current_team = team_queue.front();
                int num = team_member[current_team].front();
                cout << num << "\n";
                team_member[current_team].pop();
                if (team_member[current_team].empty()) {
                    team_queue.pop();
                }
            }
        }
        cout << "\n";
    }

    return 0;
}