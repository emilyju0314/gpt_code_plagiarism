#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TrainStop {
    int station;
    int time;
};

int convertTimeToMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));
    return hours * 60 + minutes;
}

int main() {
    int S, T;
    while (true) {
        cin >> S >> T;
        if (S == 0 && T == 0) {
            break;
        }
        
        int D, TimeD, A, TimeA;
        cin >> D >> TimeD >> A >> TimeA;
        
        vector<vector<TrainStop>> trains(T);
        for (int i = 0; i < T; i++) {
            int N;
            cin >> N;
            trains[i] = vector<TrainStop>(N);
            for (int j = 0; j < N; j++) {
                int station, time;
                cin >> station >> time;
                trains[i][j] = {station, convertTimeToMinutes(to_string(time))};
            }
        }
        
        int maxSleep = 0;
        for (int i = 0; i < T; i++) {
            int currentStation = D;
            int currentTime = TimeD;
            int sleepTime = 0;
            bool possible = true;
            for (int j = 0; j < trains[i].size(); j++) {
                if (trains[i][j].station == currentStation) {
                    if (trains[i][j].time >= currentTime) {
                        sleepTime += trains[i][j].time - currentTime;
                        currentTime = trains[i][j].time;
                    } else {
                        possible = false;
                        break;
                    }
                } else {
                    if (trains[i][j].time >= currentTime) {
                        sleepTime += trains[i][j].time - currentTime;
                        currentTime = trains[i][j].time;
                    } else {
                        possible = false;
                        break;
                    }
                }
                currentStation = trains[i][j].station;
            }
            if (possible && currentStation == A && currentTime <= TimeA) {
                maxSleep = max(maxSleep, sleepTime);
            }
        }
        
        if (maxSleep > 0) {
            cout << maxSleep << endl;
        } else {
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}