#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<char, int>> messages;
    std::unordered_map<int, int> loggedIn;

    for (int i = 0; i < m; i++) {
        char sign;
        int id;
        std::cin >> sign >> id;

        messages.push_back({sign, id});
        if (sign == '+') {
            if (loggedIn.find(id) == loggedIn.end()) {
                loggedIn[id] = i;
            }
        } else {
            if (loggedIn.find(id) != loggedIn.end()) {
                loggedIn.erase(id);
            }
        }
    }

    std::set<int> possibleLeaders;

    for (auto& msg : messages) {
        if (msg.first == '+') {
            if (possibleLeaders.empty() || possibleLeaders.count(msg.second) || possibleLeaders.size() == 1) {
                possibleLeaders.clear();
                for (auto& entry : loggedIn) {
                    if (entry.first != msg.second) {
                        possibleLeaders.insert(entry.first);
                    }
                }
            }
        } else {
            if (possibleLeaders.empty() || possibleLeaders.count(msg.second) || possibleLeaders.size() == 1) {
                possibleLeaders.clear();
                for (auto& entry : loggedIn) {
                    possibleLeaders.insert(entry.first);
                }
            }
        }
    }

    std::cout << possibleLeaders.size() << std::endl;
    for (auto& leader : possibleLeaders) {
        std::cout << leader << " ";
    }

    return 0;
}