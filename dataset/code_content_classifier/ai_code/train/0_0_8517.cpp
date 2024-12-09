#include <iostream>
using namespace std;

int main() {
    int lights[3][3];
    
    // Input
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> lights[i][j];
        }
    }
    
    // Toggling lights based on number of presses
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num_presses = lights[i][j];
            if (num_presses % 2 == 1) {
                cout << "0";
            } else {
                cout << "1";
            }
        }
        cout << endl;
    }
    
    return 0;
}