#include <iostream>
#include <vector>
#include <string>

std::vector<int> computeZFunction(const std::string& s) {
    int n = s.size();
    std::vector<int> z(n, 0);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            z[i] = std::min(r - i + 1, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    std::string s;
    std::cin >> s;

    std::vector<int> z = computeZFunction(s);

    int q;
    std::cin >> q;

    for(int i = 0; i < q; i++) {
        int l, r;
        std::cin >> l >> r;
        int answer = 0;
        for(int j = l - 1; j < r - 1; j++) {
            answer += z[j];
        }
        std::cout << answer << std::endl;
    }

    return 0;
}