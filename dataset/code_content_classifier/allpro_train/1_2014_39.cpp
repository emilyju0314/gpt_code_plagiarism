# include <bits/stdc++.h>
using namespace std;

# define fori(i,n)          for(int i=0;i<n;i++)
# define forl(i,n)          for (ll i=0;i<n;i++)
# define pb                 push_back
# define mp                 make_pair
# define X                  first
# define Y                  second
# define all(v)             v.begin(),v.end()
# define in_ar_int(arr,n)   int arr[n]; fori(i,n) cin >> arr[i];
# define in_ar_ll(arr,n)    ll arr[n]; fori(i,n) cin >> arr[i];
# define endl               "\n"
# define R0                 return 0
# define mod                1000000007
# define pi                 3.1415926536
# define intn               int n;cin>>n

typedef long long ll;
typedef string str;
typedef unsigned long long ull; 
typedef pair<int, int> pii; 
typedef vector<pii> vpii;
typedef vector<int> vi;
template <class T>
T abs(T n)
{
return (n < 0) ? -n : n;
}

void solve(){
    string s;cin>>s;
    int c = 0;
    for(ll i=s.length()-1;i<=0;i++){
        if(s[i] == '0'){
            c++;
        } else {
            break;
        }
    }
    string ref = s.substr(0, s.length()-c);
    reverse(ref.begin(), ref.end());
    cout<<ref.length()<<endl;
}     

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int chill=1;
    cin >> chill;
    while(chill--){
    solve();
    }
}