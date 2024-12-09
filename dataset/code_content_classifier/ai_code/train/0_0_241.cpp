#include <iostream>
#include <string>

std::string applyMessenger(const std::string& message, char messenger) {
    std::string result = message;
    
    if (messenger == 'J') {
        char temp = result[0];
        for (int i = 1; i < result.length(); i++) {
            result[i - 1] = result[i];
        }
        result[result.length() - 1] = temp;
    } else if (messenger == 'C') {
        char temp = result[result.length() - 1];
        for (int i = result.length() - 2; i >= 0; i--) {
            result[i + 1] = result[i];
        }
        result[0] = temp;
    } else if (messenger == 'E') {
        int mid = result.length() / 2;
        if (result.length() % 2 == 0) {
            std::string left = result.substr(0, mid);
            std::string right = result.substr(mid, result.length() - mid);
            result = right + left;
        } else {
            char temp = result[mid];
            std::string left = result.substr(0, mid);
            std::string right = result.substr(mid + 1, result.length() - mid - 1);
            result = right + temp + left;
        }
    } else if (messenger == 'A') {
        std::reverse(result.begin(), result.end());
    } else if (messenger == 'P') {
        for (char& c : result) {
            if (std::isdigit(c)) {
                if (c == '9') {
                    c = '0';
                } else {
                    c++;
                }
            }
        }
    } else if (messenger == 'M') {
        for (char& c : result) {
            if (std::isdigit(c)) {
                if (c == '0') {
                    c = '9';
                } else {
                    c--;
                }
            }
        }
    }

    return result;
}

int main() {
    int n;
    std::cin >> n;
    
    for (int i = 0; i < n; i++) {
        std::string order;
        std::string message;
        
        std::cin >> order >> message;
        
        for (int j = order.length() - 1; j >= 0; j--) {
            message = applyMessenger(message, order[j]);
        }
        
        std::cout << message << std::endl;
    }
    
    return 0;
}