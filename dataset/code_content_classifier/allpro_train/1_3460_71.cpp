#include <iostream>
#include <string>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
int a,i,p;
int main() {
    cin >> a;
    while (p < a){
        i++;
        p += i;
    }
    string s;
    REP(j,i) s = s + ')';
    REP(j,i) s = s + '(';
    swap(s[i], s[i-p+a]);
    cout << s << endl;
    return 0;
}