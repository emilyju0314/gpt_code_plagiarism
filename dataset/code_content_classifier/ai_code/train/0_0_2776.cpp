#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >>n >>m;
    
    int x1, y1, x2, y2;
    cin >>x1 >>y1 >>x2 >>y2;

    int k = 2 * (m + n - 2); // length of the path
    
    cout <<k <<"\n";
    
    cout <<x1 <<" " <<y1 <<"\n";
    
    if (x1 + x2 == n + 1) {
        if (x1 == 1) {
            for (int i = 1; i < m; i++) {
                cout <<x1 <<" " <<i + 1 <<"\n";
            }
            for (int i = n; i >= 1; i--) {
                if (i != x2) {
                    cout <<i <<" " <<m <<"\n";
                }
            }
            for (int i = m - 1; i >= 1; i--) {
                cout <<x2 <<" " <<i <<"\n";
            }
        } else {
            for (int i = m; i >= 2; i--) {
                cout <<x1 <<" " <<i <<"\n";
            }
            for (int i = 1; i <= n; i++) {
                if (i != x2) {
                    cout <<i <<" " <<1 <<"\n";
                }
            }
            for (int i = 2; i <= m; i++) {
                cout <<x2 <<" " <<i <<"\n";
            }
        }
    } else {
        if (y1 == 1) {
            for (int i = 2; i <= n; i++) {
                cout <<i <<" " <<1 <<"\n";
            }
            for (int i = 2; i <= m; i++) {
                cout <<n <<" " <<i <<"\n";
            }
            for (int i = n - 1; i >= 1; i--) {
                cout <<i <<" " <<m <<"\n";
            }
            for (int i = m - 1; i >= 1; i--) {
                cout <<1 <<" " <<i <<"\n";
            }
        } else {
            for (int i = 1; i < n; i++) {
                cout <<i <<" " <<1 <<"\n";
            }
            for (int i = 1; i <= m; i++) {
                cout <<n <<" " <<i <<"\n";
            }
            for (int i = n - 1; i >= 1; i--) {
                cout <<i <<" " <<m <<"\n";
            }
            for (int i = m - 1; i >= 1; i--) {
                cout <<1 <<" " <<i <<"\n";
            }
        }
    }
    
    cout <<x2 <<" " <<y2 <<"\n";
    
    return 0;
}