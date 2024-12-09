#include <iostream>
#include <vector>

bool checkPossibility(std::vector<int>& q, std::vector<int>& s) {
    std::vector<bool> visited(q.size(), false);

    for(int i = 0; i < q.size(); i++) {
        if(q[i] == s[i]){
            visited[i] = true;
        }
    }

    int count = 0;
    for(int i = 0; i < q.size(); i++) {
        if(!visited[i]) {
            int curr = i;
            while(!visited[curr]) {
                visited[curr] = true;
                curr = s[curr] - 1;
                count++;
            }
            if(count > q.size()) return false;
        }
    }

    return count % 2 == 0;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> q(n);
    std::vector<int> s(n);

    for(int i = 0; i < n; i++) {
        std::cin >> q[i];
    }

    for(int i = 0; i < n; i++) {
        std::cin >> s[i];
    }

    if(checkPossibility(q, s) && k % 2 == 0) {
        std::cout << "YES" << std::endl;
    } else if(!checkPossibility(q, s) && k % 2 != 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}