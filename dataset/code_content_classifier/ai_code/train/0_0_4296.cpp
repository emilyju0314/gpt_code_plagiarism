#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int k, n;
    cin >> k >> n;
    
    unordered_map<string, int> beauties;
    string s;
    int beauty;
    
    for(int i = 0; i < k; i++) {
        cin >> s >> beauty;
        string reverse_s = s;
        reverse(reverse_s.begin(), reverse_s.end());
        
        if(beauties.count(reverse_s)) {
            beauties[reverse_s] = max(beauties[reverse_s], beauty);
        } else {
            beauties[s] = beauty;
        }
    }
    
    int total_beauty = 0;
    string result = "";
    
    for(auto it : beauties) {
        string reverse_it = it.first;
        reverse(reverse_it.begin(), reverse_it.end());
        
        if(beauties.count(reverse_it)) {
            total_beauty += it.second;
            result += it.first;
        }
    }
    
    cout << total_beauty << endl;
    
    return 0;
}