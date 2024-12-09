#include <iostream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

int main() {
    string path;
    map<string, pair<int, int>> folder; // folder name -> (num subfolders, num files)

    while (getline(cin, path)) {
        istringstream iss(path);
        string token;
        vector<string> tokens;

        while (getline(iss, token, '\\')) {
            tokens.push_back(token);
        }

        string folderName = "";
        int numSubfolders = 0;
        int numFiles = 0;

        for (int i = 1; i < tokens.size() - 1; i++) {
            folderName += tokens[i];
            if (folder.find(folderName) == folder.end()) {
                folder[folderName] = {0, 0};
                numSubfolders++;
            }
            folderName += "\\";
        }

        folderName += tokens.back();
        folder[folderName].second++;
        numFiles++;

        for (int i = 1; i < tokens.size() - 1; i++) {
            folderName.erase(folderName.end() - tokens[i].length() - 1, folderName.end());
            folder[folderName].first = max(folder[folderName].first, numSubfolders);
            folder[folderName].second = max(folder[folderName].second, numFiles);
        }
    }

    int maxSubfolders = 0;
    int maxFiles = 0;
    
    for (auto it = folder.begin(); it != folder.end(); it++) {
        maxSubfolders = max(maxSubfolders, it->second.first);
        maxFiles = max(maxFiles, it->second.second);
    }

    cout << maxSubfolders << " " << maxFiles << endl;

    return 0;
}