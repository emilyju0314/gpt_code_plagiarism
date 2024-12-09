#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int g(int x) {
    if(x < 10) {
        return x;
    }
    return g(x / 10);
}

int main() {
    int Q;
    cin >> Q;

    while(Q--) {
        int l, r, k;
        cin >> l >> r >> k;

        int count = 0;
        for(int i = l; i <= r; i++) {
            if(g(i) == k) {
                count++;
            }
        }

        cout << count << endl;
    }
    
    return 0;
}