#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;
    
    vector<int> cards(n);
    for(int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    
    vector<vector<int>> swaps;
    int totalCards = n * s;
    
    for(int i = 0; i < n; i++) {
        if(cards[i] == 0) continue;
        
        int recipient = i+1;
        if(recipient == n) recipient = 0;
        
        int numSwaps = min(cards[i], cards[recipient]);
        swaps.push_back({i+1, recipient+1});
        
        cards[i] -= numSwaps;
        cards[recipient] -= numSwaps;
        totalCards -= 2*numSwaps;
    }
    
    if(totalCards != 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        cout << swaps.size() << endl;
        for(auto swap : swaps) {
            cout << swap[0] << " " << swap[1] << endl;
        }
    }
    
    return 0;
}