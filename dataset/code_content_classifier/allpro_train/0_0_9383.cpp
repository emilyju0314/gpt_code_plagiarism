#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int period = n + m;
    int days = k * period;
    int employees = (days + period - 1) / period;

    cout << employees << endl;

    vector<int> hire_days;
    int day = 1;
    for (int i = 0; i < employees; i++) {
        hire_days.push_back(day);
        day += n;
    }

    for (int day : hire_days) {
        cout << day << " ";
    }

    return 0;
}