#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int xs, ys;
    cin >> xs >> ys;
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> objects(n);
    for (int i = 0; i < n; i++) {
        cin >> objects[i].first >> objects[i].second;
    }
    
    // Calculate the minimum time needed to put all objects back into the handbag
    int minTime = INT_MAX;
    vector<int> bestOrder;
    
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i + 1;
    }
    
    do {
        // Initialize the current time as the time to move from the handbag to the first object
        int currentTime = pow(xs - objects[order[0] - 1].first, 2) + pow(ys - objects[order[0] - 1].second, 2);
        
        // Add the time it takes to go from one object to the next
        for (int i = 1; i < n; i++) {
            currentTime += pow(objects[order[i] - 1].first - objects[order[i - 1] - 1].first, 2) + pow(objects[order[i] - 1].second - objects[order[i - 1] - 1].second, 2);
        }
        
        // Add the time it takes to go from the last object back to the handbag
        currentTime += pow(objects[order[n - 1].first - 1].first - xs, 2) + pow(objects[order[n - 1].first - 1].second - ys, 2);
        
        if (currentTime < minTime) {
            minTime = currentTime;
            bestOrder = order;
        }
    } while (next_permutation(order.begin(), order.end()));
    
    // Output the minimum time needed and the optimal order of actions
    cout << minTime << endl;
    cout << "0 ";
    for (int i = 0; i < n; i++) {
        cout << bestOrder[i] << " ";
    }
    cout << "0" << endl;
    
    return 0;
}