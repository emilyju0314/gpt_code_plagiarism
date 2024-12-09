#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, p, m;
    cin >> n >> p >> m;

    vector<int> deposits(m+1, 0);

    for(int i = 0; i < n; i++) {
        int day, amount;
        cin >> day >> amount;
        deposits[day] = amount;
    }

    int balance = 0;
    int negative_days = 0;

    for(int day = 1; day <= m; day++) {
        balance -= p;
        balance += deposits[day];
        if(balance < 0) {
            negative_days++;
        }
    }

    cout << negative_days << endl;

    return 0;
}