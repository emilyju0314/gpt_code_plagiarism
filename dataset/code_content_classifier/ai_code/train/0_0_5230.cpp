#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPossible(const string& target, const vector<int>& numbers) {
    if (target.empty()) {
        return true;
    }

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i != j) {
                string concat_num = to_string(numbers[i]) + to_string(numbers[j]);
                if (concat_num == target.substr(0, concat_num.size())) {
                    vector<int> new_numbers;
                    for (int k = 0; k < numbers.size(); k++) {
                        if (k != i && k != j) {
                            new_numbers.push_back(numbers[k]);
                        }
                    }
                    new_numbers.push_back(stoi(concat_num));

                    if (isPossible(target.substr(concat_num.size()), new_numbers)) {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    string p;
    cin >> p;

    int max_elements = 1;
    for (int len = 2; len <= p.size(); len++) {
        vector<int> numbers;
        for (int i = 0; i < len; i++) {
            numbers.push_back(stoi(p.substr(i, 1)));
        }

        if (isPossible(p.substr(len), numbers)) {
            max_elements = len;
        }
    }

    cout << max_elements << endl;

    return 0;
}