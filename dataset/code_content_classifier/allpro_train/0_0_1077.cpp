#include<iostream>
#include<cmath>

using namespace std;

int main() {
    int r, h;
    cin >> r >> h;
    
    int maxBalloons = 0;
    
    if(h >= 2*r) {
        maxBalloons = h/r * 2;
        maxBalloons += min(2, h % r) + 1;
    } else {
        double d = sqrt(3)/2 * r;
        maxBalloons = h/r * 2;
        
        // Check if half of a sphere can fit in the remaining space
        if(h % r >= d) {
            maxBalloons += 3;
        } else {
            maxBalloons += 2;
        }
    }
    
    cout << maxBalloons << endl;

    return 0;
}