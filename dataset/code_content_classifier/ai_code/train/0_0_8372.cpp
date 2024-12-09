#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    
    int aCount = 0;
    int bCount = 0;
    int result = 0;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == 'a') {
            aCount++;
            result = max(result, aCount + bCount);
        } else {
            bCount++;
        }
    }
    
    cout << result << endl;

    return 0;
}