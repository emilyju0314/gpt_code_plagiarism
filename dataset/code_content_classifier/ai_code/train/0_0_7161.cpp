#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<pair<string, string>> first_layer(m);
    for (int i = 0; i < m; i++) {
        cin >> first_layer[i].first >> first_layer[i].second;
    }

    vector<pair<string, string>> second_layer(k);
    for (int i = 0; i < k; i++) {
        cin >> second_layer[i].first >> second_layer[i].second;
    }

    int result = -1;
    for (int i = 0; i < (1 << k); i++) {
        vector<int> removed_gates;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                removed_gates.push_back(j);
            }
        }

        bool love = false;
        for (int j = 0; j < (1 << n); j++) {
            bool first_layer_output[m];
            for (int a = 0; a < m; a++) {
                int input1 = first_layer[a].second[0] == 'x' ? j & 1 : (j >> 1) & 1;
                int input2 = first_layer[a].second[1] == 'x' ? j & 1 : (j >> 1) & 1;

                if (first_layer[a].first == "and") {
                    first_layer_output[a] = input1 & input2;
                } else if (first_layer[a].first == "or") {
                    first_layer_output[a] = input1 | input2;
                } else if (first_layer[a].first == "nand") {
                    first_layer_output[a] = !(input1 & input2);
                } else if (first_layer[a].first == "nor") {
                    first_layer_output[a] = !(input1 | input2);
                }
            }

            bool second_layer_output[k];
            for (int a = 0; a < k; a++) {
                int input1 = first_layer_output[second_layer[a].second[0] - 'a'];
                int input2 = first_layer_output[second_layer[a].second[1] - 'a'];

                if (second_layer[a].first == "and") {
                    second_layer_output[a] = input1 & input2;
                } else if (second_layer[a].first == "or") {
                    second_layer_output[a] = input1 | input2;
                } else if (second_layer[a].first == "nand") {
                    second_layer_output[a] = !(input1 & input2);
                } else if (second_layer[a].first == "nor") {
                    second_layer_output[a] = !(input1 | input2);
                }
            }

            bool third_layer_output = false;
            for (int a = 0; a < k; a++) {
                third_layer_output |= second_layer_output[a];
            }

            if (third_layer_output == (love ? 0 : 1)) {
                love = !love;
            }
        }

        bool all_same = true;
        for (int a = 0; a < k; a++) {
            if (find(removed_gates.begin(), removed_gates.end(), a) == removed_gates.end()) {
                all_same = false;
                break;
            }
        }

        if (all_same) {
            result = max(result, (int)removed_gates.size());
        }
    }

    cout << result << endl;

    return 0;
}