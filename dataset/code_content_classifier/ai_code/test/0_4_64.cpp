#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    std::string s;
    int x;
    std::cin >> s >> x;

    std::unordered_map<long long, int> pos;
    long long cur = 0;
    long long power = 1;

    for (int i = 0; i < s.length() - 1; i++) {
        cur = cur * 10 + (s[i] - '0');
        pos[cur] = i;
        power = power * 10;
        cur = cur % (power / 10);
    }

    cur = 0;
    power = 1;

    for (int i = s.length() - 1; i > 0; i--) {
        cur = (s[i] - '0') * power + cur;
        if (pos.find(x - cur) != pos.end() && pos[x - cur] < i - 1) {
            std::cout << pos[x - cur] + 1 << " " << i << "\n";
            std::cout << i + 1 << " " << s.length() << "\n";
            break;
        }
        power = power * 10;
    }

    return 0;
}