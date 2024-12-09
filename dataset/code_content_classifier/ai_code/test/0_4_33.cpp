#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    set<int> possibleX;
    possibleX.insert(0);
    for (int i = 0; i < n; i++) {
        set<int> newPossibilities;
        for (int x : possibleX) {
            newPossibilities.insert(x ^ a[i]);
        }
        possibleX.insert(newPossibilities.begin(), newPossibilities.end());
    }

    cout << possibleX.size() << endl;
    for (int x : possibleX) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}