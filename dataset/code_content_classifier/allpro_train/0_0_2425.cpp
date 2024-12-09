#include <iostream>
#include <string>

bool isPalindrome(int num){
    std::string str = std::to_string(num);
    int i = 0;
    int j = str.length() - 1;
    while(i < j){
        if(str[i] != str[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    int lower = n - 1;
    int upper = n + 1;
    while(true){
        if(isPalindrome(lower)){
            std::cout << lower << std::endl;
            break;
        }
        if(isPalindrome(upper)){
            std::cout << upper << std::endl;
            break;
        }
        lower--;
        upper++;
    }
    
    return 0;
}