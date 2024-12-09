#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string slogan;
    cin >> slogan;
    
    int startPos = k, endPos = k;
    
    vector<string> actions;
    
    while(endPos < n) {
        actions.push_back("RIGHT");
        endPos++;
    }
    while(startPos > 1) {
        actions.push_back("LEFT");
        startPos--;
    }
    
    for(int i = 0; i < n; ++i) {
        if(i == k - 1) {
            actions.push_back("PRINT " + string(1, slogan[i]));
        } else {
            if(i < k - 1) {
                actions.push_back("LEFT");
            } else {
                actions.push_back("RIGHT");
            }
            actions.push_back("PRINT " + string(1, slogan[i]));
        }
    }
    
    cout << actions.size() << endl;
    for(auto action : actions) {
        cout << action << endl;
    }
    
    return 0;
}