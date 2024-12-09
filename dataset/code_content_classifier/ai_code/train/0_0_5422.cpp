#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    queue<int> order;
    int minNum = *min_element(cards.begin(), cards.end());

    for (int i = 0; i < n; i++) {
        if (cards[i] == minNum) {
            order.push(cards[i]);
        }
    }

    int count = 0;
    int index = 0;

    while (!order.empty()) {
        if (cards[index] == order.front()) {
            order.pop();
        }
        index++;
        count++;
    }

    cout << count << endl;

    return 0;
}