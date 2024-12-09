#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

bool hasCycle(map<string, set<string>>& adjList, string curr, set<string>& visited, vector<string>& path) {
    visited.insert(curr);
    path.push_back(curr);
    
    for (string neighbor : adjList[curr]) {
        if (visited.find(neighbor) != visited.end()) {
            int start = path.size();
            while (path[start] != neighbor) start--;
            for (int i = start; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << neighbor << endl;
            return true;
        } else if (hasCycle(adjList, neighbor, visited, path)) {
            return true;
        }
    }
    
    path.pop_back();
    return false;
}

int main() {
    string s1, s2;
    int n, m;
    
    cin >> s1 >> s2 >> n;
    
    map<string, set<string>> adjList;
    
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> m;
        adjList[s1].insert(s2);
    }
    
    set<string> visited;
    vector<string> path;
    
    if (hasCycle(adjList, s1, visited, path)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}