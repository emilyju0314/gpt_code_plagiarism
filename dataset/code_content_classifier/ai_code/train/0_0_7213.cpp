#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<pair<int, int>> possible_locations; // Using a set to store unique points
    
    possible_locations.insert(make_pair(0, 0)); // Initial location at (0, 0)
    
    for (int i = 0; i < n; i++) {
        string movement;
        cin >> movement;
        
        set<pair<int, int>> new_possible_locations; // Temporary set to store new possible locations
        
        for (auto location : possible_locations) {
            int x = location.first;
            int y = location.second;
            
            for (char move : movement) {
                if (move == 'U') new_possible_locations.insert(make_pair(x, y + 1));
                else if (move == 'D') new_possible_locations.insert(make_pair(x, y - 1));
                else if (move == 'L') new_possible_locations.insert(make_pair(x - 1, y));
                else if (move == 'R') new_possible_locations.insert(make_pair(x + 1, y));
            }
        }
        
        possible_locations = new_possible_locations; // Update possible locations
    }
    
    cout << possible_locations.size() << endl;
    
    return 0;
}