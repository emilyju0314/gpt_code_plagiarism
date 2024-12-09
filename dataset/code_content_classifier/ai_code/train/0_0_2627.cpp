#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

bool typeMatches(string type, string variableType) {
    if (type == "T") {
        return true;
    } else {
        return type == variableType;
    }
}

int main() {
    int n;
    cin >> n;
    unordered_map<string, vector<string>> procedures;

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin >> ws, line);

        istringstream iss(line);
        string voidKeyword, procedureName, parameter;
        iss >> voidKeyword >> procedureName;

        vector<string> parameterTypes;
        while (iss >> parameter) {
            if (parameter == "(" || parameter == ")") {
                continue;
            }
            if (parameter.back() == ',') {
                parameter.pop_back();
            }
            parameterTypes.push_back(parameter);
        }
        procedures[procedureName] = parameterTypes;
    }

    int m;
    cin >> m;
    unordered_map<string, string> variables;

    for (int i = 0; i < m; i++) {
        string type, variableName;
        cin >> type >> variableName;
        variables[variableName] = type;
    }

    int k;
    cin >> k;

    for (int i = 0; i < k; i++) {
        string line;
        getline(cin >> ws, line);

        istringstream iss(line);
        string procedureName, variable;
        iss >> procedureName;

        vector<string> variableTypes;
        while (iss >> variable) {
            if (variable == "(" || variable == ")") {
                continue;
            }
            if (variable.back() == ',') {
                variable.pop_back();
            }
            variableTypes.push_back(variable);
        }

        int count = 0;
        for (auto it = procedures.begin(); it != procedures.end(); it++) {
            if (it->first == procedureName && it->second.size() == variableTypes.size()) {
                bool match = true;
                for (int j = 0; j < variableTypes.size(); j++) {
                    if (!typeMatches(it->second[j], variables[variableTypes[j]])) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    count++;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}