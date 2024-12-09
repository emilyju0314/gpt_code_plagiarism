#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> piles(n);
    int xor_sum = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        xor_sum ^= piles[i];
    }
    
    if (xor_sum == 0) {
        cout << "Rublo" << endl;
    } else {
        cout << "Furlo" << endl;
    }
    
    return 0;
}