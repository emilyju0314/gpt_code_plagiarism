#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, q;
    std::cin >> n >> k >> q;

    std::vector<int> t(n);
    for(int i=0; i<n; i++) {
        std::cin >> t[i];
    }

    std::vector<int> friendsOnline;
    for(int i=0; i<q; i++) {
        int type, id;
        std::cin >> type >> id;

        if(type == 1) {
            friendsOnline.push_back(t[id-1]);
            std::sort(friendsOnline.begin(), friendsOnline.end(), std::greater<int>());
            if(friendsOnline.size() > k) {
                friendsOnline.pop_back();
            }
        } else {
            bool displayed = false;
            for(int j=0; j<friendsOnline.size(); j++) {
                if(t[id-1] == friendsOnline[j]) {
                    displayed = true;
                    break;
                }
            }

            if(displayed) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}