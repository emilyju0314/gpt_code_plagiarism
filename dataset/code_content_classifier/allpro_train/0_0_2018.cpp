#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int n;
    std::string ticket;
    std::cin >> n >> ticket;

    std::sort(ticket.begin(), ticket.begin() + n);
    std::sort(ticket.begin() + n, ticket.end());

    bool less = true;
    bool greater = true;

    for (int i = 0; i < n; i++) {
        if (ticket[i] >= ticket[i+n]) {
            less = false;
        }
        if (ticket[i] <= ticket[i+n]) {
            greater = false;
        }
    }

    if (less || greater) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}