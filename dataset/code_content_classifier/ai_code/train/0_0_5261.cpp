#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> prices(N);
    for(int i = 0; i < N; i++) {
        cin >> prices[i];
    }

    sort(prices.begin(), prices.end(), greater<int>());

    int total = 0;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            total += prices[i] / 2;
        } else {
            total += prices[i];
        }
    }

    cout << total << endl;

    return 0;
}