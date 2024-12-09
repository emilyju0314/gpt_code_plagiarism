#include <iostream>
#include <unordered_map>
#include <set>
#include <sstream>
#include <vector>

using namespace std;

unordered_map<string, set<string>> groups;

set<string> getMembers(string groupName) {
    set<string> result;
    for (const auto &member : groups[groupName]) {
        if (groups.find(member) != groups.end()) {
            set<string> subMembers = getMembers(member);
            result.insert(subMembers.begin(), subMembers.end());
        } else {
            result.insert(member);
        }
    }
    return result;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        groups.clear();
        string input;
        getline(cin, input); // Consume newline
        for (int i = 0; i < n; ++i) {
            getline(cin, input);
            istringstream iss(input);
            string groupName;
            getline(iss, groupName, ':');
            string members;
            getline(iss, members, '.');
            stringstream ss(members);
            string member;
            while (getline(ss, member, ',')) {
                groups[groupName].insert(member);
            }
        }
        set<string> firstGroupMembers = getMembers(to_string(1));
        cout << firstGroupMembers.size() << endl;
    }
    return 0;
}