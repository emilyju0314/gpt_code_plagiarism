#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int p[8];
    
    while (cin >> p[0]) {
        for (int i = 1; i < 8; i++) {
            cin >> p[i];
        }
        
        vector<int> order = {1, 2, 1, 2, 1, 2, 4, 4}; // Order of vehicles on the merry-go-round
        
        int min_unable = 100000; // Initialize to a large number
        vector<int> best_order;
        
        do {
            int unable = 0;
            for (int i = 0; i < 8; i++) {
                unable += max(0, p[i] - order[i]); // Calculate number of passengers unable to ride
            }
            
            if (unable < min_unable) {
                min_unable = unable;
                best_order = order;
            }
        } while (next_permutation(order.begin(), order.end()));
        
        for (int i = 0; i < 8; i++) {
            cout << best_order[i] << " ";
        }
        
        cout << endl;
    }
    
    return 0;
}