#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TrainJourney {
    string departure_time;
    string departure_station;
    string arrival_time;
    string arrival_station;
};

int main() {
    int N, T;
    cin >> N >> T;

    vector<TrainJourney> train_journeys(N);

    for (int i = 0; i < N; i++) {
        cin >> train_journeys[i].departure_time >> train_journeys[i].departure_station >> train_journeys[i].arrival_time >> train_journeys[i].arrival_station;
    }

    vector<pair<string, int>> explore_stations;

    for (int i = 1; i < N; i++) {
        string departure_time = train_journeys[i-1].arrival_time;
        string arrival_time = train_journeys[i].departure_time;
        int time_diff = ((arrival_time[0]-'0')*10 + (arrival_time[1]-'0'))*60 + ((arrival_time[3]-'0')*10 + (arrival_time[4]-'0')) - ((departure_time[0]-'0')*10 + (departure_time[1]-'0'))*60 - ((departure_time[3]-'0')*10 + (departure_time[4]-'0'));
        
        if (time_diff >= T) {
            explore_stations.push_back({train_journeys[i].arrival_station, time_diff});
        }
    }

    cout << explore_stations.size() << endl;
    for (auto station : explore_stations) {
        cout << station.first << " " << station.second << endl;
    }

    return 0;
}