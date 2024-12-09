#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    int groups[n];
    for (int i = 0; i < n; i++) {
        cin >> groups[i];
    }
    
    int buses = 0;
    int current_capacity = 0;
    
    for (int i = 0; i < n; i++) {
        if (current_capacity + groups[i] <= m) {
            current_capacity += groups[i];
        } else {
            buses++;
            current_capacity = groups[i];
        }
    }
    
    if (current_capacity > 0) {
        buses++;
    }
    
    cout << buses << endl;
    
    return 0;
}