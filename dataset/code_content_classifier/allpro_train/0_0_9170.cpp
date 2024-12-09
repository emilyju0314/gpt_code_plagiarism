#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int h, w;
    
    while (cin >> h >> w && h && w) {
        vector<string> keyboard(h);
        for (int i = 0; i < h; ++i) {
            cin >> keyboard[i];
        }
        
        string s;
        cin >> s;
        
        int totalPresses = 0;
        pair<int, int> pos = {0, 0}; // Initial position
        
        for (char c : s) {
            for (int i = 0; i < h; ++i) {
                int j = keyboard[i].find(c);
                if (j != string::npos) { // If character is found in the row
                    totalPresses += abs(pos.first - i) + abs(pos.second - j) + 1;
                    pos.first = i;
                    pos.second = j;
                    break;
                }
            }
        }
        
        cout << totalPresses << endl;
    }
    
    return 0;
}