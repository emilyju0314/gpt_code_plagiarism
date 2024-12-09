#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> piles(N);
    for(int i = 0; i < N; i++) {
        cin >> piles[i];
    }
    
    int xor_sum = 0;
    int min_pile = INT_MAX;
    for(int i = 0; i < N; i++) {
        xor_sum ^= piles[i];
        min_pile = min(min_pile, piles[i]);
    }
    
    if(xor_sum == 0) {
        cout << -1 << endl; // Cheater cannot guarantee a win regardless of the moves
    } else {
        int num_stones = 0;
        for(int i = 0; i < N; i++) {
            int temp_xor = xor_sum ^ piles[i];
            if(temp_xor < piles[i]) {
                num_stones += piles[i] - temp_xor;
            }
        }
        cout << num_stones << endl;
    }
    
    return 0;
}