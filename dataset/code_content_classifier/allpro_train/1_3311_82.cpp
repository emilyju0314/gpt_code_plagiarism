/* Sometimes you win , sometimes you learn . */
/* "Genius is 1% talent and 99% hard work" . */
#include <bits/stdc++.h>
#define lp(i , N) for(ll i = 0; i < ll (N) ; i++)
#define FAST ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define debug(x) cout<<" [ " << #x << " is: " << x << " ] "<<endl;
#define int long long
using namespace std;
typedef long long ll;
typedef long double ld;
const long double EPS = 1e-6;
const long double pi = acos(-1);
const long long oo = 1e18;
const long long N = 1e6;
signed main(){
    FAST
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int cnt1 = 0 , cnt2 = 0 , result = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                cnt1++;
            }
            else if(s[i] == ')') {
                if(cnt1 > 0) {
                    cnt1--;
                    result++;
                }
            }
            else if(s[i] == '[') {
                cnt2++;
            }
            else if(s[i] == ']') {
                if(cnt2 > 0) {
                    cnt2--;
                    result++;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}
/*
[#]=============================================================[#]
         ___    ____              ____          ___ _
        |_ _|  / ___|__ _ _ __   |  _ \  ___   |_ _| |_
         | |  | |   / _` | '_ \  | | | |/ _ \   | || __|
         | |  | |__| (_| | | | | | |_| | (_) |  | || |_
        |___|  \____\__,_|_| |_| |____/ \___/  |___|\__|
                     it's just about time

[#]=============================================================[#]
*/
