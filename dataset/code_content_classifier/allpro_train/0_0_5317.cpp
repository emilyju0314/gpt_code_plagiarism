#include <iostream>

using namespace std;

int main() {
    int a, b, w, x, c;
    cin >> a >> b >> w >> x >> c;
    
    int time = 0;
    
    while (c > a) {
        if (b >= x) {
            b -= x;
        } else {
            a--;
            b = w - (x - b);
        }
        c--;
        time++;
    }
    
    cout << time << endl;
    
    return 0;
}