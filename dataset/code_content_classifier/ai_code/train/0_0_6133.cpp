#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <stack>

// Function to tokenize the input string
std::vector<std::string> tokenize(const std::string& str) {
    std::vector<std::string> tokens;
    std::istringstream iss(str);
    std::string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

// Function to evaluate the formula using stack
std::string evaluateFormula(const std::vector<std::string>& tokens, const std::map<std::string, std::vector<int>>& variableDimensions) {
    std::stack<std::vector<int>> stack;
    
    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2) {
                return "error";
            }
            std::vector<int> b = stack.top();
            stack.pop();
            std::vector<int> a = stack.top();
            stack.pop();
            std::vector<int> result;
            if (token == "+") {
                if (a.size() != b.size()) return "error";
                for (size_t i = 0; i < a.size(); i++) {
                    result.push_back(a[i] + b[i]);
                }
            } else if (token == "-") {
                if (a.size() != b.size()) return "error";
                for (size_t i = 0; i < a.size(); i++) {
                    result.push_back(a[i] - b[i]);
                }
            } else if (token == "*") {
                if (a.size() != b.size()) return "error";
                for (size_t i = 0; i < a.size(); i++) {
                    result.push_back(a[i] * b[i]);
                }
            } else if (token == "/") {
                if (a.size() != b.size()) return "error";
                for (size_t i = 0; i < a.size(); i++) {
                    result.push_back(a[i] / b[i]);
                }
            }
            stack.push(result);
        } else {
            if (variableDimensions.find(token) == variableDimensions.end()) {
                return "undefined";
            }
            stack.push(variableDimensions.at(token));
        }
    }
    
    if (stack.size() != 1) {
        return "error";
    }
    
    std::vector<int> finalDimension = stack.top();
    for (const auto& assembly : variableDimensions) {
        if (assembly.second == finalDimension) {
            return assembly.first;
        }
    }
    
    return "undefined";
}

int main() {
    int n, m, p;
    while (std::cin >> n >> m >> p) {
        if (n == 0 && m == 0 && p == 0) break;
        
        std::map<std::string, std::vector<int>> variableDimensions;
        for (int i = 0; i < m; i++) {
            std::string assemblyName;
            std::cin >> assemblyName;
            std::vector<int> dimensions(n);
            for (int j = 0; j < n; j++) {
                std::cin >> dimensions[j];
            }
            variableDimensions[assemblyName] = dimensions;
        }
        
        std::string formula;
        std::cin >> formula;
        
        std::vector<std::string> tokens = tokenize(formula);
        
        for (int i = 0; i < p; i++) {
            std::string variableName, dimensionName;
            std::cin >> variableName >> dimensionName;
            std::vector<int> dimensionValues(n);
            for (int j = 0; j < n; j++) {
                std::cin >> dimensionValues[j];
            }
            variableDimensions[variableName] = dimensionValues;
        }
        
        std::string result = evaluateFormula(tokens, variableDimensions);
        std::cout << result << std::endl;
    }
    
    return 0;
}