#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, c;
    cin >> n >> c;

    vector<pair<int, int>> planets(n);
    for (int i = 0; i < n; i++) {
        cin >> planets[i].first >> planets[i].second;
    }

    long long ways = 0;
    for (int x = 1; x <= 10000; x++) {
        bool valid = true;
        long long days = 0;
        for (int i = 0; i < n; i++) {
            int suitcases = planets[i].first;
            int citizens = planets[i].second;
            int presents = suitcases * x;
            days += suitcases;
            if (presents < citizens) {
                valid = false;
                break;
            }
            long long remaining = presents - citizens;
            long long additional_days = (remaining + citizens - 1) / citizens;
            days += additional_days;
        }
        if (valid && days == c) {
            ways++;
        }
    }

    cout << ways << endl;

    return 0;
}