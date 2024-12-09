#include <iostream>
using namespace std;

int c(int l, int r) {
    int count = 0;
    for(int i = l; i <= r; i++) {
        for(int j = i; j <= r; j++) {
            int gcd = __gcd(i, j);
            if(gcd >= l) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int f = 0;
        for(int i = 0; i < k; i++) {
            int x;
            cin >> x;
            if(i == 0 && i == k-1) {
                f += c(1, n);
            } else if(i == 0) {
                f += c(1, x+1);
            } else if(i == k-1) {
                f += c(x, n);
            } else {
                f += c(x, x+1);
            }
        }
        cout << f << endl;
    }

    return 0;
}