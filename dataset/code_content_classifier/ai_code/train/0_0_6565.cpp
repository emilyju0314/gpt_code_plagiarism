#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    unordered_map<int, vector<pair<int, int>>> lines;
    for (int i = 0; i < M; i++) {
        int p, q, c;
        cin >> p >> q >> c;
        lines[c].push_back({p, q});
    }
    
    queue<pair<int, int>> q;
    q.push({1, 1});
    
    unordered_set<int> visited;
    int minFare = -1;
    
    while (!q.empty()) {
        int station = q.front().first;
        int fare = q.front().second;
        q.pop();
        
        for (auto line : lines) {
            int company = line.first;
            
            bool hasLine = false;
            for (auto stations : line.second) {
                if (stations.first == station || stations.second == station) {
                    hasLine = true;
                    break;
                }
            }
            
            if (hasLine) {
                for (auto stations : line.second) {
                    int nextStation = (stations.first == station ? stations.second : stations.first);
                    int nextFare = (company == fare ? fare : fare + 1);
                    
                    if (nextStation == N) {
                        if (minFare == -1 || nextFare < minFare) {
                            minFare = nextFare;
                        }
                    } else if (visited.find(nextStation) == visited.end()) {
                        visited.insert(nextStation);
                        q.push({nextStation, nextFare});
                    }
                }
            }
        }
    }
    
    cout << minFare << endl;
    
    return 0;
}