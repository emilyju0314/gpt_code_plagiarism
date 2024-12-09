#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

bool isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

bool isNumberItem(const string& item) {
    for (char c : item) {
        if (!isDigit(c)) {
            return false;
        }
    }
    return true;
}

bool compareFiles(const string& file1, const string& file2) {
    vector<string> items1, items2;
    string item = "";
    for (char c : file1) {
        if (isDigit(c) && !item.empty() && !isNumberItem(item)) {
            items1.push_back(item);
            item = "";
        }
        item += c;
    }
    items1.push_back(item);
    
    item = "";
    for (char c : file2) {
        if (isDigit(c) && !item.empty() && !isNumberItem(item)) {
            items2.push_back(item);
            item = "";
        }
        item += c;
    }
    items2.push_back(item);
    
    for (int i = 0; i < min(items1.size(), items2.size()); i++) {
        if (isDigit(items1[i][0]) && isDigit(items2[i][0])) {
            int num1 = stoi(items1[i]);
            int num2 = stoi(items2[i]);
            if (num1 != num2) {
                return num1 < num2;
            }
        } else {
            if (items1[i] != items2[i]) {
                return items1[i] < items2[i];
            }
        }
    }
    
    return items1.size() < items2.size();
}

int main() {
    int n;
    cin >> n;
    string file0;
    cin >> file0;
    
    for (int i = 0; i < n; i++) {
        string file;
        cin >> file;
        
        if (compareFiles(file0, file)) {
            cout << "-" << endl;
        } else {
            cout << "+" << endl;
        }
    }
    
    return 0;
}