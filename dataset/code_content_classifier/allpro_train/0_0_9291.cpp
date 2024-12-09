#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> incomingRoads(n);
    for (int i = 0; i < n; i++) {
        cin >> incomingRoads[i];
    }

    int maxDifference = 0;
    pair<int, int> optimalPair = make_pair(0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "? " << i + 1 << " " << j + 1 << endl;
            cout.flush();

            string response;
            cin >> response;

            if (response == "Yes") {
                int difference = abs(incomingRoads[i] - incomingRoads[j]);
                if (difference > maxDifference) {
                    maxDifference = difference;
                    optimalPair = make_pair(i + 1, j + 1);
                }
            }
        }
    }

    cout << "! " << optimalPair.first << " " << optimalPair.second << endl;
    cout.flush();

    return 0;
}