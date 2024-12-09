#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValidSignboard(string store, string oldSign) {
    int storeIndex = 0;
    for(int i = 0; i < oldSign.size(); i++) {
        if(oldSign[i] == store[storeIndex]) {
            storeIndex++;
        }
        if(storeIndex == store.size()) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    
    string store;
    cin >> store;
    
    vector<string> oldSignboards(N);
    for(int i = 0; i < N; i++) {
        cin >> oldSignboards[i];
    }
    
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(isValidSignboard(store, oldSignboards[i])) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}