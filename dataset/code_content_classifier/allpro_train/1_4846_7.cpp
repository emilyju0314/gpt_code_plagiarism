#include <bits/stdc++.h> 
#define rep(i, a, n) for(int i = a; i < n; i++)
using namespace std;

int main(){
    int n;
    cin >> n;
    int MAX = -1, id = -1;
    rep(i, 1, n + 1){
        int d;
        cout << "? " << 1 << " " << i << endl;
        cout.flush();
        cin >> d;
        if(MAX < d){
            MAX = d;
            id = i;
        }
    }
    vector<int> a(n + 1, -1);
    a[0] = id;
    rep(i, 1, n + 1){
        int d;
        cout << "? " << id << " " << i << endl;
        cout.flush();
        cin >> d;
        a[d] = i;
    }
    cout << "!";
    rep(i, 0, n){
        cout << " " << a[i];
    }
    cout << endl;
    cout.flush();
}