#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string t;
    cin >> n >> t;
    
    string s = t;
    
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            reverse(s.begin(), s.begin() + i);
        }
    }
    
    cout << s << endl;
    
    return 0;
}