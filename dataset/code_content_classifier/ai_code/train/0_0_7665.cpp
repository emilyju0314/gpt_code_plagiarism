#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> piles(n);
    int xor_sum = 0;
    int max_pile = 0;
    
    for(int i = 0; i < n; i++) {
        cin >> piles[i];
        xor_sum ^= piles[i];
        max_pile = max(max_pile, piles[i]);
    }
    
    if(xor_sum == 0) {
        cout << "Nicky" << endl;
    } else {
        if(k % 2 == 0 && n == 1) {
            cout << "Nicky" << endl;
        } else if(xor_sum == max_pile) {
            cout << "Kevin" << endl;
        } else {
            cout << "Nicky" << endl;
        }
    }
    
    return 0;
}