#include <iostream>
#include <string>

using namespace std;

int main() {
    string p, s;
    int k;
    cin >> p >> s >> k;

    string result;
    int s_len = s.length();
    for (int i = 0; i < k; i++) {
        int j = 0;
        string key;
        for (int l = 0; l < i; l++) {
            key += '0';
        }
        key += '1';
        for (int l = i+1; l < k; l++) {
            key += '0';
        }
        
        int p_len = p.length();
        string extracted_message;
        for (int x = 0, y = 0; x < p_len; x++) {
            if (s[y] == '1') {
                extracted_message += p[x];
            }
            if (extracted_message == s) {
                result = key;
                break;
            }
            y++;
            if (y == s_len) {
                y = 0;
            }
        }
        
        if (!result.empty()) {
            break;
        }
    }

    if (result.empty()) {
        cout << "0" << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}