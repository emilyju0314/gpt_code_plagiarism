#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    unordered_map<int, vector<pair<int, char>>> roads;
    
    for(int i = 0; i < m; i++) {
        int x, y;
        char person;
        cin >> x >> y >> person;
        
        roads[x].push_back({y, person});
        roads[y].push_back({x, person});
    }
    
    vector<int> santa_roads, elf_roads;
    
    for(auto& entry : roads) {
        int num_santa = 0, num_elf = 0;
        
        for(auto& road : entry.second) {
            if(road.second == 'S') {
                num_santa++;
            } else {
                num_elf++;
            }
        }
        
        if(num_santa != num_elf) {
            cout << "-1" << endl;
            return 0;
        }
        
        for(auto& road : entry.second) {
            if(num_santa > 0) {
                santa_roads.push_back(road.first);
                num_santa--;
            } else {
                elf_roads.push_back(road.first);
            }
        }
    }
    
    cout << santa_roads.size() << endl;
    
    for(int road : santa_roads) {
        cout << road << " ";
    }
    cout << endl;
    
    return 0;
}