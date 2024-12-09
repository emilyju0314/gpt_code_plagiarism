#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    
    int a, b;
    cin >> a >> b;
    
    int moves = 0;
    while(a != b) {
        // Subtract 1 from a if a is greater than b
        if(a > b) {
            a--;
            moves++;
        } else {
            int min_move = a;
            for(int xi : x) {
                if(a - a % xi >= b) {
                    min_move = min(min_move, a % xi);
                }
            }
            a -= min_move;
            moves++;
        }
    }
    
    cout << moves << endl;
    
    return 0;
}