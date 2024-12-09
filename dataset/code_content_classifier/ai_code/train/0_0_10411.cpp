#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        
        vector<int> guess(n);
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++) {
            cin >> guess[i];
            freq[guess[i]]++;
        }
        
        vector<int> code(n, 0);
        int idx = 0;
        
        for (int i = 1; i <= n+1; i++) {
            if (freq[i] == 0) {
                code[idx++] = i;
            }
        }
        
        // Check if there is a valid solution
        if (x == n) {
            if (y == n) {
                for (int i = 0; i < n; i++) {
                    cout << code[i] << " ";
                }
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (y == n) {
                cout << "NO" << endl;
            } else {
                if (code[n-x] == guess[n-x]) {
                    swap(code[n-x], code[n-x-1]);
                }
                for (int i = 0; i < n; i++) {
                    cout << code[i] << " ";
                }
                cout << endl;
            }
        }
    }
    
    return 0;
} 

//The code reads the input, processes the input according to the rules of the game, and outputs the possible solution for Alice's secret code.