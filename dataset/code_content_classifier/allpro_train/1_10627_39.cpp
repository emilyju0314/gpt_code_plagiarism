#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N];
    for(int i =0; i < N; i++){
        cin >> a[i];
    }

    long long sum = 0;
    map<int, int> m;
    for(int i =0; i < N; i++){
        sum += m[a[i]];
        m[a[i]] ++;
    }
    for(int i =0; i < N; i++){
        cout << sum - (m[a[i]] - 1) << endl;
    }
}