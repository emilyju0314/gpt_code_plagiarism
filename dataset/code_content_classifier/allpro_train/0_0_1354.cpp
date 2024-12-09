#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> receipts(n);
    for (int i = 0; i < n; i++) {
        cin >> receipts[i];
    }

    int total_payments = 0;
    vector<int> bonus_used(n, 0);

    for (int i = 0; i < n; i++) {
        int bonus_to_use = min(b, receipts[i] / 2);
        bonus_used[i] = bonus_to_use;

        total_payments += receipts[i] - bonus_to_use;
        b += (receipts[i] - bonus_to_use) / 10;
    }

    cout << total_payments << endl;
    for (int i = 0; i < n; i++) {
        cout << bonus_used[i] << " ";
    }
    cout << endl;

    return 0;
}