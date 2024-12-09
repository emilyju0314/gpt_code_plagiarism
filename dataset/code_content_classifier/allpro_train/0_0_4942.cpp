#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> piles(n);
    for(int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    // Count the number of piles with odd number of stones
    int oddPiles = 0;
    for(int i = 0; i < n; i++) {
        if(piles[i] % 2 == 1) {
            oddPiles++;
        }
    }

    // If there are more than n/2 piles with odd number of stones, Alice wins
    if(oddPiles > n/2) {
        cout << "Alice" << endl;
    } else {
        cout << "Bob" << endl;
    }

    return 0;
}