#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string applyReplacements(string name) {
    while (true) {
        bool replaced = false;
        for (int i = 0; i < name.size(); i++) {
            if (name[i] == 'u' && i < name.size() - 1 && name[i+1] == 'o') {
                name = name.substr(0, i) + 'o' + name.substr(i+2);
                replaced = true;
            } else if (name[i] == 'h' && i < name.size() - 1 && name[i+1] == 'k') {
                name = name.substr(0, i) + 'k' + name.substr(i+2);
                replaced = true;
            }
        }
        if (!replaced) break;
    }
    return name;
}

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    unordered_map<string, int> groups;
    int groupCounter = 1;

    for (int i = 0; i < n; i++) {
        cin >> names[i];
        string modifiedName = applyReplacements(names[i]);
        if (groups.find(modifiedName) == groups.end()) {
            groups[modifiedName] = groupCounter;
            groupCounter++;
        }
    }

    cout << groups.size() << endl;

    return 0;
}