#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n); // initial remain of dishes
    vector<int> c(n); // cost of one dish
    vector<int> r(n); // remaining dishes
    vector<pair<int, int>> customers(m); // kind of food and number of dishes for each customer

    // Read initial remain of dishes
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        r[i] = a[i];
    }

    // Read cost of one dish
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }

    // Read orders of the m customers
    for(int i = 0; i < m; i++) {
        cin >> customers[i].first >> customers[i].second;
    }

    // Process each customer's order
    for(int i = 0; i < m; i++) {
        int totalCost = 0;

        int kind = customers[i].first - 1; // 0-indexed
        int numDishes = customers[i].second;
        while(numDishes > 0) {
            if(r[kind] > 0) {
                totalCost += c[kind];
                r[kind]--;
                numDishes--;
            } else {
                int minCost = *min_element(c.begin(), c.end());
                int minKind = min_element(c.begin(), c.end()) - c.begin();
                totalCost += minCost;
                r[minKind]--;
                numDishes--;
            }

            if(numDishes == 0) break;
        }

        cout << totalCost << endl;
    }

    return 0;
}