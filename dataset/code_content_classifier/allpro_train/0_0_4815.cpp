#include <iostream>
using namespace std;

int main() {
    int lights[4][4];

    // Input
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> lights[i][j];
        }
    }

    // Checking if an accident is possible
    bool accident = false;
    for(int i = 0; i < 4; i++) {
        if(lights[i][3] == 1) { // Pedestrian light is green
            for(int j = 0; j < 3; j++) {
                if(lights[i][j] == 1) { // Car light is green
                    accident = true;
                    break;
                }
            }
        }
        if(accident) break;
    }

    // Output
    if(accident) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}