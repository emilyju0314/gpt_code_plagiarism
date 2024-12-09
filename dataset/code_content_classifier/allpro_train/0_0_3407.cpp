#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// Function to convert IP address to integer
int ipToInteger(const std::string& ip) {
    int result = 0;
    int shift = 24;
    size_t pos = 0;
    for (int i = 0; i < 4; ++i) {
        pos = ip.find('.', pos);
        int num = std::stoi(ip.substr(pos - shift, shift));
        result |= (num << shift);
        shift -= 8;
        ++pos;
    }
    return result;
}

// Function to convert integer to IP address
std::string integerToIp(int ip) {
    return std::to_string((ip >> 24) & 255) + '.' + std::to_string((ip >> 16) & 255) + '.' + 
           std::to_string((ip >> 8) & 255) + '.' + std::to_string(ip & 255);
}

// Function to count the number of ones in subnet mask
int countOnes(int mask) {
    int count = 0;
    while (mask) {
        count += mask & 1;
        mask >>= 1;
    }
    return count;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> ips;
    std::unordered_set<int> networks;

    for (int i = 0; i < n; ++i) {
        std::string ip;
        std::cin >> ip;
        ips.push_back(ipToInteger(ip));
    }

    for (int mask = 0; mask <= 32767; ++mask) {
        if (countOnes(mask) > 16) continue;

        networks.clear();
        for (int ip : ips) {
            int network = ip & mask;
            networks.insert(network);
        }

        if (networks.size() == k) {
            std::cout << integerToIp(mask) << "\n";
            return 0;
        }
    }

    std::cout << "-1\n";

    return 0;
}