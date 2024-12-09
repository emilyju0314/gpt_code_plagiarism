#include<bits/stdc++.h>
using namespace std;
#define pb                          push_back
#define HarryPotter                 ios_base::sync_with_stdio(0);  cin.tie(0);
#define mod                         1000000007
#define ll                          long long
#define mk                          make_pair
#define ff                          first 
#define ss                          second  
#define debug(x) cout << #x << " :: "<< x <<"\n";
#define debug2(x,y) cout << #x << " :: "<< x << "\t" << #y << " :: " << y << "\n";
#define debug3(x,y,z) cout << #x << " :: "<< x << "\t" << #y << " :: " << y << "\t" << #z << " :: " << z << "\n";
#define in_range(x, y, r, c) (x < r && y < c && x >= 0 && y >= 0)

template <typename T>
void print_vector(vector<T>path)
{
    copy(path.begin(), path.end(), ostream_iterator<T>(cout, " "));
    cout << endl;
}
template <typename T>
void print_array( T a , ll n)   
{
    for( ll i=0 ; i<n ; i++)
        cout << a[i] << " ";
    cout << endl;
}
 
vector<ll> take_input( ll n )
{
    vector<ll>v(n);
    for( ll i=0 ; i<n ; i++)
        cin >> v[i];
    return v;
}

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
}; 


ll get( ll n )
{   
    ll num = n;

    for( int i=sqrt(n) ; i>=2 ; i--)
    {
        while(n%(i*i)==0)
            n = n/(i*i);
    }

    return n;
}

int main()
{
    HarryPotter;
    ll test;
    cin >> test;

    while(test--)
    {
        ll n , k;
        cin >> n >> k;

        std::vector<ll> a = take_input(n);

        ll count = 0;

        unordered_map<ll,ll>mp , has;

        for( int i=0 ; i<n ; i++)
        {
            if(has[a[i]]!=0)
                a[i] = has[a[i]];
            else
            {
                has[a[i]] = get(a[i]);
                a[i] = has[a[i]];
            }

            if(mp[a[i]]!=0)
            {
                count++;
                // debug(i);
                mp.clear();
                mp[a[i]]++;
            }

            mp[a[i]]++;
            // debug(a[i]);
        }

        cout << count+1 << endl;
    }

    return 0;
}
