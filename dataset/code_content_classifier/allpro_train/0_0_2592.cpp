#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        if (n == 0) {
            break;
        }
        
        map<string, string> variable_map;
        int current_scope = 0;
        vector<int> scope_lengths(1, 0);

        for (int i = 0; i < n; i++) {
            getline(cin, line);
            int length = line.size();
            for (char &c : line) {
                if (c >= 'a' && c <= 'z') {
                    string var_name = "";
                    while (c >= 'a' && c <= 'z') {
                        var_name += c;
                        c = getchar();
                    }
                    if (variable_map.find(var_name) == variable_map.end()) {
                        variable_map[var_name] = to_string(current_scope + 1) + var_name;
                    }
                    length -= var_name.size() - 1;
                }
            }
            if (line.find("{") != string::npos) {
                current_scope++;
                scope_lengths.push_back(0);
            } else if (line.find("}") != string::npos) {
                current_scope--;
            }
            scope_lengths[current_scope] += length;
        }

        int min_length = 0;
        for (int len : scope_lengths) {
            min_length += len;
        }

        cout << min_length << endl;
    }

    return 0;
}