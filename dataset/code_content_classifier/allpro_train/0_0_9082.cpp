#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    
    while (true) {
        cin >> n;
        if (n < 0) {
            break;
        }
        
        vector<pair<char, pair<int, int>>> mirrors;
        
        for (int i = 0; i < n; i++) {
            char d;
            int x, y;
            cin >> d >> x >> y;
            mirrors.push_back(make_pair(d, make_pair(x, y)));
        }
        
        int thiefX = 75, thiefY = 25;
        int currentX = 1, currentY = 1;
        bool hitWall = false;
        
        for (const auto &mirror : mirrors) {
            char d = mirror.first;
            int x = mirror.second.first;
            int y = mirror.second.second;
            
            if (d == 'x') {
                if (thiefY == y && (currentX >= x && currentX <= x + 1)) {
                    thiefX = 8 * 100 - thiefX;
                }
            } else if (d == 'y') {
                if (thiefX == x && (currentY >= y && currentY <= y + 1)) {
                    thiefY = 8 * 100 - thiefY;
                }
            }
        }
        
        cout << thiefX << " " << thiefY << endl;
    }
    
    return 0;
}