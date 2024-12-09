#include <iostream>
#include <vector>

using namespace std;

int main() {
    while (true) {
        int n, r;
        cin >> n >> r;
        if (n == 0 && r == 0) {
            break;
        }
        
        vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cards[i] = n - i;
        }
        
        for (int i = 0; i < r; i++) {
            int p, c;
            cin >> p >> c;
            vector<int> pulled_out;
            for (int j = 0; j < c; j++) {
                pulled_out.push_back(cards[p - 1 + j]);
            }
            for (int j = p - 1; j < n - c; j++) {
                cards[j] = cards[j + c];
            }
            for (int j = 0; j < c; j++) {
                cards[n - c + j] = pulled_out[j];
            }
        }
        
        cout << cards[0] << endl;
    }
    
    return 0;
}