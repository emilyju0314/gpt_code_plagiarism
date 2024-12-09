#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> games(n);
    vector<int> bills(m);

    for(int i = 0; i < n; i++) {
        cin >> games[i];
    }

    for(int i = 0; i < m; i++) {
        cin >> bills[i];
    }

    int games_bought = 0;
    int bill_index = 0;

    for(int i = 0; i < n; i++) {
        if(bill_index < m && bills[bill_index] >= games[i]) {
            games_bought++;
            bill_index++;
        }
    }

    cout << games_bought << endl;

    return 0;
}