#include <iostream>

using namespace std;

int main() {
    int n, m, xc, yc, k;
    cin >> n >> m >> xc >> yc >> k;

    long long steps = 0;
    
    for(int i=0; i<k; i++) {
        int dx, dy;
        cin >> dx >> dy;

        long long maxSteps = 1e18;

        if(dx > 0) {
            maxSteps = min(maxSteps, (n - xc) / dx);
        } else if(dx < 0) {
            maxSteps = min(maxSteps, (xc - 1) / (-dx));
        }

        if(dy > 0) {
            maxSteps = min(maxSteps, (m - yc) / dy);
        } else if(dy < 0) {
            maxSteps = min(maxSteps, (yc - 1) / (-dy));
        }

        steps += maxSteps;

        xc += maxSteps * dx;
        yc += maxSteps * dy;
    }

    cout << steps << endl;

    return 0;
}