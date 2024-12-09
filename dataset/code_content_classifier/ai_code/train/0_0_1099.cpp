#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<char, int>> commands(n);
    
    for(int i = 0; i < n; i++) {
        cin >> commands[i].first >> commands[i].second;
    }
    
    int result = 0;
    char op = '|';
    int constant = 0;
    
    for(int i = 0; i < n; i++) {
        if(commands[i].first == '&') {
            result &= commands[i].second;
        } else if(commands[i].first == '|') {
            result |= commands[i].second;
        } else {
            result ^= commands[i].second;
        }
    }
    
    for(int i = 0; i < 10; i++) {
        if((result & (1 << i)) != 0) {
            constant |= (1 << i);
        }
    }
    
    cout << 1 << endl;
    cout << op << " " << constant << endl;
    
    return 0;
}