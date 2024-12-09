#include <iostream>
using namespace std;

int count_changed_digits(int l, int r) {
    string l_str = to_string(l);
    string r_str = to_string(r);
    
    int num_changed = 0;
    int len = min(l_str.length(), r_str.length());
    for (int i = 0; i < len; i++) {
        if (l_str[i] != r_str[i]) {
            num_changed = len - i;
            break;
        }
    }
    
    return num_changed;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int l, r;
        cin >> l >> r;
        
        int total_changed = 0;
        for (int j = l; j < r; j++) {
            total_changed += count_changed_digits(j, j+1);
        }
        
        cout << total_changed << endl;
    }
    
    return 0;
}