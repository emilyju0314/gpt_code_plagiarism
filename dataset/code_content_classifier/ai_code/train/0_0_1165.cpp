#include <iostream>
#include <string>
using namespace std;

int main() {
    string x;
    cin >> x;
    
    int n = x.length();
    int complexity = 0;
    
    for(int i = 0; i < n; i++) {
        if(x[i] == '1') {
            complexity = (complexity + (1 << i) * (1 << i)) % 1000000007;
        }
    }
    
    cout << complexity << endl;
    
    return 0;
}