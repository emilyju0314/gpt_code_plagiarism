#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int>> doors;
vector<int> lights;
vector<vector<int>> switches;
bool visited[15];

void backtrack(int room, int steps, vector<string>& actions) {
    if(steps > 100) return; // to avoid infinite loops

    if(room == n) {
        for(int i = 0; i < n; i++) {
            if(i != n - 1 && lights[i] == 1) return; // doctor cannot enter darkened room
            if(i == n - 1 && lights[i] == 0) return; // doctor cannot leave if exit room is dark
        }

        cout << "You can go home in " << steps << " steps.\n";
        for(string action : actions) {
            cout << action << endl;
        }
        exit(0); // exit the program
    }

    visited[room] = true;

    for(int i = 0; i < n; i++) {
        if(!visited[i] && lights[i] == 1) {
            lights[i] = 0;
            actions.push_back("Switch off room " + to_string(i + 1));
            backtrack(i, steps + 1, actions);
            lights[i] = 1;
            actions.pop_back();
        }
    }

    for(int i = 0; i < doors[room].size(); i++) {
        int nextRoom = doors[room][i];
        if(lights[nextRoom] == 0) {
            lights[nextRoom] = 1;
            actions.push_back("Move to room " + to_string(nextRoom + 1));
            backtrack(nextRoom, steps + 1, actions);
            lights[nextRoom] = 0;
            actions.pop_back();
        }
    }

    visited[room] = false;
}

int main() {
    while(cin >> n >> m && n != 0 && m != 0) {
        doors.assign(n, vector<int>());
        lights.clear();
        switches.assign(n, vector<int>());

        for(int i = 0; i < m; i++) {
            int s, t;
            cin >> s >> t;
            doors[s-1].push_back(t-1);
            doors[t-1].push_back(s-1);
        }

        for(int i = 0; i < n; i++) {
            int light;
            cin >> light;
            lights.push_back(light);
        }

        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            for(int j = 0; j < k; j++) {
                int r;
                cin >> r;
                switches[i].push_back(r);
            }
        }

        vector<string> actions;
        memset(visited, false, sizeof(visited));
        backtrack(0, 0, actions);

        cout << "You can not switch off all lights.\n";
        cout << "Help me!\n";
    }

    return 0;
}