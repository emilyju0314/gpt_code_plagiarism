#include <iostream>
#include <vector>
using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int dist;
    cin >> dist;
    return dist;
}

int main() {
    int n = 1000000000;
    
    // Find the smallest x coordinate of the enemy base
    int l = 2, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        if (query(m, 1) <= query(m + 1, 1)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    
    // Find the smallest y coordinate of the enemy base
    int a = 2, b = n;
    while (a < b) {
        int m = (a + b) / 2;
        if (query(1, m) <= query(1, m + 1)) {
            b = m;
        } else {
            a = m + 1;
        }
    }
    
    // Find the largest x coordinate of the enemy base
    int p = l, q = n;
    while (p < q) {
        int m = (p + q + 1) / 2;
        if (query(m, n) <= query(m + 1, n)) {
            p = m;
        } else {
            q = m - 1;
        }
    }
    
    // Find the largest y coordinate of the enemy base
    int x = a, y = b;
    int d = query(p, q);
    while (y < q) {
        int m = (y + q + 1) / 2;
        if (query(p, m) == d) {
            y = m;
        } else {
            q = m - 1;
        }
    }
    
    cout << "! " << l << " " << a << " " << p << " " << y << endl;
    
    return 0;
}