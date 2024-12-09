#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int count = 0;

    do {
        if(s.find("0") == 0) {
            int zeroes = count(s.begin(), s.end(), '0');
            if(zeroes > 1) {
                continue;
            }
        }

        int x_count = count(s.begin(), s.end(), 'X');
        for(int num = 0; num < 100; num += 25) {
            string num_str = to_string(num);

            if(num_str.length() == s.length()) {
                int i = 0, j = 0;
                bool valid = true;
                while(i < s.length() && j < num_str.length()) {
                    if(s[i] == '_') {
                        i++;
                    } else if(s[i] == 'X') {
                        i++;
                        j++;
                    } else if(s[i] == num_str[j]) {
                        i++;
                        j++;
                    } else {
                        valid = false;
                        break;
                    }
                }

                if(valid) {
                    count++;
                }
            }
        }
    } while(next_permutation(s.begin(), s.end()));

    cout << count << endl;

    return 0;
}