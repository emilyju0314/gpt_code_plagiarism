#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> recipients;
    std::unordered_map<std::string, int> chatOrder;

    for (int i = 0; i < n; i++) {
        std::string recipient;
        std::cin >> recipient;

        if (chatOrder.count(recipient) == 0) {
            recipients.insert(recipients.begin(), recipient);
            chatOrder[recipient] = recipients.size();
        } else {
            int index = chatOrder[recipient] - 1;
            recipients.erase(recipients.begin() + index);
            recipients.insert(recipients.begin(), recipient);
            chatOrder.clear();
            for (int j = 0; j < recipients.size(); j++) {
                chatOrder[recipients[j]] = j + 1;
            }
        }
    }

    for (const auto& recipient : recipients) {
        std::cout << recipient << std::endl;
    }

    return 0;
}