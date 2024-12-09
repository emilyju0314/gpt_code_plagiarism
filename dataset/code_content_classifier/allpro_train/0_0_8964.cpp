#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string extractHostname(string address) {
    int start = 7; // Length of "http://"
    int end = address.find('/', start);
    return address.substr(start, end - start);
}

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, vector<string>> websites;
    
    for (int i = 0; i < n; i++) {
        string address;
        cin >> address;
        string hostname = extractHostname(address);
        
        websites[hostname].push_back(address);
    }
    
    vector<vector<string>> groups;
    
    for (auto it = websites.begin(); it != websites.end(); it++) {
        if (it->second.size() > 1) {
            groups.push_back(it->second);
        }
    }
    
    cout << groups.size() << endl;
    for (int i = 0; i < groups.size(); i++) {
        for (int j = 0; j < groups[i].size(); j++) {
            cout << groups[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}