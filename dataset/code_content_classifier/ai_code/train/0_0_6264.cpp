#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool compliesWithRules(const string& t, const vector<pair<string, pair<int, int>>>& rules) {
    for(const auto& rule : rules) {
        int count = 0;
        size_t pos = -1;
        while((pos = rule.first.find(t, pos + 1)) != string::npos) {
            count++;
            if(count < rule.second.first || count > rule.second.second) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<pair<string, pair<int, int>> rules;
    for(int i = 0; i < n; i++) {
        string p;
        int l, r;
        cin >> p >> l >> r;
        rules.push_back({p, {l, r}});
    }

    int goodSubstrings = 0;
    for(int i = 0; i < s.size(); i++) {
        for(int j = i; j < s.size(); j++) {
            string t = s.substr(i, j-i+1);
            if(compliesWithRules(t, rules)) {
                goodSubstrings++;
            }
        }
    }

    cout << goodSubstrings << endl;

    return 0;
}