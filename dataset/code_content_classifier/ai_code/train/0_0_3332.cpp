#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

const int MOD = 1e9 + 7;

char variables[4] = {'A', 'B', 'C', 'D'};
char neg_variables[4] = {'a', 'b', 'c', 'd'};

bool evaluate(bool a, char op, bool b) {
    if(op == '&') {
        return a & b;
    }
    else {
        return a | b;
    }
}

int main() {
    std::string expression;
    std::cin >> expression;

    int n;
    std::cin >> n;

    std::unordered_map<std::string, bool> truth_values;
    std::string variable_set;
    for(int i = 0; i < n; i++) {
        std::cin >> variable_set;
        for(int j = 0; j < 4; j++) {
            truth_values[variables[j]] = variable_set[j] == '1';
            truth_values[neg_variables[j]] = variable_set[j] == '0';
        }

        bool result = variable_set[4] == '1';

        for(auto& c : expression) {
            if(c == '?' || c == '&' || c == '|') continue;
            c = truth_values[c] ? '1' : '0';
        }

        std::vector<std::vector<bool>> dp(expression.size(), std::vector<bool>(expression.size(), false));
        for(int i = 0; i < dp.size(); i += 2) {
            dp[i][i] = expression[i] == '1';
        }

        for(int len = 3; len <= dp.size(); len += 2) {
            for(int i = 0; i + len - 1 < dp.size(); i += 2) {
                int j = i + len - 1;
                for(int k = i + 1; k < j; k += 2) {
                    if(expression[k] == '&') {
                        dp[i][j] = dp[i][j] | (dp[i][k-1] & dp[k+1][j]);
                    }
                    else {
                        dp[i][j] = dp[i][j] | (dp[i][k-1] | dp[k+1][j]);
                    }
                }
            }
        }

        if(dp[0][dp.size() - 1] != result) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    int count = 0;
    for(auto& c : expression) {
        if(c == '?' || c == '&' || c == '|') {
            count++;
        }
    }

    std::cout << std::pow(2, count) % MOD << std::endl;

    return 0;
}