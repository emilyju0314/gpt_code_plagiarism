#include <iostream>
#include <vector>

using namespace std;

bool canWinJackpot(int n, vector<int>& bids) {
    int count2 = 0, count3 = 0;
    for (int i = 0; i < n; i++) {
        while (bids[i] % 2 == 0) {
            bids[i] /= 2;
            count2++;
        }
        while (bids[i] % 3 == 0) {
            bids[i] /= 3;
            count3++;
        }
    }

    if (count2 == 0 && count3 == 0) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        if ((bids[i] * pow(2, count2) * pow(3, count3)) != (bids[0] * pow(2, count2) * pow(3, count3))) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    vector<int> bids(n);
    for (int i = 0; i < n; i++) {
        cin >> bids[i];
    }

    if (canWinJackpot(n, bids)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}