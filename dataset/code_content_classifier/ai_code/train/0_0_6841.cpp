#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;

    for (int i = 0; i < k; i++) {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;

        int time = abs(ta - tb) + min(abs(fa - fb), abs(fa - fb) + min(abs(a - fa) + abs(b - fb), abs(b - fb) + abs(a - fa)));
        
        cout << time << endl;
    }

    return 0;
}