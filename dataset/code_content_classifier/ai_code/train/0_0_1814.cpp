#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    unordered_map<string, int> memory_map;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        
        if (s == "A=malloc(10)") {
            memory_map["A"] = 1;
        } else if (s == "B=clone(A)") {
            memory_map["B"] = memory_map["A"];
        } else if (s == "free(A)") {
            memory_map["A"] = 0;
        }
    }
    
    if (memory_map["A"] == 1 && memory_map["B"] == 0) {
        cout << "0" << endl;
    } else {
        cout << "1" << endl;
    }
    
    return 0;
}