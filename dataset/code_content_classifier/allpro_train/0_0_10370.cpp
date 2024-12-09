#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<pair<int, int>> stores(N);
    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        stores[i] = make_pair(a, b);
    }

    sort(stores.begin(), stores.end(), greater<pair<int, int>>());

    int max_shopping = 0;
    for(int i = 0; i < N; i++) {
        int a = stores[i].first;
        int b = stores[i].second;
        int max_time = T / a;
        max_shopping = max(max_shopping, max_time);

        T -= b;
    }

    cout << max_shopping << endl;

    return 0;
}