#include <iostream>
using namespace std;

int main() {
    int n, x, y, c;
    cin >> n >> x >> y >> c;

    int seconds = 0;
    int switchedOn = 1;
    while(switchedOn < c) {
        seconds++;
        if (x > 1) switchedOn++;
        if (x < n) switchedOn++;
        if (y > 1) switchedOn++;
        if (y < n) switchedOn++;
        x--; y--;
    }

    cout << seconds << endl;

    return 0;
}