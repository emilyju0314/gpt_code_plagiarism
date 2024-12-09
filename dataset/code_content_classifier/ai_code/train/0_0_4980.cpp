#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<string, char>> operations(q);
    for (int i = 0; i < q; i++) {
        string ai;
        char bi;
        cin >> ai >> bi;
        operations[i] = make_pair(ai, bi);
    }

    int count = 0;

    for (int i = 0; i < 6; i++) {
        string s = "";
        s += 'a' + i;
        for (int j = 0; j < 6; j++) {
            s += 'a' + j;
            for (int k = 0; k < 6; k++) {
                s += 'a' + k;
                bool possible = true;
                string temp = s;
                for (int l = 0; l < n - 1; l++) {
                    bool found = false;
                    for (int m = 0; m < q; m++) {
                        if (temp.substr(0, 2) == operations[m].first) {
                            found = true;
                            temp = operations[m].second + temp.substr(2);
                            break;
                        }
                    }
                    if (!found) {
                        possible = false;
                        break;
                    }
                }
                if (possible && temp == "a") {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}