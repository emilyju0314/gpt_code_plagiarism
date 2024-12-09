#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int n;
    string operations;
    int x, y;
    
    cin >> n;
    cin >> operations;
    cin >> x >> y;
    
    int currX = 0, currY = 0;
    int minX = -1, maxX = n;
    for (int i = 0; i < n; i++) {
        if (operations[i] == 'U') {
            currY++;
        } else if (operations[i] == 'D') {
            currY--;
        } else if (operations[i] == 'L') {
            currX--;
        } else if (operations[i] == 'R') {
            currX++;
        }
        
        if (currX == x && currY == y) {
            cout << 0 << endl;
            return 0;
        }
    }
    
    currX = 0;
    currY = 0;
    for (int i = 0; i < n; i++) {
        if (operations[i] == 'U') {
            currY++;
        } else if (operations[i] == 'D') {
            currY--;
        } else if (operations[i] == 'L') {
            currX--;
        } else if (operations[i] == 'R') {
            currX++;
        }
        
        int dx = x - currX;
        int dy = y - currY;
        
        if (abs(dx) + abs(dy) <= i + 1) {
            int length = i - minX;
            if (minX == -1 || length < maxX - minX) {
                maxX = i;
                minX = i - length + 1;
            }
        }
    }
    
    if (minX == -1) {
        cout << -1 << endl;
    } else {
        cout << maxX - minX + 1 << endl;
    }
    
    return 0;
}