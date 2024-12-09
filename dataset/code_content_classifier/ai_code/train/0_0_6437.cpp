#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string road;
    cin >> road;
    
    bool canReachEnd = true;
    int consecutiveRocks = 0;
    for (int i = 0; i < n; i++) {
        if (road[i] == '#') {
            consecutiveRocks++;
            if (consecutiveRocks >= k) {
                canReachEnd = false;
                break;
            }
        } else {
            consecutiveRocks = 0;
        }
    }
    
    if (canReachEnd) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}