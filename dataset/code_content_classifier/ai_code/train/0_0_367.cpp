#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int time, cost;
};

int main() {
    int n;
    cin >> n;

    vector<Item> items(n);
    for(int i = 0; i < n; i++) {
        cin >> items[i].time >> items[i].cost;
    }

    sort(items.begin(), items.end(), [](Item &a, Item &b) {
        return a.time < b.time;
    });

    long long totalCost = 0;
    for(int i = 0; i < n; i++) {
        int time = items[i].time;
        int cost = items[i].cost;

        for(int j = i - 1; j >= 0 && time > 0; j--) {
            if(items[j].time == 0) {
                totalCost += items[j].cost;
                time--;
            }
        }

        totalCost += cost;
    }

    cout << totalCost << endl;

    return 0;
}