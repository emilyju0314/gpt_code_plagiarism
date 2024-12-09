#include <bits/stdc++.h>
typedef long long ll;

void solve(){
    std::string s;
    std::cin >> s;
    if(s[0] != ')' && s[s.length()-1] != '(' && s.length() % 2 == 0){
        std::cout << "YES" << std::endl;
    }
    else{
        std::cout << "NO" << std::endl;
    }
    
}  


int main(){
    #if 1
    int tc;
    std::cin >> tc;
    while(tc--){
        solve();
    }
    #else
    solve();
    #endif

	return 0;
}