#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> operations(N);
    for (int i = 0; i < N; i++) {
        cin >> operations[i].first >> operations[i].second;
    }

    vector<int> array;
    for (auto op : operations) {
        for (int i = 0; i < op.second; i++) {
            array.push_back(op.first);
        }
    }

    sort(array.begin(), array.end());

    cout << array[K - 1] << endl;

    return 0;
}