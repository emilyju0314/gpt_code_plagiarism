#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>

using namespace std;

int n;
string initial_order, final_order;

int calculate_cost(string current_order) {
    int cost = 0;
    for (int i = 0; i < n; i++) {
        if (current_order[i] != final_order[i]) {
            cost++;
        }
    }
    return cost;
}

int solve(int position, string current_order) {
    if (current_order == final_order) {
        return 0;
    }
    if (position == n - 1) {
        return calculate_cost(current_order);
    }
    
    int cost = INT_MAX;
    for (int i = position; i < n; i++) {
        swap(current_order[position], current_order[i]);
        cost = min(cost, solve(position + 1, current_order) + i - position);
        swap(current_order[i], current_order[position]);
    }
    return cost;
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        cin >> initial_order >> final_order;
        
        int result = solve(0, initial_order);
        cout << result << endl;
    }
    
    return 0;
}