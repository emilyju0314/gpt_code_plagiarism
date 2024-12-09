#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int n, k;
vector<int> a;
vector<int> badLuck;

int countGoodRoutes(int step, int mask) {
    if(step > n) {
        return 1;
    }

    int res = 0;
    for(int i = 0; i < n; i++) {
        if(((mask >> i) & 1) == 0) {
            int newPos = a[i] + step;
            bool bad = false;
            for(int j = 0; j < badLuck.size(); j++) {
                if(newPos == badLuck[j]) {
                    bad = true;
                    break;
                }
            }
            if(!bad) {
                res += countGoodRoutes(newPos, mask | (1 << i));
                res %= MOD;
            }
        }
    }

    return res;
}

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cin >> k;
    badLuck.resize(k);
    for(int i = 0; i < k; i++) {
        cin >> badLuck[i];
    }

    int result = countGoodRoutes(0, 0);
    cout << result << endl;

    return 0;
}