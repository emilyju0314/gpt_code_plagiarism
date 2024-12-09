#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string m;
    cin >> m;

    int n = m.size();
    vector<int> profile;

    int consecutiveFilledCells = 0;
    bool foundEmptyCell = false;

    for(int i = 0; i < n; i++) {
        if(m[i] == '#') {
            consecutiveFilledCells++;
        } else if(m[i] == '_' && consecutiveFilledCells > 0) {
            profile.push_back(consecutiveFilledCells);
            consecutiveFilledCells = 0;
            foundEmptyCell = true;
        }
    }

    if(!foundEmptyCell && consecutiveFilledCells > 0) {
        profile.push_back(consecutiveFilledCells);
    }

    if(profile.empty()) {
        cout << -1;
    } else {
        cout << profile.size() << endl;
        for(int length : profile) {
            cout << length << " ";
        }
    }

    return 0;
}