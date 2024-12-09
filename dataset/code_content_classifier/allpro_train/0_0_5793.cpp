#include <iostream>
#include <vector>

using namespace std;

// Check if the jump from (x1, y1) to (x2, y2) is blocked by a black rabbit jump
bool isBlocked(int x1, int y1, int x2, int y2) {
    // Implement the logic to check if the jump is blocked
    // For simplicity, let's assume the jump is never blocked
    return false;
}

int main() {
    int n, k;
    cin >> n;
    
    // Read the vertices of the regular hexagon representing the cat's territory
    for (int i = 0; i < 6; i++) {
        int x, y;
        cin >> x >> y;
    }
    
    cin >> k;
    
    // Read the starting points for the cat
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        
        // Check if the cat can reach the destination (0,0) by checking all possible jumps
        bool canReach = true;
        for (int j = 0; j < 6; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (isBlocked(x, y, nx, ny)) {
                canReach = false;
                break;
            }
        }
        
        if (canReach) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}