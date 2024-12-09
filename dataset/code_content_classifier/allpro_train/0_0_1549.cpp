#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

unordered_set<int> uniqueIntegers;

void generateIntegers(vector<int>& cards, int k, int currentInteger, int chosen, int idx) {
    if (chosen == k) {
        uniqueIntegers.insert(currentInteger);
        return;
    }

    for (int i = idx; i < cards.size(); i++) {
        generateIntegers(cards, k, currentInteger * 100 + cards[i], chosen + 1, i + 1);
    }
}

int main() {
    int n, k;
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) {
            break;
        }

        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cin >> cards[i];
        }

        uniqueIntegers.clear();
        generateIntegers(cards, k, 0, 0, 0);

        cout << uniqueIntegers.size() << endl;
    }
    return 0;
}