#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> tests(n);
    
    for(int i = 0; i < n; i++) {
        cin >> tests[i];
    }
    
    for(int i = 0; i < n; i++) {
        // If the number of vertices is even, the second player wins, otherwise the first player wins
        if(tests[i] % 2 == 0) {
            cout << "2" << endl;
        } else {
            cout << "1" << endl;
        }
    }
    
    return 0;
}