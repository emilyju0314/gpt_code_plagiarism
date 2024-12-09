#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int ab_count = 0, ba_count = 0;
        vector<int> ab_indices, ba_indices;

        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == 'a' && s[i+1] == 'b') {
                ab_count++;
                ab_indices.push_back(i);
            }
            if(s[i] == 'b' && s[i+1] == 'a') {
                ba_count++;
                ba_indices.push_back(i);
            }
        }

        if(ab_count == 0 || ba_count == 0) {
            cout << s << endl;
        } else {
            if(ab_count > ba_count) {
                s[ab_indices[0] + 1] = 'a';
            } else {
                s[ba_indices[0] + 1] = 'b';
            }
            cout << s << endl;
        }
    }

    return 0;
}