#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    string planets;
    cin >> planets;

    vector<int> connections[N];
    for (int i = 0; i < M; i++) {
        int port1, port2;
        cin >> port1 >> port2;
        
        connections[port1].push_back(port2);
        connections[port2].push_back(port1);
    }

    vector<int> flights[N];
    vector<bool> used(4, false);

    for (int i = 0; i < N; i++) {
        for (int connected_port : connections[i]) {
            int num_flights = 1;
            while (num_flights == planets[i] - 'X' + 1 || num_flights == planets[connected_port] - 'X' + 1) {
                num_flights++;
            }

            flights[i].push_back(connected_port);
            flights[i].push_back(num_flights);
            flights[connected_port].push_back(i);
            flights[connected_port].push_back(num_flights);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < flights[i].size(); j += 2) {
            cout << i << " " << flights[i][j] << " " << flights[i][j + 1] << endl;
        }
    }

    return 0;
}