#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int l, r;
        cin >> l >> r;

        int msb = 0;
        for(int i = 30; i >= 0; i--) {
            if((r & (1 << i)) != 0) {
                msb = i;
                break;
            }
        }

        int range = (1 << msb) - 1;
        if(range >= l) {
            cout << r - range << endl;
        } else {
            cout << r - l << endl;
        }
    }

    return 0;
}