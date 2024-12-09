#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string dir;
    
    while (cin >> dir) {
        if (dir == "#") {
            break;
        }
        
        int deg = 0;
        int count = 0;
        
        for (int i = 0; i < dir.size(); i++) {
            if (dir[i] == 'n') {
                deg -= 90 / pow(2, count);
            } else {
                deg += 90 / pow(2, count);
            }
            count++;
        }
        
        if (deg % 360 == 0) {
            cout << deg / 360 << endl;
        } else {
            cout << deg << "/1" << endl;
        }
    }
    
    return 0;
}