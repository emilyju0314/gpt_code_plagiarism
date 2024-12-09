#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    
    cin >> n;
    cin >> s;
    
    int count = 0;
    
    for(int i = 0; i < n; i++) {
        if((s[i] - '0') % 2 == 0) {
            count += (i+1);
        }
    }
    
    cout << count << endl;
    
    return 0;
}