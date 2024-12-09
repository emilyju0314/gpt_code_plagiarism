#include <iostream>
#include <vector>
#include <unordered_map>

const int M = 32768;

struct Matrix {
    int rows, cols;
    std::vector<std::vector<int>> data;
};

std::unordered_map<char, Matrix> variables;

Matrix parseMatrix(std::string matrixStr) {
    matrixStr = matrixStr.substr(1, matrixStr.length() - 2); // Remove enclosing square brackets
    std::vector<int> tempRow;
    std::vector<std::vector<int>> tempMatrix;
    for (char c : matrixStr) {
        if (c == ';') {
            tempMatrix.push_back(tempRow);
            tempRow.clear();
        } else if (c == ' ') {
            continue;
        } else {
            tempRow.push_back(c - '0'); // Convert char to int
        }
    }
    tempMatrix.push_back(tempRow);
    return {tempMatrix.size(), tempMatrix[0].size(), tempMatrix};
}

Matrix eval(std::string expr) {
    if (expr[0] == '[') {
        return parseMatrix(expr);
    } else if (isalpha(expr[0])) {
        return variables[expr[0]];
    }
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::string line;
        std::cin.ignore();

        for (int i = 0; i < n; ++i) {
            getline(std::cin, line);

            char varName = line[0];
            size_t exprStart = line.find('=') + 1;
            size_t exprEnd = line.find_last_of('.');
            std::string expr = line.substr(exprStart, exprEnd - exprStart);

            Matrix result = eval(expr);
            variables[varName] = result;

            // Print result
            for (int r = 0; r < result.rows; ++r) {
                for (int c = 0; c < result.cols; ++c) {
                    std::cout << result.data[r][c];
                    if (c < result.cols - 1) std::cout << " ";
                }
                std::cout << std::endl;
            }
        }

        std::cout << "-----" << std::endl;
    }

    return 0;
}