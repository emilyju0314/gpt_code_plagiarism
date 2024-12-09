#include <iostream>
using namespace std;

int main() {
    while (true) {
        int x, y, s;
        cin >> x >> y >> s;
        
        if (x == 0 && y == 0 && s == 0) {
            break;
        }
        
        int max_price = 0;
        for (int p1 = 1; p1 < s; p1++) {
            for (int p2 = 1; p2 < s; p2++) {
                if (p1 * (100 + x) / 100 + p2 * (100 + x) / 100 == s) {
                    int price = p1 * (100 + y) / 100 + p2 * (100 + y) / 100;
                    max_price = max(max_price, price);
                }
            }
        }
        
        cout << max_price << endl;
    }
    
    return 0;
}