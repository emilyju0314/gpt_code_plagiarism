#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int m, n, k, d;

// Function to calculate the minimum net calories burned for a given dataset
int calculateNetCalories(vector<int>& cakeCalories, vector<vector<int>>& distances) {
    // Implement your logic here to calculate the minimum net calories burned
    return 0;
}

int main() {
    while (true) {
        cin >> m >> n >> k >> d;
        if (m == 0 && n == 0 && k == 0 && d == 0) {
            break;
        }

        vector<int> cakeCalories(m);
        for (int i = 0; i < m; i++) {
            cin >> cakeCalories[i];
        }

        vector<vector<int>> distances(d, vector<int>(3));
        unordered_map<string, int> distanceMap;

        for (int i = 0; i < d; i++) {
            char source, target;
            string key;
            cin >> source >> target >> distances[i][2];
            key = string(1, source) + string(1, target);
            distanceMap[key] = distances[i][2];
        }

        int result = calculateNetCalories(cakeCalories, distances);
        cout << result << endl;
    }

    return 0;
}