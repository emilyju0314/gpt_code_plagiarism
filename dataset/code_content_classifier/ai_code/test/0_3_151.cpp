#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int q;
    cin >> q;

    vector<int> arr;
    unordered_map<int, int> replace;

    while(q--) {
        int type, x, y;
        cin >> type >> x;
      
        if(type == 1) {
            arr.push_back(x);
        } else {
            cin >> y;
            replace[x] = y;
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        if(replace.find(arr[i]) != replace.end()) {
            arr[i] = replace[arr[i]];
        }
        cout << arr[i] << " ";
    }

    return 0;
}