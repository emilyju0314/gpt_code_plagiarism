#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    for(int t = 0; t < T; t++) {
        int n, d;
        cin >> n >> d;

        bool possible = false;
        for(int x = 0; x <= n; x++) {
            if(x + ceil((double)d / (x + 1)) <= n) {
                possible = true;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}