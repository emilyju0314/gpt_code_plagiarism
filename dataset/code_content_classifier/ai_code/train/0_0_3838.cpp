#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        long long V = 1;
        vector<pair<int, int>> factors;
        for(int i = 0; i < k; i++) {
            int p, a;
            cin >> p >> a;
            V *= pow(p, a);
            factors.push_back(make_pair(p, a));
        }

        long long minS = 4 * V;
        long long a = 1, b = 1, c = V;
        for(int i = 0; i < (1 << k); i++) {
            long long num = 1, den = 1;
            for(int j = 0; j < k; j++) {
                if(i & (1 << j)) {
                    num *= factors[j].first;
                } else {
                    den *= factors[j].first;
                }
            }
            long long temp = 2 * (num + den + (V / (num * den)));
            if(temp < minS) {
                minS = temp;
                a = num;
                b = den;
                c = V / (num * den);
            }
        }

        cout << minS << " " << a << " " << b << " " << c << endl;
    }

    return 0;
}