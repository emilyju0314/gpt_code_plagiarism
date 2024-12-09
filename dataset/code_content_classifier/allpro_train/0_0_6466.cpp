#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> employees(n);
    for(int i = 0; i < n; i++) {
        cin >> employees[i].first >> employees[i].second;
    }

    int current_floor = 1, total_time = 0;
    
    for(int i = 0; i < n; i++) {
        total_time += abs(current_floor - employees[i].first); // Move to the employee's initial floor
        current_floor = employees[i].first;

        total_time += abs(current_floor - employees[i].second); // Move to the employee's destination floor
        current_floor = employees[i].second;
        
        total_time += 1; // Time taken for employee to enter or exit elevator
    }

    cout << total_time << endl;

    return 0;
}