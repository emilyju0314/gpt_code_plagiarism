#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> wallets(n);
    for (int i = 0; i < n; i++) {
        cin >> wallets[i];
    }

    string instructions = "";
    int current = 0;
    while (true) {
        if (wallets[current] == 0) {
            break;
        }
        if (current % 2 == 0) {
            instructions += 'R';
            wallets[current]--;
        } else {
            instructions += 'L';
            wallets[current]--;
        }
        if (wallets[current] == 0) {
            break;
        }
        instructions += 'P';
    }

    cout << instructions << endl;

    return 0;
}