#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> values(n);
    for(int i=0; i<n; i++) {
        cin >> values[i];
    }

    int max_price = 0;
    int min_days = 0;

    // sort the items in decreasing order of value
    sort(values.begin(), values.end(), greater<int>());

    for(int i=0; i<n; i++) {
        // Calculate the total price after each exchange
        int total_price = 0;
        int days = 0;

        while(total_price + values[i] <= max_price + d) {
            total_price += values[i];
            days++;
        }

        max_price = max(max_price, total_price);
        min_days += days;
    }

    cout << max_price << " " << min_days << endl;

    return 0;
}