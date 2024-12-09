#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

bool checkDistinct(int num) {
    unordered_set<int> seen;
    while (num > 0) {
        int digit = num % 10;
        if (seen.count(digit) > 0) {
            return false;
        }
        seen.insert(digit);
        num /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> cubes;
    for (int i = 0; i < 2 * n; i++) {
        int cube;
        cin >> cube;
        cubes.push_back({cube, i});
    }

    sort(cubes.begin(), cubes.end());

    vector<int> heaps(2 * n, 0);
    int count = 0;

    for (int i = 0; i < 2 * n; i += 2) {
        heaps[cubes[i].second] = 1;
        heaps[cubes[i + 1].second] = 2;
        count += (checkDistinct(cubes[i].first * 100 + cubes[i + 1].first)) ? 1 : 0;
    }

    cout << count << endl;
    for (int heap : heaps) {
        cout << heap << " ";
    }
    cout << endl;

    return 0;
}