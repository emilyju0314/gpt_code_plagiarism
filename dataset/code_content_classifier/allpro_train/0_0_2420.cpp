#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> parse_molecule(string& molecule) {
    map<string, int> elements;
    string current_element;
    int current_count = 0;

    for (char c : molecule) {
        if (isupper(c)) {
            if (!current_element.empty()) {
                if (current_count == 0) {
                    current_count = 1;
                }
                elements[current_element] += current_count;
                current_element.clear();
                current_count = 0;
            }
            current_element += c;
        } else if (islower(c)) {
            current_element += c;
        } else if (isdigit(c)) {
            current_count = current_count * 10 + (c - '0');
        } else if (c == '(') {
            if (!current_element.empty()) {
                if (current_count == 0) {
                    current_count = 1;
                }
                elements[current_element] += current_count;
                current_element.clear();
                current_count = 0;
            }
            elements[current_element] += 1; // default to 1 if no count is specified
            current_element.clear();
        } else if (c == ')') {
            if (current_count == 0) {
                current_count = 1;
            }
            current_element.clear();
        }
    }

    if (!current_element.empty()) {
        if (current_count == 0) {
            current_count = 1;
        }
        elements[current_element] += current_count;
    }

    return elements;
}

int main() {
    string equation;
    while (true) {
        getline(cin, equation);
        if (equation == ".") {
            break;
        }

        string lhs = equation.substr(0, equation.find("->"));
        string rhs = equation.substr(equation.find("->") + 2);

        map<string, int> lhs_elements = parse_molecule(lhs);
        map<string, int> rhs_elements = parse_molecule(rhs);

        int gcd = 0;
        for (auto& element : lhs_elements) {
            if (rhs_elements.find(element.first) != rhs_elements.end()) {
                int ratio = rhs_elements[element.first] / element.second;
                if (gcd == 0) {
                    gcd = ratio;
                } else {
                    gcd = __gcd(gcd, ratio);
                }
            }
        }

        vector<int> coefficients;
        for (auto& element : lhs_elements) {
            coefficients.push_back(rhs_elements[element.first] / element.second / gcd);
        }

        for (int coeff : coefficients) {
            cout << coeff << " ";
        }
        cout << endl;
    }

    return 0;
}