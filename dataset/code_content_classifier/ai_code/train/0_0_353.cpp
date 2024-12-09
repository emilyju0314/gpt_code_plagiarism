#include <iostream>
#include <string>

using namespace std;

string improveProductName(string s, string c) {
    int n = s.size();
    int m = c.size();
    bool swapped = false;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(s[i] > s[j]) {
                swap(s[i], s[j]);
                swapped = true;
                break;
            }
        }
        if(swapped) break;
    }
    
    if(s < c) {
        return s;
    }
    
    return "---";
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s, c;
        cin >> s >> c;
        
        cout << improveProductName(s, c) << endl;
    }
    
    return 0;
}