#include <iostream>

using namespace std;

int main() {
    char square[4][4];
    int blackCount = 0, whiteCount = 0;

    // Taking input
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> square[i][j];
            if(square[i][j] == '#') {
                blackCount++;
            } else {
                whiteCount++;
            }
        }
    }

    // Checking if the test can be passed
    if(blackCount >= 3 && whiteCount >= 3) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}