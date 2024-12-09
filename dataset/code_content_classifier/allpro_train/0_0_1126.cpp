#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string S;
    std::cin >> S;

    int Q, A, B;
    std::cin >> Q >> A >> B;

    std::vector<std::pair<char, std::string>> replacements(Q);
    for(int i = 0; i < Q; i++) {
        char c;
        std::string p;
        std::cin >> c >> p;
        replacements[i] = {c, p};
    }

    for(auto& replacement : replacements) {
        for(int i = 0; i < S.length(); i++) {
            if(S[i] == replacement.first) {
                S.replace(i, 1, replacement.second);
            }
        }
    }

    if(B > S.length()) {
        std::cout << "." << std::endl;
    } else {
        std::cout << S.substr(A-1, B-A+1) << std::endl;
    }

    return 0;
}