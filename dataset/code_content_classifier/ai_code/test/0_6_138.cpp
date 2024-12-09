#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> pricesMonocarp(n);
    vector<int> pricesOtherCharacter(m);
    vector<int> queries(q);

    for(int i = 0; i < n; i++) {
        cin >> pricesMonocarp[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> pricesOtherCharacter[i];
    }

    for(int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    sort(pricesMonocarp.begin(), pricesMonocarp.end());
    sort(pricesOtherCharacter.begin(), pricesOtherCharacter.end());

    vector<int> maxCosts(q);

    for(int i = 0; i < q; i++) {
        int k = queries[i];
        int totalCost = 0;
        int j = m - 1;

        for(int price : pricesMonocarp) {
            while(j >= 0 && pricesOtherCharacter[j] > price + k) {
                j--;
            }

            if(j >= 0) {
                totalCost += pricesOtherCharacter[j];
                j--;
            }
        }

        maxCosts[i] = totalCost;
    }

    for(int cost : maxCosts) {
        cout << cost << endl;
    }

    return 0;
}