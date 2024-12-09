#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<long long> piles(n);
    for(int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    
    long long total = 0;
    for(int i = 0; i < n; i++) {
        total += piles[i];
    }
    
    long long min_move = -1;
    
    for(int i = 1; i < n; i++) {
        long long takahashi_stones = 0;
        for(int j = 1; j < i; j++) {
            takahashi_stones += piles[j];
        }
        
        if(takahashi_stones >= piles[i]) {
            long long move = takahashi_stones - piles[i] + 1;
            if(min_move == -1 || move < min_move) {
                min_move = move;
            }
        }
    }
    
    cout << min_move << endl;
    
    return 0;
}