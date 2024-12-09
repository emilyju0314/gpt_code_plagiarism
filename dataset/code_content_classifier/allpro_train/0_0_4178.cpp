#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    
    for (int i = 0; i < T; i++) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        
        bool possibleFirst[4] = {false, false, false, false};
        
        if (A + B + C + D == 1) {
            int specialBox = 0;
            while (A == 0) {
                specialBox++;
                A += B % 2;
                B /= 2;
            }
            possibleFirst[specialBox] = true;
        } else {
            if ((A + C) % 2 == 0) {
                possibleFirst[0] = true;
            }
            if (B > 0) {
                possibleFirst[1] = true;
            }
            if ((A + C) > 0) {
                possibleFirst[2] = true;
            }
            if ((A + C) % 2 == 0) {
                possibleFirst[3] = true;
            }
        }
        
        for (int j = 0; j < 4; j++) {
            if (possibleFirst[j]) {
                cout << "Ya ";
            } else {
                cout << "Tidak ";
            }
        }
        cout << endl;
    }
    
    return 0;
}