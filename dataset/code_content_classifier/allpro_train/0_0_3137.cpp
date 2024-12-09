#include <iostream>
#include <string>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int operations = 0;
    
    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i]) {
            operations++;
        }
    }
    
    cout << operations << endl;
    
    return 0;
}