#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int moves = 0;

void moveTrain(vector<string>& parkingLines, string& train, int source, int dest) {
    string subTrain;
    if (source < dest) {
        subTrain = train.substr(0, dest - source);
        train = train.substr(dest - source) + train.substr(0, dest - source);
    } else {
        subTrain = train.substr(train.size() - (source - dest));
        train = train.substr(train.size() - (source - dest)) + train.substr(0, train.size() - (source - dest));
    }
    parkingLines[dest].insert(parkingLines[dest].end(), subTrain.begin(), subTrain.end());
    moves++;
}

int main() {
    int x, y;
    while (1) {
        cin >> x >> y;
        if (x == 0 && y == 0) break;

        vector<pair<int, char>> exchangeLines[y];
        for (int i = 0; i < y; i++) {
            int p, q;
            char P, Q;
            cin >> p >> P >> q >> Q;
            exchangeLines[i].push_back(make_pair(p, P));
            exchangeLines[i].push_back(make_pair(q, Q));
        }

        vector<string> arrivalConfig(x);
        vector<string> departureConfig(x);

        for (int i = 0; i < x; i++) {
            cin >> arrivalConfig[i];
        }

        for (int i = 0; i < x; i++) {
            cin >> departureConfig[i];
        }

        moves = 0;
        for (int i = 0; i < x; i++) {
            int source = find(arrivalConfig.begin(), arrivalConfig.end(), departureConfig[i]) - arrivalConfig.begin();
            if (i != source) {
                moveTrain(arrivalConfig, arrivalConfig[source], i, source);
            }
        }

        cout << moves << endl;
    }

    return 0;
}