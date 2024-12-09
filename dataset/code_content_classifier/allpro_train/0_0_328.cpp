#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(vector<string>& currConfig) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (currConfig[i][j] == currConfig[i+1][j] || currConfig[i][j] == currConfig[i][j+1]) {
                return false;
            }
        }
    }
    return true;
}

void generateConfigurations(vector<string>& boards, vector<string>& currConfig, vector<bool>& used, int& count) {
    if (currConfig.size() == 4) {
        if (isValid(currConfig)) {
            count++;
        }
        return;
    }

    for (int i = 0; i < boards.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            currConfig.push_back(boards[i]);
            generateConfigurations(boards, currConfig, used, count);
            currConfig.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    string board;
    while (getline(cin, board) && board != "END") {
        vector<string> boards;
        istringstream iss(board);
        string token;
        while (iss >> token) {
            boards.push_back(token);
        }

        vector<string> currConfig;
        vector<bool> used(boards.size(), false);
        int count = 0;
        generateConfigurations(boards, currConfig, used, count);

        cout << count << endl;
    }

    return 0;
}