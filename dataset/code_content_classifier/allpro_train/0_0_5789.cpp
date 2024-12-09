#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> atomicWeights;

    // Input Atomic Table
    string symbol;
    int weight;
    while (cin >> symbol >> weight) {
        if (symbol == "END_OF_FIRST_PART") break;
        atomicWeights[symbol] = weight;
    }

    string formula;
    while (cin >> formula) {
        if (formula == "0") break;

        int parentheses = 0;
        int prevWeight = 0;
        int totalWeight = 0;

        for (int i = 0; i < formula.size(); i++) {
            if (formula[i] == '(') {
                parentheses++;
            } else if (isdigit(formula[i])) {
                prevWeight *= (formula[i] - '0');
            } else if (isupper(formula[i])) {
                string symbol = "";
                symbol += formula[i];
                if (islower(formula[i + 1])) {
                    symbol += formula[i + 1];
                    i++;
                }

                int atomWeight = atomicWeights[symbol];
                totalWeight += prevWeight * atomWeight;
                prevWeight = 1;
            } else if (formula[i] == ')') {
                parentheses--;
                if (parentheses == 0) {
                    if (i + 1 < formula.size() && isdigit(formula[i + 1])) {
                        prevWeight *= (formula[i + 1] - '0');
                    }
                }
            }
        }

        if (totalWeight == 0) {
            cout << "UNKNOWN" << endl;
        } else {
            cout << totalWeight << endl;
        }
    }

    return 0;
}