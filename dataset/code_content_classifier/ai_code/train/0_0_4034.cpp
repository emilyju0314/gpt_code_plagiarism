#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> usernames(n);
        unordered_map<string, string> messageSenders;
        unordered_map<string, bool> messageHasSender;

        for (int j = 0; j < n; j++) {
            cin >> usernames[j];
        }

        int m;
        cin >> m;

        bool possible = true;
        string prevSender = "";

        for (int j = 0; j < m; j++) {
            string message;
            string sender;
            string text;

            cin >> message;

            if (message[0] == '?') {
                bool foundSender = false;
                for (const auto& username : usernames) {
                    if (message.find(username) != string::npos) {
                        if (prevSender != username) {
                            sender = username;
                            foundSender = true;
                            break;
                        }
                    }
                }

                if (!foundSender) {
                    possible = false;
                    break;
                }
            } else {
                sender = message.substr(0, message.find(':'));
            }

            text = message.substr(message.find(':') + 1);

            if (prevSender == sender) {
                possible = false;
                break;
            }

            messageSenders[text] = sender;
            messageHasSender[text] = true;

            prevSender = sender;
        }

        if (!possible) {
            cout << "Impossible" << endl;
        } else {
            for (int j = 0; j < m; j++) {
                string text = messageSenders.find(to_string(j))->second;
                cout << text << ": " << messageSenders[text] << endl;
            }
        }
    }

    return 0;
}