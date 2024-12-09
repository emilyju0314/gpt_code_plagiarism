#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct File {
    string name;
    int type;
};

bool comp(File a, File b) {
    return a.type < b.type;
}

int main() {
    int n;
    cin >> n;

    vector<File> files(n);
    for (int i = 0; i < n; i++) {
        cin >> files[i].name >> files[i].type;
    }

    sort(files.begin(), files.end(), comp);

    int exampleCount = 0, regularCount = 0;
    vector<string> script;

    for (int i = 0; i < n; i++) {
        if (files[i].type == 1) {
            exampleCount++;
            script.push_back("move " + files[i].name + " " + to_string(exampleCount));
        } else {
            regularCount++;
            script.push_back("move " + files[i].name + " " + to_string(exampleCount + regularCount));
        }
    }

    cout << script.size() << endl;
    for (string line : script) {
        cout << line << endl;
    }

    return 0;
}