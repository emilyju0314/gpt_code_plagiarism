#include <iostream>
using namespace std;

int main() {
    int b, r, g, c, s, t;
    
    while (true) {
        cin >> b >> r >> g >> c >> s >> t;
        if (b == 0 && r == 0 && g == 0 && c == 0 && s == 0 && t == 0) {
            break;
        }
        
        int totalMedals = 100;
        totalMedals += b * 5 * 3; // Big bonus awards 5 bonus games
        totalMedals += r * 3 * 2; // Regular bonus awards 3 bonus games
        
        for (int i = 0; i < t; i++) {
            totalMedals -= 3; // Cost of normal game
            
            if (g >= 3) {
                totalMedals += 15; // Win in normal game with 3 grape patterns
            }
            if (b > 0) {
                b--;
                totalMedals += 15; // Win in bonus game with 3 grape patterns
            } else if (c == 3) {
                totalMedals += 5; // Win in normal game with 3 cherries
            } else if (s == 3) {
                // Free game with 3 star symbols, do not earn medals
            }
        }
        
        cout << totalMedals << endl;
    }
    
    return 0;
}