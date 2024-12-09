#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> badges(n);
    for(int i = 0; i < n; i++) {
        cin >> badges[i];
    }

    sort(badges.begin(), badges.end());

    int coinsNeeded = 0;
    for(int i = 1; i < n; i++) {
        if(badges[i] <= badges[i - 1]) {
            coinsNeeded += badges[i - 1] + 1 - badges[i];
            badges[i] = badges[i - 1] + 1;
        }
    }

    cout << coinsNeeded << endl;

    return 0;
}