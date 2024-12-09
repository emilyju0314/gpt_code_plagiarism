#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    
    if(n == 1) {
        cout << (x == 0 ? "YES\n0\n" : "YES\n" + to_string(x) + "\n");
    } else if(n == 2) {
        if(x == 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n0 " + to_string(x) + "\n";
        }
    } else {
        cout << "YES\n";
        vector<int> nums;
        for(int i = 1; i <= n-3; i++) {
            cout << i << " ";
            x ^= i;
        }
        if(x == 0) {
            cout << "0 1 2\n";
        } else {
            cout << "1 2 " + to_string((1<<17) | x) + "\n";
        }
    }
    
    return 0;
}