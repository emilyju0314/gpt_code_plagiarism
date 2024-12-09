#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countInversions(vector<int>& a){
    int n = a.size();
    vector<int> b;
    int inversions = 0;

    for(int i=0; i<n; i++){
        if(i%2 == 0){
            b.push_back(a[i]);
        } else {
            b.insert(b.begin(), a[i]);
            inversions += b.size() - 1 - distance(b.begin(), find(b.begin(), b.end(), a[i]));
        }
    }

    return inversions;
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin >> a[i];
        }

        int result = countInversions(a);
        cout << result << endl;
    }

    return 0;
}