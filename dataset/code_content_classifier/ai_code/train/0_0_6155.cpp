#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> seq(n);
    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }
    
    int moves = 0;
    for (int i = 1; i < n; i++) {
        if (seq[i] <= seq[i - 1]) {
            int diff = seq[i - 1] - seq[i];
            int add = diff / d + 1;
            moves += add;
            seq[i] += add * d;
        }
    }
    
    cout << moves << endl;
    
    return 0;
}