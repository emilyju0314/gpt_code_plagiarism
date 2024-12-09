#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<int> records(n);
    for(int i = 0; i < n; i++) {
        cin >> records[i];
    }

    int min_passengers = 0, max_passengers = 0, passengers = 0;
    for(int i = 0; i < n; i++) {
        passengers += records[i];
        min_passengers = min(min_passengers, passengers);
        max_passengers = max(max_passengers, passengers);
    }

    int possible_ways = max(0, min(w - max_passengers, w - min_passengers) + 1);
    cout << possible_ways << endl;

    return 0;
}