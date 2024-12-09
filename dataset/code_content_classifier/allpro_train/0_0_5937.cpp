#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> code(n);
    std::vector<int> result(n);
    std::vector<bool> marked(n+1, false);
    
    for(int i = 0; i < n; i++) {
        std::cin >> code[i];
    }

    int current = 1;
    for(int i = 0; i < n; i++) {
        if(code[i] == -1) {
            while(marked[current]) {
                current++;
            }
            result[i] = current;
            marked[current] = true;
        } else {
            int pos = 1;
            for(int j = 0; j < n; j++) {
                if(code[j] > code[i]) {
                    if(pos == code[i]) {
                        pos++;
                    }
                }
            }
            result[i] = pos;
            marked[pos] = true;
        }
    }
    
    for(int i = 0; i < n; i++) {
        std::cout << result[i] << " ";
    }
    
    return 0;
}