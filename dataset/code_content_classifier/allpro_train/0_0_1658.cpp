#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> messages(n);
    for(int i = 0; i < n; i++) {
        std::cin >> messages[i];
    }

    std::unordered_set<int> displayedConversations;
    std::vector<int> order;

    for(int i = 0; i < n; i++) {
        if(displayedConversations.find(messages[i]) != displayedConversations.end()) {
            continue;
        }

        if(displayedConversations.size() == k) {
            displayedConversations.erase(order.back());
            order.pop_back();
        }

        displayedConversations.insert(messages[i]);
        order.insert(order.begin(), messages[i]);
    }

    std::cout << order.size() << std::endl;
    for(int id : order) {
        std::cout << id << " ";
    }
    std::cout << std::endl;

    return 0;
}