#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> handles(N);
    for(int i = 0; i < N; i++) {
        std::cin >> handles[i];
    }

    std::string T;
    std::cin >> T;

    std::vector<std::pair<int, std::string>> sorted_handles;
    
    handles.push_back(T);
    
    std::sort(handles.begin(), handles.end());
    
    for(int i = 0; i < handles.size(); i++) {
        if(handles[i] == T) {
            sorted_handles.push_back({i, T});
        }
    }

    for(int i = 0; i < sorted_handles.size(); i++) {
        std::cout << sorted_handles[i].first << " ";
    }

    std::cout << std::endl;

    return 0;
}