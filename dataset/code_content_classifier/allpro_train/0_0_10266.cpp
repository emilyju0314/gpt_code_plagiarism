#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    string name;
    cin >> name;

    unordered_map<char, char> designChanges;
    for (int i = 0; i < m; i++) {
        char xi, yi;
        cin >> xi >> yi;
        designChanges[xi] = yi;
        designChanges[yi] = xi;
    }

    for (int i = 0; i < n; i++) {
        if (designChanges.find(name[i]) != designChanges.end()) {
            name[i] = designChanges[name[i]];
        }
    }

    cout << name << endl;

    return 0;
}