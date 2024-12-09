#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    int n = s.size();
    int k = 1;
    
    while (k * (2*k - 1) <= n) {
        k++;
    }
    k--;
    
    for (int i = k; i >= 1; i--) {
        string new_s = "";
        bool deleted = false;
        for (int j = 0; j < n; j++) {
            if (j + 2*i - 1 <= n && !deleted) {
                string sub = s.substr(j, 2*i - 1);
                if (sub[0] != sub[sub.size()-1]) {
                    new_s += min(sub[0], sub[sub.size()-1]);
                    j += 2*i - 2;
                } else {
                    new_s += sub[0];
                }
                deleted = true;
            } else {
                new_s += s[j];
            }
        }
        s = new_s;
    }
    
    cout << s << endl;
    
    return 0;
}