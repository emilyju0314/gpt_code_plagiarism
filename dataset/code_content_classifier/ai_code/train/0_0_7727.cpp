#include<iostream>

using namespace std;

int main() {
    int n, m, l, r;
    cin >> n >> m;
    cin >> l >> r;
    
    for(int x = 1; x <= n; x++) {
        int y1 = x + 1;
        int x2 = 0, y2 = 0;
        while(y1 <= m) {
            int product = x * y1;
            if(product >= l && product <= r) {
                x2 = product / y1;
                y2 = x;
                break;
            }
            y1++;
        }
        if(x2 == 0 && y2 == 0) {
            cout << "-1" << endl;
        } else {
            cout << x << " " << y1 << " " << x2 << " " << y2 << endl;
        }
    }
    
    return 0;
}