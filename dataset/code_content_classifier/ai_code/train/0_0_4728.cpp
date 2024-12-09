#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string integer;
    cin >> integer;
    
    int m;
    cin >> m;
    
    int n = integer.length();
    int min_remainder = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        string shift = integer.substr(i) + integer.substr(0, i);
        int remainder = stoi(shift) % m;
        min_remainder = min(min_remainder, remainder);
    }
    
    cout << min_remainder << endl;
    
    return 0;
}