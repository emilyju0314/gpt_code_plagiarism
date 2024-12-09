#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<int> stair_times(n-1);
    vector<int> elevator_times(n-1);

    for (int i = 0; i < n-1; i++) {
        cin >> stair_times[i];
    }

    for (int i = 0; i < n-1; i++) {
        cin >> elevator_times[i];
    }

    vector<int> minimum_times(n);
    minimum_times[0] = 0;

    // Using stairs only
    for (int i = 1; i < n; i++) {
        minimum_times[i] = min(minimum_times[i-1] + stair_times[i-1], minimum_times[i] + c + elevator_times[i-1]);
    }

    // Using elevator only
    for (int i = 1; i < n; i++) {
        minimum_times[i] = min(minimum_times[i], minimum_times[i-1] + c + elevator_times[i-1]);
    }

    for (int i = 0; i < n; i++) {
        cout << minimum_times[i] << " ";
    }
    
    return 0;
}