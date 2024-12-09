#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<int> possible_lines;

    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;

        vector<int> lines(r);

        for (int j = 0; j < r; j++) {
            cin >> lines[j];
        }

        if (i == 0) {
            for (int line : lines) {
                possible_lines.insert(line);
            }
        } else {
            set<int> current_lines;
            for (int line : lines) {
                current_lines.insert(line);
            }

            vector<int> lines_to_erase;

            for (int line : possible_lines) {
                if (current_lines.find(line) == current_lines.end()) {
                    lines_to_erase.push_back(line);
                }
            }

            for (int line : lines_to_erase) {
                possible_lines.erase(line);
            }
        }
    }

    for (int line : possible_lines) {
        cout << line << " ";
    }

    return 0;
}