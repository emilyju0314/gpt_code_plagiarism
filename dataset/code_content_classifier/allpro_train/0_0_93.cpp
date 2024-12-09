#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int stones = 0;
        if(b >= 1 && c >= 2) {
            int min = (b < c / 2) ? b : c / 2;
            stones += min * 3;
            b -= min;
            c -= 2 * min;
        }
        
        if(a >= 1 && b >= 2) {
            int min = (a < b / 2) ? a : b / 2;
            stones += min * 3;
        }

        cout << stones << endl;
    }

    return 0;
}