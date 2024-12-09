#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> transactions(n);
    for (int i = 0; i < n; i++) {
        cin >> transactions[i];
    }

    int balance = 0;
    int min_days = 0;
    for (int i = 0; i < n; i++) {
        if (transactions[i] == 0) {
            if (balance < 0) {
                int deposit = min(d - balance, -balance);
                min_days += deposit > 0 ? 1 : 0;
                balance += deposit;
            }
        } else {
            balance += transactions[i];
            if (balance > d) {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << min_days << endl;

    return 0;
}