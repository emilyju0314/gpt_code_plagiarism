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

    int xor_sum = 0;
    for(int i = 0; i < n; i++) {
        xor_sum ^= piles[i];
    }

    if(xor_sum == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }

    return 0;
}