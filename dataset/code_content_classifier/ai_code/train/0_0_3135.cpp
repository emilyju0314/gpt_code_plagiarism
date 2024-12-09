#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events; // birth year is +1, death year is -1
    for(int i = 0; i < n; i++) {
        int b, d;
        cin >> b >> d;
        events.push_back({b, 1});
        events.push_back({d, -1});
    }

    sort(events.begin(), events.end());

    int maxAlive = 0;
    int currentAlive = 0;
    int year = 0;

    for(auto event : events) {
        currentAlive += event.second;
        if(currentAlive > maxAlive) {
            maxAlive = currentAlive;
            year = event.first;
        }
    }

    cout << year << " " << maxAlive << endl;

    return 0;
}