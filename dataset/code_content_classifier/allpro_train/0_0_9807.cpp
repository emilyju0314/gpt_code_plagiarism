#include <iostream>
#include <string>

using namespace std;

int minZeroToErase(string s) {
    int count = 0;
    bool startCounting = false;
    int zeros = 0;
    
    for(char c : s) {
        if(startCounting) {
            if(c == '0') {
                zeros++;
            }
        }
        if(c == '1') {
            startCounting = true;
            count += zeros;
            zeros = 0;
        }
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        cout << minZeroToErase(s) << endl;
    }
    
    return 0;
}