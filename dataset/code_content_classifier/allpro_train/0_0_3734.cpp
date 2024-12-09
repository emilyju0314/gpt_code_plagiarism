#include <iostream>
#include <string>

int countSubstrings(std::string t, std::string sbegin, std::string send) {
    int count = 0;
    int t_length = t.length();
    int begin_length = sbegin.length();
    int end_length = send.length();

    for (int i = 0; i < t_length; i++) {
        if (t.substr(i, begin_length) == sbegin) {
            for (int j = i + begin_length; j < t_length; j++) {
                if (t.substr(j, end_length) == send) {
                    count++;
                }
            }
        }
    }

    return count;
}

int main() {
    std::string t, sbegin, send;
    std::cin >> t >> sbegin >> send;

    int result = countSubstrings(t, sbegin, send);
    std::cout << result << std::endl;

    return 0;
}