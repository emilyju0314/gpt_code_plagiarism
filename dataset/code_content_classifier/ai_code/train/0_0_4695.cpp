#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while(t--) {
        std::string s;
        std::cin >> s;

        int res = 0, cur = 0;
        for(int init = 0; ; ++init) {
            cur = init;
            bool ok = true;
            for(int i = 0; i < s.length(); ++i) {
                res++;  
                if(s[i] == '+') {
                    cur++;
                } else {
                    cur--;
                }
                if(cur < 0) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                break;
            }
        }
        
        std::cout << res << std::endl;
    }

    return 0;
}