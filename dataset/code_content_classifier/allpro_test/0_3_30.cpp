#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        unordered_map<char, int> count;
        for(char ch : s) {
            count[ch]++;
        }

        int min_erased = n;
        for(auto& p : count) {
            char ch = p.first;
            int cnt = p.second;
            int left = 0, right = n - 1;
            int erased = 0;
            while(left < right) {
                if(s[left] == ch && s[right] != ch) {
                    erased++;
                    right--;
                } else if(s[left] != ch && s[right] == ch) {
                    erased++;
                    left++;
                } else if(s[left] != ch && s[right] != ch) {
                    erased += 2;
                }
                left++;
                right--;
            }
            min_erased = min(min_erased, erased);
        }

        if(min_erased == n) {
            cout << -1 << endl;
        } else {
            cout << min_erased << endl;
        }
    }

    return 0;
}