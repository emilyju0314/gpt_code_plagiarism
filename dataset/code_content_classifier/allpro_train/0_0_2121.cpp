#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Using a map to store the connections between computers
    unordered_map<int, vector<int>> connections;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        connections[a].push_back(b);
        connections[b].push_back(a);
    }

    int addedCables = 0;
    cout << (m + (m % 2)) << endl; // Minimum number of cables in the final scheme

    // Iterate through the original connections and print out the cables
    for (auto& [comp, linkedComps] : connections) {
        for (int linkedComp : linkedComps) {
            cout << comp << " " << linkedComp << endl;
            if (++addedCables % 2 == 0) {
                addedCables++;
                cout << linkedComp << " " << comp << endl;
            }
        }
    }

    return 0;
}