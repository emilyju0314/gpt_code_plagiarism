#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        cin >> skills[i];
    }

    sort(skills.begin(), skills.end());

    int num_teams = 0;
    long long count = 0;
    for (int i = 0; i < n; i++) {
        if (i >= 4) {
            if (skills[i] == skills[i-1]) {
                count++;
            } else {
                count = 1;
            }

            if (count >= 2) {
                num_teams = (num_teams + ((count * (count-1) / 2) % MOD)) % MOD;
            }
        }
    }

    int m;
    cin >> m;

    while (m--) {
        int t, x;
        cin >> t >> x;

        if (t == 1) {
            for (int i = 0; i < n; i++) {
                if (skills[i] == x) {
                    skills.erase(skills.begin() + i);
                    n--;
                    i--;
                }
            }
        } else {
            skills.push_back(x);
            n++;
            sort(skills.begin(), skills.end());

            num_teams = 0;
            count = 0;
            for (int i = 0; i < n; i++) {
                if (i >= 4) {
                    if (skills[i] == skills[i-1]) {
                        count++;
                    } else {
                        count = 1;
                    }

                    if (count >= 2) {
                        num_teams = (num_teams + ((count * (count-1) / 2) % MOD)) % MOD;
                    }
                }
            }
        }

        cout << num_teams << endl;
    }

    return 0;
}