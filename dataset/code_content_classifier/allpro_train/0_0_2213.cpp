#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct GasStation {
    int position, price;
};

bool compare(GasStation a, GasStation b) {
    return a.position < b.position;
}

int main() {
    int d, n, m;
    cin >> d >> n >> m;

    vector<GasStation> stations(m);
    for(int i = 0; i < m; i++) {
        cin >> stations[i].position >> stations[i].price;
    }

    sort(stations.begin(), stations.end(), compare);

    stations.push_back({d, 0});

    int currPos = 0, currTank = n, currCost = 0, nextPos = 0, nextStationIndex = 0;

    while(currPos < d) {
        while(nextStationIndex < m && stations[nextStationIndex].position <= currPos + n) {
            if(stations[nextStationIndex].price < stations[nextPos].price) {
                nextPos = nextStationIndex;
            }
            nextStationIndex++;
        }

        if(nextPos == nextStationIndex) {
            cout << -1 << endl;
            return 0;
        }

        if(stations[nextPos].position == currPos) {
            cout << -1 << endl;
            return 0;
        }

        if(currPos + currTank < stations[nextPos].position) {
            currCost += stations[nextPos].price * (stations[nextPos].position - currPos - currTank);
            currPos = stations[nextPos].position;
            currTank = n;
        } else {
            currTank -= stations[nextPos].position - currPos;
            currPos = stations[nextPos].position;
        }
    }

    cout << currCost << endl;

    return 0;
}