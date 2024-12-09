#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int infected = 0;
    set<pair<int, int>> infected_beds;
    
    int x = 1000000001, y = 1000000001;
    infected_beds.insert({x, y});
    
    for(int i = 0; i < n; i++) {
        char direction;
        int distance;
        cin >> direction >> distance;
        
        while(distance--) {
            if(direction == 'L') x--;
            else if(direction == 'R') x++;
            else if(direction == 'U') y++;
            else y--;
            
            if(infected_beds.count({x-1, y}) || infected_beds.count({x+1, y}) || infected_beds.count({x, y-1}) || infected_beds.count({x, y+1})) {
                infected++;
            } else {
                infected_beds.insert({x, y});
            }
        }
    }
    
    cout << (1001*1001 - infected) << endl;
    
    return 0;
}