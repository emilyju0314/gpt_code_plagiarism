#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool isSubstring(string s1, string s2) {
    size_t found = s2.find(s1);
    if (found != string::npos) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> greetings(n);
    for (int i = 0; i < n; i++) {
        cin >> greetings[i];
    }

    vector<int> result;
    unordered_set<int> chosen;

    for (int i = 0; i < n; i++) {
        bool isStylish = true;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                if (isSubstring(greetings[i], greetings[j])) {
                    isStylish = false;
                    break;
                }
            }
        }
        if (isStylish) {
            result.push_back(i + 1);
        }
    }

    cout << result.size() << endl;
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}