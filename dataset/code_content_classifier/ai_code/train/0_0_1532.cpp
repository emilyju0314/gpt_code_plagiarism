#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, m, r, k;
    cin >> n >> m >> r >> k;
    
    if (k == 1) {
        cout << fixed << setprecision(10) << 1.0 << endl;
        return 0;
    }
    
    int nn = n - r + 1;
    int mm = m - r + 1;
    long double expected = 0.0;
    
    for (int i = 0; i < nn; i++) {
        for (int j = 0; j < mm; j++) {
            int count = min(r, min(n - i, m - j));
            long double prob = 1.0 * count / (n * m - i * m - j);
            expected += prob * count;
        }
    }
    
    cout << fixed << setprecision(10) << expected << endl;
    
    return 0;
}