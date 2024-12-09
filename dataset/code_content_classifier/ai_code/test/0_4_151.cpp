#include <iostream>
#include <vector>
#include <map>

int main() {
    int q;
    std::cin >> q;

    std::vector<int> arr;
    std::map<int, int> replace;

    for(int i = 0; i < q; i++) {
        int type, x, y;
        std::cin >> type >> x;
        
        if(type == 1) {
            arr.push_back(x);
        } else {
            std::cin >> y;
            replace[x] = y;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        if(replace.find(arr[i]) != replace.end()) {
            arr[i] = replace[arr[i]];
        }
        std::cout << arr[i] << " ";
    }

    return 0;
}