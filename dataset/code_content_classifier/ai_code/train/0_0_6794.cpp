#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> arguments(n);
    for(int i = 0; i < n; i++) {
        cin >> arguments[i];
    }
    
    // Check if the number of '0's and '1's are not equal
    int count_0 = 0, count_1 = 0;
    for(int i = 0; i < n; i++) {
        if(arguments[i] == 0) count_0++;
        else count_1++;
    }
    
    if(count_0 != count_1) {
        cout << "YES\n";
        cout << arguments[0];
        for(int i = 1; i < n; i++) {
            cout << "->" << arguments[i];
        }
        cout << endl;
    } else {
        cout << "NO\n";
    }
    
    return 0;
}