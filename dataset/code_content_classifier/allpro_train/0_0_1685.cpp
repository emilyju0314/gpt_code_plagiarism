#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s, p;
    cin >> s >> p;

    vector<int> count(s.size() + 1, 0);

    for (int x = 0; x <= s.size(); x++) {
        string s_prime = s;
        for (int i = 0; i < s.size() && x > 0; i++) {
            if (s_prime[i] == p[0]) {
                s_prime.erase(i, 1);
                x--;
                i--;
            }
        }

        int max_substr_count = 0;
        for (size_t i = 0; i < s_prime.size(); ) {
            bool found = true;
            for (char c : p) {
                if (i < s_prime.size() && s_prime[i] == c) {
                    i++;
                } else {
                    found = false;
                    break;
                }
            }

            if (found) {
                max_substr_count++;
                i += p.size();
            } else {
                i++;
            }
        }

        count[x] = max_substr_count;
    }

    for (int x : count) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}