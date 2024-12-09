#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> trips(n);
    vector<int> totalCost(n); // to store the total cost after each trip
    totalCost[0] = 20; // since the first trip always costs 20 rubles

    for (int i = 0; i < n; i++) {
        cin >> trips[i];
    }

    for (int i = 1; i < n; i++) {
        totalCost[i] = totalCost[i - 1] + 20; // assuming buying single trip ticket
        if (trips[i] - trips[i - 1] < 90) 
            totalCost[i] = min(totalCost[i], totalCost[max(0, i - 1)] + 30); // if 90 minutes ticket is cheaper
        if (trips[i] - trips[max(0, i - 1)] < 1440) 
            totalCost[i] = min(totalCost[i], totalCost[max(0, i - 2)] + 100); // if daily ticket is cheaper
    }

    cout << totalCost[0] << endl; // print the cost for the first trip
    for (int i = 1; i < n; i++) {
        cout << totalCost[i] - totalCost[i - 1] << endl; // print the cost after each trip
    }

    return 0;
}