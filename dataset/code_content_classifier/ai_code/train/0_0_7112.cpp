#include <iostream>
#include <vector>
#include <map>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> whiteBoards(n);
    for (int i = 0; i < n; i++) {
        cin >> whiteBoards[i];
    }

    vector<int> redBoards(k);
    for (int i = 0; i < k; i++) {
        cin >> redBoards[i];
    }

    int q;
    cin >> q;

    vector<int> specialIntegers(q);
    for (int i = 0; i < q; i++) {
        cin >> specialIntegers[i];
    }

    map<int, long long> fenceCount;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int perimeter = 2 * whiteBoards[i] + 2 * redBoards[j];
            if (fenceCount.find(perimeter) == fenceCount.end()) {
                fenceCount[perimeter] = 1;
            } else {
                fenceCount[perimeter]++;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int specialPerimeter = specialIntegers[i];
        if (fenceCount.find(specialPerimeter) != fenceCount.end()) {
            cout << fenceCount[specialPerimeter] % MOD << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}