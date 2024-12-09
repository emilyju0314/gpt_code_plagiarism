#include <iostream>
#include <string>

int main() {
    int N;
    std::string S;
    
    std::cin >> N >> S;
    
    int count = 0;
    
    for(int i = 0; i < N; i++) {
        if(i==0 && S[i] == '#') {
            count++;
        } else if(i > 0 && S[i] == '#' && S[i-1] == '.') {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}