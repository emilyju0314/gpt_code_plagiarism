#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        
        vector<int> prices(n);
        for (int j = 0; j < n; j++) {
            cin >> prices[j];
        }

        int days_with_bad_price = 0;
        int min_price = prices[n-1];
        
        for (int j = n-2; j >= 0; j--) {
            if (prices[j] > min_price) {
                days_with_bad_price++;
            } else {
                min_price = prices[j];
            }
        }

        cout << days_with_bad_price << endl;
    }

    return 0;
}