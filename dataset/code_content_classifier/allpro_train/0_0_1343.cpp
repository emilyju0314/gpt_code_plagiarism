#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> groups;
    
    if (n % 2 == 0) {
        cout << n / 2 << endl;
        for (int i = 1; i <= n / 2; i++) {
            cout << i << " " << i + n/2 << endl;
        }
    } else {
        cout << n / 2 << endl;
        for (int i = 1; i <= n / 2; i++) {
            cout << i << " " << i + n/2 + 1 << endl;
        }
    }
    
    return 0;
}