#include <iostream>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int p, n;
    
    while (cin >> p >> n) {
        if (p == 0 && n == 0) {
            break;
        }
        
        int sqrtp = sqrt(p);
        int u = sqrtp;
        int x = sqrtp + 1;
        int v = 1;
        int y = 1;
        
        while (true) {
            if (x * x > p * y * y) {
                break;
            }
            x++;
            y++;
        }
        
        while (u * v != p) {
            if (u * v < p) {
                if (v < n) {
                    v++;
                } else {
                    u++;
                }
            } else {
                u--;
            }
        }

        int g = gcd(u, v);
        u /= g;
        v /= g;

        g = gcd(x, y);
        x /= g;
        y /= g;
        
        cout << x << "/" << y << " " << u << "/" << v << endl;
    }
    
    return 0;
}