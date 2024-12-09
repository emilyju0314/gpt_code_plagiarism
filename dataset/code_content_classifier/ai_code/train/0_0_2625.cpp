#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    unordered_map<string, string> last_message;
    vector<pair<string, string>> friends;

    for (int i = 0; i < n; i++) {
        string sender, receiver;
        int time;
        cin >> sender >> receiver >> time;

        if (last_message.find(receiver) != last_message.end() && last_message[receiver] == sender) {
            friends.push_back({receiver, sender});
            last_message.erase(receiver);
        } else {
            last_message[sender] = receiver;
        }
    }

    cout << friends.size() << endl;
    for (auto pair : friends) {
        cout << pair.first << " " << pair.second << endl;
    }

    return 0;
}