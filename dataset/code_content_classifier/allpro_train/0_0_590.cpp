#include <iostream>
#include <vector>

using namespace std;

int main() {
    int p, s;
    while (cin >> p >> s) {
        if (p == 0 && s == 0) {
            break;
        }

        vector<vector<string>> table(p + 1, vector<string>(s + 1));
        vector<int> row_totals(p, 0);
        vector<int> col_totals(s, 0);

        // Read input table
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < s + 1; j++) {
                cin >> table[i][j];
                if (table[i][j] != "?") {
                    row_totals[i] += stoi(table[i][j]);
                    col_totals[j] += stoi(table[i][j]);
                }
            }
        }

        // Read totals row
        for (int j = 0; j < s + 1; j++) {
            cin >> table[p][j];
            col_totals[j] = stoi(table[p][j]);
        }

        // Find missing values
        bool unique_solution = true;
        for (int i = 0; i < p; i++) {
            bool found_question_mark = false;
            for (int j = 0; j < s + 1; j++) {
                if (table[i][j] == "?") {
                    if (found_question_mark) {
                        unique_solution = false;
                        break;
                    }
                    int missing_value = row_totals[i] - stoi(table[i][s]);
                    table[i][j] = to_string(missing_value);
                    col_totals[j] += missing_value;
                    found_question_mark = true;
                }
            }
        }

        if (unique_solution) {
            for (int i = 0; i < p; i++) {
                for (int j = 0; j < s; j++) {
                    cout << table[i][j] << endl;
                }
            }
        } else {
            cout << "NO" << endl;
        }
        
        cout << endl;
    }

    return 0;
}