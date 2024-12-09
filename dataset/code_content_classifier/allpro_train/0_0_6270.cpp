#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<pair<int, int>>> network;
    vector<pair<int, int>> knownLinks;

    for (int i = 0; i < m; i++) {
        int f, t, w, b;
        cin >> f >> t >> w >> b;
        knownLinks.push_back({f, t});

        network[f].push_back({t, w*b});
        network[t].push_back({f, w*b});
    }

    int totalCost = 0;
    int totalBandwidth = 0;

    for (auto link : knownLinks) {
        int f = link.first;
        int t = link.second;
        for (auto connectedNode : network[f]) {
            if (connectedNode.first == t) {
                totalCost += connectedNode.second;
                totalBandwidth += sqrt(connectedNode.second);
            }
        }
    }

    // Check if intern's solution may be optimal
    int efficiency = totalCost / totalBandwidth;
    for (auto link : knownLinks) {
        int f = link.first;
        int t = link.second;
        for (auto connectedNode : network[f]) {
            if (connectedNode.first != t) {
                int theoreticalCost = pow(totalBandwidth, 2) * connectedNode.second / totalBandwidth;
                if (theoreticalCost < connectedNode.second) {
                    cout << "BAD " << f << endl;
                    return 0;
                }
            }
        }
    }

    if (efficiency == 0) {
        cout << "UNKNOWN" << endl;
    } else {
        cout << efficiency << endl;
    }

    return 0;
}