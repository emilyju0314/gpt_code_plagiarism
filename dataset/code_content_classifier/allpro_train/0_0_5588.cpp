#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Gadget {
    int type;
    int cost;
};

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;

    vector<int> dollar_cost(n);
    vector<int> pound_cost(n);

    for (int i = 0; i < n; i++) {
        cin >> dollar_cost[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> pound_cost[i];
    }

    vector<Gadget> gadgets(m);
    for (int i = 0; i < m; i++) {
        cin >> gadgets[i].type >> gadgets[i].cost;
    }

    // Sort gadgets by cost
    sort(gadgets.begin(), gadgets.end(), [](const Gadget &a, const Gadget &b) {
        return a.cost < b.cost;
    });

    vector<int> result;
    int gadget_count = 0;
    for (int day = 0; day < n; day++) {
        for (int i = 0; i < m; i++) {
            if (gadgets[i].type == 1 && gadgets[i].cost <= dollar_cost[day] * s) {
                result.push_back(i + 1);
                result.push_back(day + 1);
                gadget_count++;
                break;
            } else if (gadgets[i].type == 2 && gadgets[i].cost <= pound_cost[day] * s) {
                result.push_back(i + 1);
                result.push_back(day + 1);
                gadget_count++;
                break;
            }
        }

        if (gadget_count == k) {
            cout << day + 1 << endl;
            for (int j = 0; j < result.size(); j += 2) {
                cout << result[j] << " " << result[j + 1] << endl;
            }
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}