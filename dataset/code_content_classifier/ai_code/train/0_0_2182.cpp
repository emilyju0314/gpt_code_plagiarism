#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int c, sum;
        cin >> c >> sum;
        
        int cost = 1e9;
        for (int j = 1; j <= c; j++) {
            int sections_per_radiator = (sum + j - 1) / j; // Ceiling division
            int curr_cost = j + sections_per_radiator * sections_per_radiator;
            cost = min(cost, curr_cost);
        }
        
        cout << cost << endl;
    }
    
    return 0;
}