#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m), k(q);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < q; i++) {
        cin >> k[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<long long> maxTotalCost(q);
    for(int i = 0; i < q; i++) {
        int j = m - 1;
        long long totalCost = 0;
        for(int itemPrice : a) {
            while(j >= 0 && b[j] > itemPrice + k[i]) {
                j--;
            }
            if(j >= 0) {
                totalCost += b[j];
                j--;
            }
        }
        maxTotalCost[i] = totalCost;
    }

    for(long long cost : maxTotalCost) {
        cout << cost << endl;
    }

    return 0;
}