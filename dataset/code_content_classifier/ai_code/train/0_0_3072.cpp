#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct GasStation {
    int type;
    int position;
};

bool compareGasStation(const GasStation& a, const GasStation& b) {
    return a.position < b.position;
}

int main() {
    int e, s, n, m;
    cin >> e >> s >> n >> m;

    vector<GasStation> gasStations;
    for (int i = 0; i < n; i++) {
        GasStation station;
        cin >> station.type >> station.position;
        gasStations.push_back(station);
    }

    sort(gasStations.begin(), gasStations.end(), compareGasStation);

    vector<int> startPoints(m);
    for (int i = 0; i < m; i++) {
        cin >> startPoints[i];
    }

    for (int i = 0; i < m; i++) {
        int minRegular = -1, minPremium = -1;

        for (int j = 0; j < n; j++) {
            GasStation station = gasStations[j];
            int regular = 0, premium = 0;
            
            if (station.position <= startPoints[i] && station.position < e) {
                if (station.type == 1) {
                    regular = max(s - (e - station.position), 0);
                    premium = min(s - regular, s - (e - station.position));
                } else if (station.type == 2) {
                    premium = max(s - (e - station.position), 0);
                    regular = min(s - premium, s - (e - station.position));
                }

                if (minRegular == -1 || regular < minRegular || (regular == minRegular && premium < minPremium)) {
                    minRegular = regular;
                    minPremium = premium;
                }
            }
        }

        if (minRegular == -1) {
            cout << "-1 -1" << endl;
        } else {
            cout << minRegular << " " << minPremium << endl;
        }
    }

    return 0;
}