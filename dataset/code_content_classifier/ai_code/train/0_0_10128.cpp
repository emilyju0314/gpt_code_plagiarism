#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int datasets;
    cin >> datasets;

    while(datasets--) {
        int n, m;
        cin >> n >> m;

        int natsume_room, lennon_room;
        cin >> natsume_room >> lennon_room;

        vector<vector<pair<int, char>>> rooms(n+1);
        vector<int> dist(n+1, -1);

        for(int i = 0; i < m; i++) {
            int room1, room2;
            char type;
            cin >> room1 >> room2 >> type;

            rooms[room1].push_back({room2, type});
            rooms[room2].push_back({room1, type});
        }

        queue<int> q;
        q.push(natsume_room);
        dist[natsume_room] = 0;

        while(!q.empty()) {
            int curr_room = q.front();
            q.pop();

            if(curr_room == lennon_room) {
                cout << dist[lennon_room] << endl;
                break;
            }

            for(auto adj_room : rooms[curr_room]) {
                int next_room = adj_room.first;
                char door_type = adj_room.second;

                if(dist[next_room] == -1) {
                    if(door_type == 'N') {
                        dist[next_room] = dist[curr_room];
                    } else {
                        dist[next_room] = dist[curr_room] + 1;
                    }
                    q.push(next_room);
                }
            }
        }
    }

    return 0;
}