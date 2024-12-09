#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int k;
        cin >> k;

        string s, a, b;
        cin >> s >> a >> b;

        vector<char> template_str(k);
        vector<int> count(26, 0);

        for(char c : s) {
            count[c - 'a']++;
        }

        vector<pair<char, int>> sorted_count;
        for(int i = 0; i < k; i++) {
            sorted_count.push_back({char('a' + i), count[i]});
        }

        sort(sorted_count.rbegin(), sorted_count.rend(), [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        });

        bool found_template = false;

        do {
            vector<char> template_str(k);
            for(int i = 0; i < k; i++) {
                template_str[sorted_count[i].first - 'a'] = char('a' + i);
            }

            string transformed_s;
            for(char c : s) {
                transformed_s += template_str[c - 'a'];
            }

            if(transformed_s >= a && transformed_s <= b) {
                cout << "YES" << endl;
                for(char c : template_str) {
                    cout << c;
                }
                cout << endl;
                found_template = true;
                break;
            }
        } while(next_permutation(sorted_count.begin(), sorted_count.end()));

        if(!found_template) {
            cout << "NO" << endl;
        }
    }

    return 0;
}