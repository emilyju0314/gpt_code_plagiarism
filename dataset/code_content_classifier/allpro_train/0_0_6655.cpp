#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int r, c, q;
    
    while (cin >> r >> c >> q) {
        if (r == 0 && c == 0 && q == 0) break;
        
        vector<vector<int>> instructions(r, vector<int>(c, 0));
        
        for (int i = 0; i < q; i++) {
            int A, B, order;
            cin >> A >> B >> order;
            
            if (A == 0) { // row
                for (int j = 0; j < c; j++) {
                    if (order == 0) instructions[B][j] = 0; // seat
                    else instructions[B][j] = 1; // stand
                }
            } else { // column
                for (int j = 0; j < r; j++) {
                    if (order == 0) instructions[j][B] = 0; // seat
                    else instructions[j][B] = 1; // stand
                }
            }
        }
        
        int maxArrivals = 0;
        
        for (int i = 0; i < r; i++) {
            int arrivals = 0;
            for (int j = 0; j < c; j++) {
                if (instructions[i][j] == 1) {
                    arrivals++;
                }
            }
            maxArrivals += max(arrivals, c - arrivals);
        }
        
        cout << maxArrivals << endl;
    }
    
    return 0;
}