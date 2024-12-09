#include <iostream>
#include <string>

using namespace std;

bool canTransform(string a, string b) {
    int count_a = 0, count_b = 0;
    
    for(char c : a) {
        if(c == '0') count_a++;
        else count_a--;
    }
    
    for(char c : b) {
        if(c == '0') count_b++;
        else count_b--;
    }
    
    if(count_a != count_b) return false;
    
    int n = a.length();
    int diff = 0;
    
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            diff++;
            if(diff > 2 || (diff == 2 && a[i] != a[i-1])) {
                return false;
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        string a, b;
        cin >> n >> a >> b;
        
        if(canTransform(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}