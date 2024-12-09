#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;

// Function to parse the YAML input and create a nested unordered_map representing the object
unordered_map<string, string> parseYAML(vector<string>& input) {
    unordered_map<string, string> yamlObject;
    int indentLevel = -1;
    
    for (string line : input) {
        int i = 0;
        while (line[i] == ' ') {
            i++;
        }
        int currentIndentLevel = i / 2;
        
        string key, value;
        if (line[i] == '.') {
            key = line.substr(i, line.find(':') - i);
            value = line.substr(line.find(':') + 2);
        } else {
            key = line.substr(i, line.find(':') - i);
            value = "object";
        }
        
        if (currentIndentLevel == indentLevel) {
            yamlObject.insert({key, value});
        } else if (currentIndentLevel > indentLevel) {
            vector<string> lines;
            while (i < line.size()) {
                lines.push_back(line);
            }
            yamlObject.insert({key, parseYAML(lines)});
        }
        
        indentLevel = currentIndentLevel;
    }
    
    return yamlObject;
}

// Function to search for a property in the nested unordered_map
string searchProperty(unordered_map<string, string>& yamlObject, string& query) {
    istringstream iss(query);
    string key;
    iss >> key;
    
    int i = 0;
    while (iss >> key) {
        if (yamlObject.find(key) == yamlObject.end()) {
            return "no such property";
        } else if (yamlObject[key] == "object") {
            yamlObject = yamlObject[key];
        } else {
            return "string \"" + yamlObject[key] + "\"";
        }
    }
    
    return yamlObject[key];
}

int main() {
    string query;
    getline(cin, query);
    
    vector<string> input;
    string line;
    while (getline(cin, line)) {
        input.push_back(line);
    }
    
    unordered_map<string, string> yamlObject = parseYAML(input);
    
    string result = searchProperty(yamlObject, query);
    cout << result << endl;
    
    return 0;
}