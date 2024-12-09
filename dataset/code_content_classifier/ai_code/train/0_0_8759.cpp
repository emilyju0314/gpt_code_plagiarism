#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<int> coefficients_f(n);
    for(int i = 0; i < n; i++) {
        cin >> coefficients_f[i];
    }

    vector<int> coefficients_g(m);
    for(int i = 0; i < m; i++) {
        cin >> coefficients_g[i];
    }

    int t = 0;
    while(t < n + m - 1) {
        if((long long) coefficients_f[min(t, n-1)] * coefficients_g[min(t, m-1)] % p != 0) {
            break;
        }
        t++;
    }

    cout << t << endl;

    return 0;
}