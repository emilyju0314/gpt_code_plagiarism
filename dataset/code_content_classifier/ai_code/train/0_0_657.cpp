#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> files(n);

    for(int i = 0; i < n; i++) {
        string name;
        int type;
        cin >> name >> type;
        files[i] = make_pair(name, type);
    }

    sort(files.begin(), files.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        if(a.second != b.second) {
            return a.second > b.second;
        } else {
            return a.first < b.first;
        }
    });

    vector<string> script;
    int example_count = 0;
    int regular_count = 0;

    for(int i = 0; i < n; i++) {
        if(files[i].second == 1) {
            script.push_back("move " + files[i].first + " " + to_string(++example_count));
        } else {
            script.push_back("move " + files[i].first + " " + to_string(++regular_count));
        }
    }

    cout << script.size() << endl;
    for(string move : script) {
        cout << move << endl;
    }

    return 0;
}