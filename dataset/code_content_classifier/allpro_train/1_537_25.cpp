#include <bits/stdc++.h>
#define db(a) cout << a << endl
#define db2(a,b) cout << a << " " << b << endl
#define dbd(a) cout << #a << ": " << a << endl
#define dbd2(a,b) cout << #a << ": " << a << ", " << #b << ": " << b << endl 
#define dbp(a) cout << a.first << " " << a.second << endl
#define adb(a) for(auto _i:a) cout << _i << " "; cout << endl
#define adbp(a) for(auto _i:a) cout << _i.first << " " << _i.second << endl;
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define mod 1000000007
#define N 100010
#define M 100010
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    fastIO;
    int t;
    cin >> t;

    while(t--)
    {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        if(n%k)
        {
            cout << -1 << endl;
            continue;
        }

        int cnt[26] = {0};
        bool ok = false, ok2 = true;
        string ans = "";

        for(int i=0; i<n; i++) cnt[s[i] - 'a']++;
        for(int i=0; i<26; i++) ok2 &= (cnt[i]%k == 0);

        if(ok2)
        {
            cout << s << endl;
            continue;
        }
        // adb(cnt);

        for(int i=n-1; i>=0 && !ok; i--)
        {
            cnt[s[i] - 'a']--;
            for(int j=1;j+(s[i]-'a')<26&& !ok;j++){
            	cnt[s[i]+j-'a']++;
            	int tcnt=0,cnt2[26]={0};
            	for(int kk=0;kk<26;kk++){
            		
            		if(cnt[kk]%k==0)cnt2[kk]=0;
            		else cnt2[kk]=(k-cnt[kk]%k); 
					tcnt+=cnt2[kk];
				}
				int diff=n-i-1-tcnt;
				if(diff>=0){
					ok=true;
					for(int l=0;l<i;l++)ans.push_back(s[l]);
					ans.push_back(s[i]+j);
					for(int l=0;l<diff;l++)ans.push_back('a');
					for(int l=0;l<26;l++){
						for(int m=0;m<cnt2[l];m++)
						ans.push_back(char('a'+l));
					}
				}
            	cnt[s[i]+j-'a']--;
			}
        }

        if(!ok) cout << -1 << endl;
        else cout << ans << endl;
    }
}