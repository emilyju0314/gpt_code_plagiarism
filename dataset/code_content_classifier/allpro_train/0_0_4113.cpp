#include <iostream>
#include <vector>
#include <algorithm>

bool is_satisfiable(int n, int m, std::vector<std::vector<int>>& clauses) {
    std::vector<int> variables(m);
    std::fill(variables.begin(), variables.end(), -1);

    for (int i = 0; i < n; i++) {
        bool satisfied = false;
        for (int j = 0; j < clauses[i].size(); j++) {
            int literal = clauses[i][j];
            if (literal > 0) {
                if (variables[literal - 1] != 0) {
                    satisfied = true;
                    break;
                }
            } else {
                if (variables[-literal - 1] != 1) {
                    satisfied = true;
                    break;
                }
            }
        }
        if (!satisfied) {
            return false;
        }
    }

    return true;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> clauses(n);

    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++) {
            int literal;
            std::cin >> literal;
            clauses[i].push_back(literal);
        }
    }

    if (is_satisfiable(n, m, clauses)) {
        std::cout << "YES" << std::endl;
        for (int i = 0; i < m; i++) {
            if (i > 0) {
                std::cout << variables[i];
            }
        }
        std::cout << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}