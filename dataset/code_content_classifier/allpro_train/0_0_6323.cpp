#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    
    int max_length = 1;
    int length = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] > s[i-1]) {
            length++;
        } else {
            length = 1;
        }
        max_length = max(max_length, length);
    }
    
    cout << max_length << endl;
    
    return 0;
}