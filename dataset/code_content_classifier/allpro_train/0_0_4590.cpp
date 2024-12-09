#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    s += s; // doubling the sequence to handle wrapping cases
    
    int max_length = 0;
    int count = 1;
    
    for(int i = 1; i < s.size(); i++) {
        if(s[i] != s[i-1]) {
            count++;
        } else {
            max_length = max(max_length, count);
            count = 1;
        }
    }
    
    cout << min(max_length, (int)s.size()/2) << endl;
    
    return 0;
}