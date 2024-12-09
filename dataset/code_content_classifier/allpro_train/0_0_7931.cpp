#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void printComments(const vector<string>& comments) {
    int maxDepth = 0;
    vector<vector<string>> nestedComments;

    for (int i = 0; i < comments.size(); i+=2) {
        string comment = comments[i];
        int numOfReplies = stoi(comments[i+1]);
        maxDepth = max(maxDepth, numOfReplies);

        if (nestedComments.size() <= numOfReplies) {
            nestedComments.resize(numOfReplies + 1);
        }

        nestedComments[numOfReplies].push_back(comment);
    }

    cout << maxDepth + 1 << endl;
    for (const vector<string>& level : nestedComments) {
        for (const string& comment : level) {
            cout << comment << " ";
        }
        cout << endl;
    }
}

int main() {
    string input;
    getline(cin, input);

    vector<string> comments;
    stringstream ss(input);
    string token;

    while (getline(ss, token, ',')) {
        comments.push_back(token);
    }

    printComments(comments);

    return 0;
}