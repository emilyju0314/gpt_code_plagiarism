#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << min(9, n) + max(min(900, n-99), 0) + max(min(90000, n-9999), 0);
    return 0;
}