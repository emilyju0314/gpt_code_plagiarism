#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), k(n);

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> k[i];
    }

    long long money = 0;
    long long max_price = 0;

    for(int i = 0; i < n; i++) {
        long long loan = a[i];
        long long repayment = b[i] * k[i];
        for(int j = 0; j < n; j++) {
            if(j != i) {
                money -= min(k[j] * b[j], repayment);
            }
        }
        money += loan;
        max_price = max(max_price, money);
        money -= repayment;
    }

    cout << max_price << endl;

    return 0;
}