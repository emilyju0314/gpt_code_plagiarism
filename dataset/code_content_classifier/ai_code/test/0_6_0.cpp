#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool customSort(string a, string b) {
    for(int i = 0; i < a.length(); i++) {
        if(i % 2 == 0) {
            if(a[i] != b[i])
                return a[i] < b[i];
        } else {
            if(a[i] != b[i])
                return a[i] > b[i];
        }
    }
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> books(n);
    for(int i = 0; i < n; i++) {
        cin >> books[i];
    }
    
    vector<int> indices(n);
    for(int i = 0; i < n; i++) {
        indices[i] = i+1;
    }
    
    sort(indices.begin(), indices.end(), [&](int i, int j){
        return customSort(books[i-1], books[j-1]);
    });
    
    for(int i = 0; i < n; i++) {
        cout << indices[i] << " ";
    }
    
    return 0;
}