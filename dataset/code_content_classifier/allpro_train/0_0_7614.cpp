#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int MOD = 1000000007;

unordered_map<string, vector<string>> rules;
unordered_map<string, int> countA, countT, countG, countC;

string expand(string rule) {
    string result = "";
    if (rule[0] == '[') {
        result = rule.substr(1, 1);
    } else if (rules.find(rule) != rules.end()) {
        vector<string> options = rules[rule];
        for (const string& option : options) {
            result += expand(option);
        }
    }
    return result;
}

int main() {
    int Na, Nt, Ng, Nc;
    cin >> Na >> Nt >> Ng >> Nc;

    int m;
    cin >> m;

    string nonterminal, rule;
    for (int i = 0; i < m; i++) {
        cin >> nonterminal;
        cin.ignore(); // Ignore the ':'
        
        getline(cin, rule);
        string delimiter = " ";
        size_t pos = 0;
        
        string symbol;
        vector<string> symbols;
        while ((pos = rule.find(delimiter)) != string::npos) {
            symbol = rule.substr(0, pos);
            symbols.push_back(symbol);
            rule.erase(0, pos + delimiter.length());
        }
        symbols.push_back(rule);
        
        rules[nonterminal] = symbols;
    }

    countA["A"] = 1;
    countT["T"] = 1;
    countG["G"] = 1;
    countC["C"] = 1;

    for (int i = 0; i < Na; i++) {
        unordered_map<string, int> newCountA;
        for (const auto& pair : countA) {
            string rule = pair.first;
            int count = pair.second;
            string expanded = expand(rule);
            for (char c : expanded) {
                newCountA[string(1, c)] += count;
            }
        }
        countA = newCountA;
    }

    for (int i = 0; i < Nt; i++) {
        unordered_map<string, int> newCountT;
        for (const auto& pair : countT) {
            string rule = pair.first;
            int count = pair.second;
            string expanded = expand(rule);
            for (char c : expanded) {
                newCountT[string(1, c)] += count;
            }
        }
        countT = newCountT;
    }

    for (int i = 0; i < Ng; i++) {
        unordered_map<string, int> newCountG;
        for (const auto& pair : countG) {
            string rule = pair.first;
            int count = pair.second;
            string expanded = expand(rule);
            for (char c : expanded) {
                newCountG[string(1, c)] += count;
            }
        }
        countG = newCountG;
    }

    for (int i = 0; i < Nc; i++) {
        unordered_map<string, int> newCountC;
        for (const auto& pair : countC) {
            string rule = pair.first;
            int count = pair.second;
            string expanded = expand(rule);
            for (char c : expanded) {
                newCountC[string(1, c)] += count;
            }
        }
        countC = newCountC;
    }

    int totalGenes = 0;
    for (const auto& pairA : countA) {
        for (const auto& pairT : countT) {
            for (const auto& pairG : countG) {
                for (const auto& pairC : countC) {
                    totalGenes += pairA.second * pairT.second * pairG.second * pairC.second;
                    totalGenes %= MOD;
                }
            }
        }
    }

    cout << totalGenes << endl;

    return 0;
}