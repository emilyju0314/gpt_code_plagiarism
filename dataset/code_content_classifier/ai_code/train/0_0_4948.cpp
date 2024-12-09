#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> main_lamps(n-1);
    for(int i=0; i<n-1; i++) {
        cin >> main_lamps[i];
    }

    map<int, vector<int>> connections; // map to store connections between lamps
    int current_power = n; // start with the last lamp as the main one
    for(int i=n-1; i>=0; i--) {
        connections[current_power].push_back(i+1); // connect current_power to current lamp
        current_power = main_lamps[i]; // the current lamp becomes the main lamp for the next wire
    }

    // check if the scheme is valid
    if(connections[current_power].size() != 0) {
        cout << -1 << endl;
    } else {
        // output the scheme
        cout << n << endl;
        for(auto it=connections.begin(); it!=connections.end(); it++) {
            for(int lamp : it->second) {
                cout << it->first << " " << lamp << endl;
            }
        }
    }

    return 0;
}