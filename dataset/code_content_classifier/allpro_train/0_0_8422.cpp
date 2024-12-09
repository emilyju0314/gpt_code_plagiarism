#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;
    
    unordered_map<int, int> pawnCounts; // keeps track of number of pawns in each column
    vector<int> maxRowsToAdd(n+1, 0); // maximum rows to be added to make board good after each change
    
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        
        // Checking if there is a pawn at the requested cell
        bool pawnExists = (pawnCounts.find(x) != pawnCounts.end() && pawnCounts[x] >= y);
        
        if(!pawnExists) {
            pawnCounts[x]++;
        } else {
            pawnCounts[x]--;
        }
        
        int targetRows = max(0, 3 - abs(k - x)); // maximum possible moves to special column
        maxRowsToAdd[x] = max(maxRowsToAdd[x], y+targetRows-1);
        
        int minRowsToAdd = maxRowsToAdd[x] - pawnCounts[x];
        cout << minRowsToAdd << endl;
    }
    
    return 0;
}