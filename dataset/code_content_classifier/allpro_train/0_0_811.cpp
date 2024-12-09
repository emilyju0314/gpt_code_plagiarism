#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    
    unordered_map<pair<int, int>, int> ants; // Map to store the number of ants at each junction
    
    // Initialize colony of ants at junction (0, 0)
    ants[{0, 0}] = n;
    
    for (int i = 0; i < t; i++) {
        int xi, yi;
        cin >> xi >> yi;
        
        // Calculate the number of ants at the given query junction
        int cur_ants = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                cur_ants += ants[{xi+dx, yi+dy}];
            }
        }
        
        cout << cur_ants << endl;
    }
    
    return 0;
}