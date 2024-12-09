#include <iostream>
#include <string>
#include <vector>
#include <map>

int main() {
    std::string t, p;
    std::cin >> t >> p;

    std::vector<int> a(t.size());
    for (int i = 0; i < t.size(); i++) {
        std::cin >> a[i];
    }

    std::map<char, int> t_freq, p_freq;
    for (char c : t) {
        t_freq[c]++;
    }
    for (char c : p) {
        p_freq[c]++;
    }

    int removed = 0;
    int j = 0;
    for (int i = 0; i < t.size(); i++) {
        if (j >= p.size()) {
            break;
        }
        if (t[a[i]-1] == p[j]) {
            j++;
            removed++;
        }
    }

    std::cout << removed << std::endl;

    return 0;
}