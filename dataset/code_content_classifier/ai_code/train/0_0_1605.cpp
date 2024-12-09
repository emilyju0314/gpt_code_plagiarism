#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    string original = s;

    vector<int> p(k);
    for (int i = 0; i < k; i++) {
        p[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int li, ri;
            char ci;
            cin >> li >> ri >> ci;

            for (int j = li - 1; j <= ri - 1; j++) {
                s[j] = ci;
            }
        } else {
            string permutation;
            cin >> permutation;

            int result = 0;
            do {
                string repeated;
                for (int j = 0; j < k; j++) {
                    char c = permutation[p[j]];
                    repeated += string(count(original.begin(), original.end(), c), c);
                }

                int j = 0, k = 0;
                while (j < repeated.size() && k < s.size()) {
                    if (repeated[j] == s[k]) {
                        j++;
                    }

                    k++;
                }

                if (j == repeated.size()) {
                    result = repeated.size();
                    break;
                }
            } while (next_permutation(p.begin(), p.end()));

            cout << result << endl;
        }
    }

    return 0;
}