#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMaxImpostors(int n, int m, vector<vector<int>>& comments) {
    unordered_map<int, int> roles;
    for(auto comment : comments) {
        int i = comment[0];
        int j = comment[1];
        string c = comment[2];

        if(roles.find(i) == roles.end() && roles.find(j) == roles.end()) {
            roles[i] = (c == "imposter") ? 1 : 0;
            roles[j] = roles[i] ^ 1;
        } else if(roles.find(i) == roles.end()) {
            roles[i] = roles[j] ^ (c == "imposter");
        } else if(roles.find(j) == roles.end()) {
            roles[j] = roles[i] ^ (c == "imposter");
        } else {
            if(roles[i] == roles[j] && c == "crewmate")
                return -1;
            if(roles[i] != roles[j] && c == "imposter")
                return -1;
        }
    }

    int impostorCount = 0;
    for(auto role : roles) {
        if(role.second == 1)
            impostorCount++;
    }

    return impostorCount;
}

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> comments;
        for(int i = 0; i < m; i++) {
            int a, b;
            string c;
            cin >> a >> b >> c;

            comments.push_back({a, b, (c == "imposter") ? 1 : 0});
        }

        int result = findMaxImpostors(n, m, comments);
        cout << result << endl;
    }

    return 0;
}