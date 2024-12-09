#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> chatParticipants;
    int totalTraffic = 0;

    string line;
    while (getline(cin, line)) {
        if (line[0] == '+') {
            chatParticipants.push_back(line.substr(1));
        } else if (line[0] == '-') {
            string name = line.substr(1);
            int idx = find(chatParticipants.begin(), chatParticipants.end(), name) - chatParticipants.begin();
            if (idx != chatParticipants.size()) {
                chatParticipants.erase(chatParticipants.begin() + idx);
            }
        } else {
            string sender;
            string message = line.substr(line.find(':') + 1);
            for (const string& participant : chatParticipants) {
                totalTraffic += message.size();
            }
        }
    }

    cout << totalTraffic << endl;

    return 0;
}