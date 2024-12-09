#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int s;
        cin >> s;
        
        int num = 1;
        vector<int> beautifulArray;
        while(s > 0) {
            beautifulArray.push_back(num);
            s -= num;
            num += 2;
        }
        
        cout << beautifulArray.size() << endl;
    }
    
    return 0;
}