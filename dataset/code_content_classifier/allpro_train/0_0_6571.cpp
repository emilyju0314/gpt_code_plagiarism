#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int getMinSubstitutions(const vector<pair<string, string>>& substitutions, const string& initial, const string& final) {
    map<string, int> dp;
    dp[initial] = 0;

    while (true) {
        bool updated = false;
        for (const auto& sub : substitutions) {
            string alpha = sub.first;
            string beta = sub.second;

            for (auto it = dp.begin(); it != dp.end(); ++it) {
                size_t found = it->first.find(alpha);
                while (found != string::npos) {
                    string newString = it->first;
                    newString.replace(found, alpha.size(), beta);

                    if (dp.find(newString) == dp.end() || dp[newString] > it->second + 1) {
                        dp[newString] = it->second + 1;
                        updated = true;
                    }

                    found = it->first.find(alpha, found + beta.size());
                }
            }
        }

        if (!updated) {
            break;
        }
    }

    if (dp.find(final) == dp.end()) {
        return -1;
    } else {
        return dp[final];
    }
}

int main() {
    int n;
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        vector<pair<string, string>> substitutions;
        for (int i = 0; i < n; i++) {
            string alpha, beta;
            cin >> alpha >> beta;
            substitutions.push_back(make_pair(alpha, beta));
        }

        string initial, final;
        cin >> initial >> final;

        int minSubstitutions = getMinSubstitutions(substitutions, initial, final);
        cout << minSubstitutions << endl;
    }

    return 0;
}