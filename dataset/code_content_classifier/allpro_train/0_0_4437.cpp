#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> prices(n);
    for(int i = 0; i < n; i++) {
        cin >> prices[i].first;
        prices[i].second = i;
    }

    sort(prices.begin(), prices.end());

    vector<int> result(n);
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            result[2*i] = prices[i].first;
        } else {
            result[2*(n-i)-1] = prices[i].first;
        }
    }

    int cheap_count = 0;
    for(int i = 1; i < n-1; i++) {
        if(result[i] < result[i-1] && result[i] < result[i+1]) {
            cheap_count++;
        }
    }

    cout << cheap_count << endl;
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}