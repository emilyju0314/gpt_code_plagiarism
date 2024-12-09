#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    string ans = "";
    unordered_map<int, char> vertexToCharacter;
    for (int i = 0; i < n; i++) {
        vector<char> possibleCharacters{'a', 'b', 'c'};
        for (int neighbor : adjList[i]) {
            if (vertexToCharacter.find(neighbor) != vertexToCharacter.end()) {
                possibleCharacters.erase(remove(possibleCharacters.begin(), possibleCharacters.end(), vertexToCharacter[neighbor]), possibleCharacters.end());
            }
        }
        if (possibleCharacters.size() != 1) {
            cout << "No" << endl;
            return 0;
        } else {
            vertexToCharacter[i] = possibleCharacters[0];
            ans += possibleCharacters[0];
        }
    }

    cout << "Yes" << endl;
    cout << ans << endl;

    return 0;
}