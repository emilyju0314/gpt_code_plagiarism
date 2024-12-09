#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int main() {
    int n, maxCost;
    cin >> n >> maxCost;

    unordered_map<string, unordered_map<string, int>> costs;

    for(int i = 0; i < n; i++) {
        string city1, city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        costs[city1][city2] = cost;
        costs[city2][city1] = cost;
    }

    int totalCost = 0;
    int tripsExceedingMaxCost = 0;

    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        string startCity, endCity, viaCity;
        cin >> startCity >> viaCity >> endCity;

        int tripCost = costs[startCity][viaCity] + costs[viaCity][endCity];
        totalCost += tripCost;

        if(tripCost > maxCost) {
            tripsExceedingMaxCost++;
        }
    }

    cout << totalCost << " " << tripsExceedingMaxCost;

    return 0;
}