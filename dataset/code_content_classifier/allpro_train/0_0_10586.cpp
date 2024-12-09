#include <iostream>
#include <string>
#include <algorithm>

int main() {
    std::string guest, host, letters;
    std::cin >> guest >> host >> letters;

    std::sort(guest.begin(), guest.end());
    std::sort(host.begin(), host.end());
    std::sort(letters.begin(), letters.end());

    std::string combined = guest + host;

    std::sort(combined.begin(), combined.end());

    if (combined == letters) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}