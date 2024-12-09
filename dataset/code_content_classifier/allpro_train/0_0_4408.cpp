#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int x, y, n;
    
    while (true) {
        cin >> x >> y >> n;
        if (x == 0 && y == 0 && n == 0) {
            break;
        }
        
        int steps = 0;
        
        while (x != 0 || y != 0 || n != 0) {
            if (n == 0) {
                steps += abs(x) > abs(y) ? abs(x) * 2 : abs(y) * 2;
                break;
            }
            
            if (n == 1 || n == 2) {
                y++;
            } else if (n == 4 || n == 5) {
                y--;
            } else if (n == 0 || n == 3 || n == 6) {
                x++;
            } else {
                x--;
            }
            
            if (x + y % 2 != 0) {
                n = (n + 3) % 6;
            } else {
                n = (n + 2) % 6;
            }
            
            steps++;
        }
        
        cout << steps << endl;
    }
    
    return 0;
}