#include <iostream>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    map<string, vector<string>> variables;
    map<string, bitset<1000>> values;

    for (int i = 0; i < n; i++) {
        string var, eq, op1, op, op2;
        cin >> var >> eq >> op1 >> op >> op2;

        if (op1 == "?") {
            variables[var].push_back(op2);
        } else if (op2 == "?") {
            variables[var].push_back(op1);
        }

        values[var].reset();
    }

    bitset<1000> min_value;
    bitset<1000> max_value;

    for (int i = 0; i < m; i++) {
        int cnt_0 = 0, cnt_1 = 0;
        for (auto it = variables.begin(); it != variables.end(); it++) {
            const string& var = it->first;
            const vector<string>& ops = it->second;
            bitset<1000> tmp;
            for (const string& op : ops) {
                tmp |= values[op];
            }
            values[var] = tmp;

            if (values[var].test(i)) {
                cnt_1++;
            } else {
                cnt_0++;
            }
        }

        if (cnt_0 <= cnt_1) {
            min_value.set(i);
        }

        if (cnt_0 >= cnt_1) {
            max_value.set(i);
        }

    }

    cout << min_value.to_string().substr(1000 - m) << endl;
    cout << max_value.to_string().substr(1000 - m) << endl;

    return 0;
}