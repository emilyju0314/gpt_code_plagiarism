#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days[i];
    }

    int max_possible_days = 0;
    for (int i = 0; i < n; i++) {
        int current_day = min(days[i], days[n-1-i]);
        max_possible_days = max(max_possible_days, current_day);
    }

    cout << max_possible_days << endl;

    return 0;
}