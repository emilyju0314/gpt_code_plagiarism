#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        int imposters = 0;
        unordered_map<int, bool> role; // true for crewmate, false for imposter
        bool contradiction = false;

        vector<pair<int, int>> comments;
        vector<pair<int, int>> crewmateComments;

        for(int i = 0; i < m; i++) {
            int a, b;
            string c;
            cin >> a >> b >> c;
            if(c == "imposter") {
                imposters++;
                if(role.find(a) == role.end()) {
                    role[a] = false; // imposter
                }
                if(role.find(b) == role.end()) {
                    role[b] = false; // imposter
                }
            } else {
                crewmateComments.push_back({a, b});
            }
            comments.push_back({a, b});
        }

        for(auto comment : crewmateComments) {
            if(role.find(comment.first) == role.end()) {
                role[comment.first] = true; // crewmate
            }
            if(role.find(comment.second) == role.end()) {
                role[comment.second] = true; // crewmate
            }
        }

        for(auto comment : comments) {
            if(role[comment.first] == false && role[comment.second] == true) {
                contradiction = true;
                break;
            }
        }

        if(contradiction) {
            cout << "-1\n";
        } else {
            cout << imposters << "\n";
        }
    }

    return 0;
}