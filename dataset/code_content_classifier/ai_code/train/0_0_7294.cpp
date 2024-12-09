#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Customer {
    int index;
    int money;

    bool operator<(const Customer& other) const {
        if (money == other.money) {
            return index > other.index;
        }
        return money < other.money;
    }
};

int main() {
    int q;
    cin >> q;

    priority_queue<Customer> pq;
    queue<int> servedCustomers;

    int currentIndex = 1;

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int money;
            cin >> money;

            pq.push({currentIndex, money});
            currentIndex++;
        } else {
            if (type == 2) {
                servedCustomers.push(pq.top().index);
                pq.pop();
            } else {
                servedCustomers.push(pq.top().index);
                pq.pop();
            }
        }
    }

    while (!servedCustomers.empty()) {
        cout << servedCustomers.front() << " ";
        servedCustomers.pop();
    }

    return 0;
}