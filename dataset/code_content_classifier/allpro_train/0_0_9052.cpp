#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> toys(n);
    for (int i = 0; i < n; i++) {
        cin >> toys[i];
    }

    sort(toys.begin(), toys.end());

    vector<int> chosenToys;
    int remainingBudget = m;
    int i = 1;

    while (remainingBudget >= i) {
        if (find(toys.begin(), toys.end(), i) == toys.end()) {
            chosenToys.push_back(i);
            remainingBudget -= i;
        }
        i++;
    }

    cout << chosenToys.size() << endl;
    for (int toy : chosenToys) {
        cout << toy << " ";
    }

    return 0;
}