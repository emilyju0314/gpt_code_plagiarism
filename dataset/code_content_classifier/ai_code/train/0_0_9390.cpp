#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    if (n == 1) {
        cout << -1 << endl;
    } else if (n == 2) {
        int diff = cards[1] - cards[0];
        if (diff % 2 == 0) {
            cout << 3 << endl;
            cout << cards[0] - diff << " " << (cards[0] + cards[1]) / 2 << " " << cards[1] + diff << endl;
        } else {
            cout << 2 << endl;
            cout << cards[0] - diff << " " << cards[1] + diff << endl;
        }
    } else {
        set<int> possibleNums;
        int diff = cards[1] - cards[0];
        for (int i = 0; i < n - 1; i++) {
            if (cards[i + 1] - cards[i] != diff) {
                possibleNums.insert(cards[i] + diff);
                possibleNums.insert(cards[i] - diff);
            }
        }

        if (possibleNums.size() == 0) {
            cout << 0 << endl;
        } else {
            cout << possibleNums.size() << endl;
            for (int num : possibleNums) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}