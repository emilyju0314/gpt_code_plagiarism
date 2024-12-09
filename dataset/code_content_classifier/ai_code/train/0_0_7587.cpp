#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<set<int>> connections(n+1);
    vector<int> count(n+1);
    
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        
        while (k--) {
            string line;
            cin >> line;
            
            int pos = line.find(':');
            int source = stoi(line.substr(0, pos));
            
            line = line.substr(pos+1);
            while (!line.empty()) {
                pos = line.find_first_of(",-", 0);
                int dest = stoi(line.substr(0, pos));
                
                connections[source].insert(dest);
                count[dest]++;
                
                if (line[pos] == ',') line = line.substr(pos+1);
                else break;
            }
        }
    }
    
    vector<pair<int, int>> cords;
    for (int i = 1; i <= n; i++) {
        for (int dest : connections[i]) {
            if (connections[dest].find(i) != connections[dest].end()) {
                cords.push_back({min(i, dest), max(i, dest)});
            }
        }
    }
    
    sort(cords.begin(), cords.end());
    cords.erase(unique(cords.begin(), cords.end()), cords.end());
    
    if (cords.size() < n-1) {
        cout << -1 << endl;
    } else {
        cout << cords.size() << endl;
        for (auto cord : cords) {
            cout << cord.first << " " << cord.second << endl;
        }
    }
    
    return 0;
}