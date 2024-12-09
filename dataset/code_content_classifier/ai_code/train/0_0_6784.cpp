#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string hint;
    cin >> hint;
    
    long long result = 1;
    vector<int> used(10, 0);
    
    for(char c : hint) {
        if(c == '?') {
            result *= 10;
        } else if(c >= '0' && c <= '9') {
            if(used[c - '0'] == 0) {
                used[c - '0'] = 1;
                result *= 1;
            } else {
                result = 0;
                break;
            }
        } else {
            if(used[c - 'A'] == 0) {
                used[c - 'A'] = 1;
                if(c != hint[0]) {
                    result *= 10 - (hint[0] == '?' ? 1 : 0) - (hint[0] >= '0' && hint[0] <= '9' ? 1 : 0);
                }
            } else {
                result = 0;
                break;
            }
        }
    }
    
    cout << result << endl;
    
    return 0;
}